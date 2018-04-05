#include<iostream>
using namespace std;

template<typename T>	
class Stack;

template<typename T>
class Node{
public: 
	T data;
	Node<T> *next;
public:
	Node(T d):data(d){}

//friend class Stack;
};

template<typename T>
class Stack{
	Node<T> * head;
public:
	Stack():head(NULL){}
	
	void push(T data){
		Node<T> *n = new Node<T>(data);
		n->next = head;
		head = n;
	}

	T pop(){
		if(head!=NULL){
			Node<T>* temp = head;
			head = head->next;
			
			T data = temp->data;
			delete temp;
			return data;
		}
	}
	
	bool isEmpty(){
		return head==NULL?true:false;
	}

};

bool checkParanthesis(char *str){
	Stack<char> s;
	while(*str != '\0'){
		if(*str == '{'){
			s.push('{');
		}else if(*str == '['){
			s.push('[');
		}else if(*str == '('){
			s.push('(');
		}else if(*str == '}'){
			if(s.pop() == '{'){
			}else{
				return false;
			}
		}else if(*str == ']'){
			if(s.pop() == '['){
			}else{
				return false;
			}
		}else if(*str == ')'){
			if(s.pop() == '('){ 
			}else{
				return false;
			}
		}
		*str++;
	}

	return s.isEmpty() == 1 ? true : false;
}

int main(){
int T,i=0,j;
	cin>>T;
	while(i<T+1){
	    char str[100];
	    cin.getline(str,100);
	    if(i>0)
	    checkParanthesis(str)==1? cout<<"balanced"<<endl : cout<<"not balanced"<<endl;
	    
	    i++;
	}
return 0;
}

