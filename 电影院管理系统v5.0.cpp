/*
影院放映厅基本信息：放映厅编号 座位数 放映时间安排表（一天）
影片基本信息：影片名称 影片类型 语言种类 票价 放映厅编号 放映档期（一个时间段） 
 系统功能主要功能包括
 1)影片基本信息管理。
①创建影片基本信息文件，输入若干影片的信息，并将其保存至一个文件中。
②增加影片信息，增加新的影片信息，并保存至影片基本信息文件中。
③删除影片信息，提示用户输入要进行删除的影片名称，如果在影片基本信息文件中有该影片存在，则将对应的
影片信息删除，否则输出提示信息，并提示用户选择是否继续进行删除操作。
④影片查询，可以根据影片名称、影片类型、放映日期(年·月·日)等分别进行查询或多个条件组合起来进行查询。
(2)影片放映管理。
①售票，创建一个售票信息文件，包括以下信息：影片名称、放映厅编号、放映日期(年·月·日)、
放映时间(几点几分)、购票数(购票数小于等于该放映厅的余票数，余票数=座位数一购票数)。注意，
对于同一部影片，如果该片在多个放映厅放映，则会产生多条售票信息，但是同一部影片同一个放映厅
只有一条售票信息。
②输入影片名称和放映日期(年·月·日)，输出该影片当天的票房信息(观看人数和票房收入)。注意，
一个影片可能在多个放映厅放映，每个放映厅不同的放映时间观看电影的人数都不同。
③输入影片名称，输出该影片在放映档期内的票房信息(观看人数和票房收入)。
④输入一个日期(年·月·日)，输出该天每一部影片的观看人数和票房收入，并统计该天电影院的全部影片的
观看人数和票房收入。
⑤输入一个日期(年·月)，统计该月电影院的票房收入。
⑥输入一个日期(如2013年)，统计在该年度内放映的每部影片的票房总收入，并按票房总收入从高到低的顺序
将影片名称和票房收入这两项信息存入一个文件中。 

*/ 
/*
我们这里假定一个放映厅能坐100个人，毕竟题目没有说明 
我们定义电影院的放映厅都是三位数的编号，还是切合一下实际比较好 
我们同时加入管理员登录系统 有管理员的密码 ,这里预设为123456 
我们认为影片信息也是可以修改的，所以定义了修改函数 
我们假设电影名称不超过30个字，类型、语言不超过10个字 
我们定义了电影编号
我们假设电影票价稳定不变 
我们自定义电影观看人数，因为这是个管理系统 
我们还定义了售票信息的增加、删除和修改函数 
我们规定此系统存入的所有电影均为2000年(包含2000年)以后的电影 
*/
//==============================================================================================//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
int frmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //定义全局变量，此数组存储非闰年的各月份天数 
int rmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31}; //定义全局变量，此数组存储闰年的各月份天数

//结构体类型定义 

typedef struct date             //日期类型 
{
	int year;             		//年 
	int month; 					//月 
	int day; 					//日 
}SDATE;
typedef struct dangqi           //档期类型 
{ 								 
	int syear;					//开始日期年份 
	int smonth;					//开始日期月份 
	int sday;					//开始日期日份 
	int eyear;					//结束日期年份
	int emonth;					//结束日期月份
	int eday;					//结束日期日份 		
}Sdangqi; 
typedef struct time				//时间类型 
{
	int hour;					//小时 
	int minute;					//分钟 
}STIME;
typedef struct movie 			//电影类型 
{	
	int IMDB;					//电影编号 
	char name[30]; 				//电影名称 
	char type[10];				//电影类型 (爱情、警匪、科幻、灾难） 
	char language[10];			//语言种类(中文、英文) 
	float price;				//价格
	char room_num[10];			//放映厅编号 
	SDATE print_date;			//放映日期 
	Sdangqi print_dangqi;      	//放映档期 
}SMOVIE;

typedef struct ticket			//票类型 
{
	int ITDB;					//售票编号 
	int id;						//名称编号 
	char name[30];				//电影名称
	char room_num[10];			//放映厅编号 
	float price;				//票价 
	int chargenum;				//购票数 
	SDATE print_date;			//放映日期 
	STIME print_time;			//放映时间 
}STICKET;

struct tik						//售票统计类型 
{	
	float in;					// 收入 
	char name[30];				//电影名称 
};

#define SMOVIE_LEN sizeof(SMOVIE)	 //电影类型占用储存空间的大小 
#define STICKET_LEN sizeof(STICKET)  //票类型占用储存空间的大小 
#define MOVIENUM 1000 				 // 电影总数，可按需求更改其数值
#define TICKETNUM 10000 			 //票总数，可按需求更改其数值
SMOVIE movie[MOVIENUM]={0}; 		 //电影数组（全局变量） 
STICKET ticket[TICKETNUM]={0};		 //票数组（全局变量） 

//函数声明 

