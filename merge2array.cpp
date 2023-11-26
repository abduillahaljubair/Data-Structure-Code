#include<bits/stdc++.h>
using namespace std;
vector<int>c(10);
void Merge(vector<int>l,vector<int>r)
{
    int m=l.size();
    int n=r.size();
    l.push_back(99999999);
    r.push_back(99999999);
    int i=0,j=0,k=0;
    for( k=0;k<=(m+n)-1;k++)
    {
        if(l[i]<=r[j]){
      
      c[k]=l[i];
       i++;
        }
       else if(l[i]>=r[j]){
        c[k]=r[j];
        j++;
       }

    }
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i]<<" ";

    }
}
int main()
{
    vector<int>a;
    vector<int>b;
    int ele,ele2;
    int size1,size2;
    cout<<"enter total element for f1 : ";
    cin>>size1;
    for(int i=0;i<size1;i++)
    {
        cin>>ele;
        a.push_back(ele);

    }
    cout<<"enter total element for f2 : ";
    cin>>size2;
      for(int i=0;i<size2;i++)
    {
        cin>>ele2;
        b.push_back(ele2);

    }
    Merge(a,b);




}