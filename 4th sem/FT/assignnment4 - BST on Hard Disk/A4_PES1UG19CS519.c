#include "assignment_4.h"
#include <stdio.h>
#include <stdlib.h>

// helper functions used
static void inorder_helper(FILE* fp,int offset);
static void preorder_helper(FILE* fp,int offset);
static int number_of_entries(FILE* fp);

// create a file with the filename and initialize the header with tree_t structure
// if the file already exists, just return the file ptr
FILE* init_tree(const char* filename)
{
    // open in read+ mode
    FILE* fp = fopen(filename,"r+");
    if(fp == NULL)   // if file doesn't exist
    {
        fp = fopen(filename,"w+");   // open in write+ mode
        if(fp == NULL)  // other file errors
        {
            exit(0);
        }
        else // create new file and initialize
        {
            tree_t bst;
            bst.free_head = -1;
            bst.root = -1;
            fseek(fp,0,SEEK_SET);
            fwrite(&bst,sizeof(tree_t),1,fp);
            return fp;
        }
    }
    else  // file exists
    {
        return fp;
    }
}

// close the file pointed by fp
void close_tree(FILE *fp)
{
    fclose(fp);
}

static void inorder_helper(FILE* fp,int offset)
{
    // until we reach -1, go to that particular left subtree offsets, print and go to right subtree offsets until -1
    if (offset != -1) 
	{
		node_t iter;
		fseek(fp,sizeof(tree_t) + offset*sizeof(node_t), SEEK_SET);
		fread(&iter,sizeof(node_t),1,fp);
		inorder_helper(fp,iter.left_offset);
		printf("%d ",iter.key);
		inorder_helper(fp,iter.right_offset);
	}
}

// Space separated keys printed in ascending order. Last key followed by '\n'
void display_inorder(FILE *fp)
{
    tree_t bst;   
	fseek(fp,0,SEEK_SET);
	fread(&bst,sizeof(tree_t),1,fp);
    // tree empty
	if(bst.root == -1)
    {
        printf("\n");
        return;
    } 
    inorder_helper(fp, bst.root);
	printf("\n");
}

static void preorder_helper(FILE* fp,int offset)
{
    // print the key, until we reach -1, go to that particular left subtree offsets, and go to right subtree offsets until -1
    if (offset != -1) 
	{
		node_t iter;
		fseek(fp,sizeof(tree_t) + offset*sizeof(node_t), SEEK_SET);
		fread(&iter,sizeof(node_t),1,fp);
        printf("%d ",iter.key);
		preorder_helper(fp,iter.left_offset);
		preorder_helper(fp,iter.right_offset);
	}
}

// Space separated keys in preorder fashion. Last key followed by '\n'
void display_preorder(FILE *fp)
{
    tree_t bst;   
	fseek(fp,0,SEEK_SET);
	fread(&bst,sizeof(tree_t),1,fp);
    // Tree empty
	if(bst.root == -1)
    {
        printf("\n");
        return;
    }
    preorder_helper(fp,bst.root);
	printf("\n");
}

// return the total number of nodes(occupied node + holes) in the file
static int number_of_entries(FILE* fp)
{
    int count = 0; node_t iter;
    fseek(fp,0,SEEK_SET);
    fseek(fp,sizeof(tree_t),SEEK_SET);
    // iterate until fread gives EOF error(return value <= 0)
    while(fread(&iter, sizeof(node_t), 1, fp) > 0)
	{
		count++;
	}
    return count;
}

