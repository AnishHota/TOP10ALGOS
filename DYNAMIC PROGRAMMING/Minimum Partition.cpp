#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,int> buffer;
int part(int arr[],int n,int s1,int s2)
{
  if(n<0)
    return abs(s1-s2);

  string key = to_string(n)+to_string(s1);
  if(buffer.find(key) == buffer.end())
  {
    int inc = part(arr,n-1,s1+arr[n],s2);
    int exc = part(arr,n-1,s1,s2+arr[n]);
    buffer[key] = min(inc,exc);
  }
  return buffer[key];
}
int main()
{
  int n,i;
  cin>>n;
  int arr[n];
  for(i=0;i<n;i++)
    cin>>arr[i];
  int ans = part(arr,n-1,0,0);
  cout<<ans<<endl;
}
