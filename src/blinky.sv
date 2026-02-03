
// Hardware Logic: A simple 4-bit counter that toggles an LED
module blinky (
    input  logic clk,
    input  logic rst,
    output logic led
);

    logic [3:0] count;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            count <= 4'b0;
            led   <= 1'b0;
        end else begin
            count <= count + 1;
            // Toggle LED when the counter reaches 15 (hex 'f')
            if (count == 4'hf) begin
                led <= ~led;
            end
        end
    end

endmodule