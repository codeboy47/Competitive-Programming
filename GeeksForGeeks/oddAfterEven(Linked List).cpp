#include <iostream>
using namespace std;


class Node{
public:
	int data;
	Node*next;

	Node():data(0),next(NULL){}
	Node(int d):data(d),next(NULL){}

	friend class linkedList;

};


class linkedList{
public:
	Node*head;
	linkedList():head(NULL){}
	void insertBack(int d){
		Node*n = new Node(d);
		if(head == NULL){
			head = n;
		}else{
			Node*temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = n;
			n->next = NULL;
		}
	}

	void oddAfterEven(){
		Node*start = head,*prev = head,*next;
		if(head == NULL){
			//cout<<"enter right data except -1 "<<endl;
			return;
		}
		next = start->next;
		while(next != NULL){
			if((next->data)%2 == 0 && (prev->data)%2 == 0){
				start = start->next;
				prev = next;
				next = next->next;
			}
			else if((next->data)%2 == 0){
				prev->next = next->next;
				if((head->data)%2 == 1){
					next->next = head;
					head = next;
					//-- reset
					start = head;
					prev = head;
					next = prev->next;
				}
				else{
					next->next = start->next;
					start->next = next;
				
					start = start->next;
					next = prev->next;
				}
			}
			else if((next->data)%2 == 1){
				prev = next;
				next =next->next;
			}
		}
	}
	void print(){
	    Node*node = head;
        while (node!=NULL)
        {
        printf("%d ", node->data);
        node = node->next;
        }
    }
    void deleteList(){
		Node *temp = head;
		while(temp!=NULL){
			temp = head->next;
			delete head;
			head = temp;
		}
		head = temp;
	}
};
int main() {
	//code
	linkedList l;
	int T,N,i=0,j,arr[100];
	cin>>T;
	while(i<T){
	    cin>>N;
	    for(j=0;j<N;j++){
	        cin>>arr[j];
	        l.insertBack(arr[j]);
	    }
	    l.oddAfterEven();
	    l.print();
	    cout<<endl;
	    l.deleteList();
	    i++;
	}
	return 0;
}