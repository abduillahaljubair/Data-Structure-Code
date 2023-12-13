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

}
int main()
{
    node *p,*q,*r,*s;
    p=(struct node*)malloc(sizeof(node));
    q=(struct node*)malloc(sizeof(node));
    r=(struct node*)malloc(sizeof(node));
    s=(struct node*)malloc(sizeof(node));
    p->data=10;
    q->data=15;
    r->data=20;
    s->data=25;
    root=p;
    p->next=q;
    q->next=r;
    r->next=s;
    s->next=NULL;
    printing();
    Searching(10);
    FirstPrint();
    lastPrint();
    sceondlastPrint();
    reverseprint(root);
}