#include<stdio.h>
void mo(int n,char q,char w)
{
	printf("%d %c-->%c\n",n,q,w);
}
void ho(int n,char a,char b,char c)
{
	if(n==1)
 	mo(n,a,c);
 	else
 	{ho(n-1,a,c,b);
 	mo(n,a,c);
 	ho(n-1,b,a,c);
	 }
}

int main()
{
	int n;
	scanf("%d",&n);
	
	ho(n,'A','B','C');
	return 0;
}
