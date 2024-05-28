module cpu_coppy(
input clk, reset,
// для памяти команд
input [31:0] command,
output 		 rden,
output [7:0] address,

// для память данных
input	 	  [31:0] read_data_dm,
output reg       wren_dm, rden_dm,
output reg [7:0] wraddress_dm, rdaddress_dm,
output reg [31:0] write_data_dm

// для Signal Tab
//output reg [7:0] alu_word, alu_result,
//output reg 		  rf_write,
//output 			  need_jump
);
// бит чтения из памяти программы
assign rden = 1'b1;
// биты для перехода
wire need_jump;
reg flag_jamp;

reg [7:0] ip;

// номер команды для УУ
reg [7:0] num_command_I, num_command_D, num_command_E, num_command_M, num_command_W;
 
// адреса значения для регистрового файла 
reg			rf_rden_1, rf_rden_2, rf_write; 
reg  [3:0] 	rf_write_dest, rf_read_addr_1, rf_read_addr_2;
reg  [31:0] 	rf_write_data;	
wire [31:0] 	rf_read_data_1, rf_read_data_2;
reg  [7:0]	rf_read_addr_1_D, rf_read_addr_2_D;
	
// адрес перхода
reg  [7:0]  jump_addr; 

// для ALU
reg  [31:0] rf_read_data_1_E, rf_read_data_1_M, rf_read_data_1_W, rf_read_data_2_E;
reg  [31:0] reg_rezult_M, reg_rezult_W;
reg  [31:0] alu_word, alu_result;
wire [31:0] rf_data_1, rf_data_2, retunt_data_W_1, retunt_data_W_2, retunt_data_M_1, retunt_data_M_2;
reg 	[2:0]	alu_comand;

reg [31:0] reg_write_data_dm_M, reg_write_data_dm_W;	 	

// регистры и шины для конвеера 
reg [31:0] r_opcode_D, r_opcode_E, r_opcode_M, r_opcode_W;

//назначение основных команд
// parameter CMD_ADD = 8'h0F; // Сложение Rr=R2+R1+8bit, Rr=R2+R1, Rr=R2+8bit.  Перессылка в регистр Rr=R2;
// parameter LOAD = 8'h4F;		// Загрузка из памяти данных в регистр. Load Rr <= Mem(Ra + смещение)
// parameter STORE = 8'h47;	// Сохранение в память данных из регистра. Store Mem(Ra + смещение) <= Rr
// parameter BEQ = 8'h87;		// Условный переход. if(a==b) переход.  // Вданный момент безусловный


initial begin
	ip = 0;
	
	rf_rden_1 = 1'b0;
	rf_read_addr_1 = 4'b0;
	rf_rden_2 = 1'b0;
	rf_read_addr_2 = 4'b0;
	
	jump_addr = 8'b0;
	flag_jamp = 1'b0;
	
	rden_dm = 1'b0;
	rdaddress_dm = 4'b0;
	
	rden_dm = 1'b0;
	rdaddress_dm = 4'b0;
	alu_word = 32'b0;
	
	reg_write_data_dm_M = 32'b0;
	
	wren_dm = 1'b0;
	wraddress_dm = 1'b0;
	write_data_dm = 32'b0;
	rf_write = 1'b0;
	rf_write_dest = 4'b0;
	rf_write_data = 32'b0;

	alu_result = 32'b0;
	
	r_opcode_D <= 32'b0;
	r_opcode_E <= 32'b0;
	r_opcode_M <= 32'b0;
	r_opcode_W <= 32'b0;
		
	rf_read_data_1_E <= 32'b0;
	rf_read_data_1_M <= 32'b0;
	rf_read_data_1_W <= 32'b0;
	rf_read_data_2_E <= 32'b0;
		
	reg_rezult_M <= 32'b0;
	reg_rezult_W <= 32'b0;
	
	reg_write_data_dm_W <= 32'b0;
end

// Управляющее устройство для конвеера
always @*
begin	

