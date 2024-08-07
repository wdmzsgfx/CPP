/*
#include <iostream>
using namespace std;

const int N=100010;
int n,m;
int a[N],s[N];
int main()
{
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++)
  {
    s[i]=s[i-1]+a[i];
  }

  while(m--)
  {
    int l,r;
    scanf("%d %d",&l,&r);
    printf("%d\n",s[r]-s[l-1]);
  }
  return 0;
} 
*/


//��ά 
#include<iostream>

using namespace std;

const int N=1010;
int n,m,q;
int a[N][N],s[N][N]={0};

int main()
{
	scanf("%d %d %d",&n,&m,&q);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
		}
	}
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
	}
	return 0;
}

