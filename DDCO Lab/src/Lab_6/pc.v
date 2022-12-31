// Write code for modules you need here

module full_adder(input wire a, b, cin, output wire sum, cout);
wire w0,w1,w2,w3;
xor2 xorUnit0(a,b,w0);
xor2 xorUnit1(w0,cin,sum);
and2 andUnit0(a,b,w1);
and2 andUnit1(b,cin,w2);
and2 andUnit2(cin,a,w3);
or3 orUnit0(w1,w2,w3,cout);
endmodule

module adder_subtractor(input wire a,b,id,cin,output wire cout,output wire sd);
wire w;
xor2 xorUnit(id,b,w);
full_adder fulladderUnit(a,w,cin,sd,cout);
endmodule



module pcSlice1(input wire os,inc,sub,cin,load,clk,reset,output wire cout,po);

wire w1,w2;

    or2 orUnit(os,inc,w1);
    adder_subtractor adderSubtractorUnit(po,w1,sub,cin,cout,w2);
    dfrl dfrlUnit(clk,reset,load,w2,po);

endmodule

module pcSlice2(input wire os,inc,sub,cin,load,clk,reset,output wire cout,p1);

wire w1,w2,w3;


invert invUnit(inc,w2);
and2 andUnit(os,w2,w1);

adder_subtractor addsubUnit(p1,w1,sub,cin,cout,w3);
dfrl dfrlUnit(clk,reset,load,w3,p1);

endmodule


module pc (input wire clk, reset, inc, add, sub, input wire [15:0] offset, output wire [15:0] pc);

// Declare wires here
wire Wire;
wire w[0:15];
// Instantiate modules here
or3 orUnit(inc,add,sub,Wire);
pcSlice1 pcSliceUnit0(offset[0],inc,sub,sub,Wire,clk,reset,w[0],pc[0]);
pcSlice2 pcSliceUnit1(offset[1],inc,sub,w[0],Wire,clk,reset,w[1],pc[1]);
pcSlice2 pcSliceUnit2(offset[2],inc,sub,w[1],Wire,clk,reset,w[2],pc[2]);
pcSlice2 pcSliceUnit3(offset[3],inc,sub,w[2],Wire,clk,reset,w[3],pc[3]);
pcSlice2 pcSliceUnit4(offset[4],inc,sub,w[3],Wire,clk,reset,w[4],pc[4]);
pcSlice2 pcSliceUnit5(offset[5],inc,sub,w[4],Wire,clk,reset,w[5],pc[5]);
pcSlice2 pcSliceUnit6(offset[6],inc,sub,w[5],Wire,clk,reset,w[6],pc[6]);
pcSlice2 pcSliceUnit7(offset[7],inc,sub,w[6],Wire,clk,reset,w[7],pc[7]);
pcSlice2 pcSliceUnit8(offset[8],inc,sub,w[7],Wire,clk,reset,w[8],pc[8]);
pcSlice2 pcSliceUnit9(offset[9],inc,sub,w[8],Wire,clk,reset,w[9],pc[9]);
pcSlice2 pcSliceUnit10(offset[10],inc,sub,w[9],Wire,clk,reset,w[10],pc[10]);
pcSlice2 pcSliceUnit11(offset[11],inc,sub,w[10],Wire,clk,reset,w[11],pc[11]);
pcSlice2 pcSliceUnit12(offset[12],inc,sub,w[11],Wire,clk,reset,w[12],pc[12]);
pcSlice2 pcSliceUnit13(offset[13],inc,sub,w[12],Wire,clk,reset,w[13],pc[13]);
pcSlice2 pcSliceUnit14(offset[14],inc,sub,w[13],Wire,clk,reset,w[14],pc[14]);
pcSlice2 pcSliceUnit15(offset[15],inc,sub,w[14],Wire,clk,reset,w[15],pc[15]);

endmodule


