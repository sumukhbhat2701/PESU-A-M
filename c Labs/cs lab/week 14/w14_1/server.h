struct node
{
    int data;
    struct Node *next;
};
int sumall(struct node *);
int sumalternate(struct node *);
int sumodd(struct node *);
int sumeven(struct node *);
void display(struct node *);
struct node* beg(struct node *);
struct node* end(struct node *);

