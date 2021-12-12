#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        if(a[0]==0)
        {
            cout<<-1<<"\n";
            continue;
        }
      //  cout<<"rached";
        int reach=a[0];
        int steps=a[0];
        int count=1;
        for(int j=1;j<n;j++)
        {
            if(j==n-1)
            {
                break;
            }
            if(reach>j+a[j])
            reach=reach;
            else
            reach=j+a[j];
            steps--;
            if(steps==0)
            {
                count++;
                if(j>=reach)
                {
                    count=-1;
                    break;
                }
                steps=reach-j;
            }
            
        }
        cout<<count<<"\n";
    }
//	return 0;
}
