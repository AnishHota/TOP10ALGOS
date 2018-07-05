// COUNT TRIPLETS WITH SUM SMALLER THAN A GIVEN VALUE
#include<iostream>
#include<algorithm>
using namespace std;
void counttriplets(int a[],int n,int k)
{
  int i,ans=0;
  sort(a,a+n);
  //arr[] = {2,3,4,5,6,7}
  for(i=0;i<n;i++)
  {
    int sum = k-a[i];
    int l = i+1;
    int r = n-1;
    while(l<r)
    {
      if(a[l]+a[r]>=sum)
      {
        r--;
      }
      else if(a[l]+a[r]<sum)
      {
        ans+=(r-l);
        //Very important as all the numbers below the a[r]
        //will satisfy the equation too.Hence,we have to count
        //those numbers too.
        l++;
      }
    }
  }
  cout<<ans<<endl;
}
int main()
{
  int arr[] = {5,1,3,4,7};
  int k = 12;
  int n = sizeof(arr)/sizeof(arr[0]);
  counttriplets(arr,n,k);
  return 0;
}
