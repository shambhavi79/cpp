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
        next=NULL;
    }
    Node(int k, int d){
        key=k;
        data=d;
    }
};

class CircularLinkedList{
    public:
    Node* head;
    
    CircularLinkedList(){
        head=NULL;
    }
    
    Node* nodeExists(int k){
        Node* temp=NULL;
        Node* ptr=head;
        
        if(ptr==NULL){
            return temp;
        }
        else{
            do{
                if(ptr->key==k){
                    temp=ptr;
                }
                ptr=ptr->next;
            }while(ptr!=head);
            return temp;
        }
    }
    
    void appendNode(Node* n){
        if(nodeExists(n->key)!=NULL){
            cout<<"Node already exists"<<endl;
        }
        else{
            if(head==NULL){
                head=n;
                n->next=head;
                cout<<"Node appended at head position"<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
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
                n->next=head;
                cout<<"Node prepended at head position"<<endl;
            }
            else{
                Node*ptr=head;
                while(ptr->next!=head){
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
                head=n;
                cout<<"Node prepended"<<endl;
            }
        }
    }
    
    void insertNodeAfter(int k, Node* n){
        Node* ptr= nodeExists(k);
        if(ptr==NULL){
            cout<<"No node exists with given key value"<<endl;
        }
        else{
            if(nodeExists(n->key)!=NULL){
                cout<<"Node already in the list."<<endl;
            }
            else{
                if(ptr->next==head){
                    n->next=head;
                    ptr->next=n;
                    cout<<"Node inserted at the end"<<endl;
                }
                else{
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"Node inserted in between"<<endl;
                } 
            }
        }
        
    }
    
    void deleteByKey(int k){
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"Node with the given key value does not exist"<<endl;
        }
        else{
            if(ptr==head){
                if(head->next==NULL){
                    head=NULL;
                    cout<<"Node unlinked. List empty"<<endl;
                }
                else{
                    Node* ptr1=head;
                    while(ptr1->next!=head){
                        ptr1=ptr1->next;
                    }
                    ptr1->next=head->next;
                    head=head->next;
                    cout<<"Node unlinked from head position"<<endl;
                }
                
            }
            else{
                Node* temp=NULL;
                Node* prev=head;
                Node* curr=head->next;
                while(curr!=NULL){
                    if(curr->key==k){
                        temp=curr;
                        curr=NULL;
                    }
                    else{
                        prev=prev->next;
                        curr=curr->next;
                    }
                }
                prev->next=temp->next;
                cout<<"Node unlinked from between"<<endl;
            }
        }
    }
    
    void updateByKey(int k, int d){
        Node* ptr=nodeExists(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node updated"<<endl;
        }
        else{
            cout<<"Node with given key not found"<<endl;
        }
    }
    
    void printList(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
        }
        else{
            cout<<"The Circular Linked List is: "<<endl;
            Node* temp=head;
            do{
                cout<<"("<<temp->key<<", "<<temp->data<<")-->";
                temp=temp->next;
            }while(temp!=head);
            cout<<endl;
        }
    }
};

int main()
{
    Node n1(1, 10);
    Node n2(2, 20);
    Node n3(3, 30);
    Node n4(4, 40);
    CircularLinkedList c;
    c.appendNode(&n1);
    c.appendNode(&n2);
    c.appendNode(&n3);
    c.printList();
    c.insertNodeAfter(3, &n4);
    c.printList();
    c.deleteByKey(1);
    c.printList();
    c.prependNode(&n1);
    c.printList();
    c.updateByKey(3, 33);
    c.printList();
    

    return 0;
}

