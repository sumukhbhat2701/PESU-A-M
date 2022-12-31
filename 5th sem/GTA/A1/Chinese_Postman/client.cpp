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
        fscanf(fp, "%d", &n);     
    }
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
                    G.connect(src, dst, w);
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
        w = atoi(number);
        number[len] = '\0';
        G.connect(src, dst, w);
    }
    fclose(fp);

    if(DEBUG) G.printGraph();

    G.ChinesePostman();

    return 0;
}