###############################################################################
#
# Copyright (C) 2017 Xilinx, Inc.  All rights reserved.
# This Tcl is confidential and proprietary of Xilinx, All Rights Reserved.
#
# xsct_create_fsbl.tcl
# 
# Instructions:
#   1) Place this script in the <projectname>/<projectname>.sdk
#      directory after the HDF file is created.  This is the location
#      where the HDF file should be.
#   2) Modify constants below if needed.
#   3) From the commandline, cd to the
#      <projectname>/<projectname>.sdk directory.
#   4) Run command: xsct xsct_create_fsbl.tcl
#
###############################################################################

# Constants

# Change this if the xsa file has a different name
set xsapath  design_1_wrapper.xsa

# Change this to use a different core for the FSBL (Note: IBERT GTR uses the R5 0)
set fsblcore psu_cortexa53_0

# Change this to use custom compiler flags
set c_optimizations {Optimize more (-O2)}
set c_symbols [list FSBL_DEBUG_INFO XPS_BOARD_ZCU102]

# Change this to disable modifying FSBL if there is a USB in the design
set modify_usb 1


##### Nothing below this should need to be modified #####

set fsblmainh ./fsbl_design_1/src/xfsbl_main.h
set fsblmainc ./fsbl_design_1/src/xfsbl_main.c

# This function checks to see if the design is using usb
proc design_has_usb {} {
    global modify_usb
    
    if {$modify_usb == 0} {
        return 0
    }
    
    set drivers [bsp getdrivers]
    if {[lsearch $drivers *usb*] != -1} {
        return 1
    }
    
    return 0
}

# This funtion searches the file for a specific string and
# adds the input string after it
proc insert_in_file {filename searchstr inputstr} {
    # Read lines of file
    set f [open $filename "r"]
    set lines [split [read $f] "\n"]
    close $f

    # Find the insertion index in the reversed list
    set idx [lsearch [lreverse $lines] $searchstr]
    if {$idx < 0} {
        error "did not find insertion point in $filename"
    }

    # Insert the lines
    set linesToInsert [split $inputstr "\n"]
    set lines [linsert $lines end-$idx {*}$linesToInsert]

    # Write the lines back to the file
    set f [open $filename "w"]
    puts $f [join $lines "\n"]
    close $f
}

# This function modifies the FSBL main c/h files with the
# code changes needed for USB to enter link state without Linux
proc modify_fsbl_for_usb {} {
    global fsblmainh
    global fsblmainc

    # If this design has USB then modify the FSBL files
    # So that USB enters linked state for IBERT GTR
    if {[design_has_usb] == 0} {
        return
    }
    
    set searchstr "#define XFSBL_IMAGE_SEARCH_OFFSET*"
    set inputstr "
/**
 * EyeScan
 */
#undef USB3_0_XHCI_GCTL_OFFSET
#define USB3_0_XHCI_GCTL_OFFSET   0XFE20C110
#define USB3_0_XHCI_GCTL_U0_LTSSM_MASK    0XFFFFDFFFU /*GCTL[13:12]=01*/
"
    insert_in_file $fsblmainh $searchstr $inputstr
    
    set searchstr "*================= In Stage 4 ============*"
    set inputstr "
\t\t\t\t//EyeScan
\t\t\t\tu32 RegValue;
\t\t\t\tRegValue = Xil_In32(USB3_0_XHCI_GCTL_OFFSET) &
\t\t\t\t\t\tUSB3_0_XHCI_GCTL_U0_LTSSM_MASK;
\t\t\t\tXil_Out32(USB3_0_XHCI_GCTL_OFFSET, RegValue);
"
    insert_in_file $fsblmainc $searchstr $inputstr
}

# Sets the workspace to the current directory
setws
# Opens the XSA file and creates a new FSBL Application
app create -name fsbl_design_1 \
           -hw $xsapath \
           -proc $fsblcore \
           -os standalone \
           -template "Zynq MP FSBL" \
           -arch 64 \
           -lang c 

app config -name fsbl_design_1 -set compiler-optimization $c_optimizations
foreach symbol $c_symbols {
    app config -name fsbl_design_1 -add define-compiler-symbols $symbol
}
modify_fsbl_for_usb
app build -name fsbl_design_1

set elfpath [pwd]
set elfpath ${elfpath}/fsbl_design_1/Debug/fsbl_design_1.elf
puts "\n\nThe generated FSBL elf is available here:"
puts $elfpath
