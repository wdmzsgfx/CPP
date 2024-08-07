#include<iostream>
#include<vector>
using namespace std;

const int N=1e6+10;

bool cmp(vector<int> &A,vector<int> &B)
{
	if(A.size() != B.size())
		return A.size()>B.size();
	for(int i=A.size()-1;i>=0;i--)
		if(A[i]!=B[i])
			return A[i] > B[i];
	return true;
}

vector<int> add(vector<int> &A,vector<int> &B)
{
	vector<int> C;
	int t=0;
	for(int i=0;i<A.size()||i<B.size();i++)
	{
		if(i<A.size())
			t+=A[i];
		if(i<B.size())
			t+=B[i];
		C.push_back(t%10);
		t/=10;
	}
	if(t)
		C.push_back(1);
	return C;
}

vector<int> sub(vector<int> &A,vector<int> &B)//A>B A-B A<B -(B-A)
{
	vector<int> C;
	for(int i=0,t=0;i<A.size();i++)
	{
		t=A[i]-t;
		if(i<B.size())
			t-=B[i];
		C.push_back((t+10)%10);
		if(t<0)
			t=1;
		else
			t=0;
	}
	
	while(C.size()>1&&C.back()==0)//去掉前导0 
		C.pop_back();
	
	return C;
}

vector<int> mul(vector<int> &A,int b)
{
	vector<int> C;
	int t=0;
	for(int i=0;i<A.size();i++)
	{
		if(i<A.size())
		t+=A[i]*b;
		C.push_back(t%10);
		t/=10;
	}
	
	return C;
}

vector<int> div(vector<int> &A,int b)
{
	vector<int> C;
	int r=0;
	for(int i=0;i<A.size();i++)
	{
		r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
	}
	reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}

int main()
{
	string a,b;
	vector<int> A,B;
	int d;
	
	cin >> a >> b ;
	for(int i=a.size()-1;i>=0;i--)
		A.push_back(a[i]-'0');//减0告诉向量这里存的是int，不是字符 
	for(int i=b.size()-1;i>=0;i--)
		B.push_back(b[i]-'0');	
	
	if(cmp(A,B))
	{
	vector<int> C=sub(A,B);
	
	for(int i=C.size()-1;i>=0;i--)
		printf("%d",C[i]);	
	}
	else
	{
		vector<int> C=sub(B,A);
		printf("-");
	for(int i=C.size()-1;i>=0;i--)
		printf("%d",C[i]);
	}
	
			
	return 0;
}

