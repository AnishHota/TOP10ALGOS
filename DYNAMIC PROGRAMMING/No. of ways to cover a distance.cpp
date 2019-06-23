#include<iostream>
using namespace std;
/* Recursive Solution: O(3^n)
int count(int n)
{
  if(n==0)
    return 1;
  if(n<0)
    return 0;
  return count(n-1)+count(n-2)+count(n-3);
}*/
// Dynamic programming Solution
int count(int n)
{
  int cnt[n+1];
  cnt[0]=1;cnt[1]=1;cnt[2]=2;
  for(int i=3;i<=n;i++)
  {
    cnt[i] = cnt[i-1]+cnt[i-2]+cnt[i-3];
  }
  return cnt[n];
}
int main()
{
  int n;
  cin>>n;
  int ans = count(n);
  cout<<ans<<endl;
}
