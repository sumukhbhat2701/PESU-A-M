#include<stdio.h>
#include<stdlib.h>
struct numbers
{
    int x,y;
}; typedef struct numbers num;
struct node
{
	int key;
	int left_offset;
	int right_offset;
};
typedef struct node node_t;
struct tree
{
	int free_head;
	int root;
};
typedef struct tree tree_t;
static void display_file(FILE* fp)
{
    tree_t bst;
    fseek(fp,0,SEEK_SET);
    fread(&bst,sizeof(tree_t),1,fp);
    printf("%d %d\n",bst.root,bst.free_head);
    node_t iter;
    while(fread(&iter, sizeof(node_t), 1, fp) > 0)
    {
        printf("%d %d %d\n",iter.left_offset,iter.key,iter.right_offset);
    }
    // printf("#Nodes= %d\n\n",number_of_entries(fp));
}
int main()
{
    node_t x[5]= {{5,1,2},{3,-1,-1},{6,-1,-1},{2,-1,4},{4,-1,-1}};
    tree_t t;
    t.free_head = 3;
    t.root = 0;
    FILE* fp = fopen("test.dat","w");
    fseek(fp,0,SEEK_SET);
    fwrite(&t,sizeof(tree_t),1,fp);
    for(int i=0;i<5;i++)
    {
        fwrite(&x[i],sizeof(node_t),1,fp);
    }
    display_file(fp);
    fclose(fp);

    // fp = fopen("test.dat","r");
    // fseek(fp,0,SEEK_SET);
    // num l;
    // for(int i=0;i<5;i++)
    // {
    //     fread(&l,sizeof(num),1,fp);
    //     printf("%d %d\n",l.x,l.y);
    // }
    // fclose(fp);
    // int x = 1,y,z;
    // x == 1?y=10:z=50;
    // printf("%d,%d,%d\n",x,y,z);
    return 0;
}