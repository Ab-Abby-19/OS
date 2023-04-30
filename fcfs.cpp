#include<iostream>
using namespace std;

int main ()
{
int n, pid[10], at[10], bt[10], wt[10], ct[10],i,j,temp;
cout<<"Enter number of processes: ";
cin>>n;
cout<<endl;
for (i=0;i<n;i++)
{
    cout<<"Enter "<<i+1<<" process id : ";
    cin>>pid[i];
    cout<<"Enter "<<i+1<<" arrival time : ";
    cin>>at[i];
    cout<<"Enter "<<i+1<<" burst time : ";
    cin>>bt[i];
}
cout<<"\n Question";
cout<<"\nP\t\t AT\t BT\t "<<endl;
for(i=0;i<n;i++)
{
    cout<<"P"<<i+1<<"\t\t"<<at[i]<<"\t"<<bt[i]<<endl;
}
cout<<endl;
// sorting at,bt,pid according to at
for (i=0;i<n;i++)
{
    for (j=0;j<(n-i);j++)
    {
        if(at[j]>at[j+1])
        {
             temp=pid[j+1];
             pid[j+1]=pid[j];
             pid[j]=temp;
             temp=at[j+1];
             at[j+1]=at[j];
             at[j]=temp;
             temp=bt[j+1];
             bt[j+1]=bt[j];
             bt[j]=temp;
        }
    }
}
// calculating completion time
ct[0]=at[0]+bt[0];
for (i=1;i<n;i++)
{
    temp=0;
    if(ct[i-1]<at[i])
    {
        temp=at[i]=ct[i-1];
    }
    ct[i]=ct[i-1]+bt[i]+temp;
}

// calculating wt

for(i=0;i<n;i++)
{
wt[i]=ct[i]-at[i]-bt[i];
}

// print the table
cout<<"Solution \n";
cout<<"P\t\tAT\tBT\tCT\tWT\t"<<endl;
for (i=0;i<n;i++)
{
    cout<<"P"<<pid[i]<<"\t\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<endl;
}
}
