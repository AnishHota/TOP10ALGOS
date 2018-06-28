// MERGE SORT
#include<iostream>
using namespace std;
void merge(int arr[],int f,int m,int l)
{
  int i,j,k;
  int n1 = m-f+1;
  int n2 = l-m;
  int left[n1];
  int right[n2];
  for(i=0;i<n1;i++)
  {
    left[i] = arr[f+i];
  }
  for(j=0;j<n2;j++)
  {
    right[j] = arr[m+1+j];
  }
  i=0;j=0;k=f;
  while(i<n1 && j<n2)
  {
    if(left[i]<=right[j])
    {
      arr[k] = left[i];
      i++;
      k++;
    }
    else if(left[i]>right[j])
    {
      arr[k] = right[j];
      j++;
      k++;
    }
  }
  while(i<n1)
  {
    arr[k] = left[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    arr[k] = right[j];
    k++;
    j++;
  }
}
void mergesort(int arr[],int f,int l)
{
  if(f<l)
  {
    int m = (f+l)/2;
    mergesort(arr,f,m);
    mergesort(arr,m+1,l);
    merge(arr,f,m,l);
  }
}
int main()
{
  int i;
  int arr[] = {1,6,3,2,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  mergesort(arr,0,n-1);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
