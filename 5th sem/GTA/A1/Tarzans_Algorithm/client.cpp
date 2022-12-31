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
    else
    {
        fscanf(fp,"%d",&n);
        fgets(line,MAX,fp);      
    }
    Graph G(n);
    for(int i=0;(fgets(line,MAX,fp) != NULL);i++)
    {
        first = 1; len = 0;
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
                number[len] = '\0';
                dst = atoi(number);
                G.connect(src, dst);
                len = 0;
            }
            else
            {
                number[len] = line[j];
                len++;
            } 
                           
        }
        number[len] = '\0';
        dst = atoi(number);
        G.connect(src, dst);
        
    }
    fclose(fp);

    if(DEBUG) 
    {
        cout << "Input Graph:"<<endl;
        G.printGraph();
    }

    vector<int> soln;
    G.findArticulation(soln);
    if(soln.size() == 0) 
    {
        cout<<"No articulation points found!"<<endl;
    }
    else
    {
        cout<<"Articulation points obtained are:"<<endl;
        for(int i = 0; i<soln.size(); ++i)
        {
            cout<<soln[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}