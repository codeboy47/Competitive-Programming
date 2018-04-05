/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void display(Node *head)
{   
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
   //add code here
}