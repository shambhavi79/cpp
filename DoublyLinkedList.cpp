#include <iostream>

using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(){
        key=0;
        data=0;
        next= NULL;
        prev= NULL;
    }
    Node(int k, int d){
        key=k;
        data=d;
        next= NULL;
        prev= NULL;
        
    }
};
class DoublyLinkedList{
    public:
    Node* head;
    
    DoublyLinkedList(){
        head=NULL;
    }
    DoublyLinkedList(Node *n){
        head=n;
    }
    
    Node* nodeExists(int k){
        Node* temp=NULL;
        Node* ptr=head;
        while(ptr!=NULL){
            if(ptr->key==k){
                temp=ptr;
                break;
            }
            ptr=ptr->next;
        }
        return temp;
    }
    
    void appendNode(Node* n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists"<<endl;
        }
        else{
            if(head==NULL){
                head=n;
                cout<<"Node apppended as head node"<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node appended"<<endl;
            }
        }
    }
    
    void prependNode(Node* n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists"<<endl;
        }
        else{
            if(head==NULL){
                head=n;
            }
            else{
                head->prev=n;
                n->next=head;
                head=n;
                cout<<"Node prepended"<<endl;
            }
        }
    }
    
    void insertNodeAfter(int k, Node* n){
        Node* ptr= nodeExists(k);
        if(ptr==NULL){
            cout<<"No node exists with this key value"<<endl;
        }
        else{
            if(nodeExists(n->key)!=NULL){
                cout<<"Node already exists"<<endl;
            }
            else{
                Node *nextNode= ptr->next;
                if(nextNode==NULL){
                    ptr->next=n;
                    n->prev=ptr;
                    cout<<"Node inseted at the end of the list"<<endl;
                }
                else{
                    n->next=nextNode;
                    nextNode->prev=n;
                    n->prev=ptr;
                    ptr->next=n;
                }
            }
        }
    }
    
    void deleteNode(int k){
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"No node exists with this key value"<<endl;
        }
        else{
            if(head->key==k){
                head=head->next;
                cout<<"Node unlinked at head"<<endl;
            }
            else{
                Node *nextNode= ptr->next;
                Node *prevNode= ptr->prev;
                if(nextNode==NULL){
                    prevNode->next=NULL;
                    cout<<"Node unlinked at end"<<endl;
                }
                else{
                    prevNode->next=nextNode;
                    nextNode->prev=prevNode;
                    cout<<"Node unlinked in between"<<endl;
                }
                
            }
            
        }
    }
    
    void updateNode(int k, int d){
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"Node with key value does not exist"<<endl;
        }
        else{
            ptr->data=d;
            cout<<"Node updated sucessfully"<<endl;
        }
        
    }
    
    void printList(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            Node* temp=head;
            while(temp!=NULL){
                cout<<"("<<temp->key<<", "<<temp->data<<") <-->";
                temp=temp->next;
            }
        }
    }
};

int main()
{
    Node* n1= new Node;
    n1->key=1;
    n1->data=10;
    
    Node* n2= new Node;
    n2->key=2;
    n2->data=20;
    
    Node* n3= new Node;
    n3->key=3;
    n3->data=30;
    
    Node* n4= new Node;
    n4->key=4;
    n4->data=40;
    
    Node* n5= new Node;
    n5->key=5;
    n5->data=50;
    
    DoublyLinkedList d;
     d.appendNode(n1);
     d.appendNode(n2);
     d.printList();
     d.appendNode(n3);
     d.appendNode(n4);
     d.printList();
     d.appendNode(n5);
     d.printList();
     d.deleteNode(1);
     d.deleteNode(4);
     d.printList();
     d.prependNode(n1);
     d.insertNodeAfter(3, n4);
     d.printList();
     d.updateNode(3, 33);
     d.printList();

    return 0;
}
