//BINARY SEARCH
#include<iostream>
using namespace std;
int binarysearch(int arr[],int low,int high,int data)
{
  int mid = low + (high-low)/2;
  if(low>high)
    return -1;
  if(arr[mid]==data)
    return mid;
  else if(arr[mid]>data)
  {
    return binarysearch(arr,low,mid-1,data);
  }
  else
  {
    return binarysearch(arr,mid+1,high,data);
  }
  return -1;
}
int main()
{
  int data;
  int arr[] = {12,24,36,44,56,89};
  int n = sizeof(arr)/sizeof(arr[0]);
  cin>>data;
  int index = binarysearch(arr,0,n,data);
  cout<<index<<endl;
}
