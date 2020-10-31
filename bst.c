#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right,*left;
};
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);    
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);    
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);    
    printf("%d ",root->data);
    
}
struct node *create(int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
int main()
{
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root = create(10);
    root->left = create(5);
    root->right = create(15);
    preorder(root);
    inorder(root);
    postorder(root);
}