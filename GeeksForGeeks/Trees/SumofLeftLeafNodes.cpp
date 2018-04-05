/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all
// left leaf nodes
int leftLeafSum(Node* root)
{
    if(root == NULL){
        return 0;
    }

    int l = leftLeafSum(root->left);
    if(root->left == NULL && root->right == NULL){
        //cout<<root->data<<" ";
        return root->data;
    }

    if(root->right && root->right->left == NULL && root->right->right == NULL){
        return l;
    }
    int r = leftLeafSum(root->right);
    return l+r;
}
