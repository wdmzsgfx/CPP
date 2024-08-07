#include<bits/stdc++.h>

using namespace std;



int main()
{
	int n;
	int i,j;
	cin >> n;
	int x=n/2;
	int y=n/2;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(abs(x-i)+abs(y-j)<=n/2)
				cout<<"*";
			else
				cout<<" ";
		}
		cout << endl;
	}
	return 0;
}

