// PYTHAGOREAN TRIPLET IN AN ARRAY
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
void pytriplet(int arr[],int n)
{
  int i;
  for(i=0;i<n;i++)
    arr[i] = arr[i]*arr[i];

  sort(arr,arr+n);
  for(i=n-1;i>=2;i--)
  {
    int l = 0;
    int r = i-1;
    while(l<r)
    {
      if(arr[l]+arr[r] == arr[i])
      {
        cout<<sqrt(arr[l])<<" "<<sqrt(arr[r])<<" "<<sqrt(arr[i])<<endl;
        l++;
        r--;
      }
      else if(arr[l]+arr[r] >arr[i])
      {
        r--;
      }
      else
      {
        l++;
      }
    }
  }
}
int main()
{
  int arr[] = {3,1,4,6,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  pytriplet(arr,n);
  return 0;
}
