`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02.10.2021 19:45:25
// Design Name: 
// Module Name: lab3_2
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module lab3_2(
    input [3:0] sw,
    input [1:0] digits,
    output reg [3:0] an,
    output reg [6:0] c
    );
    
    reg [6:0] ss_arr[15:0];
    reg [1:0] i;
    
    initial begin
        ss_arr[0] = 7'h40; //0
        ss_arr[1] = 7'h79; //1
        ss_arr[2] = 7'h24; //2
        ss_arr[3] = 7'h30; //3
        ss_arr[4] = 7'h19; //4
        ss_arr[5] = 7'h12; //5
        ss_arr[6] = 7'h02; //6
        ss_arr[7] = 7'h78; //7
        ss_arr[8] = 7'h00; //8
        ss_arr[9] = 7'h10; //9
        ss_arr[10] = 7'h08; //A
        ss_arr[11] = 7'h03; //B
        ss_arr[12] = 7'h46; //C
        ss_arr[13] = 7'h21; //D
        ss_arr[14] = 7'h06; //E
        ss_arr[15] = 7'h0e; //F 
    end
    
    always @* begin 
        c = ss_arr[sw];
        an = ~(1'h1 << digits);
    end
endmodule
