`timescale 1ns/1ps

module sync_fifo #(
    parameter WIDTH = 16,
    parameter DEPTH = 8,              // Must be a power of 2
    localparam ADDR_W = $clog2(DEPTH) // Address width
)(
    input  logic              clk,
    input  logic              rst_n,

    // Write Interface
    input  logic              wr_en,
    input  logic [WIDTH-1:0]  din,
    output logic              full,

    // Read Interface
    input  logic              rd_en,
    output logic [WIDTH-1:0]  dout,
    output logic              empty
);

    // The Memory Array
    logic [WIDTH-1:0] mem [DEPTH-1:0];

    // Pointers
    logic [ADDR_W:0] wr_ptr; // One extra bit to distinguish full vs empty
    logic [ADDR_W:0] rd_ptr;

    // --- Status Logic ---
    // If pointers are identical, it's empty. 
    // If only the MSB is different, it's full.
    assign empty = (wr_ptr == rd_ptr);
    assign full  = (wr_ptr[ADDR_W] != rd_ptr[ADDR_W]) && 
                   (wr_ptr[ADDR_W-1:0] == rd_ptr[ADDR_W-1:0]);

    // --- Write Logic ---
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= '0;
        end else if (wr_en && !full) begin
            mem[wr_ptr[ADDR_W-1:0]] <= din;
            wr_ptr <= wr_ptr + 1;
        end
    end

    // --- Read Logic ---
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rd_ptr <= '0;
        end else if (rd_en && !empty) begin
            dout <= mem[rd_ptr[ADDR_W-1:0]];
            rd_ptr <= rd_ptr + 1;
        end
    end

endmodule