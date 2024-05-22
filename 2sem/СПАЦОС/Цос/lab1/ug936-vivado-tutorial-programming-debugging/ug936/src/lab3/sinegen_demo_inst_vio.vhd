--------------------------------------------------------------
-- (C) Copyright 2010-2011 Xilinx, Inc. All Rights Reserved.
-- 
-- XILINX, the Xilinx logo, the Brand Window and other 
-- designated brands included herein are trademarks of Xilinx, 
-- Inc. All other trademarks are the property of their 
-- respective owners.
-- 
-- NOTICE OF DISCLAIMER: The information disclosed to you 
-- hereunder (the ?Information?) is provided ?AS-IS? with no 
-- warranty of any kind, express or implied. Xilinx does not 
-- assume any liability arising from your use of the 
-- Information. You are responsible for obtaining any rights 
-- you may require for your use of this Information. Xilinx 
-- reserves the right to make changes, at any time, to the 
-- Information without notice and at its sole discretion. 
-- Xilinx assumes no obligation to correct any errors contained 
-- in the Information or to advise you of any corrections or 
-- updates. Xilinx expressly disclaims any liability in 
-- connection with technical support or assistance that may be 
-- provided to you in connection with the Information. XILINX 
-- MAKES NO OTHER WARRANTIES, WHETHER EXPRESS, IMPLIED, OR 
-- STATUTORY, REGARDING THE INFORMATION, INCLUDING ANY 
-- WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
-- PURPOSE, OR NONINFRINGEMENT OF THIRD-PARTY RIGHTS.
--------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

library unisim;
use unisim.vcomponents.all;

entity sinegen_demo_inst_vio is
  port
  (
    CLK_P         : in  std_logic;
    CLK_N         : in  std_logic;
    GPIO_BUTTONS  : in  std_logic_vector(1 downto 0);
    GPIO_SWITCH   : in  std_logic;
    LEDS_n        : out std_logic_vector(3 downto 0)
  );
end entity;

architecture hdl_inst_vio of sinegen_demo_inst_vio is
     
  signal clk, clk_ibufgds              : std_logic;
  signal sine                         : std_logic_vector(19 downto 0);
  signal sineSel                      : std_logic_vector(1 downto 0);

  signal GPIO_BUTTONS_db              : std_logic_vector(1 downto 0);
  signal GPIO_BUTTONS_dly             : std_logic_vector(1 downto 0);
  signal GPIO_BUTTONS_re              : std_logic_vector(1 downto 0);

  signal DONT_EAT0                    : std_logic;
  signal DONT_EAT1                    : std_logic;
  signal DONT_EAT2                    : std_logic;
  signal DONT_EAT3                    : std_logic;
  signal DONT_EAT4                    : std_logic;
  signal DONT_EAT                     : std_logic;
  
  signal push_button_vio              : std_logic;
  signal push_button_reset            : std_logic;

  -- Attributes for Synplify Pro
  -- attribute syn_keep : boolean;
  -- attribute syn_keep of GPIO_BUTTONS_db   : signal is true;
  -- attribute syn_keep of GPIO_BUTTONS_dly  : signal is true;
  -- attribute syn_keep of GPIO_BUTTONS_re   : signal is true;
  
   
  component sinegen is
    port
    (
      clk   : in    std_logic;
      reset : in    std_logic;
      sel   : in    std_logic_vector(1 downto 0);
      sine  : out   std_logic_vector(19 downto 0)
    );
  end component;

  component fsm is
    port
    (
      clk       : in  std_logic;
      reset     : in  std_logic;
      button    : in  std_logic;
      Y         : out std_logic_vector(1 downto 0)
    );
  end component;
  
  component debounce is
    port
    (
    clk       : in  std_logic;
    button_in : in  std_logic;
    button_db : out std_logic
  );
  end component;
  
  component ila_0 is
    port
    (
    CLK : IN STD_LOGIC;
    PROBE0 : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    PROBE1 : IN STD_LOGIC_VECTOR(19 DOWNTO 0);
    PROBE2 : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    PROBE3 : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
    PROBE4 : IN STD_LOGIC_VECTOR(1 DOWNTO 0)
  );  
  end component;
  
  component vio_0 is
    port 
    (
    CLK : IN STD_LOGIC;
    PROBE_IN0 : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    PROBE_OUT0 : OUT STD_LOGIC_VECTOR(1 DOWNTO 0)
  );
  end component;
  
