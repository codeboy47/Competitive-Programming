/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function
Node is as follows:
struct node
{
    int data;
    struct node *left, *right;
};
*/

struct node *correctBSTHelper(struct node*root, int minV, int maxV){

	if(!root)	return NULL;

	if(minV > root->data || root->data > maxV)
		return root;

	struct node* left = correctBSTHelper(root->left,minV,root->data);
	if(left){
		return left;
	}	


	struct node* right = correctBSTHelper(root->right,root->data,maxV);
	
	return right;

}

struct node *correctBST( struct node* root )
{	
    if(!root)   return NULL;
    
	struct node* tempL = NULL, *tempR = NULL;

	if(root->left)
		tempL = correctBSTHelper(root->left,INT_MIN,root->data);

	if(root->right)
		tempR = correctBSTHelper(root->right,root->data,INT_MAX);
    
    if(tempL && tempR){
    	int temp = tempL->data;
    	tempL->data = tempR->data;
    	tempR->data = temp;
    }
    
    if(!tempL){
        int temp = root->data;
    	root->data = tempR->data;
    	tempR->data = temp;
    }
    
    if(!tempR){
        int temp = tempL->data;
    	tempL->data = root->data;
    	root->data = temp;
    }
    
	return root;
	
}







