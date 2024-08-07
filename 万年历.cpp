#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int g_MonthDays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int LeapYear(int n);
int CountYearDays(int year);
void Menu(void);
void ListMonth(int days,int t);
void Search1(void);
void Search2(void);
void Search3(void);

int main()
{
	int select;
	while(1)
	{    Menu();
	     scanf("%d",&select);
	     switch(select)
	     {
	     	case 1:Search1();break;
	     	case 2:Search2();break;
	     	case 3:Search3();break;
	     	case 0:printf("\n\tллʹ��!�ټ�!\n");exit(0);
	     	default:printf("\n\t��������,������ѡ��!\n");
		 }
	}
	return 0;
}

int LeapYear(int n)
{
	if((n%4==0&&n%100!=0)||n%400==0) return 1;
	else return 0;
}

int CountYearDays(int year)
{
	int i,flag,days=0;
	for(i=1;i<year;i++)
	{
		flag=LeapYear(i);
		if(flag) days=days+366;
		else days=days+365;
	}
	return(days);
}

int CountMonthDays(int month)
{
	int i,days=0;
	for(i=1;i<month;i++)
	    days+=g_MonthDays[i];
	return(days);
}

void Menu(void)
{
	printf("\n");
	printf("\t-----------------------------\n");
	printf("\t*                           *\n");
	printf("\t*    ��ӭʹ��������ϵͳ     *\n");
	printf("\t*                           *\n");
	printf("\t-----------------------------\n");
	printf("\n");
	printf("\t��ѡ����Ҫ��ѯ������:\n\n");
	printf("\t 1.��ʾĳ�������\n");
	printf("\t 2.��ʾĳ��ĳ�µ�����\n");
	printf("\t 3.��ʾĳ�������ڼ�\n");
	printf("\t 0.�˳�ϵͳ\n\n");
	printf("\t ��ѡ�񰴼�(0~3):");
}

void ListMonth(int days,int t)
{
	int i,j;
	printf("������ ����һ ���ڶ� ������ ������ ������ ������\n");
	for(i=1;i<=days;i++)
	{
		if(i==1)
		for(j=0;j<t;j++)
		    printf("       ");
		printf("%-7d",i);
		if((i+t)%7==0)
		printf("\n");
	}
}

void Search1(void)
{
	int year,t,k,flag,days;
	printf("\n ���������:");
	scanf("%d",&year);
	flag=LeapYear(year);
	t=(CountYearDays(year)+1)%7;
	for(k=1;k<=12;k++)
	{
		days=g_MonthDays[k];
		if(flag&&k==2)
		days=29;
		printf("\n %d��:\n",k);
		ListMonth(days,t);
		t=(t+days%7)%7;
		printf("\n");
		if(k%3==0)
		{
			printf("\n �����������!\n");
			getch();
		}
	}
}

void Search2(void)
{
	int t,year,month,flag,days,ydays,mdays,alldays;
	printf("\n ��������,��(��2009.5)��");
	scanf("%d.%d",&year,&month);
	ydays=CountYearDays(year);
	mdays=CountMonthDays(month);
	days=g_MonthDays[month];
	flag=LeapYear(year);
	if(flag)
	{
		if(month>2)
		mdays++;
		else
		if(month==2)
		days=29;
	 } 
	 alldays=ydays+mdays+1;
	 t=alldays%7;
	 printf("\n%d��%d��:\n\n",year,month);
	 ListMonth(days,t);
	 printf("\n");
}

void Search3(void)
{
    int t,year,month,day,flag,ydays,mdays,alldays;
    printf("\n��������.��.��(��2009.3.25):");
    scanf("%d.%d.%d",&year,&month,&day);
    ydays=CountYearDays(year);
    mdays=CountMonthDays(month);
    flag=LeapYear(year);
    if(flag&&month>2)
        mdays++;
    alldays=ydays+mdays+day;
    t=alldays%7;
    printf("\n %d��%d��%d����",year,month,day);
    switch(t)
    {
    	case 0:printf("������\n");break;
    	case 1:printf("����һ\n");break;
    	case 2:printf("���ڶ�\n");break;
    	case 3:printf("������\n");break;
    	case 4:printf("������\n");break;
    	case 5:printf("������\n");break;
    	case 6:printf("������\n");break;
	};
}
