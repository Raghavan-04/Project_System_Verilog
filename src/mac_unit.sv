`timescale 1ns/1ps

module mac_unit #(
    parameter WIDTH = 16
)(
    input  logic              clk,
    input  logic              rst_n,
    input  logic              en,       // Enable: High when FIFO is not empty
    input  logic              clr,      // Clear: To reset the running total
    input  logic signed [WIDTH-1:0] a_in,
    input  logic signed [WIDTH-1:0] b_in,
    output logic signed [(WIDTH*2)-1:0] out 
);

    // Pipeline Registers
    logic signed [(WIDTH*2)-1:0] mult_reg;
    logic signed [(WIDTH*2)-1:0] acc_reg;
    logic signed [(WIDTH*2)-1:0] next_acc;

    // --- OVERFLOW DETECTION & SATURATION CONSTANTS ---
    // For a 32-bit signed accumulator
    localparam signed [31:0] MAX_POS = 32'h7FFFFFFF;
    localparam signed [31:0] MAX_NEG = 32'h80000000;

    // --- ARITHMETIC LOGIC ---
    always_comb begin
        // Preliminary addition result
        next_acc = acc_reg + mult_reg;

        // Saturation Logic:
        // If (Pos + Pos = Neg) -> Positive Overflow
        if (acc_reg > 0 && mult_reg > 0 && next_acc < 0) begin
            next_acc = MAX_POS;
        end 
        // If (Neg + Neg = Pos) -> Negative Overflow
        else if (acc_reg < 0 && mult_reg < 0 && next_acc > 0) begin
            next_acc = MAX_NEG;
        end
    end

    // --- STAGE 1: Multiplication ---
    // Latency: 1 Cycle
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mult_reg <= '0;
        end else if (en) begin
            mult_reg <= a_in * b_in;
        end
    end

    // --- STAGE 2: Accumulation with Saturation ---
    // Latency: 1 Cycle (Total 2)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            acc_reg <= '0;
        end else if (clr) begin
            acc_reg <= '0;
        end else if (en) begin
            acc_reg <= next_acc; // Store the saturated result
        end
    end

    // Direct output assignment
    assign out = acc_reg;

endmodule