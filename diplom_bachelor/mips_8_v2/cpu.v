module cpu(
input clk, reset,
// для памяти команд
input [31:0] command,
output 		 rden,
output [7:0] address,

// для память данных
input	 	  [7:0] read_data_dm,
output reg       wren_dm, rden_dm,
output reg [7:0] wraddress_dm, rdaddress_dm,
output reg [7:0] write_data_dm,

// для Signal Tab
output reg [7:0] alu_word, alu_result,
output reg 		  rf_write,
output 			  need_jump
);
// бит чтения из памяти программы
assign rden = 1'b1;
// биты для перехода
wire jump;  //need_jump; отправил в заголовок

reg [7:0] ip;

// номер команды для УУ
reg [7:0] num_command_D, num_command_E, num_command_M, num_command_W, num_command_2W;
 
// адреса значения для регистрового файла 
reg			rf_rden_1, rf_rden_2;	//rf_write; отправил в заголовок
reg [3:0] 	rf_write_dest, rf_read_addr_1, rf_read_addr_2;
reg [7:0] 	rf_write_data;	
wire [7:0] 	rf_read_data_1, rf_read_data_2;
	
// адрес перхода
reg [7:0] jump_addr; 

// для ALU
reg [7:0] rf_read_data_1_D_E, rf_read_data_1_E_M, rf_read_data_1_M_W, rf_read_data_2_D_E;
reg [7:0] reg_rezult_E_M, reg_rezult_M_W;
//reg [7:0] alu_word, alu_result;

reg [7:0] reg_write_data_dm_M, reg_write_data_dm_M_W;	 	

// регистры и шины для конвеера
wire [31:0] opcode_D, opcode_E, opcode_M, opcode_W; 
reg [31:0] reg_I_D, reg_D_E, reg_E_M, reg_M_W;

//назначение основных команд
parameter CMD_ADD = 8'h01; // Сложение Rr=R2+R1+8bit, Rr=R2+R1, Rr=R2+8bit.  Перессылка в регистр Rr=R2;
parameter LOAD = 8'h02;		// Загрузка из памяти данных в регистр. Load Rr <= Mem(Ra + смещение)
parameter STORE = 8'h03;	// Сохранение в память данных из регистра. Store Mem(Ra + смещение) <= Rr
parameter BEQ = 8'h08;		// Условный переход. if(a==b) переход.  // Вданный момент безусловный


// Управляющее устройство для конвеера
always @*
begin	
	num_command_D = opcode_D[31:24];
	case(num_command_D)
		CMD_ADD: begin
			rf_rden_1 = 1'b1;
			rf_rden_2 = 1'b1;
			rf_read_addr_1 = opcode_D[19:16];
			rf_read_addr_2 = opcode_D[15:12];
			jump_addr = 1'b0;
		end
		LOAD: begin
			rf_rden_1 = 1'b0;
			rf_rden_2 = 1'b1;
			rf_read_addr_1 = 4'b0;
			rf_read_addr_2 = opcode_D[15:12];
			jump_addr = 1'b0;
		end 
		STORE: begin
			rf_rden_1 = 1'b1;
			rf_rden_2 = 1'b1;
			rf_read_addr_1 = opcode_D[23:20];
			rf_read_addr_2 = opcode_D[15:12];
			jump_addr = 1'b0;
		end
		BEQ: begin
			rf_rden_1 = 1'b1;
			rf_rden_2 = 1'b1;
			rf_read_addr_1 = opcode_D[19:16];
			rf_read_addr_2 = opcode_D[15:12];
			jump_addr = opcode_D[7:0];
		end
		default: begin
			rf_rden_1 = 1'b0;
			rf_rden_2 = 1'b0;
			rf_read_addr_1 = 4'b0;
			rf_read_addr_2 = 4'b0;
			jump_addr = 1'b0;
		end
	endcase
	
	num_command_E = opcode_E[31:24];
	case(num_command_E)
		CMD_ADD, STORE: begin
			rden_dm = 1'b0;
			alu_word = opcode_E[7:0];
			rdaddress_dm = 4'b0;
		end
		LOAD: begin	
			alu_word = opcode_E[7:0];
			rden_dm = 1'b1;
			rdaddress_dm = alu_result;
		end
		default: begin
			rden_dm = 1'b0;
			alu_word = 8'b0;
			rdaddress_dm = 4'b0;
		end
	endcase
	
	num_command_M = opcode_M[31:24];
	case(num_command_M)
		CMD_ADD: begin
			reg_write_data_dm_M = reg_rezult_E_M;
			
		end
		LOAD: begin		
			reg_write_data_dm_M = read_data_dm;
		end
		default: begin
			reg_write_data_dm_M = 8'b0;
		end
	endcase
	
	num_command_W = opcode_W[31:24];
	case(num_command_W)
		CMD_ADD, LOAD: begin
			wren_dm = 1'b0;
			wraddress_dm = 1'b0;
			write_data_dm = 1'b0;
			rf_write = 1'b1;
			rf_write_dest = opcode_W[23:20];
			rf_write_data = reg_write_data_dm_M_W;
		end		
		STORE: begin
			wren_dm = 1'b1;
			wraddress_dm = reg_rezult_M_W;
			write_data_dm = rf_read_data_1_M_W;
			rf_write = 1'b0;
			rf_write_dest = 4'b0;
			rf_write_data = 8'b0;
		end
		default: begin
			wren_dm = 1'b0;
			wraddress_dm = 1'b0;
			write_data_dm = 1'b0;
			rf_write = 1'b0;
			rf_write_dest = 4'b0;
			rf_write_data = 8'b0;
		end
	endcase
	
