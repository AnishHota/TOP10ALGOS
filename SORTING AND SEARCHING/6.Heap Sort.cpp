// HEAP SORT
#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)
{
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;
  if(left<n && arr[left]>arr[largest])
  {
    largest = left;
  }
  if(right<n && arr[right]>arr[largest])
  {
    largest = right;
  }
  if(largest!=i)
  {
    swap(arr[i],arr[largest]);
    //recursively heapify the affected subtree
    heapify(arr,n,largest);
  }
}
void heapsort(int arr[],int n)
{
  int i;
  //build a max heap
  for(i=n/2 - 1;i>=0;i--)
  {
    heapify(arr,n,i);
  }
  for(i=n-1;i>=0;i--)
  {
    swap(arr[i],arr[0]);
    //call heapify on the reduced subtree
    heapify(arr,i,0);
  }
}
int main()
{
  int i;
  int arr[] = {1,6,3,2,7,8};
  int n = sizeof(arr)/sizeof(arr[0]);
  heapsort(arr,n);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}