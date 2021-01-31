#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(){

        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

//Initialising
Node *head = NULL;
Node *tail = NULL;


void insertFront(int data){
    Node *node = new Node(data);
    if(head==NULL){
        head=node;
        tail=node;
    }
    else{
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
    }

}
void insertBack(int data){
    Node *node = new Node(data);
    if(tail==NULL){
        head=node;
        tail=node;
    }
    else{
        tail->next = node;
        node->prev = tail;
        tail = node;

    }
}
void insertAfter(int ele,int data){
    Node *t = head;


        while((t!=NULL)&&(t->data!=ele)){
            t=t->next;
        }
        if(t!=NULL){
            Node *node = new Node(data);
            if(head==tail){
                head->next=node;
                node->prev=head;
                tail=node;
            }
            else if(ele==(tail->data)){
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
            else{

                (t->next)->prev = node;
                node->next = (t->next);
                t->next = node;
                node->prev = t;
            }

        }
        else{
            if(head==NULL){
                cout<<"List is empty."<<endl;
            }
            else
                cout<<"Element not present."<<endl;
        }


}
void deleteEle(int ele){
    Node *t = head;
    while(t->data!=ele){
        t=t->next;
    }



    while((t!=NULL)&&(t->data!=ele)){
            t=t->next;
        }
        if(t!=NULL){
            Node *node = new Node(data);
            if(head==tail){
                head=NULL;
                tail=NULL;
                delete t;
            }
            else if(ele==(tail->data)){
                tail->next=node;
                node->prev=tail;
                tail=node;
            }
            else{

                Node *del = t;
                (t->prev)->next=t->next;
                (t->next)->prev=(t->prev);
                cout<<del->data<<" is successfully deleted."<<endl;
                delete del;
            }

        }
        else{
            if(head==NULL){
                cout<<"List is empty."<<endl;
            }
            else
                cout<<"Element not present."<<endl;
        }
}
void display(){
    Node *t = head;
    cout<<"NULL<=>";
    while(t!=NULL){
        cout<<t->data<<"<=>";
        t=t->next;
    }
    cout<<"NULL";
}
int main(){
    //Insertion at front
    insertAfter(10,900);
    insertFront(10);
    insertAfter(10,900);
    insertFront(20);
    insertFront(30);

    insertBack(40);
    insertBack(50);
    insertBack(60);
    insertBack(70);
    insertAfter(40,90);
    insertAfter(70,77);
    deleteEle(40);
    display();

}
