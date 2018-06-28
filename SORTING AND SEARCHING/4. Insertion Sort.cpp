//INSERTION SORT
#include<iostream>
using namespace std;
void insertionsort(int a[], int n)
{
  int i,j,v;
  for(i=1;i<n-1;i++)
  {
    v = a[i];
    j=i;
    while(a[j-1]>v && j>=1)
    {
      a[j] = a[j-1];
      j--;
    }
    a[j] = v;
  }
}
int main()
{
  int i;
  int arr[] = {1,6,3,2,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  insertionsort(arr,n);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
