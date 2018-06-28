//INTERPOLATION SEARCH
#include<iostream>
using namespace std;
int interpolationsearch(int arr[],int low,int high,int data)
{
  int mid = low + (((data-arr[low])*(high-low))/(arr[high]-arr[low]));
  if(low>high)
    return -1;
  else if(arr[mid] == data)
    return mid;
  else if(arr[mid]>data)
    return interpolationsearch(arr,low,mid-1,data);
  else
    return interpolationsearch(arr,mid+1,high,data);
  return -1;
}
int main()
{
  int data;
  int arr[] = {12,24,36,44,56,89};
  int n = sizeof(arr)/sizeof(arr[0]);
  cin>>data;
  int index = interpolationsearch(arr,0,n,data);
  cout<<index<<endl;
}
