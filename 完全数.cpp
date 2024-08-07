#include<bits/stdc++.h>

using namespace std;



int main()
{
	long long m,n;
	cin >> n;
	long long i,j;
	while(n--)
	{
		cin >> m;
		long long sum=0;
		if(m==6||m==28||m==496||m==8128||m==33550336)
			cout<<m<<" is perfect"<<endl;
		else
			cout<<m<<" is not perfect"<<endl; 
	}
	return 0;
}

