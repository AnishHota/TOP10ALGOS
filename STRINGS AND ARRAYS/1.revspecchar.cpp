// 1.REVERSE AN ARRAY WITHOUT AFFECTING SPECIAL CHARACTERS
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int n = s.length();
  int ans[n];
  int i=0;
  int j = n-1;
  while(i<j)
  {
    if(isalpha(s[i]) && isalpha(s[j]))
    {
      swap(s[i],s[j]);
      i++;
      j--;
    }
    else if(!isalpha(s[i]))
    {
      i++;
    }
    else if(!isalpha(s[j]))
    {
      j--;
    }
  }
  for(i=0;i<s.length();i++)
  {
    cout<<s[i];
  }
  return 0;
}
