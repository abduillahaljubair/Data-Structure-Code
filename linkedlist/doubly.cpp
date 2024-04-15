#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *root=NULL;
node *tail=NULL;
void rev_printing()
{
    node *curr_node=tail;
    while(true)
    {
        cout<<curr_node->data<<endl;
        curr_node=curr_node->prev;
        if(curr_node==NULL)
        break;
    }
    cout<<"all value are printed"<<endl<<endl;
}
void printing()
{
    node *curr_node=root;
    while(true)
    {
        cout<<curr_node->data<<endl;
        curr_node=curr_node->next;
        if(curr_node==NULL)
        break;
    }
    cout<<"all value are printed"<<endl<<endl;
}
void Searching(int value)
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        if(curr_node->data==value)
        {
            cout<<value<<" has founded "<<endl;
            break;
        }
        //curr_node=curr_node->next;
        curr_node=curr_node->next;
    }
    cout<<"Searched"<<endl<<endl;
}
int list_Size()
{
    node *current_node = root;
    int count = 0;

    while (current_node != NULL)
    {
        count++;
        current_node = current_node->next;
    }
    return count;
}
void deletelast()
{
    tail=tail->prev;
    tail->next=NULL;
}
void deletefirst()
{
    root=root->next;
    root->prev=NULL;
}
void last_node()
{

    cout<<"last node="<<tail->data<<endl;
}
void prev_last_node()
{

    cout<<"previous last node="<<tail->prev->data<<endl;
}
void insertlast(int val)
{
    node *temp;
    temp=new node();
    node *curr_node=root;
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    while (curr_node!=NULL)
    {
        if(curr_node->next==NULL)
        {
            temp->prev=curr_node;
            curr_node->next=temp;
            temp->next=NULL;
          
        }
        else 
        curr_node=curr_node->next;

    }
}
void firstinsert(int val)
{
     node *temp;
    temp=new node();
    temp->data=val;
    temp->next=NULL;
    temp->prev=tail;
    if(root==NULL)
    {
        root=temp;
    }
    if(tail==NULL)
    {

        tail=temp;
    }
    else
        temp->next=root;
    root->prev=temp;
    root=temp;


}
void insertanywhere(int val,int pos)
{
     node *curr_node=root;
     node *temp;
     temp=new node();
     int position=0;
     temp->data=val;
     if(temp==NULL)
    {
        return;
    }
    while(curr_node!=NULL&&position<=pos)
    {
        curr_node=curr_node->next;
        position++;
    }
    temp->next=curr_node->next;
    curr_node->next=temp;
    temp->prev=curr_node;
    
}
int main()
{
insertlast(10);
insertlast(15);
insertlast(20);
insertlast(25);
insertlast(30);
printing();
rev_printing();
printing();
rev_printing();
deletelast();
printing();
deletefirst();
printing();
insertanywhere(12,3);
printing();


}