/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
//You are required to complete this method
void levelOrder(Node* node)
{
	queue<Node*> q;

	q.push(node);

	while(!q.empty()){

		Node*n = q.front();
		cout<<n->data<<" ";
		q.pop();

		if(n->left)
			q.push(n->left);
		if(n->right)
			q.push(n->right);
		
	}

}
