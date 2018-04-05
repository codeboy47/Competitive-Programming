#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left,*right;
};

Node *createNode(char ch){

    Node* n = new Node;
    n->data = ch;
    n->left = n->right = NULL;
    return n;
}

Node* ConvertTernaryExpressionToBinaryTree(string str, int &i){

    Node*root;

        if(i < str.size() && str[i] != '?' && str[i] != ':'){
            root = createNode(str[i]);
            i++;
        }
        if(i == str.size()){
            return root;
        }
        
        if(str[i] == '?'){
            i++;
            root->left = ConvertTernaryExpressionToBinaryTree(str,i);
        }
        if(str[i] == ':'){
            i++;
            return root;
        }
        
        root->right = ConvertTernaryExpressionToBinaryTree(str,i);
    
        return root;

}


void printPreOrder(Node*root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main(){

    int t;
    string str;
    cin>>t;
   
    while(t--){
          
        cin>>str;
        
        int i = 0;
        Node* root = ConvertTernaryExpressionToBinaryTree(str,i);
        printPreOrder(root);
        cout<<endl;
          
    }

    return 0;
}