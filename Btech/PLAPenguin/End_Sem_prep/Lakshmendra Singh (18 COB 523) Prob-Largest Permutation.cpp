#include<iostream>
using namespace std;
int main()
{
	int t,n,k;
	{
		cin>>n>>k;
		int a[n+1],pos[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			pos[a[i]]=i; 
		}
		for(int i=1;i<=n;i++)
		{
			if(!k) 
			break;
			else
			{
				if(a[i]!=n-i+1)
				{
					k--;
					int temp = a[i]; 
					a[i] = n-i+1;
					a[pos[n-i+1]] = temp;
					pos[temp] = pos[n-i+1];
					pos[n-i+1] = i;
				}
			}
		}
		for(int i=1;i<=n;i++) 
		cout<<a[i]<<" ";
	}
}