void menu();						//菜单函数 
void Createmovie(int i);            //创建影片信息函数 
int Addmovie(int mn);				//增加影片信息函数 
int Deletemovie(int mn);			//删除影片信息函数 
void Modifymovie(int mn);			//修改影片信息函数 
void Outputonemovie(int i,int mn);	//输出一部电影信息函数 
int LoadMovies(void);				//从文件载入全部影片信息函数 
int Originalmovie(void);			//初始化电影信息 
void Saveonemovie(int i);			//保存一部电影信息 
void Saveallmovie(int i);			//保存全部电影信息 
void outputAllmovie(int mn);		//输出全部电影详细信息的函数
void outputBrief(int mn); 			//输出全部电影简要信息的函数
void Createticket(int i);			//创建售票信息函数 
int Addticket(int tn);				//增加售票信息函数 
int Deleteticket(int mn);			//删除售票信息函数 
void Modifyticket(int tn);			//修改售票信息函数 
void Outputoneticket(int i);		//输出一张售票信息函数 
int LoadTickets(void);				//从文件载入全部售票信息函数 
int Originalticket(void);			//初始化售票信息 
void outputAllticket(int tn);		//输出全部售票详细信息的函数
void outputbrieft(int tn); 			//输出全部售票简要信息的函数
void Saveoneticket(int i);			//保存一部售票信息 
void Saveallticket(int i);			//保存全部售票信息 
void Searchmovie(int mn);			//查询一个电影的信息
void Searchticketmenu(int mn);		//票查询系统 
void Searchticket1(int tn);			//输入名称和放映日期输出当天的票房信息 
void Searchticket2(int tn);			//输入名称输出放映档期内的票房信息 
void Searchticket3(int tn);			//输入年月日输出当天每一部影片观看人数和票房收入，并统计该天电影院全部影片的观看人数和票房收入 
void Searchticket4(int tn);			//输入年月统计该月电影院的票房收入 
void Searchticket5(int tn);			//输入年统计该年度内放映的每部影片票房总收入，从高到低排序，并将名称和收入存入一个文件 

void menu(int *pmn,int *ptn) 		//菜单函数 
{
	system("cls"); 					//清屏 
	int select,flag1=0,flag2=0;
	char password[11];
	printf("\n请输入密码: ");
	while(gets(password)!=NULL)
	{
		if(strcmp(password,"123456")!=0)
		{
			printf("\n密码错误!\n");
			printf("请输入密码:");
			continue;
		}
		else break;
	}
	
	while(1)
	{
	printf("\n");
	printf("------------------------------------------\n");
	printf("     			  欢迎！                  \n");
	printf("  1.初始化影片信息       7.初始化售票信息\n");
	printf("  2.增加影片信息         8.增加售票信息   \n");
	printf("  3.删除影片信息         9.删除售票信息  \n");
	printf("  4.修改影片信息         10.修改售票信息 \n");
	printf("  5.查询影片信息         11.输出电影信息  \n");	
	printf("  6.查询售票信息         12.输出售票信息  \n");
	printf("  0.返回主菜单                            \n");
	printf("------------------------------------------\n");
	printf("\n 请选择您需要的服务(0-12):");
	scanf("%d",&select);
	getchar();						//空读 
	switch(select)
	{
		case 1:*pmn=Originalmovie(); break;
		case 2:*pmn=Addmovie(*pmn); break;
		case 3:*pmn=Deletemovie(*pmn); break;
		case 4:Modifymovie(*pmn); break;
		case 5:Searchmovie(*pmn); break;	
		case 6:Searchticketmenu(*ptn); break;
		case 7:*ptn=Originalticket(); break;
		case 8:*ptn=Addticket(*ptn); break;
		case 9:*ptn=Deleteticket(*ptn); break;
		case 10:Modifyticket(*ptn); break;
		case 11:printf("详细信息请按'1'，简要信息请按'2':");
			scanf("%d",&flag1);
			getchar();
			if(flag1==1)
				outputAllmovie(*pmn);
			if(flag1==2)
				outputBrief(*pmn); 
			break;
		case 12:printf("详细信息请按'1'，简要信息请按'2':");
			scanf("%d",&flag2);
			getchar();
			if(flag2==1)
				outputAllticket(*ptn);
			if(flag2==2)
				outputbrieft(*ptn); 
			break;
		case 0: return;
		default :printf("按键错误，请重新选择！\n");
	}
	}
	
}

void Createmovie(int i)					//创建影片信息 
{
	int q;
	printf("电影编号：");
	scanf("%d",&movie[i].IMDB);
	getchar();
	printf("影片名称: ");
	gets(movie[i].name);
	printf("影片类型: ");
	gets(movie[i].type);
	printf("语言种类: ");
	gets(movie[i].language);
	printf("票价: ");
	scanf("%f",&movie[i].price);
	while(movie[i].price<=0)
		{
			q=0;
			printf("输入有误，请重新输入！\n"); 
			printf("票价：\n");
			scanf("%f",&q); 
			if(q>0)
			{
				q=movie[i].price;
				break;
			}
		}
	getchar();
	printf("放映厅编号: ");
	gets(movie[i].room_num);
	printf("放映档期(开始年份 开始月份 开始日份 结束年份 结束月份 结束日份 )：\n"); 
	scanf("%d %d %d %d %d %d",&movie[i].print_dangqi.syear,&movie[i].print_dangqi.smonth,&movie[i].print_dangqi.sday,&movie[i].print_dangqi.eyear,&movie[i].print_dangqi.emonth,&movie[i].print_dangqi.eday);
	 
	getchar();
}

int LoadMovies(void)					//载入全部电影的信息 
{
	FILE *fm;
	int mn=0; //mn记录电影数量 
	if((fm=fopen("movie.txt","r+"))==NULL)
	{
		printf("文件打开失败\n");
		return(mn); //失败返回值为0 
	}
	while(!feof(fm)) //文件没有结束时进行读数据操作 
		if(fread(&movie[mn],SMOVIE_LEN,1,fm)) 
			mn++; //从文件中每读到一个电影，电影数量加一 
	fclose(fm);
	return mn;
}

