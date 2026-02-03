`timescale 1ns/1ps

module mac_unit #(
    parameter WIDTH = 16  // Q8.8 format
)(
    input  logic              clk,
    input  logic              rst_n,
    input  logic              en,       // Enable processing
    input  logic              clr,      // Clear the accumulator
    input  logic signed [WIDTH-1:0] a_in,
    input  logic signed [WIDTH-1:0] b_in,
    output logic signed [(WIDTH*2)-1:0] out  // Double width to prevent overflow
);

    // Pipeline Registers
    logic signed [(WIDTH*2)-1:0] mult_reg;
    logic signed [(WIDTH*2)-1:0] acc_reg;

    // --- STAGE 1: Multiplication ---
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            mult_reg <= '0;
        end else if (en) begin
            mult_reg <= a_in * b_in;
        end
    end

    // --- STAGE 2: Accumulation ---
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            acc_reg <= '0;
        end else if (clr) begin
            acc_reg <= '0;
        end else if (en) begin
            // We add the previous multiplication result to the accumulator
            acc_reg <= acc_reg + mult_reg;
        end
    end

    // Continuous assignment to output
    assign out = acc_reg;

endmodule