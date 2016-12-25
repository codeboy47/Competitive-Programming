/*
The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 
void QueueStack :: push(int x)
{
        // Your Code
}

int QueueStack :: pop()
{
        // Your Code       
}
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Stack{
	queue<int> q1;
	queue<int> q2;
public:	
	void push(int data){
		q1.push(data);
	}

	int pop(){
		if(q1.empty()){
        	return -1;
    	}
		int i = 0;
		int size = q1.size();
		while(i < size-1){
			q2.push(q1.front());
			q1.pop();
			i++;
		}
		int top = q1.front();
		q1.pop();
		while(!q2.empty()){
			q1.push(q2.front());
			q2.pop();
		}

		return top;
	}

	int size(){
		return q1.size();
	}

	int top(){
		return q1.back();
	}
};
int main() {
	//code
	Stack s;
	int k = 0;
	int T,Q,i=0,j,arr[100];
	cin>>T;
	while(i<T){
	    cin>>Q;
	    for(j=0;j<Q;j++){
	        cin>>arr[j];
	        if(arr[j] == 1){
	            cin>>k;
	            s.push(k);
	        }    
	        if(arr[j] == 2){
	            cout<<s.pop()<<" ";
	        }
	    }
	    i++;
	}
	return 0;
}