void Saveonemovie(int i)				//保存一部电影信息 
{
	FILE *fm;
	if((fm=fopen("movie.txt","r+"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1); 
	}
	fseek(fm,SMOVIE_LEN *i,0); //定位到第i部电影
	fwrite(&movie[i],SMOVIE_LEN,1,fm); //将第i部电影写入文件
	fclose(fm); 
}

void Saveallmovie(int mn)				//保存全部电影信息 
{
	FILE *fm;
	if((fm=fopen("movie.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}
	fwrite(movie,SMOVIE_LEN,mn,fm);
	fclose(fm);
}

int Originalmovie(void)					//初始化电影信息 
{
	int n;
	char c='y';
	for(n=0;c=='y'||c=='Y';n++)
	{
		printf("\n输入电影%d的信息：\n",n+1);
		Createmovie(n);
		printf("\n继续输入请按'y',停止输入请按'n':");
		c=getchar();
		getchar();
	}
	Saveallmovie(n);
	return n;
}
 
int Addmovie(int mn)					//增加影片信息 
{
	char c='y';
	FILE *fm;
	if((fm=fopen("movie.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}
	while(c=='y'||c=='Y')
	{
		printf("\n请输入新增电影的信息：\n");
		Createmovie(mn);
		fwrite(&movie[mn],SMOVIE_LEN,1,fm);
		mn++;
		printf("\n继续输入其他新电影的信息么？<y/n>\n");
		c=getchar();
		getchar();
	}
	printf("\n按任意键继续\n");
	getch();
	fclose(fm);
	return mn;
}

void Modifymovie(int mn)				//修改影片信息 
{
	
	int select,k=-1;
	int imdb,c1='y',c2;
	if(mn==0)
	{
		printf("\n影片信息为空，无法进行操作！\n");
		return; //返回管理员菜单 
	}
	while(c1=='y'||c1=='Y')
	{
		c2='y';
		printf("\n请输入要修改的电影的编号：\n");
		scanf("%d",&imdb);
		getchar();
		for(int i=0;i<mn;i++)
		if(movie[i].IMDB==imdb)
		{
			k=i;
			break;
		}
		if(k<0) //在数组movie中没找到对应的电影
			printf("\n输入错误，请重新输入！\n");
		else //找到电影，进行操作 
		{
			printf("\n显示电影信息：\n");
			Outputonemovie(k,mn);
			while(c2=='y'||c2=='Y')
			{
				printf("\n电影信息包括如下：\n");
				printf("------------------------\n");
				printf("1.电影编号     5.票价\n");
				printf("2.影片名称     6.放映厅编号\n");
				printf("3.影片类型     7.放映档期\n");
				printf("4.语言种类              \n");
				printf("------------------------\n");
				printf("\n请选择要修改的数据项（1-7）: \n");
				scanf("%d",&select);
				getchar();
				switch(select)
				{
					case 1:printf("电影编号："); scanf("%d",&movie[k].IMDB); break;
					case 2:printf("影片名称："); gets(movie[k].name); break;
					case 3:printf("影片类型："); gets(movie[k].type); break;
					case 4:printf("语言种类："); gets(movie[k].language); break;
					case 5:printf("票价："); scanf("%f",&movie[k].price); break;
					case 6:printf("放映厅编号："); gets(movie[k].room_num); break;
					case 7:printf("放映档期(开始年份.开始月份.开始日份.结束年份.结束月份.结束日份)："); scanf("%d.%d.%d.%d.%d.%d",&movie[k].print_dangqi.syear,&movie[k].print_dangqi.smonth,&movie[k].print_dangqi.sday,&movie[k].print_dangqi.eyear,&movie[k].print_dangqi.emonth,&movie[k].print_dangqi.eday); break;
					default :printf("\n按键错误，请重新选择！\n");		
				}
				printf("\n还要继续修改该电影的其他信息么?<y/n>: \n");
				c2=getchar();
				getchar();
			}	
		}
		Saveonemovie(k);
		printf("\n还要继续修改其他电影的信息么？<y/n>\n");
		c1=getchar();
		getchar();
	}
	printf("\n按任意键继续\n");
	getch();
}

void Outputonemovie(int i,int mn)				//输出一部电影的全部信息 
{	
	printf("\n");
	printf("影片编号: ");
	printf("%d\n",movie[i].IMDB); 
	printf("影片名称: ");
	puts(movie[i].name);
	printf("影片类型: ");
	puts(movie[i].type);
	printf("语言种类: ");
	puts(movie[i].language);
	printf("票价: ");
	printf("%.2f\n",movie[i].price);
	printf("放映厅编号: ");
	puts(movie[i].room_num);
	printf("放映档期: ");
	printf("放映档期(开始年份 开始月份 开始日份 结束年份 结束月份 结束日份 )：\n"); 
	printf("%d %d %d %d %d %d",movie[i].print_dangqi.syear,movie[i].print_dangqi.smonth,movie[i].print_dangqi.sday,movie[i].print_dangqi.eyear,movie[i].print_dangqi.emonth,movie[i].print_dangqi.eday);
}

int Deletemovie(int mn)					//删除影片信息 
{
	int i,k=-1,j;
	int imdb,c1='y',c2;
	if(mn==0)
	{
		printf("\n电影信息为空，无法进行操作！\n");
		return(mn);
	}
	while(c1=='y'||c1=='Y')
	{
		c2='n';
		printf("请输入要删除电影的编号");
		scanf("%d",&imdb);
		getchar();
		for(i=0;i<mn;i++)
			if(movie[i].IMDB==imdb)
			{	k=i;
				break;
			}
		if(k<0)		//k<0表示没找到 
			printf("\n输入的影片名称有误，请重新输入！\n");
		else
		{
			printf("显示该电影的信息: \n");
			Outputonemovie(k,mn); 
			printf("\n确定要删除该电影的全部信息么？<y/n>:");
			c2=getchar();
			getchar();
			if(c2=='y') //c2为y，确认删除 
			{
				for(i=k;i<mn;i++)
					movie[i]=movie[i+1];
				mn--; //电影数减一 
				printf("删除成功!");
			}
			else //c2为n，不删除 
				printf("\n删除取消\n");
			printf("\n继续删除其它电影的信息么？<y/n>\n");
			c1=getchar();
			getchar();
		}
	}
	Saveallmovie(mn); //保存删除后的信息 
	printf("\n按任意键继续\n");
	getch(); //按任意键自动读取，不用回车 
	return(mn); //返回删除后的电影数量 
}

void Searchmovie(int mn)					//影片查询函数		
{
	system("cls"); 
	int count=0;
	int i,n,k=-1,j,mimdb,x=0,syear,smonth,sday;
	char mname[30],mtype[10],mlang[10],mroom[10];
	int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0;
	float pr;
	while(1)
	{
		char choice[7];
		printf("\n");
		printf("---------------------------\n");
		printf("    欢迎进入影片查询系统   \n");
		printf("电影编号------------------1\n");
		printf("影片名称------------------2\n");
		printf("影片类型------------------3\n"); 
		printf("语言种类------------------4\n"); 
		printf("票价----------------------5\n"); 
		printf("放映厅编号----------------6\n"); 
		printf("放映档期------------------7\n");  
		printf("退出系统------------------0\n");
		printf("---------------------------\n");
		printf("\n");
		printf("请输入要查询的选项(可多选)：\n");
		scanf("%c", &choice[i]);
		while (choice[i] != '\n')
		{
			i++;
			scanf("%c", &choice[i]);
		}
		for (n = 0; n <i; n++)
		{
		switch (choice[n])
		{
		case '1':{	
					printf("\n请输入电影编号：");
					scanf("%d", &mimdb);
					getchar();
					flag1 = 1;
				}
				break;
		case '2':{
					printf("\n请输入影片名称：");
					scanf("%s", mname);
					getchar();
					flag2 = 1;
				}
				break;	
		case '3':{
					printf("\n请输入影片类型：");
					scanf("%s", mtype);
					getchar();
					flag3 = 1;
				}
				break;
		case '4':{printf("\n请输入语言类型：");
					scanf("%s", mlang);
					getchar();
					flag4 = 1;
				}
				break;
		case '5':{
					printf("\n请输入票价：");
					scanf("%f", &pr);
					getchar();
					flag5 = 1;
				}
				break;
		case '6':{
					printf("\n请输入放映厅编号：");
					scanf("%s", mroom);
					getchar();
					flag6 = 1;
				}	
				break;
		case '7':{
					printf("\n请输入放映档期：");
					scanf("%d %d %d", &syear,&smonth,&sday);
					getchar();
					flag7 = 1;
				}
				break;
		case '0':return;
		default:("\n按键错误，请重新选择\n");
		}
		}
		while (movie[x].IMDB!=0)
		{
			x++;
			mn++;
		}
		x=0;
		if(flag1)
		{
			while(movie[x].IMDB!=0)
			{
				if(movie[x].IMDB==mimdb)
				{
					Outputonemovie(x,mn);
					count+=1;
				}
				x++;
			}
			flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0;
		}
		else if(flag3)
		{
			while(movie[x].IMDB!=0)
			{
				if(strcmp(movie[x].type,mtype)==0)
				{
					Outputonemovie(x,mn);
					count+=1;
				}
				x++;
			}	
			flag2=0,flag4=0,flag5=0,flag6=0,flag7=0;
		}
		else if(flag4)
		{
			while(movie[x].IMDB!=0)
			{
				if(strcmp(movie[x].language,mlang)!=NULL)	
				{
					Outputonemovie(x,mn);
					count+=1;
				}
			x++;
			}
			flag2=0,flag5=0,flag6=0,flag7=0;
		}	
		else if(flag5)
		{
			while(movie[x].IMDB!=0)
			{
				if(pr==movie[x].price)	
				{
					Outputonemovie(x,mn);
					count+=1;
				}
			x++;
			}
			flag2=0,flag6=0,flag7=0;
		}
		else if(flag6)
		{
			while(movie[x].IMDB!=0)
			{
				if(strcmp(movie[x].room_num,mroom)!=NULL)	
				{
					Outputonemovie(x,mn);
					count+=1;
				}
			x++;
			}
			flag2=0,flag7=0;
		}
		else if(flag7)
		{
			while(movie[x].IMDB!=0)
			{
				if(movie[x].print_date.year==syear&&movie[x].print_date.month==smonth&&movie[x].print_date.day==sday)
				{
					Outputonemovie(x,mn);
					count+=1;
				}
			x++;
			}
			flag2=0;
		}
		else if(flag2)
		{
			printf("\n模糊查询结果如下:\n");
			while(movie[x].IMDB!=0)
			{
				if(strstr(movie[x].name,mname)!=NULL)	
					{
						Outputonemovie(x,mn);
						count+=1;
					}
			x++;
			}
		}
		if(count==0)
		printf("\n抱歉！未查询到相应电影信息！\n"); 
	}
	
		printf("\n按任意键返回菜单\n");
		getch();
		
} 

void outputAllmovie(int mn)			//输出全部电影详细信息的函数
{
	int i;
	printf("\n全部电影的详细信息：\n");
	for(i=0;i<mn;i++)
	{
		Outputonemovie(i,mn);
		printf("\n按任意键继续!\n");
		getch;		
	}
	printf("\n全部电影信息输出完毕!\n");
	printf("\n按任意键返回\n");
	getch(); 
}

void outputBrief(int mn) 			//输出全部电影简要信息的函数
{
	int i;
	printf("\n全部电影的简要信息\n");
	printf("\n序号 电影编号 电影名称     票价          放映档期\n");
	for(i=0;i<mn;i++)
	{
		printf("%2d   %-8d %-12s  %-2.2f    ",i+1,movie[i].IMDB,movie[i].name,movie[i].price);
		printf("%2d年%2d月%2d日-%2d年%2d月%2d日",movie[i].print_dangqi.syear,movie[i].print_dangqi.smonth,movie[i].print_dangqi.sday,movie[i].print_dangqi.eyear,movie[i].print_dangqi.emonth,movie[i].print_dangqi.eday);
		printf("\n");
	} 
	printf("\n按任意键继续\n");
	getch(); 
}

void Createticket(int i)					//创建票函数 
{
	printf("影片编号：");
	scanf("%d",&ticket[i].ITDB);
	getchar();
	printf("影片名称：");
	gets(ticket[i].name);
	printf("名称编号：");
	scanf("%d",&ticket[i].id);
	getchar(); 
	printf("放映厅编号：");
	gets(ticket[i].room_num);
	printf("放映日期：年 月 日\n");
	scanf("%d %d %d",&ticket[i].print_date.year,&ticket[i].print_date.month,&ticket[i].print_date.day);
	getchar();
	printf("放映时间：小时 分钟\n");
	scanf("%d %d",&ticket[i].print_time.hour,&ticket[i].print_time.minute);
	getchar();
	printf("票价：");
	scanf("%f",&ticket[i].price);
	getchar();
	printf("购票数：");
	scanf("%d",&ticket[i].chargenum);
	getchar();
	printf("余票数为：\n");
	printf("%d\n",100-ticket[i].chargenum); 
	
}

int LoadTickets(void)					//载入全部售票的信息 
{
	FILE *ft;
	int tn=0; //mn记录售票数量 
	if((ft=fopen("ticket.txt","r+"))==NULL)
	{
		printf("文件打开失败\n");
		return(tn); //失败返回值为0 
	}
	while(!feof(ft)) //文件没有结束时进行读数据操作 
		if(fread(&ticket[tn],STICKET_LEN,1,ft)) 
			tn++; //从文件中每读到一个售票，售票数量加一 
	fclose(ft);
	return tn;
}

void Saveoneticket(int i)				//保存一部售票信息 
{
	FILE *ft;
	if((ft=fopen("ticket.txt","r+"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1); 
	}
	fseek(ft,STICKET_LEN *i,0); //定位到第i张售票
	fwrite(&ticket[i],STICKET_LEN,1,ft); //将第i张售票写入文件
	fclose(ft); 
}

void Saveallticket(int tn)				//保存全部售票信息 
{
	FILE *ft;
	if((ft=fopen("ticket.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}
	fwrite(ticket,STICKET_LEN,tn,ft);
	fclose(ft);
}

int Originalticket(void)					//初始化售票信息 
{
	int n;
	char c='y';
	for(n=0;c=='y'||c=='Y';n++)
	{
		printf("\n输入票%d的信息：\n",n+1);
		Createticket(n);
		printf("\n继续输入请按'y',停止输入请按'n':");
		c=getchar();
		getchar();
	}
	Saveallticket(n);
	return n;
}
 
int Addticket(int tn)					//增加售票信息 
{
	char c='y';
	FILE *ft;
	if((ft=fopen("ticket.txt","w"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1);
	}
	while(c=='y'||c=='Y')
	{
		printf("\n请输入新增售票的信息：\n");
		Createticket(tn);
		fwrite(&ticket[tn],STICKET_LEN,1,ft);
		tn++;
		printf("\n继续输入其他新售票的信息么？<y/n>\n");
		c=getchar();
		getchar();
	}
	printf("\n按任意键继续\n");
	getch();
	fclose(ft);
	return tn;
}

void Modifyticket(int tn)				//修改售票信息 
{
	int select,k=-1;
	int itdb,c1='y',c2;
	if(tn==0)
	{
		printf("\n售票信息为空，无法进行操作！\n");
		return; //返回管理员菜单 
	}
	while(c1=='y'||c1=='Y')
	{
		c2='y';
		printf("\n请输入要修改的售票的编号：\n");
		scanf("%d",&itdb);
		for(int i=0;i<tn;i++)
		if(ticket[i].ITDB==itdb)
		{
			k=i;
			break;
		}
		if(k<0) //在数组ticket中没找到对应的电影
			printf("\n输入错误，请重新输入！\n");
		else //找到售票，进行操作 
		{
			printf("\n显示电影信息：\n");
			Outputoneticket(k);
			while(c2=='y'||c2=='Y')
			{
				printf("\n电影信息包括如下：\n");
				printf("--------------------------\n");
				printf("1.售票编号      4.放映日期\n");
				printf("2.影片名称      5.放映时间\n");
				printf("3.放映厅编号    6.购票数\n");
				printf("7.价格          8.名称编号\n");
				printf("--------------------------\n");
				printf("\n请选择要修改的数据项（1-8）: \n");
				scanf("%d",&select);
				getchar();
				switch(select)
				{
					case 1:printf("售票编号："); scanf("%d",&ticket[k].ITDB); break;
					case 2:printf("影片名称："); gets(ticket[k].name); break;
					case 3:printf("放映厅编号："); gets(ticket[k].room_num); break;
					case 4:printf("放映日期："); scanf("%d %d %d",&ticket[k].print_date.year,&ticket[k].print_date.month,&ticket[k].print_date.day); break;
					case 5:printf("放映时间："); scanf("%d %d",&ticket[k].print_time.hour,&ticket[k].print_time.minute);break;
					case 6:printf("购票数："); scanf("%d",&ticket[k].chargenum); break;
					case 7:printf("价格："); scanf("%f",&ticket[k].price); break;
					case 8:printf("名称编号："); scanf("%d",&ticket[k].id); break; 
					default :printf("\n按键错误，请重新选择！\n");		
				}
				printf("\n还要继续修改该售票的其他信息么?<y/n>: \n");
				c2=getchar();
				getchar();
			}	
		}
		Saveoneticket(k);
		printf("\n还要继续修改其他售票的信息么？<y/n>\n");
		c1=getchar();
		getchar();
	}
	printf("\n按任意键继续\n");
	getch();
}

int Deleteticket(int tn)					//删除售票信息 
{
	int i,k=-1,j;
	int itdb,c1='y',c2;
	if(tn==0)
	{
		printf("\n售票信息为空，无法进行操作！\n");
		return(tn);
	}
	while(c1=='y'||c1=='Y')
	{
		c2='n';
		printf("请输入要删除售票的编号：");
		scanf("%d",&itdb);
		for(i=0;i<tn;i++)
			if(ticket[i].ITDB==itdb)
			{	k=i;
				break;
			}
		if(k<0)		//k<0表示没找到 
			printf("\n输入的售票名称有误，请重新输入！\n");
		else
		{
			printf("显示该售票的信息: \n");
			Outputoneticket(k); 
			printf("\n确定要删除该售票的全部信息么？<y/n>:");
			c2=getchar();
			getchar();
			if(c2=='y') //c2为y，确认删除 
			{
				for(i=k;i<tn;i++)
					ticket[i]=ticket[i+1];
				tn--; //售票信息数减一 
				printf("删除成功!");
			}
			else //c2为n，不删除 
				printf("\n删除取消\n");
			printf("\n继续删除其它售票的信息么？<y/n>\n");
			c1=getchar();
			getchar();
		}
	}
	Saveallticket(tn); //保存删除后的信息 
	printf("\n按任意键继续\n");
	getch(); //按任意键自动读取，不用回车 
	return(tn); //返回删除后的售票数量 
}

void Outputoneticket(int i)				//输出一张售票的全部信息 
{	
	printf("\n");
	printf("影片编号：\n");
	printf("%d\n",ticket[i].ITDB); 
	printf("影片名称: ");
	puts(ticket[i].name);
	printf("名称编号：");
	printf("%d\n",ticket[i].id);
	printf("放映厅编号: ");
	puts(ticket[i].room_num);
	printf("放映日期: ");
	printf("%d年%d月%d日",ticket[i].print_date.year,ticket[i].print_date.month,ticket[i].print_date.day);
	printf("\n");
	printf("放映时间: ");
	printf("%d时%d分",ticket[i].print_time.hour,ticket[i].print_time.minute);
	printf("\n");
	printf("价格：");
	printf("%.2f\n",ticket[i].price);
	printf("购票数: ");
	printf("%d\n",ticket[i].chargenum);
}

void outputAllticket(int tn)		//输出全部售票详细信息的函数
{
	int i;
	printf("\n全部售票的详细信息：\n");
	for(i=0;i<tn;i++)
	{
		Outputoneticket(i);
		printf("\n按任意键继续!\n");
		getch;		
	}
	printf("\n全部售票信息输出完毕!\n");
	printf("\n按任意键返回\n");
	getch(); 
}

void outputbrieft(int tn) 			//输出全部售票简要信息的函数
{
	int i;
	printf("\n全部售票的简要信息\n");
	printf("\n序号 售票编号  电影名称     放映厅编号    放映日期           放映时间 \n"); 
	for(i=0;i<tn;i++)
	{
		printf("%2d    %-2d       %-2s        %2s  ",i+1,ticket[i].ITDB,ticket[i].name,ticket[i].room_num);
		printf("      %2d年%2d月%2d日    ",ticket[i].print_date.year,ticket[i].print_date.month,ticket[i].print_date.day);
		printf("%2d时%2d分钟",ticket[i].print_time.hour,ticket[i].print_time.minute);
		printf("\n");
	
	}	
	printf("\n按任意键继续\n");
	getch(); 
}

void Searchticketmenu(int tn)				//票查询函数 
{
	system("cls"); 
	int choice=0;
	while(1)
	{
	printf("---------------------------\n");
	printf("    欢迎进入票房查询系统   \n");
	printf("按影片名称和放映日期查询--1\n");
	printf("按影片名称查询人数和票房--2\n");
	printf("按一个日期查询当天票房----3\n");
	printf("按一个日期查询一个月收入--4\n");
	printf("按一个日期查询一年票房----5\n");
	printf("退出查询系统--------------0\n");
	printf("---------------------------\n");
	printf("\n");
	printf("请选择功能（1-5）：");
	scanf("%d",&choice);
	getchar();
	switch(choice)
	{
		case 1:Searchticket1(tn); break;
		case 2:Searchticket2(tn); break;
		case 3:Searchticket3(tn); break;
		case 4:Searchticket4(tn); break;
		case 5:Searchticket5(tn); break;
		case 0:return;
		default :printf("\n输入有误，请重新选择！\n"); 
	}
	}
} 

void Searchticket1(int tn) 					// 输入影片名称和放映日期(年xxxx·月xx·日xx)，输出该影片当天的票房信息
{
	char ssname[30];
	int  ssyear,ssmonth,ssday,i,k,num=0;
	printf("请输入影片名称: ");
	gets(ssname);
	printf("请输入放映日期(年 月 日): ");
	scanf("%d %d %d",&ssyear,&ssmonth,&ssday);
	getchar(); 
	while(ssyear<2000||ssmonth<=0||ssday<=0)
		{
			printf("很抱歉，您输入的年份或者月份或者日份格式不对！\n");
			printf("请重新输入！\n"); 
			scanf("%d %d %d",&ssyear,&ssmonth,&ssday);
			getchar();
		}
		
	for(i=0;i<tn;i++)
	{
		k=0;
		if((strcmp(ticket[i].name,ssname)==0)&&(ssyear==ticket[i].print_date.year)&&(ticket[i].print_date.month==ssmonth)&&(ticket[i].print_date.day==ssday))
		{
			k=i;
			printf("影片名称：%s 观看人数与收入： %d,%.2f 放映厅编号：%s",ticket[k].name,ticket[k].chargenum,ticket[k].price*ticket[k].chargenum*1.0,ticket[k].room_num);
			printf("\n");
			num+=1;
		}
	}
	if(num==0)
	{
		printf("抱歉，未找到相符合的电影票房信息");
		return;
	}
	printf("\n按任意键继续\n");
	getch();
}

void Searchticket2(int tn) 					//输入影片名称，输出该影片在放映档期内的票房信息(观看人数和票房收入)。

{
	char name[30];
	int peoplenum=0,num=0,i,k;
	float totalincome=0;
	printf("请输入影片名称：\n");
	gets(name);
	for(i=0;i<tn;i++)
	{
		k=0;
		if(strcmp(ticket[i].name,name)==0)
		{
			k=i;
			peoplenum+=ticket[k].chargenum;
			totalincome+=ticket[k].chargenum*1.0*ticket[k].price;
			num+=1;
		}
	}
	
	if(num==0)
	{
		printf("抱歉，未找到相符合的电影票房信息");
		return;
	}
	else
	{
		printf("相关票房信息如下：\n");
		printf("\n观看人数:%d人     票房收入:%.2f元\n",peoplenum,totalincome);
	}
	printf("\n按任意键继续\n");
	getch();
}

void Searchticket3(int tn) 				            //输入一个日期(年xxxx·月xx·日xx)，输出该天每一部影片的观看人数和票房收入
{
	int year,month,day;
	int peoplenum=0;
	float totalincome=0.00;
	int i=0;
	float price;
	int ii=-1;
	int bijiaok;
    char sname[30];
    char dian1,dian2;
	printf("请输入您想查询的日期（年 月 日）：");
	scanf("%d %d %d",&year,&month,&day);
	getchar(); 
	while(year<0||month<=0||day<=0||month>12||day>31||(year%4==0&&year%100!=0&&year%400==0&&month>rmonth[month-1])||(year%4!=0&&year%100==0&&year%400!=0&&month>frmonth[month-1]))
		{
			printf("很抱歉，您输入的日期不合法！\n");
			printf("请重新输入！\n"); 
			printf("请输入您想要查询的日期（年.月.日）:");
			scanf("%d %d %d",&year,&month,&day);
			getchar(); 
		}
	while(year<2000&&year>0)
		{
			printf("很抱歉,您输入的日期合法但小于我们电影院中最小的年份！\n");
			printf("请重新输入！\n"); 
			printf("请输入您想要查询的日期（年.月.日）:");
			scanf("%d %d %d",&year,&month,&day);
			getchar();
		}
	printf("对应信息如下：\n");
	printf(" 电影名称  观看人数  票房收入\n");	
	for(i=0;i<tn;i++)
	{
		if(ticket[i].print_date.day==day&&ticket[i].print_date.month==month&&ticket[i].print_date.year==year)
		{
			printf("%s  %d   %.2f",ticket[i].name,ticket[i].chargenum,ticket[i].price*1.0*ticket[i].chargenum);
			printf("\n");
			peoplenum+=ticket[i].chargenum;
			totalincome+=ticket[i].price*1.0*ticket[i].chargenum;
		}
	}
	printf("总观看人数：%d  总票房收入：%.2f\n",peoplenum,totalincome);
	printf("\n按任意键继续\n");
	getch();
}

void Searchticket4(int tn) 					//输入一个日期(年xxxx·月xx)，统计该月电影院的票房收入。
{
	int year,month;
	char dian;
	float totalincome,income;
	int i=0; 
	int peoplenum;
	printf("请输入您想要查询的日期（年 月）:");
	scanf("%d %d",&year,&month);
	getchar();
		while(year<=0||month<=0||month>12||(year%4==0&&year%100!=0&&year%400==0&&month>rmonth[month-1])||(year%4!=0&&year%100==0&&year%400!=0&&month>frmonth[month-1]))
		{
			printf("很抱歉，您输入的日期不合法！\n");
			printf("请重新输入！:\n"); 
			printf("请输入您想要查询的日期（年.月）:");
			scanf("%d %d",&year,&month);
			getchar();
		}
		while(year<2000&&year>0)
		{
			printf("很抱歉,您输入的日期合法但小于我们电影院中最小的年份！\n");
			printf("请重新输入！"); 
			printf("请输入您想要查询的日期（年.月）:");
			scanf("%d %d",&year,&month);
			getchar();
		}
	for(i=0;i<tn;i++)
	{
		if(ticket[i].print_date.year==year&&ticket[i].print_date.month==month)
		{
			income=0;
			income=ticket[i].chargenum*1.0*ticket[i].price;
			totalincome+=income;
		}
	}
	printf("\n%d年%d月的票房收入共计：%.2f元\n",year,month,totalincome);
	printf("\n按任意键继续\n");
	getch();
}

void Searchticket5(int tn) 					//输入一个日期(如2013年)，统计在该年度内放映的每部影片的票房总收入
{
	int year;
	int peoplenum=0;
	float income,totalincome=0;
	float temp;
	struct tik ti[100];
	int i,k=0,j,q;
	printf("请输入您想要查询的日期（年xxxx）：");
	scanf("%d",&year);
	getchar();
	while(year<=0)
		{
			printf("很抱歉，您输入的日期不合法！\n");
			printf("请重新输入！\n"); 
			printf("请输入您想要查询的日期（年xxxx）:");
			scanf("%d",&year);
			getchar();
		}
	while(year<2000&&year>0)
		{
			printf("很抱歉,您输入的日期合法但小于我们电影院中最小的年份！\n");
			printf("请重新输入！\n"); 
			printf("请输入您想要查询的日期（年）:");
			scanf("%d",&year);
			getchar();
		}
	for(i=0;i<tn;i++)
	{
		if(ticket[i].print_date.year==year)
		{
			income=0;
			income=ticket[i].chargenum*1.0*ticket[i].price;
			totalincome+=income;
		}
			
	}
	k=-1;
	
	for(i=0;i<tn;i++)
		{
            if(ticket[i].print_date.year==year)
            {
            	k++;
            	strcpy(ti[k].name,ticket[i].name);
             	for(j=0;j<tn;j++)
				{
					if(ticket[j].id==ticket[i].id&&ticket[j].print_date.year==year)
					{
						ti[k].in+=ticket[j].chargenum*1.0*ticket[j].price;
					}
					
				}
			}
		}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<=k;j++)
		{
			if(ti[i].in>ti[j].in)
			{
				temp=ti[i].in;
				ti[i].in=ti[j].in;
				ti[j].in=temp;
				char *str;
				strcpy(str,ti[i].name);
				strcpy(ti[i].name,ti[j].name);
				strcpy(ti[j].name,str);
			}
		}
	}
	printf("\n影片名称   票房收入\n");
	for(i=0;i<=k;i++)
	{
		printf("%s   %.2f\n",ti[i].name,ti[i].in);
	} 
	printf("%d年的票房收入共计：%.2f元",year,totalincome);
	FILE *fp;
	if((fp=fopen("rank.txt","w+"))==NULL)
	{
		printf("文件打开失败\n");
		exit(1); 
	}
	fseek(fp,SMOVIE_LEN *i,0); //定位到第i部电影
	for(j=0;j<=k;j++)
		fprintf(fp,"%s  %.2f\n",ti[j].name,ti[j].in); //将第i部电影写入文件
	fclose(fp); 
	printf("\n按任意键继续\n");
	getch();
}


int main()
{
	int select,mn,tn,rn;
	mn=LoadMovies();
	if(mn==0)
		printf("电影信息为空！\n\n");
	tn=LoadMovies();
	if(tn==0)
		printf("票信息为空！\n\n");
	int *pmn=&mn;
	int *ptn=&tn;
	while(1)
	{
		printf("\n");
		printf("\t--------------------\n");
		printf("\t                    \n");
		printf("\t   电影院管理系统   \n");
		printf("\t                    \n");
		printf("\t       1.登入       \n");
		printf("\t       0.登出       \n");
		printf("\t                    \n");
		printf("\t--------------------\n");
		printf("\t请选择：");
		scanf("%d",&select);
		getchar();
		switch(select)
		{
			case 1:menu(&mn,&tn);
			case 0:printf("谢谢使用，再见！\n"); exit(1);
			default:printf("\n按键错误，请重新选择！\n");
		} 
	}
	return 0;
}