end

// регистровый файл
//reg_file rf (.clk(clk),
//		.reg_write_en(rf_write),
//		.reg_write_dest(rf_write_dest),
//		.reg_write_data(rf_write_data),
//		.rden_1(rf_rden_1),
//		.reg_read_addr_1(rf_read_addr_1),
//		.reg_read_data_1(rf_read_data_1),
//		.rden_2(rf_rden_2),
//		.reg_read_addr_2(rf_read_addr_2),
//		.reg_read_data_2(rf_read_data_2));
		
		
// Регистровый файл на RAM
reg_file_ram rfr(
	.clk(clk), 
	.aclr(reset),
	.wren(rf_write),
	.wraddress(rf_write_dest),
	.data(rf_write_data),
	.rden_1(rf_rden_1), 
	.rdaddress_1(rf_read_addr_1), 
	.q_1(rf_read_data_1), 
	.rden_2(rf_rden_2), 
	.rdaddress_2(rf_read_addr_2), 
	.q_2(rf_read_data_2));
		
		
// проверка перехода
assign jump = (rf_read_data_1 == rf_read_data_2) ? 1'b1 : 1'b0;
assign need_jump = ( (opcode_D[31:24] == BEQ) & jump) ? 1'b1 : 1'b0;

//Арифметико-Логическое Устройство
always @*
begin
	case(num_command_E)
		CMD_ADD: begin
			alu_result = rf_read_data_1_D_E + rf_read_data_2_D_E + alu_word;
		end
		LOAD, STORE: begin
			alu_result = rf_read_data_2_D_E + alu_word;
		end
		default: begin
			alu_result = 8'b0;
		end
	endcase
end

//шины конвеера
assign opcode_D = reg_I_D;
assign opcode_E = reg_D_E;
assign opcode_M = reg_E_M;
assign opcode_W = reg_M_W;

// Передача регистров с результатом по конвееру
always @(posedge clk or posedge reset)
begin

	if(reset)
   begin
		reg_D_E <= 1'b0;
		reg_E_M <= 1'b0;
		reg_M_W <= 1'b0;
		
		rf_read_data_1_D_E <= 1'b0;
		rf_read_data_2_D_E <= 1'b0;
		
		reg_rezult_E_M <= 1'b0;
		reg_rezult_M_W <= 1'b0;
   end else begin
		if( need_jump ) // очищаем конвеер при перходе
			reg_D_E <= 8'b0;
		else
			reg_D_E <= opcode_D;
		reg_E_M <= opcode_E;
		reg_M_W <= opcode_M;
		
		rf_read_data_1_D_E <= rf_read_data_1;
		rf_read_data_1_E_M <= rf_read_data_1_D_E;
		rf_read_data_1_M_W <= rf_read_data_1_E_M;
		
		rf_read_data_2_D_E <= rf_read_data_2;
		
		reg_rezult_E_M <= alu_result;
		reg_rezult_M_W <= reg_rezult_E_M;
		
		reg_write_data_dm_M_W <= reg_write_data_dm_M;
				
	end
	
end

// Определение следующего адреса
always @(posedge clk or posedge reset)
begin
    if(reset)
    begin
        ip <= 0;
    end
    else
    begin
		if( need_jump )
		begin
			ip <= jump_addr;
		end
		else
		begin
			ip <= ip + 1'b1;
		end

    end
end

assign address = ip;

//последовательно принимаем код инструкции от RAM
always @(posedge clk or posedge reset)
begin
	if(reset)
		reg_I_D <= 0;
	else
	begin
		reg_I_D <= command;
	end
end

endmodule
