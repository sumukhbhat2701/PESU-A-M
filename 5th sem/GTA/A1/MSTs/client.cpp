#include "interface.h"

int main(int argc, char *argv[])
{
    int n,src,dst,w,len,first, parity;
    char line[MAX]; char number[MAX];

    vector<string> files = {"testcase1.txt","testcase2.txt","testcase3.txt","testcase4.txt","testcase5.txt", "testcase6.txt"};
    // change it according to the file name
    int default_ = 0;
    int file_idx;
    if(argc > 1)
        file_idx = argv[1][0] - '0';
    else
        file_idx = default_;
    FILE* fp = fopen(files[file_idx].c_str(),"r");

    if(fp == NULL)
    {
        if(DEBUG)
            printf("Error opening file\n");
        exit(0);
    }
    fscanf(fp,"%d",&n);
    Graph G(n);
    fgets(line,MAX,fp);
    for(int i=0;(fgets(line,MAX,fp) != NULL);i++)
    {
        first = 1; parity = 1; len = 0;
        for(int j=0;line[j]!='\0';j++)
        {
            if(line[j] == ' ' && first)
            {
                number[len] = '\0';
                src = atoi(number);
                len = 0;
                first = 0;
            }
            else if(line[j] == ' ' && !first)
            {
                if(parity)
                {
                    number[len] = '\0';
                    dst = atoi(number);       
                }
                else
                {
                    number[len] = '\0';
                    w = atoi(number);
                    G.connect(src,dst,w);
                }
                len = 0;
                parity = !parity; 
                
            }
            else
            {
                number[len] = line[j];
                len++;
            } 
                
        }
        number[len] = '\0';
        w = atoi(number);
        G.connect(src,dst,w);
    }
        
    fclose(fp);

    if(DEBUG) G.printGraph();

    
    vector<vector<int>> soln1;
    auto startB = high_resolution_clock::now();
    cout<<"Weight of obtained MST = "<<G.BaruvkasMST(soln1)<<endl;
    auto endB = high_resolution_clock::now();
    cout<<"Baruvkas Algorithm:"<<endl;
    cout<<"Undirected edges included in the obtained MST:"<<endl;
    auto durationB = duration_cast<microseconds>(endB - startB);
    G.printMST(soln1);

    vector<vector<int>> soln2;
    auto startP = high_resolution_clock::now();
    G.PrimsMST(soln2);
    auto endP = high_resolution_clock::now();


    vector<vector<int>> soln3;
    auto startK = high_resolution_clock::now();
    G.KrushkalsMST(soln3);
    auto endK = high_resolution_clock::now();

    cout<<"\nReverse Delete Algorithm:"<<endl;
    vector<vector<int>> soln4;
    auto startR = high_resolution_clock::now();
    G.ReverseDeleteMST(soln4);
    auto endR = high_resolution_clock::now();
    cout<<"Undirected edges included in the obtained MST:"<<endl;
    G.printMST(soln4);

    cout<<"\nCOMPARISION:\n";
    cout<<"PRIMS (in ms) = "<<duration_cast<microseconds>(endP - startP).count()<<endl;
    cout<<"KRUSHKALS (in ms) = "<<duration_cast<microseconds>(endK - startK).count()<<endl;
    cout<<"BARUVKAS (in ms) = "<<duration_cast<microseconds>(endB - startB).count()<<endl;
    cout<<"REVERSE DELETE (in ms) = "<<duration_cast<microseconds>(endR - startR).count()<<endl;

    return 0;
}