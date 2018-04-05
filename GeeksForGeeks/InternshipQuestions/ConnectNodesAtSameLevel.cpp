/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p)
{
   queue<pair< Node*,int> > q;
   if(p == NULL) return;
   //struct Node *top = q.front();

   q.push(make_pair(p,0));
   while(!q.empty()){
       struct Node* top = q.front().first;
       int level = q.front().second;
       q.pop();
       if(q.empty() || level != q.front().second){
           top->nextRight = NULL;
       }
       else if(!q.empty() && level == q.front().second){
           top->nextRight = q.front().first;
       }

       if(top->left)
       q.push(make_pair(top->left,level+1));
       if(top->right)
       q.push(make_pair(top->right,level+1));
   }

}
