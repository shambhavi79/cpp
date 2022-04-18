#include <iostream>

using namespace std;

#define MAX_SIZE 10

class Stack{
    private:
    int stack[MAX_SIZE];
    int top; //Denotes last element in the array or top of stack
    public:
    Stack(){
        top=-1;
    }
    
    void push(int data){
        if(isFull){
            cout<<"Stack is already full"<<endl;
            return;
        }
        else{
            stack[++top]=data;
        }
    }
    
    void pop(){
        if(isEmpty){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        else{
            top--;
        }
    }
    
    bool isFull(){
        return top>=MAX_SIZE-1;
    }
    
    bool isEmpty(){
        return top==-1;
    }
    
    int Peek(){
        if(top!=-1){
            retur stack[top];
        }
        else{
            return -1;
        }
    }
};

class Queue{
    private:
    int* queue;
    int front;
    int rear;
    int capacity;
    public:
    Queue(int c){
        queue=new int[c];
        front=rear=-1;
        capacity=c;
    }
    ~Queue(){
        delete [] queue;
    }
    
    void Enqueue(int d){
        if(isFull){
            cout<<"Queue is full"<<endl;
        }
        else{
            if(front==-1){
                front++;
                rear++;
                queue[rear]=d;
            }
            else{
                rear++;
                queue[rear]=data;
            }
        }
    }
    
    void Dequeue(){
        if(isEmpty){
            cout<<"Queue is empty"<<endl;
        }
        else if(front==rear){
            front = rear = -1;
        }
        else{
            front++;
        }
    }
    
    bool isFull(){
        if(rear==capacity-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

bool hasDulicateParenthesis(string ex){
    
}

bool isBalancedExp(string exp) {
   stack<char> stk;
   char x;
   for (int i=0; i<exp.length(); i++) {
      if (exp[i]=='('||exp[i]=='['||exp[i]=='{') {
         stk.push(exp[i]);
         continue;
      }
      if (stk.empty())
         return false;
      switch (exp[i]) {
      case ')':
         x = stk.top();
         stk.pop();
         if (x=='{' || x=='[')
            return false;
         break;
case '}':
         x = stk.top();
         stk.pop();
         if (x=='(' || x=='[')
            return false;
         break;
      case ']':
         x = stk.top();
         stk.pop();
         if (x =='(' || x == '{')
            return false;
         break;
      }
   }
   return (stk.empty());
}

bool isBalanced(string x){
    stack<char> stk;
    
    for(char ch: x){
        if(ch=='(' || ch=='{' || ch=='['){
            stk.push(ch);
        }
        
    }
}

int main()
{
    cout<<"Hello World";

    return 0;
}