// SEARCH AN ELEMENT IN A SORTED AND ROTATED ARRAY
// NOTE 1: THERE ARE ONLY DISTINCE ELEMENTS IN THE ARRAY I.E NO REPEATING ELEMENTS
#include<iostream>
using namespace std;
int search(int arr[],int low,int high,int key)
{
  if(low>high)
    return -1;

  int mid = low + (high-low)/2;
  if(arr[mid] == key)
    return mid;
  if(arr[low] <= arr[mid])
  {
    if(key >= arr[low] && key <= arr[mid])
      return search(arr,low,mid-1,key);
    else
      return search(arr,mid+1,high,key);
  }
  if(key >= arr[mid+1] && key <= arr[high])
    return search(arr,mid+1,high,key);
  else
    return search(arr,mid-1,high,key);
}
int main()
{
  int data;
  int arr[] = {12,24,36,44,56,89};
  int n = sizeof(arr)/sizeof(arr[0]);
  cin>>data;
  int index = search(arr,0,n-1,data);
  cout<<index<<endl;
}
