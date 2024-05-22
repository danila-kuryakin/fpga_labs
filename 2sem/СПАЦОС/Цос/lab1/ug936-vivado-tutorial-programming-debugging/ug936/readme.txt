*************************************************************************
   ____  ____ 
  /   /\/   / 
 /___/  \  /   
 \   \   \/    © Copyright 2021 Xilinx, Inc. All rights reserved.
  \   \        This file contains confidential and proprietary 
  /   /        information of Xilinx, Inc. and is protected under U.S. 
 /___/   /\    and international copyright and other intellectual 
 \   \  /  \   property laws. 
  \___\/\___\ 
 
*************************************************************************

Vendor: Xilinx 
Current readme.txt Version: 19.0
Date Last Modified:  02FEB2021
Date Created: 14MAY2015

Associated Filename: ug936-vivado-tutorial-programming-debugging.zip
Associated Document: UG936, Vivado Design Suite Tutorial: Programming and Debugging

Supported Device(s): Kintex-7

*************************************************************************

Disclaimer: 

      This disclaimer is not a license and does not grant any rights to 
      the materials distributed herewith. Except as otherwise provided in 
      a valid license issued to you by Xilinx, and to the maximum extent 
      permitted by applicable law: (1) THESE MATERIALS ARE MADE AVAILABLE 
      "AS IS" AND WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL 
      WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, 
      INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
      NON-INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and 
      (2) Xilinx shall not be liable (whether in contract or tort, 
      including negligence, or under any other theory of liability) for 
      any loss or damage of any kind or nature related to, arising under 
      or in connection with these materials, including for any direct, or 
      any indirect, special, incidental, or consequential loss or damage 
      (including loss of data, profits, goodwill, or any type of loss or 
      damage suffered as a result of any action brought by a third party) 
      even if such damage or loss was reasonably foreseeable or Xilinx 
      had been advised of the possibility of the same.

Critical Applications:

      Xilinx products are not designed or intended to be fail-safe, or 
      for use in any application requiring fail-safe performance, such as 
      life-support or safety devices or systems, Class III medical 
      devices, nuclear facilities, applications related to the deployment 
      of airbags, or any other applications that could lead to death, 
      personal injury, or severe property or environmental damage 
      (individually and collectively, "Critical Applications"). Customer 
      assumes the sole risk and liability of any use of Xilinx products 
      in Critical Applications, subject only to applicable laws and 
      regulations governing limitations on product liability.



*************************************************************************

This readme file contains these sections:

1. REVISION HISTORY
2. OVERVIEW
3. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS
4. DESIGN FILE HIERARCHY
5. INSTALLATION AND OPERATING INSTRUCTIONS
6. OTHER INFORMATION (OPTIONAL)
7. SUPPORT


1. REVISION HISTORY 

            Readme  
Date        Version      Revision Description
=========================================================================
04JUL2014   1.0          Updates to the tutorials to reflect the 2014.1 Vivado software changes.
04JUN2014   2.0  	 Updates to the tutorials to reflect the 2014.2 Vivado software changes.
15OCT2014   3.0  	 Updates to the tutorials to reflect the 2014.3 Vivado software changes.
19NOV2014   4.0		 Updates to the tutorials to reflect the 2014.4 Vivado software changes.
03DEC2014   5.0          Fixed link to design files.
01MAY2015   6.0          Updates to the tutorials to reflect the 2015.1 Vivado software changes.
24JUN2015   7.0          Updates to the tutorials to reflect the 2015.2 Vivado software changes.
29SEP2015   8.0          Updates to the tutorials to reflect the 2015.3 Vivado software changes.
09NOV2015   9.0          Updates to the tutorials to reflect the 2015.4 Vivado software changes.
04APR2016   10.0         Updates to the tutorials to reflect the 2016.1 Vivado software changes.
04MAY2016   11.0         Added Lab6: Using ECO Flow to Replace Debug Probes Post Implementation.
24JUN2016   12.0         Added Lab7: Debugging Designs Using Incremental Compile Flow.
15MAR2017   13.0         Updates to the tutorials to reflect the 2017.1 Vivado software changes.
05MAY2017   14.0         Added Lab10: Using Vivado Serial Analyzer to Debug GTR Serial Links 
11OCT2017   15.0         Updates to the tutorials to reflect the 2017.3 Vivado software changes. 
27APR2018   16.0	    Updated menu commands.
08NOV2019   17.0      Removed Lab10 as it is not compatable with Vitis.  See AR
05JUN2020   18.0       Updates to the tutorials to reflect the 2020.1 Vivado software changes. 
04FEB2021   19.0      Updates for 2020.2, re-instate lab10 with changes for Vitis flow.

=========================================================================



2. OVERVIEW

This readme describes how to use the files that come with UG936

4 designs to demonstrate how to use the Viavdo Hardware Debugging and Programming tools including the Vivado Logical Analyzer tools.


3. SOFTWARE TOOLS AND SYSTEM REQUIREMENTS


* Xilinx Vivado 2020.2
* Xilinx KC705 board


4. DESIGN FILE HIERARCHY

<Describe the file hierarchy by type (HDL files, simulation files, etc.)>

<For example:>
The directory structure underneath this top-level folder is described 
below:

src/
   Lab 1: This lab walks you through the steps of marking nets for debug in HDL as well as the post-synthesis netlist (Netlist Insertion Method). Following are the required files:
   • debounce.vhd
   • fsm.vhd
   • sinegen.vhd
   • sinegen_demo.vhd
   • sine_high/sine_high.xci
   • sine_low/sine_low.xci
   • sine_mid/sine_mid.xci
   • sinegen_demo_kc705.xdc

   Lab2: This lab goes over the details of marking nets for debug in the source HDL (HDL instantiation method) as well as instantiating an ILA core in the HDL. Following are the required files:
   • debounce.vhd
   • fsm.vhd
   • sinegen.vhd
   • sinegen_demo_inst.vhd
   • ila_0/ila_0.xci
   • sine_high/sine_high.xci
   • sine_low/sine_low.xci
   • sine_mid/sine_mid.xci
   • sinegen_demo_kc705.xdc

   Lab 3: You can test your design even if the hardware is not physically accessible, using a VIO core. This lab will walk you over the steps of instantiating and customizing a VIO core that you will hook to the I/Os of the design. Following are the required files:
   • debounce.vhd
   • fsm.vhd
   • sinegen.vhd
   • sinegen_demo_inst_vio.vhd
   • sine_high/sine_high.xci
   • sine_low/sine_low.xci
   • sine_mid/sine_mid.xci
   • ila_0/ila_0.xci
   • sinegen_demo_kc705.xdc
  
   Lab 4: Nets can also be marked for debug in a third-party synthesis tool using directives for the synthesis tool. This lab walks you through the steps of marking nets for debug in the Synplify tool and then using Vivado to perform the rest of the debug. Following are the required files:
   • dds_compiler_v6_0_viv.edn
   • dds_compiler_v6_0_viv_parameterized1.edn
   • dds_compiler_v6_0_viv_parameterized3.edn
   • debounce.vhd
   • fsm.vhd
   • sine_high.xci
   • sine_low.xci
   • sine_mid.xci
   • sinegen.edn
   • sinegen_synplify.vhd
   • synplify_1.sdc
   • sinegen_demo_kc705.xdc

5. INSTALLATION AND OPERATING INSTRUCTIONS 

   1) Install the Xilinx Vivado 2020.2


6. OTHER INFORMATION (OPTIONAL) 


7. SUPPORT

To obtain technical support for this reference design, go to 
www.xilinx.com/support to locate answers to known issues in the Xilinx
Answers Database.  
