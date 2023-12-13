#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
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
    p->next=q;
    q->next=r;
    r->next=s;
    s->next=NULL;
    cout<<p->data<<" ";
    cout<<p->next->data<<" ";
    cout<<p->next->next->data<<" ";
    cout<<p->next->next->next->data<<" ";
}