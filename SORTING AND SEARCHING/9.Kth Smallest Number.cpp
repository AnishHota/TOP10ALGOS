// KTH SMALLEST NUMBER IN AN ARRAY
#include<iostream>
#include<limits.h>
#include<math.h>
using namespace std;
int partition(int arr[],int l,int r)
{
  int pivot = arr[r];
  int i,j=l;
  for(i=l;i<r;i++)
  {
    if(arr[i]<=pivot)
    {
      swap(arr[i],arr[j]);
      j++;
    }
  }
  swap(arr[j],arr[r]);
  return j;
}
int randompartition(int arr[],int l,int r)
{
  int n = r-l+1;
  int pivotindex = rand()%n;
  swap(arr[pivotindex+l],arr[r]);
  return partition(arr,l,r);
}
int kthsmallest(int arr[],int k,int l,int r)
{
  if(k>0 && k<=r-l+1)
  {
    int pos = randompartition(arr,l,r);
    if(pos-l == k-1)
      return arr[pos];
    if(pos-l > k-1)
    {
      return kthsmallest(arr,k,l,pos-1);
    }
    else
      return kthsmallest(arr,k-pos+l-1,pos+1,r);
  }
  return INT_MAX;
}
int main()
  {
  int data;
  int arr[] = {12,24,36,44,56,89};
  int n = sizeof(arr)/sizeof(arr[0]);
  cin>>data;
  int index = kthsmallest(arr,data,0,n-1);
  cout<<index<<endl;
}
