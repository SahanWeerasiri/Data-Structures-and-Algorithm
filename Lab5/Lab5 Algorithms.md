# Lab 5 (Stacks)
***
> * Stack implementation with an array
> * Stack implementation with a linked list
***
# Stack implementation with an array
```cpp
class Stack {
    // <--- ADD YOUR CODE HERE --->
    public:
    int *arr;
    int n;
    int top;
    Stack(int max_size){
        arr=new int[max_size];
        n=max_size;
        top=-1;
    }
    void push(int val){
        top++;
        if(top>n-1){
            std::cout<<"Stack Overflow"<<std::endl;
            top--;
            return;
        }
        arr[top]=val;
    }
    int pop(){
        if(isEmpty()){
            std::cout<<"Stack Underflow"<<std::endl;
            return -1;
        }
        int data=arr[top];
        top--;
        return data;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top==n-1){
            return true;
        }
        return false;
    }
    int stackTop(){
        return arr[top];
    }
    void display(){
        int temp_top=top;//keep top safely in another variable
        for(int i=top;i>=0;i--){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
        top=temp_top;//restore top
    }
};
```
***
# Stack implementation with a linked list
```cpp
class Node {
    // <--- ADD YOUR CODE HERE --->
    public:
        Node *next;
        int data;
        Node(int val){
            data=val;
            next=nullptr;
        }
    
};

class Stack{
    // <--- ADD YOUR CODE HERE --->
    public:
        Node *top;
        Node *head;
        Stack(){
            top=nullptr;
            head=nullptr;
        }
        void push(int val){
	        Node *temp=new Node(val);
            if(isEmpty()){//new Stack;(head=top);(first node)
                top=temp;
                head=temp;
                return;
            }
            //add a new node for existing stack
            top->next=temp;
            top=temp;
        }
        int pop(){
            if(isEmpty()){//no elements
                std::cout<<"Stack Underflow";
                return -1;
            }
            int d=top->data;
            if(head==top){//only one node
                top=nullptr;
                head=nullptr;
                return d;
            }
            //more than one node
            Node *current=head;
            while(current->next!=top){
                current=current->next;
            }
            current->next=nullptr;
            top=current;
            return d;
        }
        bool isEmpty(){
            if(top==nullptr){
                return true;
            }
            return false;
        }
        int stackTop(){
            return top->data;
        }
        void display(){
            Stack *temp=new Stack();//to store the stack in the same order
            Node *current=head;
            while(current->next!=nullptr){
                temp->push(current->data);
                current=current->next;
            }
            temp->push(current->data);//top element
            while(temp->head!=temp->top){
                std::cout<<temp->pop()<<" ";
            }
            std::cout<<temp->pop()<<std::endl;
        }
        
};
```
