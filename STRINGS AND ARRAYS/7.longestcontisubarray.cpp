// LENGTH OF THE LARGEST SUBARRAY WITH CONTIGUOUS ELEMENTS
#include<iostream>
#include<algorithm>
using namespace std;
void lengthsubarray(int arr[],int n)
{
  int i,j,maxl=0;
  for(i=0;i<n-1;i++)
  {
    int maxcurr = arr[i],mincurr = arr[i];
    for(j=i+1;j<n;j++)
    {
      maxcurr = max(maxcurr,arr[j]);
      mincurr = min(mincurr,arr[j]);
      if(maxcurr - mincurr == j-i)
        maxl = max(maxl,j-i);
    }
  }
  cout<<maxl+1;
}
int main()
{
  int arr[] = {1, 56, 58, 57, 90, 92, 94, 93, 91, 45};
  int n = sizeof(arr)/sizeof(arr[0]);
  lengthsubarray(arr,n);
  return 0;
}
