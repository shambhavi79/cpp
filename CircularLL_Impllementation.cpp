#include <iostream>

using namespace std;

class Node{
    int data;
    Node* next;
    
    Node(int d){
        data = d;
        next= NULL;
    }
};

void insetNodeAtHead(Node* &tail, int d){
    if(tail==NULL){
        tail=new Node(d);
        tail->next=tail;
    }
    else{
        Node* n=new Node(d);
        n->next= tail->next;
        tail->next=n;
    }
}

void insetNodeAtTail(Node* &tail, int d){
    if(tail==NULL){
        tail=new Node(d);
        tail->next=tail;
    }
    else{
        Node* n=new Node(d);
        n->next= tail->next;
        tail->next=n;
        tail=n;
    }
}

void insertAtMiddle(Node* &tail, int d, int after){
    if(tail==NULL){
        tail=new Node(d);
        tail->next=tail;
    }
    else{
        Node* temp= tail->next;
        do{
            if(temp->data==after){
                Node* n= new Node(d);
                n->next=temp->next;
                temp->next=n;
                
                if(temp==tail){
                    tail=n;
                    
                    return;
                }
            }temp=temp->next;
        }while(temp!=tail->next);
    }
}


void deleteAfter(Node* &tail, int after){
    if(tail==NULL){
        return;
    }
    else{
        Node* temp=tail->next();
        do{
            if(temp->data==after){
                Node* n=temp->next;
                temp->next=n->next;
                if(n==tail){
                    tail=temp;
                }
                delete n;
            }
            temp=temp->next;
        }while(temp!=tail->next);
    }
}

bool find(Node* tail, int d){
    if(tail==NULL){
        return false;
    }
    Node* temp= tail->next;
    do{
        if(temp->data==d){
            return true;
        }
        temp=temp->next;
    }while(temp!=tail->next);
    return false;
}

void reverse(Node* &head){
    // Start here
}
int main()
{
    cout<<"Hello World";

    return 0;
}