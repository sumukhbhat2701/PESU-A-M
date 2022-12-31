int height(struct tnode *t)
		{
			int l,r;
			if(t==NULL) //empty tree
				return -1;
				//one node tree
			if((t->left==NULL)&&(t->right==NULL))
				return 0;
			l=height(t->left);//height of left subtree
			r=height(t->right);//height of right subtree
			if(l>r)
				return 1+l;
			else
				return 1+r;
		}