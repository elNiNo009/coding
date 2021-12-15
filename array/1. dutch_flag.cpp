#include<iostream>
using namespace std;
void swap(int &i, int &j) {
  int temp = i;
  i = j;
  j = temp;
}
int main()
 {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int j=0;j<n;j++)
	    cin>>arr[j];
	    int s=0,e=0,l=n,p=1;
	    while(e<l)
	    {
	        if(arr[e]<p)
	        swap(arr[e++],arr[s++]);
	        else if(arr[e]==p)
	        e++;
	        else
	        swap(arr[e],arr[--l]);
	    }
	    for(int j=0;j<n;j++)
	    cout<<arr[j]<<" ";
	    cout<<"\n";
	}
	return 0;
}
