#include<iostream>

using namespace std;
const int N=1010;

int n;
int num[N];
bool p[N];

void dfs(int u)
{
	if(u==n)
	{
		for(int i=0;i<n;i++)
		{
			printf("%5d",num[i]);
		}
		cout << endl;
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!p[i])
		{
			num[u]=i;
			p[i]=true;
			dfs(u+1);
			p[i]=false;	
		}
			
	}
	
	
}

int main()
{
	cin >> n;
	dfs(0);
	return 0;
}

