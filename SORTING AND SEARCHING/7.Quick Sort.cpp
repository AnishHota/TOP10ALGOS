// QUICK SORT
#include<iostream>
using namespace std;
int partition(int arr[],int low,int high)
{
  int j;
  int pivot = arr[high];
  int i = low;
  for(j=low;j<high;j++)
  {
    if(arr[j]<=pivot)
    {
      swap(arr[i],arr[j]);
      i++;
    }
  }
  swap(arr[i],arr[high]);
  return i;
}
void quicksort(int arr[],int low,int high)
{
  int pivot;
  if(low<high)
  {
    pivot = partition(arr,low,high);
    quicksort(arr,low,pivot-1);
    quicksort(arr,pivot+1,high);
  }
}
int main()
{
  int i;
  int arr[] = {7,3,6,2,5,1};
  int n = sizeof(arr)/sizeof(arr[0]);
  quicksort(arr,0,n-1);
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}
