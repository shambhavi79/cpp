#include <iostream>

using namespace std;

class Node{
    int data;
    Node* prev;
    Node* next;
    
    Node(int d){
        data = d;
        next= NULL;
    }
};

void insertAtBeginning(Node* &head, int d){
    if(head==NULL){
        head= new Node(d);
        return;
    }
    Node* n= new Node(d);
    n->next=head;
    head->prev=n;
    head=n;
}

void insetAfter(Node* &head, int d, int after){
    if(head==NULL){
        head=new Node(d);
        return;
    }
    else{
        Node* temp=head;
        while(temp->data!=after){
            temp=temp->next;
        }
        Node* n=new Node(d);
        n->next=temp->next;
        n->prev=temp;
        temp->next=n;
        if(n->next!=NULL){
            n->next->prev=n;
        }
    }
}

void insertAtEnd(Node* &head, int d){
    if(head==NULL){
        head= new Node(d);
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* n=new Node(d);
    temp->next=n;
    n->prev=temp;
}

void deleteAfter(Node* &head, int after){
    if(head==NULL){
        return;
    }
    Node* temp=head;
    while(temp->data!=after){
        temp=temp->next;
    }
    Node* n=temp->next;
    temp->next=n->next;
    if(n->next!=NULL){
        n->next->prev=temp;
    }
    delete n;
}