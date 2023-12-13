#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *root=NULL;
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
/*void Searching(int value)
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        if(curr_node->data==value)
        {
            cout<<value<<" has founded "<<endl;
            break;
        }
        else
        {
            cout<<"NOT FOUND"<<endl;

        }
        curr_node=curr_node->next;
    }
    cout<<"Searched"<<endl<<endl;
}
void FirstPrint()
{
    node *curr_node=root;
    cout<<curr_node->data<<endl<<"1stvalueprinted";
    cout<<endl<<endl;
    
}
void lastPrint()
{
    node *curr_node=root;
    while(curr_node!=NULL)
    {
        curr_node=curr_node->next;
        if(curr_node->next==NULL)
        break;
    }
    cout<<curr_node->data<<endl;
    cout<<"last value printed"<<endl<<endl;
}
void sceondlastPrint()
{
    node *curr_node=root;
    node *prev_node=NULL;
    while(curr_node!=NULL)
    {
        prev_node=curr_node;
        curr_node=curr_node->next;
        if(curr_node->next==NULL)
        break;
    }
    cout<<prev_node->data<<endl;
    cout<<"2ndlast value printed"<<endl<<endl;
}
void reverseprint(node *curr_node)
{
    if(curr_node==NULL)
    {
    cout<<"Reversed"<<endl<<endl;
    return;
    }
    reverseprint(curr_node->next);
    cout<<curr_node->data<<endl;

}*/
void insert_first(int val)
{
    node *temp;
    temp=(struct node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=root;
    root=temp;

}
void deletefirst()                                                    //node *curr_node=root;//root=curr_node->next;
{
    node *curr_node=root;
    if(curr_node!=NULL)
    {
        root=curr_node->next;
    }
}
void insertlast(int val)
{
    node *curr_node=root;
    node *temp;
    temp=(struct node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    while (curr_node->next!=NULL)
    {
        curr_node=curr_node->next;
    }
    curr_node->next=temp;
  
}
void deletelast()
{
    node *curr_node=root;
    node *prev_node=NULL;
    while(curr_node->next!=NULL)
    {
        prev_node=curr_node;
        curr_node=curr_node->next;
        if(curr_node->next==NULL)
        break;
    }
    prev_node->next=NULL;
}
void deleteanywhere(int val)
{
    node *curr_node=root;
    node *prev_node=NULL;

    while(curr_node!=NULL)
    {
        if(curr_node->data==val)
        {
            if (prev_node==NULL)
            {
             deletefirst();
            }
            else
            {
                prev_node->next=curr_node->next;
            }
            break;
        }

        prev_node=curr_node;
        curr_node=curr_node->next;
    }
}
void insertanywhere(int val,int pos)
{
    node *curr_node=root;
    node *prev_node=NULL;
    node *temp;
    temp=(struct node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        return;
    }
    temp->data=val;
    int position=0;
    while(curr_node!=NULL&&position<pos)
    {
        prev_node=curr_node;
        curr_node=curr_node->next;
        position++;
    }
    if(prev_node==NULL)
    {
        temp->next=root;
        root=temp;
    }
    else
    {
        prev_node->next=temp;
        temp->next=curr_node;
    }
}
int main()
{
    node *p,*q,*r,*s;
    insert_first(10);
    printing();
    insert_first(15);
    printing();
    insert_first(20);
    printing();
    insert_first(25);
    printing();
    deletefirst();
    printing();
    deletefirst();
    printing();
    insertlast(35);
    printing();
    insertlast(45);
    printing();
    deletelast();
    printing();
    deleteanywhere(10);
    printing();
    insertanywhere(12,1);
    printing();
}