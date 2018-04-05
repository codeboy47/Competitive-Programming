/* Tree node structure
struct Node 
{
   int data;
   Node *left, *right;
}*/

// Function should construct tree and return root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is size of these arrays

int postIndex;
Node *buildhelp(int postorder[], int inorder[],int start,int end){
    int breakPoint;
	if(start > end){
		return NULL;
	}
	Node*root = newNode(postorder[postIndex]);
	postIndex--;
	if(start == end){
		return root;
	}	
	for(int i = start;i <= end;i++){
		if(inorder[i] == root->data){
			breakPoint = i;
			break;
		}
	}
	root->right = buildhelp(postorder,inorder,breakPoint+1,end);
	root->left = buildhelp(postorder,inorder,start,breakPoint-1);
	return root;    
}

Node *buildTree(int in[], int post[], int n){
	postIndex = n-1;
	return buildhelp(post,in,0,n-1);
}

