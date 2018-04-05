// Ques. Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.

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


// time complexity is O(N)
// result = max(result,root->data+left,root->data+right,root->data,left+right+root->data)
int findMaxSum(node*root, int &result){

     if(root == NULL) {
          return 0;
     }

     int l = findMaxSum(root->left,result);
     int r = findMaxSum(root->right,result);

     // node or node + left or node + right  - all three paths possible so return t
     // these can make path with their ancestors that is why we return these 3 only
     int t = max(root->data,max(root->data+l,root->data+r));

     // another case : no ancestor involved in max sum path
     result = max(result,max(t,l+r+root->data));

     return t;

}

int main(){

     node*root = new node(10);
     root->left = new node(2);
     root->right = new node(10);
     root->left->left = new node(20);
     root->left->right = new node(1);
     root->right->right = new node(-25);
     root->right->right->left  = new node(3);
     root->right->right->right  = new node(476);
     int res = INT_MIN;
     findMaxSum(root,res);
     cout<<res<<endl;
     return 0;
}

/*
     node*root = new node(1);
     root->left = new node(2);
     root->right = new node(2);
     root->left->left = new node(10);
     root->left->right = new node(1);
     root->right->right = new node(-25);
     root->right->right->left  = new node(3);
     root->right->right->right  = new node(24); // 26

*/
