#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;
    Node(){
        key=0;
        data=0;
        next= NULL;
    }
    Node(int k, int d){
        key=k;
        data=d;
    }
};

class SinglyLinkedList{
    public:
    Node* head;
    
    SinglyLinkedList(){
        head=NULL;
    }
    
    SinglyLinkedList(Node *n){
        head= n;
    }
    
    Node* nodeExist(int k){
        
        Node* temp= NULL;
        Node* ptr= head;
        
        while(ptr!=NULL){
            if(ptr->key==k){
                temp=ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }
    
    void appendNode(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout<<"Node already exists;"<<endl;
        }
        else{
            if(head==NULL){
                head = n;
                cout<<"Node appended"<<endl;
            }
            else{
                Node* ptr= head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node appended"<<endl;
            }
        }
    }
    
    void prependNode(Node *n){
        if(nodeExist(n->key)!=NULL){
            cout<<"Node already exists;"<<endl;
        }
        else{
            n->next= head;
            head=n;
            cout<<"Node prepended"<<endl;
        }
    }
    void insertNodeAfter(int k, Node *n){
        Node* ptr= nodeExist(k);
       if(nodeExist(n->key)!=NULL){
            cout<<"Node already exists;"<<endl;
        } 
        else{
            if(nodeExist(n->key)!=NULL){
                cout<<"Node already exists with key value"<<n->key<<"Input a node with different key value"<<endl;
            }
            else{
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node inserted"<<endl;
            }
        }
    }
    void deleteByKey(int k){
        if(head==NULL){
            cout<<"Singly Linked List already empty"<<endl;
        }
        else{
            if(head->key==k){
                head=head->next;
                cout<<"Node unlinked with key value: "<<k<<endl;
            }
            else{
                Node* temp= NULL;
                Node* prevptr=head;
                Node* currptr= head->next;
                while(currptr!=NULL){
                    if(currptr->key==k){
                        temp=currptr;
                        currptr=NULL;
                    }
                    else{
                        currptr=currptr->next;
                        prevptr=prevptr->next;
                    }
                }
                if(temp!=NULL){
                    prevptr->next=temp->next;
                    cout<<"Node unlinked with key value: "<<k<<endl;
                }
                else{
                    cout<<"Node does not exist"<<endl;
                }
            }
        }
    }
    void updateNodeKey(int k, int d){
        Node* ptr= nodeExist(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node updated sucessfully"<<endl;
        }
        else{
            cout<<"Node with key value does not exist"<<endl;
        }
    }
    void printList(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            cout<<"Singly Linked List values are: "<<endl;
            Node* temp=head;
            while(temp!=NULL){
                cout<<"("<<temp->key<<", "<<temp->data<<") -->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    SinglyLinkedList s;
    Node* n1= new Node;
    Node* n2= new Node;
    Node* n3= new Node;
    Node* n4= new Node;
    Node* n5= new Node;
    n1->key=1;
    n1->data=10;
    n2->key=2;
    n2->data=20;
    n3->key=3;
    n3->data=30;
    n4->key=4;
    n4->data=40;
    n5->key=5;
    n5->data=50;
    s.appendNode(n1);
    s.appendNode(n2);
    s.printList();
    s.insertNodeAfter(2, n3);
    s.printList();
    s.deleteByKey(1);
    s.printList();
    s.prependNode(n1);
    s.printList();
    s.appendNode(n4);
    s.appendNode(n5);
    s.printList();
    s.updateNodeKey(3,33);
    s.printList();

    return 0;
}