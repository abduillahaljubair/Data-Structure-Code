#include<bits/stdc++.h>
using namespace std;
vector<int>a;
void SelectionSort(int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size-1;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        swap(a[i],a[min]);
    }
    cout<<"Arter sorting : ";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    int n;
    int element;
    cout<<"Enter Your array size"<<" :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        a.push_back(element);
    }
    SelectionSort(n);
}
