// find min path sum from root to leaf in bst
// company - citibank

#include <iostream>
#include <climits>
using namespace std;

class node{
public:
     int data;
     node*left;
     node*right;
     node(int d) : data(d), left(NULL), right(NULL) { }
};

int findMinSumFromRootToLeaf(node*root){
     if(root == NULL){
          return -1;
     }
     if(root->left == NULL && root->right == NULL){
          return root->data;
     }
     int l = INT_MAX, r = INT_MAX;
     if(root->left){
          l = findMinSumFromRootToLeaf(root->left);
     }
     if(root->right){
          r = findMinSumFromRootToLeaf(root->right);
     }
     return min(l,r) + root->data;

}

int main(){

   node *root = new node(15);
   root->left = new node(10);
   root->right = new node(20);
   root->right->left = new node(22);
   root->left->left = new node(6);
   root->left->right = new node(1);
   root->left->right->left = new node(2);
   root->left->right->right = new node(16);
   root->left->right->left->left = new node(0);
   root->left->right->left->right = new node(5);
   root->left->right->right->left = new node(3);

   cout<<findMinSumFromRootToLeaf(root);

return 0;
}
