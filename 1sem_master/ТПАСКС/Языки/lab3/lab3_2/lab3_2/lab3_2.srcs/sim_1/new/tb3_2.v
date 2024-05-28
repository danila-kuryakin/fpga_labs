`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 21.11.2021 07:53:33
// Design Name: 
// Module Name: tb3_2
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


module tb3_2();

localparam period = 10; 
integer i;
reg [3:0] sw;
reg [1:0] digits;
wire [3:0] an;
wire[6:0] c;

lab3_2 Lab( sw, digits, an, c);

initial begin
    for(i = 0; i < 16; i = i + 1) begin
        sw = i;
        digits = 2'h0;
        #period;
        digits = 2'h1;
        #period;
        digits = 2'h2;
        #period;
        digits = 2'h3;
        #period;
    end
end
endmodule
