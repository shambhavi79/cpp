#include <iostream>

using namespace std;
class Stack{
    
    private:
    int top;
    int arr[5];
    
    public:
    Stack(){
        top=-1;
    }
    
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
    
    bool isFull(){
        if(top==4)
            return true;
        else
            return false;
    }
    
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=x;
        }
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            int popValue = arr[top];
            arr[top]=0;
            top--;
            return popValue;
        }
    }
    
    int count(){
        return(top+1);
    }
    
    int peek(int position){
       if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            return arr[position];
        }
    }
    void display(){
        cout<<"All values in display are"<<endl;
        for(int i=4; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s1;
    int option, position, value;
    do{
        cout<<"What operation do you want to perform? Select option number. Enter 0 to exit"<<endl;
        cout<<"1. Push()"<<endl;
        cout<<"2. Pop()"<<endl;
        cout<<"3. isEmpty()"<<endl;
        cout<<"4. isFull()"<<endl;
        cout<<"5. peek()"<<endl;
        cout<<"6. count()"<<endl;
        cout<<"7. display()"<<endl;
        cin>>option;
        switch(option)
        {
            case 0:
                break;
            case 1:
                cout<<"Enter an item to push in the stack"<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<"Popped Value: "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty()){
                    cout<<"Stack is Empty"<<endl;
                }
                else{
                    cout<<"Stack is not empty"<<endl;
                }
                break;
            case 4:
                if(s1.isFull()){
                    cout<<"Stack is Full"<<endl;
                }
                else{
                    cout<<"Stack is not Full"<<endl;
                }
                break;
            case 5:
               cout<<"Enter position of item you want to peek: "<<endl;
               cin>>position;
               cout<<"Value at the position: "<<s1.peek(position)<<endl;
               break;
            case 6:
               cout<<"Number of items in stack are: "<<s1.count()<<endl;
               break;
            case 7:
               s1.display();
               break;
            default:
               cout<<"Enter proper option number "<<endl;
        }
        
    }while(option!=0);

    return 0;
}
