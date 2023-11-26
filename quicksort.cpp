#include<bits/stdc++.h>
using namespace std;
vector<int>a(10);
int partition(int low,int high)
{
int i=low;
int j=high;
int pivot=a[low];
while(i<j)
{ 
    while(a[i]<=pivot)
     {
         i++;
     }  
    while(a[i]>pivot)
     {
      j++;
     }


    if(i<j)
     {
     swap(a[i],a[j]);
     }
}
 swap(a[low],a[j]);
return j;
}
void quicksort(int low,int high)
{
    if(low<high)
    {
        int j=partition(low,high);
        partition(low,j-1);
        partition(j+1,high);

    }
}
int main()
{
    vector<int>c;
    int ele,n;
    cout<<"enter total element";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        c.push_back(ele);
    }
    quicksort(0,n-1);

     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }



}