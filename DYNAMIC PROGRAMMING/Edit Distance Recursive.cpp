#include<iostream>
using namespace std;
string a,b;
int EditDistance(int m,int n)
{
  if(m==0)
    return n;
  if(n==0)
    return m;
  if(a[m]==b[n])
    return EditDistance(m-1,n-1);
  else
    return 1+min(EditDistance(m-1,n),min(EditDistance(m-1,n-1),EditDistance(m,n-1)));
}
int main()
{
  cin>>a>>b;
  int ops = EditDistance(a.length()-1,b.length()-1);
  cout<<ops<<endl;
}
