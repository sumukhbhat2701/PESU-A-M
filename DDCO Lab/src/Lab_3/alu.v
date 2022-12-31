
// Write code for modules you need here
//Module full adder.
module fulladders(input wire a, b, cin, output wire sum, cout);
wire [4:0] t;
    xor2 x0(a, b, t[0]);
    xor2 x1(t[0], cin, sum);

    and2 a0(a, b, t[1]);
    and2 a1(a, cin, t[2]);
    and2 a2(b, cin, t[3]);

    or2 o0(t[1], t[2], t[4]);
    or2 o1(t[3], t[4], cout);
endmodule

module aluSlice(input wire op0,op1,input wire i0,i1,cin,output wire cout,o);

wire xorWire,andWire,orWire,faWire,muxWire;

xor2 xorGate(i1,op0,xorWire);
fulladders fulladderGate(i0,xorWire,cin,faWire,cout);
and2 andGate(i0,i1,andWire);
or2 orGate(i0,i1,orWire);
mux2 muxGate1(andWire,orWire,op0,muxWire);
mux2 muxGate2(faWire,muxWire,op1,o);

endmodule



module alu (input wire [1:0] op, input wire [15:0] i0, i1,
    output wire [15:0] o, output wire cout);

// Declare wires here
wire [14:0] w;

// Instantiate modules here
aluSlice circuit0(op[0],op[1],i0[0],i1[0],op[0],w[0],o[0]);
aluSlice circuit1(op[0],op[1],i0[1],i1[1],w[0],w[1],o[1]);
aluSlice circuit2(op[0],op[1],i0[2],i1[2],w[1],w[2],o[2]);
aluSlice circuit3(op[0],op[1],i0[3],i1[3],w[2],w[3],o[3]);
aluSlice circuit4(op[0],op[1],i0[4],i1[4],w[3],w[4],o[4]);
aluSlice circuit5(op[0],op[1],i0[5],i1[5],w[4],w[5],o[5]);
aluSlice circuit6(op[0],op[1],i0[6],i1[6],w[5],w[6],o[6]);
aluSlice circuit7(op[0],op[1],i0[7],i1[7],w[6],w[7],o[7]);
aluSlice circuit8(op[0],op[1],i0[8],i1[8],w[7],w[8],o[8]);
aluSlice circuit9(op[0],op[1],i0[9],i1[9],w[8],w[9],o[9]);
aluSlice circuit10(op[0],op[1],i0[10],i1[10],w[9],w[10],o[10]);
aluSlice circuit11(op[0],op[1],i0[11],i1[11],w[10],w[11],o[11]);
aluSlice circuit12(op[0],op[1],i0[12],i1[12],w[11],w[12],o[12]);
aluSlice circuit13(op[0],op[1],i0[13],i1[13],w[12],w[13],o[13]);
aluSlice circuit14(op[0],op[1],i0[14],i1[14],w[13],w[14],o[14]);
aluSlice circuit15(op[0],op[1],i0[15],i1[15],w[14],cout,o[15]);

endmodule
