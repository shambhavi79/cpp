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

void insertAtHead(Node* &head, int d){
    if(head==NULL){
        head = new Node(d);
        return
    }
    Node* n= new Node(d);
    n->next=head;
    head=n;
}

void insertAtEnd(Node* &head, int d){
    if(head==NULL){
        head= new Node(d);
        return;
    }
    Node* temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    
    temp->next=new Node(d);
    return;
}

int lengthofLL(Node* head){
    if(head==NULL){
        return 0;
    }
    Node* temp=head;
    int length =0;
    while(temp->next!=NULL){
        temp= temp->next;
        length++;
    }
    return length;
}

void insertAtMiddle(Node* &head, int d, int pos){
    if(pos==0){
        insertAtHead(head, d);
    }
    else if(pos>lengthofLL(head)){
        insertAtEnd(head, d);
    }
    else{
        Node* temp=head;
        int jump=pos-2;
        while(jump!=0){
            temp=tem->next;
            jump--;
        }
        Node* n= new Node(d);
        n->next= temp->next;
        temp->next=n;
    }
}

void deleteAtHead(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp=head->next;
    delete head;
    head= temp;
}

void deleteAtEnd(Node* &head){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* n= temp->next;
    temp->next= NULL;
    delete n;
}

void deleteInMiddle(Node* &head, int pos){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    int jump=pos-2;
    while(jump>0){
        temp=temp->next;
        jump--;
    }
    Node* n= temp->next;
    temp->next= n->next;
    delete n;
    
}

int findUnique3(int arr[], int n){
    int res=0;
    int sum;
    for(int i=0; i<size; i++){
        sum=0;
        int x= i<<1;
        for(int j=0; j<n; j++){
            if(arr[j]&x){
                sum++;
            }
            if(sum%3!=0){
                res= res|x;
            }
        }
    }
}

int main()
{
    cout<<"Hello World";

    return 0;
}