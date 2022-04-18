#include <iostream>

using namespace std;
class CircularQueue{
    private:
    int front;
    int rear;
    int arr[5];
    int itemCount;
    public:
    CircularQueue(){
        itemCount=0;
        front =-1;
        rear=-1;
        for(int i=0; i<5; i++){
            arr[i]=0;
        }
    }
    bool isEmpty(){
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    bool isFull(){
        if((rear+1)%5==front)
        return true;
        else
        return false;
    }
    void Enqueue(int val){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
            return ;
        }
        else if(isEmpty()){
            rear = 0;
            front = 0;
            arr[rear]=val;
        }
        else{
            rear= (rear+1)%5;
            arr[rear]=val;
        }
        itemCount++;
    }
    int Dequeue(){
        int x;
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return 0;
        }
        else if(front == rear){
            x=arr[rear];
            arr[front]=0;
            rear=-1;
            front=-1;
            itemCount--;
            return x;
        }
        else{
            x=arr[front];
            arr[front]=0;
            front=(front+1)%5;
            itemCount--;
            return x;
        }
    }
    int Count(){
        return itemCount;
    }
    void Display(){
        cout<<"All values in the queue are"<<endl;
        for(int i=0; i<5; i++){
            cout<<arr[i]<<endl;
        }
    }
    
    
};

int main()
{
    CircularQueue q1;
    int option, value;
    do{
        cout<<"Which operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. isFull"<<endl;
        cout<<"4. isEmpty"<<endl;
        cout<<"5. Count"<<endl;
        cout<<"6. Display"<<endl;
        cin>>option;
        switch(option){
            case 0:
            break;
            
            case 1:
            cout<<"Enter value to enqueue"<<endl;
            cin>>value;
            q1.Enqueue(value);
            break;
            
            case 2:
            cout<<"The value from dequeue is "<<q1.Dequeue()<<endl;
            break;
            
            case 3:
            if(q1.isFull())
            cout<<"Queue is full"<<endl;
            else
            cout<<"Queue is not full"<<endl;
            break;
            
            case 4:
            if(q1.isEmpty())
            cout<<"Queue is empty"<<endl;
            else
            cout<<"Queue is not empty"<<endl;
            break;
            
            case 5:
            cout<<"The count of the queue is "<<q1.Count()<<endl;
            break;
            
            case 6:
            q1.Display();
            break;
            
            default:
            cout<<"Please enter a valid option number"<<endl;
            break;
        }
    }while(option!=0);

    return 0;
}