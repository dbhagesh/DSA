#include<bits/stdc++.h>
//keep head on the left always
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(){
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
Node *head =NULL;
void pushNode(int data){


    Node *node =new Node(data);
    if(head==NULL)
        head=node;
    else{
        node->next=head;
        head=node;
    }

}
void insertAfter(int pos, int data){

    Node *t = head;
    while(pos-- >1){
        t=t->next;
    }
    Node *node = new Node(data);
    node->next=t->next;
    t->next=node;

}

void deleteNode(int data){
    Node *t =head;
    if((t->data)==data){
        head=t->next;
        delete t;
    }
    else{
        while((t->next!=NULL)&&((t->next)->data!=data)){
            t=t->next;
        }
        if(t->next!=NULL){
            Node *del = (t->next);
            t->next=(t->next)->next;
            cout<<del->data<<" "<<"Deleted successfully"<<endl;
            delete del;
        }
        else
            cout<<"Element not present."<<endl;

    }

}

void revList(){
    Node *prev=NULL,*cur=head,*next=NULL;

    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;

        prev=cur;
        cur=next;
        //next=next->next;

    }
    head=prev;
    //cout<<head->data;
}
void printList(){
    Node *t = head;
    while(t!=NULL){
        cout<<(t->data)<<" ";
        t=t->next;
    }
}
int main(){
    int n;
    cout<<"Number of insertions: ";
    cin>>n;
    while(n--)
    {   int inp;
        cout<<"Enter number to insert: ";
        cin>>inp;
        pushNode(inp);
    }
    int pos,inp;

    cout<<"Enter pos to insert value at: ";
    cin>>pos;
    cout<<"Enter value to insert: ";
    cin>>inp;
    insertAfter(pos,inp);

    cout<<"Enter element to delete: ";
    cin>>inp;
    deleteNode(inp);
    cout<<"List: ";
    printList();
    revList();
    cout<<endl;
    cout<<"Reversed List: ";
    printList();


}
