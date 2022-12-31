Assumptions and Instruction:
1) Vertices are named as 0 to n-1 where n is the total number of vertices

2) Input file format is:

- For weighted graph:
<n>
<src1> <dst1> <weight1> <dst2> <weight2> ...
<src1> <dst1> <weight1> <dst2> <weight2> ...
.
.

- For non-weighted graph:
<n>
<src1> <dst1> <dst2> ...
<src1> <dst1> <dst2> ...
.
.

3) Input file format for maximum bipartite matching includes value of m on the first line followed by n and then same as above
<m>
<n>
.
.

4) All graphs are assumed as directed. This means that to represent a undirect edge from u to v, we to insert twice -> (u,v) and (v,u).

5) Graphs are represented as adjacency lists

6) All code is developed and tested on Ubuntu and using g++ compiler as it is assumed to have bits/stdc++.h

7) Huge graphs are generated randomly for testcases using python script:

python3 randomGraph.py

8) For Maximum Bipartite matching, to create a random bipartite graph is created using networkx module:

pip3 install networkx

9) Testcases file are named from testcase1.txt to testcase6.txt, except for fleurys where it is from testcase1.txt to testcase9.txt and corresponding outputs are also named from output1.txt to output6.txt (or 1 to 9 for fleurys algorithm).

10) To compile, go to one of the folder and type:

g++ impl.cpp client.cpp

11) To run the executable with testcase1.txt,
 
./a.out 

12) To run the executable with any testcase file, go to client.cpp and edit the initialization value of default_ variable from 0 to 8 incase of fleurys algo and 0 to 5 incase of others and run:
 
./a.out

13) To run the executable with testcase<n+1>.txt where n is from 0 to 8 incase of fleurys algo and 0 to 5 incase of others and run:

./a.out <n>

14) To save the output to a file using output redirection(>):

./a.out <n> > output<n+1>.txt

where n = 0 to 8 for fleury's algo
and n = 0 to 4 for all others.

Eg: 
./a.out 0 > output1.txt

15) Input from a file is not taken with an input redirection, but has to be specified in client.cpp file


