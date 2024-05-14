#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
 int b[3][3]={{1,2,3},{4,5,6},{7,8,9}};

 vector<vector<int>>c(3,vector<int>(3,0));//1st er 3 mani 3ta row ba sari//2nd 3 ta holo 3 ta column ar sobgula index  0 diye defined kora 

 for(int i=0;i<3;i++)
 {
    for(int j=0;j<3;j++)
    {
        for(int k=0;k<3;k++)
        {
            c[i][j]+=a[i][k]*b[k][j];
        }
    }
 }
  for(int i=0;i<3;i++)
 {
    for(int j=0;j<3;j++)
    {
        cout<<c[i][j]<<" ";
    }
    cout<<endl;

 }
}