begin
 
  ------------------------------------------------------------
  --  Differential clock buffer
  ------------------------------------------------------------
    U_IBUFGDS : ibufgds
    generic map 
    (
    IOSTANDARD => "LVDS"
    )
    port map 
    (   
    O => clk_ibufgds, 
    I => CLK_P,
    IB => CLK_N
    );
    U_BUFG : bufg
    port map 
    (   
    O => clk, 
    I => clk_ibufgds
    );

  ------------------------------------------------------------
  --  Buttons and debouncers
  ------------------------------------------------------------
  U_DEBOUNCE_0 : debounce 
    port map
    (
      clk       => clk,
      button_in => push_button_vio,
      button_db => GPIO_BUTTONS_db(0)
    ); 

  U_DEBOUNCE_1 : debounce
    port map
    (
      clk       => clk,
      button_in => push_button_reset,
      button_db => GPIO_BUTTONS_db(1)
    ); 

  -- Rising edge logic for the buttons
  process (clk)
  begin
    if (rising_edge(clk)) then
      -- If (GPIO_SWITCH = '1') then enable the actual buttons on the KC705 board.  
      if (GPIO_SWITCH = '1') then
        GPIO_BUTTONS_dly(0) <= GPIO_BUTTONS_db(0);
        GPIO_BUTTONS_re(0)  <= not GPIO_BUTTONS_db(0) and GPIO_BUTTONS_dly(0);
        GPIO_BUTTONS_dly(1) <= GPIO_BUTTONS_db(1);
        GPIO_BUTTONS_re(1)  <= not GPIO_BUTTONS_db(1) and GPIO_BUTTONS_dly(1);
      -- Otherwise, select the outputs of the VIO core  
      else
        GPIO_BUTTONS_dly(0) <= push_button_reset;
        GPIO_BUTTONS_re(0)  <= not push_button_reset and GPIO_BUTTONS_dly(0);
        GPIO_BUTTONS_dly(1) <= push_button_vio;
        GPIO_BUTTONS_re(1)  <= not push_button_vio and GPIO_BUTTONS_dly(1);
      end if;
    end if;
  end process;

  ------------------------------------------------------------
  --  Sine generator
  ------------------------------------------------------------
  U_SINEGEN : sinegen
    port map
    (
      clk   => clk,
      reset => GPIO_BUTTONS_re(0),
      sel   => sineSel,
      sine  => sine
    ); 
    
  ------------------------------------------------------------
  --  Finite state machine
  ------------------------------------------------------------
  U_FSM : fsm
    port map
    (
      clk    => clk,
      reset   => GPIO_BUTTONS_re(0),
      button  => GPIO_BUTTONS_re(1),
      Y       => sineSel
    ); 
    
  ------------------------------------------------------------
  --  LEDs
  ------------------------------------------------------------
  LEDS_n(0)   <= sineSel(0);
  LEDS_n(1)   <= sineSel(1);
  LEDS_n(2)   <= GPIO_BUTTONS_re(1);
  LEDS_n(3)   <= DONT_EAT;
 
  ------------------------------------------------------------
  -- ILA 
  ------------------------------------------------------------
  U_ILA : ila_0
    port map
    (
      CLK => clk,
      PROBE0 => sineSel,
      PROBE1 => sine,
      PROBE2 => (push_button_reset & push_button_vio),
      PROBE3 => GPIO_BUTTONS_re,
      PROBE4 => GPIO_BUTTONS_dly
    );  
  
  ------------------------------------------------------------
  -- VIO
  ------------------------------------------------------------
  U_VIO : vio_0
    port map
    (
      CLK => clk,
      PROBE_IN0(3) => DONT_EAT,
      PROBE_IN0(2) => GPIO_BUTTONS_re(1),
      PROBE_IN0(1 downto 0) => sineSel,
      PROBE_OUT0(1) => push_button_reset,
      PROBE_OUT0(0) => push_button_vio
    );
  
  
  -- Dummy logic to keep XST from eating the design
  process (clk)
  begin
    if (rising_edge(clk)) then
      DONT_EAT4 <= sine(16) and sine(17) and sine(18) and sine(19);
      DONT_EAT3 <= sine(15) and sine(14) and sine(13) and sine(12);
      DONT_EAT2 <= sine(11) and sine(10) and sine(9) and sine(8);
      DONT_EAT1 <= sine(7) and sine(6) and sine(5) and sine(4);
      DONT_EAT0 <= sine(3) and sine(2) and sine(1) and sine(0);
      DONT_EAT  <= DONT_EAT4 and DONT_EAT3 and DONT_EAT2 and DONT_EAT1 and DONT_EAT0; 
    end if;
  end process;

end hdl_inst_vio;