// -------------I BEGINE-------------

	num_command_I = command[31:24];
	if ( num_command_I[2] == 1'b1 ) begin
		rf_rden_1 = 1'b1;
		if( num_command_I[6] == 1'b1 )
			rf_read_addr_1 = command[23:20];
		else
			rf_read_addr_1 = command[19:16];
	end else begin
		rf_rden_1 = 1'b0;
		rf_read_addr_1 = 8'b0;
	end
	
	rf_rden_2 = 1'b1;
	rf_read_addr_2 = command[15:12];
	

// -------------D BEGINE-------------

	
	num_command_D = r_opcode_D[31:24];
	if( num_command_D[7] == 1'b1 & num_command_D[0] == 1'b1) begin
		jump_addr = r_opcode_D[7:0];
		flag_jamp = 1'b1;
	end else begin
		jump_addr = 8'b0;
		flag_jamp = 1'b0;
	end

// -------------E BEGINE-------------

	num_command_E = r_opcode_E[31:24];
		alu_word = {20'b0, r_opcode_E[11:0]};
		
	if(num_command_E[7:6] == 2'b00 | num_command_E[7:6] == 2'b01) begin
		alu_comand = num_command_E[5:3];
	end else begin
		alu_comand = 3'b0;	
	end
	
	
	if( num_command_E[6] == 1'b1 & num_command_E[3] == 1'b1) begin
		rden_dm = 1'b1;
		rdaddress_dm = alu_result;
	end else begin
		rden_dm = 1'b0;
		rdaddress_dm = 8'b0;
	end
	
// -------------M BEGINE-------------

	num_command_M = r_opcode_M[31:24];
	if( num_command_M[3] == 1'b1)
		if( num_command_M[6] == 1'b0 )
			reg_write_data_dm_M = reg_rezult_M;
		else
			reg_write_data_dm_M = read_data_dm;
	else
		reg_write_data_dm_M = 32'b0;
		
// -------------W BEGINE-------------

	num_command_W = r_opcode_W[31:24];
	if( num_command_W[3] == 1'b1) begin
		wren_dm = 1'b0;
		wraddress_dm = 4'b0;
		write_data_dm = 32'b0;
		rf_write = 1'b1;
		rf_write_dest = r_opcode_W[23:20];
		rf_write_data = reg_write_data_dm_W;
	end else begin
		rf_write = 1'b0;
		rf_write_dest = 4'b0;
		rf_write_data = 32'b0;
		if( num_command_W[6] == 1'b1) begin
			wren_dm = 1'b1;
			wraddress_dm = reg_rezult_W;
			write_data_dm = rf_read_data_1_W;
		end else begin
			wren_dm = 1'b0;
			wraddress_dm = 4'b0;
			write_data_dm = 32'b0;
		end
		
	end

// ----------------------------------
end		
		
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
assign need_jump = ( flag_jamp & (rf_data_1 == rf_data_2));

//Арифметико-Логическое Устройство
always @*
begin	
	
	case(alu_comand)
		3'b001: alu_result = rf_read_data_1_E + rf_read_data_2_E + alu_word;
		3'b010: alu_result = rf_read_data_1_E - rf_read_data_2_E;
		3'b011: alu_result = rf_read_data_1_E + 1'b1;
		3'b100: alu_result = rf_read_data_1_E | rf_read_data_2_E;
		3'b101: alu_result = rf_read_data_1_E & rf_read_data_2_E;
		3'b110: alu_result = rf_read_data_1_E ^ rf_read_data_2_E;
		3'b111: alu_result = ~rf_read_data_2_E;
		default: alu_result = 32'b0;	
	endcase

//	if ( num_command_E[7:6] == 2'b00 ) begin
//		if (num_command_E[5] == 1'b0) begin
//			if (num_command_E[4] == 1'b0) begin
//				if (num_command_E[3] == 1'b1)
//					alu_result = rf_read_data_1_E + rf_read_data_2_E + alu_word;
//			end else begin
//				if (num_command_E[3] == 1'b0)
//					alu_result = rf_read_data_1_E - rf_read_data_2_E;
//				else
//					alu_result = rf_read_data_2_E + 1'b1;
//			end
//		end else begin
//			if (num_command_E[4] == 1'b0) begin
//				if (num_command_E[3] == 1'b0)
//					alu_result = rf_read_data_1_E | rf_read_data_2_E;
//				else
//					alu_result = rf_read_data_1_E & rf_read_data_2_E;
//			end else begin
//				if (num_command_E[3] == 1'b0)
//					alu_result = rf_read_data_1_E ^ rf_read_data_2_E;
//				else
//					alu_result = ~rf_read_data_2_E ;
//			end
//		end
//	end else begin
//		if(num_command_E[6] == 1'b1) begin
//			alu_result = rf_read_data_2_E + alu_word;
//		end else alu_result = 32'b0;
//	end
	
end

assign retunt_data_W_1 = ( rf_read_addr_1_D == r_opcode_W[23:20]) ? reg_rezult_W : rf_read_data_1;
assign retunt_data_W_2 = ( rf_read_addr_2_D == r_opcode_W[23:20]) ? reg_rezult_W : rf_read_data_2;

assign retunt_data_M_1 = ( rf_read_addr_1_D == r_opcode_M[23:20]) ? reg_rezult_M : retunt_data_W_1;
assign retunt_data_M_2 = ( rf_read_addr_2_D == r_opcode_M[23:20]) ? reg_rezult_M : retunt_data_W_2;

assign rf_data_1 = ( rf_read_addr_1_D == r_opcode_E[23:20]) ? alu_result : retunt_data_M_1;
assign rf_data_2 = ( rf_read_addr_2_D == r_opcode_E[23:20]) ? alu_result : retunt_data_M_2;
// Передача регистров с результатом по конвееру
always @(posedge clk or posedge reset)
begin

	if(reset)
   begin
		r_opcode_D <= 32'b0;
		r_opcode_E <= 32'b0;
		r_opcode_M <= 32'b0;
		r_opcode_W <= 32'b0;
		
		rf_read_addr_1_D <= 4'b0;
		rf_read_addr_2_D <= 4'b0;
		
		rf_read_data_1_E <= 32'b0;
		rf_read_data_1_M <= 32'b0;
		rf_read_data_1_W <= 32'b0;
		rf_read_data_2_E <= 32'b0;
		
		reg_rezult_M <= 32'b0;
		reg_rezult_W <= 32'b0;
		
		reg_write_data_dm_W <= 32'b0;
   end else begin
		if( need_jump ) begin // очищаем конвеер при перходе
			r_opcode_D <= 32'b0;
			r_opcode_E <= 32'b0;
		end else begin
			r_opcode_D <= command;
			r_opcode_E <= r_opcode_D;
		end
		r_opcode_M <= r_opcode_E;
		r_opcode_W <= r_opcode_M;
		
		rf_read_addr_1_D <= rf_read_addr_1;
		rf_read_addr_2_D <= rf_read_addr_2;
		
//		case ( rf_read_addr_1_D ) 
//			r_opcode_E[23:20]: rf_read_data_1_E <= alu_result;
//			r_opcode_M[23:20]: rf_read_data_1_E <= reg_rezult_M;
//			r_opcode_W[23:20]: rf_read_data_1_E <= reg_rezult_W;
//			default: rf_read_data_1_E <= rf_read_data_1;
//		endcase
//		
//		case ( rf_read_addr_2_D ) 
//			r_opcode_E[23:20]: rf_read_data_2_E <= alu_result;
//			r_opcode_M[23:20]: rf_read_data_2_E <= reg_rezult_M;
//			r_opcode_W[23:20]: rf_read_data_2_E <= reg_rezult_W;
//			default: rf_read_data_2_E <= rf_read_data_2;
//		endcase
		
//		need_jump = ( flag_jamp & (rf_read_data_1_E == rf_read_data_2_E));
		rf_read_data_1_E <= rf_data_1;
		rf_read_data_1_M <= rf_read_data_1_E;
		rf_read_data_1_W <= rf_read_data_1_M;
		rf_read_data_2_E <= rf_data_2;
		
		reg_rezult_M <= alu_result;
		reg_rezult_W <= reg_rezult_M;
		
		reg_write_data_dm_W <= reg_write_data_dm_M;
				
	end
	
end

assign address = ip;
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

endmodule
