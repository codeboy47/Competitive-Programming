/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */
/*You are required to complete below method */
int sumOfLeafNodes(Node *root ){
    if(root == NULL){
        return 0;
    }

    int l = sumOfLeafNodes(root->left);
    if(root->left == NULL && root->right == NULL){
        //cout<<root->data<<" ";
        return root->data;
    }

    int r = sumOfLeafNodes(root->right);
    return l+r;
}