// insert the key into the tree in the file
// if the key already exists just return
void insert_key(int key, FILE *fp)
{
    tree_t bst;
    node_t new;
    //create a node out of the key
    new.key = key;
    new.left_offset = -1;
    new.right_offset = -1;
    fseek(fp,0,SEEK_SET);
    fread(&bst,sizeof(tree_t),1,fp);
    // tree empty, root insertion
    if(bst.root == -1)
    {
        // inserting for the first time to a file
        if(bst.free_head == -1)
        {
            // root is inserted at 0
            bst.root = 0;
            fseek(fp,0,SEEK_SET);
            fwrite(&bst,sizeof(tree_t),1,fp);
            fwrite(&new,sizeof(node_t),1,fp);
        }
        // holes exist
        else
        {
            // root is inserted at the first hole in the file and update the free_head
            bst.root = bst.free_head;
            node_t hole;
            fseek(fp,sizeof(tree_t) + bst.free_head*sizeof(node_t),SEEK_SET);
            fread(&hole,sizeof(node_t),1,fp);
            bst.free_head = hole.right_offset;
            fseek(fp,-sizeof(node_t),SEEK_CUR);
            fwrite(&new,sizeof(node_t),1,fp);
            fseek(fp,0,SEEK_SET);
            fwrite(&bst,sizeof(node_t),1,fp);

        }
        
    }
    else
    {
        //search for the position to insert the key
        node_t iter; int left,offset;   // iter is a like a pointer variable to iterate through the bst. left keeps track whether iter moves left/right in the previous move.
        fseek(fp,sizeof(tree_t) + bst.root*sizeof(node_t),SEEK_SET);
        fread(&iter,sizeof(node_t),1,fp);
        // initialize offset and left w.r.t root node
        if(key > iter.key)
        {
            offset = iter.right_offset;
            left = 0;
        }
        else if(key < iter.key)
        {
            offset = iter.left_offset;
            left = 1;
        }
        else if(key == iter.key)
        {
            return;  // duplicate key
        }
        // until we reach -1(NULL), iterate according to the property of bst. At the end, iter will point to the leaf node where new node has to be inserted.
        while(offset != -1)
        {
            fseek(fp,sizeof(tree_t) + offset*sizeof(node_t),SEEK_SET);
            fread(&iter,sizeof(node_t),1,fp);
            if(iter.key == key) { return; }  // duplicate key
            if(key > iter.key)
            {
                offset = iter.right_offset;
                left = 0;
            }
            else
            {
                offset = iter.left_offset;
                left = 1;
            }
        }
        fseek(fp,-sizeof(node_t),SEEK_CUR);
        //if no holes, insert the new node at the EOF and update that leaf node
        if(bst.free_head == -1)
        {
                offset = (int)ftell(fp);
                if(left)
                { 
                    iter.left_offset = number_of_entries(fp); 
                }
                else
                {
                    iter.right_offset = number_of_entries(fp); 
                }
                fseek(fp,offset,SEEK_SET);
                fwrite(&iter,sizeof(node_t),1,fp);
                fseek(fp,sizeof(tree_t) + number_of_entries(fp)*sizeof(node_t),SEEK_SET);
                fwrite(&new,sizeof(node_t),1,fp);
        }
        // holes exist, insert to the first hole. Update free_head, 
        else
        {            
                if(left)
                { 
                    iter.left_offset = bst.free_head; 
                }
                else
                {
                    iter.right_offset = bst.free_head; 
                }
                fwrite(&iter,sizeof(node_t),1,fp);

                node_t hole;
                fseek(fp,(bst.free_head)*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fread(&hole,sizeof(node_t),1,fp);
                // no more holes after insertion
                if(hole.right_offset == -1)
                {
                    fseek(fp,-sizeof(node_t),SEEK_CUR);
                    fwrite(&new,sizeof(node_t),1,fp);
                    bst.free_head = -1;
                    fseek(fp,0,SEEK_SET);
                    fwrite(&bst,sizeof(tree_t),1,fp);
                }
                // otherwise
                else
                {
                    fseek(fp,-sizeof(node_t),SEEK_CUR);
                    fwrite(&new,sizeof(node_t),1,fp);
                    bst.free_head = hole.right_offset;
                    fseek(fp,0,SEEK_SET);
                    fwrite(&bst,sizeof(tree_t),1,fp);
                }           
        }
    }
}



// delete the key from the tree in the file
// the key may or may not exist
void delete_key(int key, FILE *fp)
{
    tree_t bst;
    fseek(fp,0,SEEK_SET);
    fread(&bst,sizeof(tree_t),1,fp);
    // if tree is empty
    if(bst.root == -1)
    {
        return;
    }
    else
    {
        //search for the position to insert the key
        node_t iter, parent, child; 
        int p_offset = -1,c_offset = bst.root,left,is_root = 0;
        fseek(fp,bst.root*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
        fread(&iter,sizeof(node_t),1,fp);
        // iterate with the property of bst and keep track of parent and its offset as well 
        if(iter.key > key)
        {
            left = 1;
            p_offset = c_offset;
            c_offset = iter.left_offset;
            
        }
        else if(iter.key < key)
        {
            left = 0;
            p_offset = c_offset;
            c_offset = iter.right_offset;     
        }
        else
        {
            is_root = 1;  // root deletion
        }
        while(c_offset!= -1)
        {
            fseek(fp,c_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
            fread(&iter,sizeof(node_t),1,fp);
            if(key == iter.key) // key to be deleted found
                break;
            else
            {
                if(iter.key > key)
                {
                    left = 1;
                    p_offset = c_offset;
                    c_offset = iter.left_offset;
                    
                }
                else if(iter.key < key)
                {
                    left = 0;
                    p_offset = c_offset;
                    c_offset = iter.right_offset;     
                }
            }
        }

        if(c_offset == -1) {return;}   // key to be deleted not found

        // node to be deleted
        fseek(fp,sizeof(tree_t) + c_offset*sizeof(node_t),SEEK_SET);
        fread(&child,sizeof(node_t),1,fp);

        // read its parent if child is not root
        if(!is_root)
        {
            fseek(fp,sizeof(tree_t) + p_offset*sizeof(node_t),SEEK_SET);
            fread(&parent,sizeof(node_t),1,fp);
        }
        
       
        // node to be deleted is a leaf node
        if(child.left_offset == -1 && child.right_offset == -1)
        {
            // make the child as hole
            child.right_offset = -1;            
            fseek(fp,sizeof(tree_t) + c_offset*sizeof(node_t),SEEK_SET);
            fwrite(&child,sizeof(node_t),1,fp);

            // if the node is be deleted is not root, then update its parent
            if(!is_root)
            {
                if(left) parent.left_offset = -1;
                else parent.right_offset = -1;
                fseek(fp,sizeof(tree_t) + p_offset*sizeof(node_t),SEEK_SET);
                fwrite(&parent,sizeof(node_t),1,fp);
            }
            // if it is root, then update the header
            else
            {
                bst.root = -1;
                fseek(fp,0,SEEK_SET);
                fwrite(&bst,sizeof(tree_t),1,fp);
            }
            
            // update hole offset information
            node_t hole;
            // if this deletion causes the first ever hole, update the header
            if(bst.free_head == -1)
            {
                bst.free_head = c_offset;
                fseek(fp,0,SEEK_SET);
                fwrite(&bst,sizeof(tree_t),1,fp);
            }
            // iterate to the last hole offset and update it's right offset with new hole
            else
            {
                fseek(fp,(bst.free_head)*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fread(&hole,sizeof(node_t),1,fp);

                while(hole.right_offset!=-1)
                {
                    fseek(fp,sizeof(tree_t) + hole.right_offset*sizeof(node_t),SEEK_SET);
                    fread(&hole,sizeof(node_t),1,fp);
                }
            
                hole.right_offset = c_offset;
                fseek(fp,-sizeof(node_t),SEEK_CUR);
                fwrite(&hole,sizeof(node_t),1,fp);
            }
            

        }
        // if the node to be deleted has 1 child
        else if((child.left_offset == -1 && child.right_offset!=-1) || (child.left_offset!=-1 && child.right_offset == -1))
        {
            int offset;
            // if the one child is right child only
            if(child.left_offset == -1)
            {
                offset = child.right_offset;
                // update the parent if non-root node is to be deleted
                if(!is_root)
                {
                    if(left)
                    {
                        parent.left_offset = offset;
                    }
                    else
                    {
                        parent.right_offset = offset;
                    }
                    fseek(fp,sizeof(tree_t) + p_offset*sizeof(node_t),SEEK_SET);
                    fwrite(&parent,sizeof(node_t),1,fp);
                }
                // if root has to be deleted, it's child becomes the root
                else
                {
                    // if root has 1 child and we delete root 
                    bst.root = offset;
                    fseek(fp,0,SEEK_SET);
                    fwrite(&bst,sizeof(node_t),1,fp);
                }
            }
            // if the one child is left child only
            else
            {
                offset = child.left_offset;
                // update the parent if non-root node is to be deleted
                if(!is_root)
                {
                    if(left)
                    {
                        parent.left_offset = offset;
                    }
                    else
                    {
                        parent.right_offset = offset;
                    }
                    fseek(fp,sizeof(tree_t) + p_offset*sizeof(node_t),SEEK_SET);
                    fwrite(&parent,sizeof(node_t),1,fp);
                }
                // if root has to be deleted, it's child becomes the root
                else
                {
                    // if root has 1 child and we delete root 
                    bst.root = offset;
                    fseek(fp,0,SEEK_SET);
                    fwrite(&bst,sizeof(node_t),1,fp);
                }
            }

            // make the child node as hole and update hole offsets
            child.right_offset = -1;            
            fseek(fp,sizeof(tree_t) + c_offset*sizeof(node_t),SEEK_SET);
            fwrite(&child,sizeof(node_t),1,fp);

            node_t hole;
            // if this deletion causes the first ever hole, update the header
            if(bst.free_head == -1)
            {
                bst.free_head = c_offset;
                fseek(fp,0,SEEK_SET);
                fwrite(&bst,sizeof(tree_t),1,fp);
            }
            // iterate to the last hole offset and update it's right offset with new hole
            else
            {
                fseek(fp,(bst.free_head)*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fread(&hole,sizeof(node_t),1,fp);

                while(hole.right_offset!=-1)
                {
                    fseek(fp,sizeof(tree_t) + hole.right_offset*sizeof(node_t),SEEK_SET);
                    fread(&hole,sizeof(node_t),1,fp);
                }
            
                hole.right_offset = c_offset;
                fseek(fp,-sizeof(node_t),SEEK_CUR);
                fwrite(&hole,sizeof(node_t),1,fp);
            }

        }
        // if the node to be deleted has both left and right child
        else if(child.left_offset!=-1 && child.right_offset!=-1)
        {
            node_t insucc; int left = 0;
            fseek(fp,sizeof(tree_t) + c_offset*sizeof(node_t),SEEK_SET);
            fread(&insucc,sizeof(node_t),1,fp);
            //find the inorder successor: Traverse to the right once and then to the right subtree until -1. Keep track of parent as well
            int temp = insucc.right_offset;
            int insucc_offset = c_offset;
            p_offset = c_offset;
            while(temp!=-1)
            {
                fseek(fp,sizeof(tree_t) + temp*sizeof(node_t),SEEK_SET);
                p_offset = insucc_offset;
                insucc_offset = temp;
                parent = insucc;
                fread(&insucc,sizeof(node_t),1,fp);
                temp = insucc.left_offset;
                if(insucc.left_offset!=-1)
                    left = 1;
            }

            fseek(fp,insucc_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
            fread(&insucc,sizeof(node_t),1,fp);

            // swap the values of child(root to be deleted) and inorder successor and delete the node originally in the place of inorder successor
            int swap = child.key; 
            child.key = insucc.key;
            insucc.key = swap;

            fseek(fp,insucc_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
            fwrite(&insucc,sizeof(node_t),1,fp);

            fseek(fp,sizeof(tree_t) + c_offset*sizeof(node_t),SEEK_SET);
            fwrite(&child,sizeof(node_t),1,fp);

            //DELETE:
            // from this point onwards: child = insucc => node originally in the place of inorder successor ; parent => it's parent  
            child = insucc;
            // child/insucc has no children
            if(insucc.right_offset == -1)
            {
                // make the child as hole
                child.right_offset = -1;            
                fseek(fp,insucc_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fwrite(&child,sizeof(node_t),1,fp);

                // update the offsets in it's parent
                fseek(fp,p_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fread(&parent,sizeof(node_t),1,fp);

                // if the child was a right child of it's parent
                if(!left)
                    parent.right_offset = -1;
                // if the child was a left child of it's parent
                else
                    parent.left_offset = -1;

                fseek(fp,sizeof(tree_t) + p_offset*sizeof(node_t),SEEK_SET);
                fwrite(&parent,sizeof(node_t),1,fp);

                // update hole offset information
                node_t hole;
                // if this deletion causes the first ever hole, update the header
                if(bst.free_head == -1)
                {
                    bst.free_head = insucc_offset;
                    fseek(fp,0,SEEK_SET);
                    fwrite(&bst,sizeof(tree_t),1,fp);
                }
                // otherwise, iterate to the last hole offset and update it's right offset with new hole
                else
                {
                    fseek(fp,(bst.free_head)*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                    fread(&hole,sizeof(node_t),1,fp);

                    while(hole.right_offset!=-1)
                    {
                        fseek(fp,sizeof(tree_t) + hole.right_offset*sizeof(node_t),SEEK_SET);
                        fread(&hole,sizeof(node_t),1,fp);
                    }
                
                    hole.right_offset = insucc_offset;
                    fseek(fp,-sizeof(node_t),SEEK_CUR);
                    fwrite(&hole,sizeof(node_t),1,fp);
                }
            }
            // if it has a right child
            else
            {
                // update parent offsets
                fseek(fp,p_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fread(&parent,sizeof(node_t),1,fp);

                // if the child was a left child of it's parent
                if(left)
                    parent.left_offset = insucc.right_offset;
                // if the child was a right child of it's parent
                else
                    parent.right_offset = insucc.right_offset;
                    

                fseek(fp,sizeof(tree_t) + p_offset*sizeof(node_t),SEEK_SET);
                fwrite(&parent,sizeof(node_t),1,fp);

                // make the child as hole
                insucc.right_offset = -1;            
                fseek(fp,insucc_offset*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                fwrite(&insucc,sizeof(node_t),1,fp);

                // update hole offset information
                node_t hole;
                // if this deletion causes the first ever hole, update the header
                if(bst.free_head == -1)
                {
                    bst.free_head = insucc_offset;
                    fseek(fp,0,SEEK_SET);
                    fwrite(&bst,sizeof(tree_t),1,fp);
                }
                // otherwise, iterate to the last hole offset and update it's right offset with new hole
                else
                {
                    fseek(fp,(bst.free_head)*sizeof(node_t) + sizeof(tree_t),SEEK_SET);
                    fread(&hole,sizeof(node_t),1,fp);

                    while(hole.right_offset!=-1)
                    {
                        fseek(fp,sizeof(tree_t) + hole.right_offset*sizeof(node_t),SEEK_SET);
                        fread(&hole,sizeof(node_t),1,fp);
                    }
                
                    hole.right_offset = insucc_offset;
                    fseek(fp,-sizeof(node_t),SEEK_CUR);
                    fwrite(&hole,sizeof(node_t),1,fp);
                }

            }

        }
        
    }
}

