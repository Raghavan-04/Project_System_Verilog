`timescale 1ns/1ps

module pwm_controller #(
    parameter WIDTH = 8
)(
    input  logic             clk,
    input  logic             rst_n,
    input  logic [WIDTH-1:0] duty_cycle,
    output logic             pwm_out
);

    logic [WIDTH-1:0] counter;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            counter <= 0;
        end else begin
            counter <= counter + 1;
        end
    end

    always_comb begin
        pwm_out = (counter < duty_cycle);
    end

endmodule