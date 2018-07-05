// 2.PRINT ALL POSSIBLE PALINDROMIC PARTITIONS OF A STRING
#include<iostream>
#include<vector>
using namespace std;
bool ispalindrome(string s,int low,int high)
{
    while(low<high)
    {
      if(s[low]!=s[high])
        return false;
      low++;
      high--;
    }
    return true;
}
//In vector,you have to used the '&' operator for call by address
void ppartition(vector <vector <string>> &allparts,vector <string> &currpart,int start,int n
,string s)
{
  if(start>=n)
  {
    allparts.push_back(currpart);
    return;
  }
  int i;
  for(i=start;i<n;i++)
  {
    if(ispalindrome(s,start,i))
    {
      currpart.push_back(s.substr(start,i-start+1));
      ppartition(allparts,currpart,i+1,n,s);
      currpart.pop_back();
    }
  }
}
void allpartsutil(string s)
{
  vector <vector <string>> allparts;
  vector <string> currpart;
  int n = s.length();
  ppartition(allparts,currpart,0,n,s);
  int i;
  for(i=0;i<allparts.size();i++)
  {
    for(auto x:allparts[i])
      cout<<x<<" ";
    cout<<endl;
  }
}
int main()
{
  string s = "habitihit";
  allpartsutil(s);
  return 0;
}
