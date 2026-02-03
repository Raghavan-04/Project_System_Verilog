`timescale 1ns/1ps

module top_accelerator #(
    parameter WIDTH = 16,
    parameter DEPTH = 16
)(
    input  logic              clk,
    input  logic              rst_n,

    // Input side (From Mac/Testbench)
    input  logic              wr_en,
    input  logic [WIDTH-1:0]  din_a,
    input  logic [WIDTH-1:0]  din_b,
    output logic              fifo_full,

    // Control
    input  logic              acc_clr, // Clear the MAC accumulator
    
    // Output side
    output logic signed [(WIDTH*2)-1:0] acc_out,
    output logic              valid_out
);

    // Internal Wires
    logic [WIDTH-1:0] fifo_a_out, fifo_b_out;
    logic fifo_empty;
    logic mac_en;

    // The MAC should run as long as there is data in the FIFO
    assign mac_en = !fifo_empty;

    // 1. FIFO for Operand A
    sync_fifo #(.WIDTH(WIDTH), .DEPTH(DEPTH)) fifo_a (
        .clk(clk), .rst_n(rst_n),
        .wr_en(wr_en), .din(din_a), .full(fifo_full), // Simplified: assume both FIFOs fill together
        .rd_en(mac_en), .dout(fifo_a_out), .empty(fifo_empty)
    );

    // 2. FIFO for Operand B
    sync_fifo #(.WIDTH(WIDTH), .DEPTH(DEPTH)) fifo_b (
        .clk(clk), .rst_n(rst_n),
        .wr_en(wr_en), .din(din_b), .full(), 
        .rd_en(mac_en), .dout(fifo_b_out), .empty()
    );

    // 3. The MAC Unit
    mac_unit #(.WIDTH(WIDTH)) processor (
        .clk(clk), .rst_n(rst_n),
        .en(mac_en), .clr(acc_clr),
        .a_in(fifo_a_out), .b_in(fifo_b_out),
        .out(acc_out)
    );

    // Pipeline delay for the valid signal (MAC has 2-cycle latency)
    logic [1:0] valid_pipe;
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) valid_pipe <= 2'b00;
        else        valid_pipe <= {valid_pipe[0], mac_en};
    end
    assign valid_out = valid_pipe[1];

endmodule