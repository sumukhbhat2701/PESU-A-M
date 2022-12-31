#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "server.h"
#define MAX 9999

int main()
{
    int n,src,dst,w,len,first, parity;
    char line[MAX]; char number[MAX];
    graph_t* G;

    FILE* fp = fopen("adjacencylist.txt","r");
    if(fp == NULL)
    {
        if(DEBUG)
            printf("Error opening file\n");
        exit(0);
    }
    else
    {
        fscanf(fp,"%d",&n);
        G = new_graph(n);
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
                        insert_edge(G,src,dst,w);
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
            insert_edge(G,src,dst,w);
        }
        
    }
    fclose(fp);

    if(DEBUG) { printf("Given Graph:\n"); print_graph(G); }

    single_dest_dijkstras(G,n);
    delete_graph(G);
    return 0;
}
