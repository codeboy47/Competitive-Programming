/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

int isHelperSumTree(Node*root){
 
	if(!root->left && !root->right){
		return root->data;
	}

	if(!root->left || !root->right){
		return -1;
	}

	int left = isHelperSumTree(root->left);
	if(left == -1)	return -1;

	int right = isHelperSumTree(root->right);

	if(root->data == left + right){
		return root->data + left + right;
	}
	return -1;
}

bool isSumTree(Node* root)
{
	if(!root){
		return true;
	}


	if(isHelperSumTree(root) != -1){
		return true;
	}

	return false;

}