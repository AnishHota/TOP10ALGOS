// GENERATE ALL POSSIBLE SORTED ARRAYS FROM ALTERNATE ELEMENTS OF TWO
// GIVEN SORTED ARRAYS
#include<iostream>
using namespace std;
void printarr(int arr[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void possarr(int arr1[],int s1,int n1,int arr2[],int s2,int n2,int c[],int len,bool flag)
{
  int i,j;
  if(flag)
  {
    if(len)
    printarr(c,len+1);
    for(i=s1;i<n1;i++)
    {
      if(!len)
      {
        c[len] = arr1[i];
        possarr(arr1,i+1,n1,arr2,s2,n2,c,len,!flag);
      }
      else if(arr1[i]>c[len])
      {
        c[len+1] = arr1[i];
        possarr(arr1,i+1,n1,arr2,s2,n2,c,len+1,!flag);
      }
    }
  }
  else
  {
    for(j=s2;j<n2;j++)
    {
      if(arr2[j]>c[len])
      {
        c[len+1] = arr2[j];
        possarr(arr1,s1,n1,arr2,j+1,n2,c,len+1,!flag);
      }
    }
  }
}
void genarr(int arr1[],int n1,int arr2[],int n2)
{
  int c[n1+n2];
  possarr(arr1,0,n1,arr2,0,n2,c,0,true);
}
int main()
{
  int arr1[] = {10,15,25};
  int n1 = sizeof(arr1)/sizeof(arr1[0]);
  int arr2[] = {5,20,30};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  genarr(arr1,n1,arr2,n2);
}
