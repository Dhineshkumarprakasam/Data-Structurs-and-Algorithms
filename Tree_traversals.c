#include <stdio.h>

struct node
{
    struct node *left,*right;
    int data;
};

struct node *create()
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=0;

    int x;
    printf("Enter value : ");
    scanf("%d",&x);

    if(x==-1)
    {
        return 0;
    }

    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left=create();
    printf("Enter right child of %d\n",x);
    newnode->right=create();

    return newnode;
};

void pre(struct node*root)
{
    if(root==0)
    {
        return;
    }
    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}

void post(struct node*root)
{
    if(root==0)
    {
        return;
    }
    post(root->left);
    post(root->right);
    printf("%d ",root->data);

}

void in(struct node*root)
{
    if(root==0)
    {
        return;
    }

    in(root->left);
    printf("%d ",root->data);
    in(root->right);
}
void main()
{
    struct node *root;
    root=create();

    printf("Pre order:\n");
    pre(root);
    printf("\n");

    printf("Post order:\n");
    post(root);
    printf("\n");

    printf("In order:\n");
    in(root);
}
