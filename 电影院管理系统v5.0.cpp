/*
ӰԺ��ӳ��������Ϣ����ӳ����� ��λ�� ��ӳʱ�䰲�ű�һ�죩
ӰƬ������Ϣ��ӰƬ���� ӰƬ���� �������� Ʊ�� ��ӳ����� ��ӳ���ڣ�һ��ʱ��Σ� 
 ϵͳ������Ҫ���ܰ���
 1)ӰƬ������Ϣ����
�ٴ���ӰƬ������Ϣ�ļ�����������ӰƬ����Ϣ�������䱣����һ���ļ��С�
������ӰƬ��Ϣ�������µ�ӰƬ��Ϣ����������ӰƬ������Ϣ�ļ��С�
��ɾ��ӰƬ��Ϣ����ʾ�û�����Ҫ����ɾ����ӰƬ���ƣ������ӰƬ������Ϣ�ļ����и�ӰƬ���ڣ��򽫶�Ӧ��
ӰƬ��Ϣɾ�������������ʾ��Ϣ������ʾ�û�ѡ���Ƿ��������ɾ��������
��ӰƬ��ѯ�����Ը���ӰƬ���ơ�ӰƬ���͡���ӳ����(�ꡤ�¡���)�ȷֱ���в�ѯ������������������в�ѯ��
(2)ӰƬ��ӳ����
����Ʊ������һ����Ʊ��Ϣ�ļ�������������Ϣ��ӰƬ���ơ���ӳ����š���ӳ����(�ꡤ�¡���)��
��ӳʱ��(���㼸��)����Ʊ��(��Ʊ��С�ڵ��ڸ÷�ӳ������Ʊ������Ʊ��=��λ��һ��Ʊ��)��ע�⣬
����ͬһ��ӰƬ�������Ƭ�ڶ����ӳ����ӳ��������������Ʊ��Ϣ������ͬһ��ӰƬͬһ����ӳ��
ֻ��һ����Ʊ��Ϣ��
������ӰƬ���ƺͷ�ӳ����(�ꡤ�¡���)�������ӰƬ�����Ʊ����Ϣ(�ۿ�������Ʊ������)��ע�⣬
һ��ӰƬ�����ڶ����ӳ����ӳ��ÿ����ӳ����ͬ�ķ�ӳʱ��ۿ���Ӱ����������ͬ��
������ӰƬ���ƣ������ӰƬ�ڷ�ӳ�����ڵ�Ʊ����Ϣ(�ۿ�������Ʊ������)��
������һ������(�ꡤ�¡���)���������ÿһ��ӰƬ�Ĺۿ�������Ʊ�����룬��ͳ�Ƹ����ӰԺ��ȫ��ӰƬ��
�ۿ�������Ʊ�����롣
������һ������(�ꡤ��)��ͳ�Ƹ��µ�ӰԺ��Ʊ�����롣
������һ������(��2013��)��ͳ���ڸ�����ڷ�ӳ��ÿ��ӰƬ��Ʊ�������룬����Ʊ��������Ӹߵ��͵�˳��
��ӰƬ���ƺ�Ʊ��������������Ϣ����һ���ļ��С� 

*/ 
/*
��������ٶ�һ����ӳ������100���ˣ��Ͼ���Ŀû��˵�� 
���Ƕ����ӰԺ�ķ�ӳ��������λ���ı�ţ������к�һ��ʵ�ʱȽϺ� 
����ͬʱ�������Ա��¼ϵͳ �й���Ա������ ,����Ԥ��Ϊ123456 
������ΪӰƬ��ϢҲ�ǿ����޸ĵģ����Զ������޸ĺ��� 
���Ǽ����Ӱ���Ʋ�����30���֣����͡����Բ�����10���� 
���Ƕ����˵�Ӱ���
���Ǽ����ӰƱ���ȶ����� 
�����Զ����Ӱ�ۿ���������Ϊ���Ǹ�����ϵͳ 
���ǻ���������Ʊ��Ϣ�����ӡ�ɾ�����޸ĺ��� 
���ǹ涨��ϵͳ��������е�Ӱ��Ϊ2000��(����2000��)�Ժ�ĵ�Ӱ 
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
int frmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //����ȫ�ֱ�����������洢������ĸ��·����� 
int rmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31}; //����ȫ�ֱ�����������洢����ĸ��·�����

//�ṹ�����Ͷ��� 

typedef struct date             //�������� 
{
	int year;             		//�� 
	int month; 					//�� 
	int day; 					//�� 
}SDATE;
typedef struct dangqi           //�������� 
{ 								 
	int syear;					//��ʼ������� 
	int smonth;					//��ʼ�����·� 
	int sday;					//��ʼ�����շ� 
	int eyear;					//�����������
	int emonth;					//���������·�
	int eday;					//���������շ� 		
}Sdangqi; 
typedef struct time				//ʱ������ 
{
	int hour;					//Сʱ 
	int minute;					//���� 
}STIME;
typedef struct movie 			//��Ӱ���� 
{	
	int IMDB;					//��Ӱ��� 
	char name[30]; 				//��Ӱ���� 
	char type[10];				//��Ӱ���� (���顢���ˡ��ƻá����ѣ� 
	char language[10];			//��������(���ġ�Ӣ��) 
	float price;				//�۸�
	char room_num[10];			//��ӳ����� 
	SDATE print_date;			//��ӳ���� 
	Sdangqi print_dangqi;      	//��ӳ���� 
}SMOVIE;

typedef struct ticket			//Ʊ���� 
{
	int ITDB;					//��Ʊ��� 
	int id;						//���Ʊ�� 
	char name[30];				//��Ӱ����
	char room_num[10];			//��ӳ����� 
	float price;				//Ʊ�� 
	int chargenum;				//��Ʊ�� 
	SDATE print_date;			//��ӳ���� 
	STIME print_time;			//��ӳʱ�� 
}STICKET;

struct tik						//��Ʊͳ������ 
{	
	float in;					// ���� 
	char name[30];				//��Ӱ���� 
};

#define SMOVIE_LEN sizeof(SMOVIE)	 //��Ӱ����ռ�ô���ռ�Ĵ�С 
#define STICKET_LEN sizeof(STICKET)  //Ʊ����ռ�ô���ռ�Ĵ�С 
#define MOVIENUM 1000 				 // ��Ӱ�������ɰ������������ֵ
#define TICKETNUM 10000 			 //Ʊ�������ɰ������������ֵ
SMOVIE movie[MOVIENUM]={0}; 		 //��Ӱ���飨ȫ�ֱ����� 
STICKET ticket[TICKETNUM]={0};		 //Ʊ���飨ȫ�ֱ����� 

//�������� 

void menu();						//�˵����� 
void Createmovie(int i);            //����ӰƬ��Ϣ���� 
int Addmovie(int mn);				//����ӰƬ��Ϣ���� 
int Deletemovie(int mn);			//ɾ��ӰƬ��Ϣ���� 
void Modifymovie(int mn);			//�޸�ӰƬ��Ϣ���� 
void Outputonemovie(int i,int mn);	//���һ����Ӱ��Ϣ���� 
int LoadMovies(void);				//���ļ�����ȫ��ӰƬ��Ϣ���� 
int Originalmovie(void);			//��ʼ����Ӱ��Ϣ 
void Saveonemovie(int i);			//����һ����Ӱ��Ϣ 
void Saveallmovie(int i);			//����ȫ����Ӱ��Ϣ 
void outputAllmovie(int mn);		//���ȫ����Ӱ��ϸ��Ϣ�ĺ���
void outputBrief(int mn); 			//���ȫ����Ӱ��Ҫ��Ϣ�ĺ���
void Createticket(int i);			//������Ʊ��Ϣ���� 
int Addticket(int tn);				//������Ʊ��Ϣ���� 
int Deleteticket(int mn);			//ɾ����Ʊ��Ϣ���� 
void Modifyticket(int tn);			//�޸���Ʊ��Ϣ���� 
void Outputoneticket(int i);		//���һ����Ʊ��Ϣ���� 
int LoadTickets(void);				//���ļ�����ȫ����Ʊ��Ϣ���� 
int Originalticket(void);			//��ʼ����Ʊ��Ϣ 
void outputAllticket(int tn);		//���ȫ����Ʊ��ϸ��Ϣ�ĺ���
void outputbrieft(int tn); 			//���ȫ����Ʊ��Ҫ��Ϣ�ĺ���
void Saveoneticket(int i);			//����һ����Ʊ��Ϣ 
void Saveallticket(int i);			//����ȫ����Ʊ��Ϣ 
void Searchmovie(int mn);			//��ѯһ����Ӱ����Ϣ
void Searchticketmenu(int mn);		//Ʊ��ѯϵͳ 
void Searchticket1(int tn);			//�������ƺͷ�ӳ������������Ʊ����Ϣ 
void Searchticket2(int tn);			//�������������ӳ�����ڵ�Ʊ����Ϣ 
void Searchticket3(int tn);			//�����������������ÿһ��ӰƬ�ۿ�������Ʊ�����룬��ͳ�Ƹ����ӰԺȫ��ӰƬ�Ĺۿ�������Ʊ������ 
void Searchticket4(int tn);			//��������ͳ�Ƹ��µ�ӰԺ��Ʊ������ 
void Searchticket5(int tn);			//������ͳ�Ƹ�����ڷ�ӳ��ÿ��ӰƬƱ�������룬�Ӹߵ������򣬲������ƺ��������һ���ļ� 

void menu(int *pmn,int *ptn) 		//�˵����� 
{
	system("cls"); 					//���� 
	int select,flag1=0,flag2=0;
	char password[11];
	printf("\n����������: ");
	while(gets(password)!=NULL)
	{
		if(strcmp(password,"123456")!=0)
		{
			printf("\n�������!\n");
			printf("����������:");
			continue;
		}
		else break;
	}
	
	while(1)
	{
	printf("\n");
	printf("------------------------------------------\n");
	printf("     			  ��ӭ��                  \n");
	printf("  1.��ʼ��ӰƬ��Ϣ       7.��ʼ����Ʊ��Ϣ\n");
	printf("  2.����ӰƬ��Ϣ         8.������Ʊ��Ϣ   \n");
	printf("  3.ɾ��ӰƬ��Ϣ         9.ɾ����Ʊ��Ϣ  \n");
	printf("  4.�޸�ӰƬ��Ϣ         10.�޸���Ʊ��Ϣ \n");
	printf("  5.��ѯӰƬ��Ϣ         11.�����Ӱ��Ϣ  \n");	
	printf("  6.��ѯ��Ʊ��Ϣ         12.�����Ʊ��Ϣ  \n");
	printf("  0.�������˵�                            \n");
	printf("------------------------------------------\n");
	printf("\n ��ѡ������Ҫ�ķ���(0-12):");
	scanf("%d",&select);
	getchar();						//�ն� 
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
		case 11:printf("��ϸ��Ϣ�밴'1'����Ҫ��Ϣ�밴'2':");
			scanf("%d",&flag1);
			getchar();
			if(flag1==1)
				outputAllmovie(*pmn);
			if(flag1==2)
				outputBrief(*pmn); 
			break;
		case 12:printf("��ϸ��Ϣ�밴'1'����Ҫ��Ϣ�밴'2':");
			scanf("%d",&flag2);
			getchar();
			if(flag2==1)
				outputAllticket(*ptn);
			if(flag2==2)
				outputbrieft(*ptn); 
			break;
		case 0: return;
		default :printf("��������������ѡ��\n");
	}
	}
	
}

void Createmovie(int i)					//����ӰƬ��Ϣ 
{
	int q;
	printf("��Ӱ��ţ�");
	scanf("%d",&movie[i].IMDB);
	getchar();
	printf("ӰƬ����: ");
	gets(movie[i].name);
	printf("ӰƬ����: ");
	gets(movie[i].type);
	printf("��������: ");
	gets(movie[i].language);
	printf("Ʊ��: ");
	scanf("%f",&movie[i].price);
	while(movie[i].price<=0)
		{
			q=0;
			printf("�����������������룡\n"); 
			printf("Ʊ�ۣ�\n");
			scanf("%f",&q); 
			if(q>0)
			{
				q=movie[i].price;
				break;
			}
		}
	getchar();
	printf("��ӳ�����: ");
	gets(movie[i].room_num);
	printf("��ӳ����(��ʼ��� ��ʼ�·� ��ʼ�շ� ������� �����·� �����շ� )��\n"); 
	scanf("%d %d %d %d %d %d",&movie[i].print_dangqi.syear,&movie[i].print_dangqi.smonth,&movie[i].print_dangqi.sday,&movie[i].print_dangqi.eyear,&movie[i].print_dangqi.emonth,&movie[i].print_dangqi.eday);
	 
	getchar();
}

int LoadMovies(void)					//����ȫ����Ӱ����Ϣ 
{
	FILE *fm;
	int mn=0; //mn��¼��Ӱ���� 
	if((fm=fopen("movie.txt","r+"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		return(mn); //ʧ�ܷ���ֵΪ0 
	}
	while(!feof(fm)) //�ļ�û�н���ʱ���ж����ݲ��� 
		if(fread(&movie[mn],SMOVIE_LEN,1,fm)) 
			mn++; //���ļ���ÿ����һ����Ӱ����Ӱ������һ 
	fclose(fm);
	return mn;
}

void Saveonemovie(int i)				//����һ����Ӱ��Ϣ 
{
	FILE *fm;
	if((fm=fopen("movie.txt","r+"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1); 
	}
	fseek(fm,SMOVIE_LEN *i,0); //��λ����i����Ӱ
	fwrite(&movie[i],SMOVIE_LEN,1,fm); //����i����Ӱд���ļ�
	fclose(fm); 
}

void Saveallmovie(int mn)				//����ȫ����Ӱ��Ϣ 
{
	FILE *fm;
	if((fm=fopen("movie.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}
	fwrite(movie,SMOVIE_LEN,mn,fm);
	fclose(fm);
}

int Originalmovie(void)					//��ʼ����Ӱ��Ϣ 
{
	int n;
	char c='y';
	for(n=0;c=='y'||c=='Y';n++)
	{
		printf("\n�����Ӱ%d����Ϣ��\n",n+1);
		Createmovie(n);
		printf("\n���������밴'y',ֹͣ�����밴'n':");
		c=getchar();
		getchar();
	}
	Saveallmovie(n);
	return n;
}
 
int Addmovie(int mn)					//����ӰƬ��Ϣ 
{
	char c='y';
	FILE *fm;
	if((fm=fopen("movie.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}
	while(c=='y'||c=='Y')
	{
		printf("\n������������Ӱ����Ϣ��\n");
		Createmovie(mn);
		fwrite(&movie[mn],SMOVIE_LEN,1,fm);
		mn++;
		printf("\n�������������µ�Ӱ����Ϣô��<y/n>\n");
		c=getchar();
		getchar();
	}
	printf("\n�����������\n");
	getch();
	fclose(fm);
	return mn;
}

void Modifymovie(int mn)				//�޸�ӰƬ��Ϣ 
{
	
	int select,k=-1;
	int imdb,c1='y',c2;
	if(mn==0)
	{
		printf("\nӰƬ��ϢΪ�գ��޷����в�����\n");
		return; //���ع���Ա�˵� 
	}
	while(c1=='y'||c1=='Y')
	{
		c2='y';
		printf("\n������Ҫ�޸ĵĵ�Ӱ�ı�ţ�\n");
		scanf("%d",&imdb);
		getchar();
		for(int i=0;i<mn;i++)
		if(movie[i].IMDB==imdb)
		{
			k=i;
			break;
		}
		if(k<0) //������movie��û�ҵ���Ӧ�ĵ�Ӱ
			printf("\n����������������룡\n");
		else //�ҵ���Ӱ�����в��� 
		{
			printf("\n��ʾ��Ӱ��Ϣ��\n");
			Outputonemovie(k,mn);
			while(c2=='y'||c2=='Y')
			{
				printf("\n��Ӱ��Ϣ�������£�\n");
				printf("------------------------\n");
				printf("1.��Ӱ���     5.Ʊ��\n");
				printf("2.ӰƬ����     6.��ӳ�����\n");
				printf("3.ӰƬ����     7.��ӳ����\n");
				printf("4.��������              \n");
				printf("------------------------\n");
				printf("\n��ѡ��Ҫ�޸ĵ������1-7��: \n");
				scanf("%d",&select);
				getchar();
				switch(select)
				{
					case 1:printf("��Ӱ��ţ�"); scanf("%d",&movie[k].IMDB); break;
					case 2:printf("ӰƬ���ƣ�"); gets(movie[k].name); break;
					case 3:printf("ӰƬ���ͣ�"); gets(movie[k].type); break;
					case 4:printf("�������ࣺ"); gets(movie[k].language); break;
					case 5:printf("Ʊ�ۣ�"); scanf("%f",&movie[k].price); break;
					case 6:printf("��ӳ����ţ�"); gets(movie[k].room_num); break;
					case 7:printf("��ӳ����(��ʼ���.��ʼ�·�.��ʼ�շ�.�������.�����·�.�����շ�)��"); scanf("%d.%d.%d.%d.%d.%d",&movie[k].print_dangqi.syear,&movie[k].print_dangqi.smonth,&movie[k].print_dangqi.sday,&movie[k].print_dangqi.eyear,&movie[k].print_dangqi.emonth,&movie[k].print_dangqi.eday); break;
					default :printf("\n��������������ѡ��\n");		
				}
				printf("\n��Ҫ�����޸ĸõ�Ӱ��������Ϣô?<y/n>: \n");
				c2=getchar();
				getchar();
			}	
		}
		Saveonemovie(k);
		printf("\n��Ҫ�����޸�������Ӱ����Ϣô��<y/n>\n");
		c1=getchar();
		getchar();
	}
	printf("\n�����������\n");
	getch();
}

void Outputonemovie(int i,int mn)				//���һ����Ӱ��ȫ����Ϣ 
{	
	printf("\n");
	printf("ӰƬ���: ");
	printf("%d\n",movie[i].IMDB); 
	printf("ӰƬ����: ");
	puts(movie[i].name);
	printf("ӰƬ����: ");
	puts(movie[i].type);
	printf("��������: ");
	puts(movie[i].language);
	printf("Ʊ��: ");
	printf("%.2f\n",movie[i].price);
	printf("��ӳ�����: ");
	puts(movie[i].room_num);
	printf("��ӳ����: ");
	printf("��ӳ����(��ʼ��� ��ʼ�·� ��ʼ�շ� ������� �����·� �����շ� )��\n"); 
	printf("%d %d %d %d %d %d",movie[i].print_dangqi.syear,movie[i].print_dangqi.smonth,movie[i].print_dangqi.sday,movie[i].print_dangqi.eyear,movie[i].print_dangqi.emonth,movie[i].print_dangqi.eday);
}

int Deletemovie(int mn)					//ɾ��ӰƬ��Ϣ 
{
	int i,k=-1,j;
	int imdb,c1='y',c2;
	if(mn==0)
	{
		printf("\n��Ӱ��ϢΪ�գ��޷����в�����\n");
		return(mn);
	}
	while(c1=='y'||c1=='Y')
	{
		c2='n';
		printf("������Ҫɾ����Ӱ�ı��");
		scanf("%d",&imdb);
		getchar();
		for(i=0;i<mn;i++)
			if(movie[i].IMDB==imdb)
			{	k=i;
				break;
			}
		if(k<0)		//k<0��ʾû�ҵ� 
			printf("\n�����ӰƬ�����������������룡\n");
		else
		{
			printf("��ʾ�õ�Ӱ����Ϣ: \n");
			Outputonemovie(k,mn); 
			printf("\nȷ��Ҫɾ���õ�Ӱ��ȫ����Ϣô��<y/n>:");
			c2=getchar();
			getchar();
			if(c2=='y') //c2Ϊy��ȷ��ɾ�� 
			{
				for(i=k;i<mn;i++)
					movie[i]=movie[i+1];
				mn--; //��Ӱ����һ 
				printf("ɾ���ɹ�!");
			}
			else //c2Ϊn����ɾ�� 
				printf("\nɾ��ȡ��\n");
			printf("\n����ɾ��������Ӱ����Ϣô��<y/n>\n");
			c1=getchar();
			getchar();
		}
	}
	Saveallmovie(mn); //����ɾ�������Ϣ 
	printf("\n�����������\n");
	getch(); //��������Զ���ȡ�����ûس� 
	return(mn); //����ɾ����ĵ�Ӱ���� 
}

void Searchmovie(int mn)					//ӰƬ��ѯ����		
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
		printf("    ��ӭ����ӰƬ��ѯϵͳ   \n");
		printf("��Ӱ���------------------1\n");
		printf("ӰƬ����------------------2\n");
		printf("ӰƬ����------------------3\n"); 
		printf("��������------------------4\n"); 
		printf("Ʊ��----------------------5\n"); 
		printf("��ӳ�����----------------6\n"); 
		printf("��ӳ����------------------7\n");  
		printf("�˳�ϵͳ------------------0\n");
		printf("---------------------------\n");
		printf("\n");
		printf("������Ҫ��ѯ��ѡ��(�ɶ�ѡ)��\n");
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
					printf("\n�������Ӱ��ţ�");
					scanf("%d", &mimdb);
					getchar();
					flag1 = 1;
				}
				break;
		case '2':{
					printf("\n������ӰƬ���ƣ�");
					scanf("%s", mname);
					getchar();
					flag2 = 1;
				}
				break;	
		case '3':{
					printf("\n������ӰƬ���ͣ�");
					scanf("%s", mtype);
					getchar();
					flag3 = 1;
				}
				break;
		case '4':{printf("\n�������������ͣ�");
					scanf("%s", mlang);
					getchar();
					flag4 = 1;
				}
				break;
		case '5':{
					printf("\n������Ʊ�ۣ�");
					scanf("%f", &pr);
					getchar();
					flag5 = 1;
				}
				break;
		case '6':{
					printf("\n�������ӳ����ţ�");
					scanf("%s", mroom);
					getchar();
					flag6 = 1;
				}	
				break;
		case '7':{
					printf("\n�������ӳ���ڣ�");
					scanf("%d %d %d", &syear,&smonth,&sday);
					getchar();
					flag7 = 1;
				}
				break;
		case '0':return;
		default:("\n��������������ѡ��\n");
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
			printf("\nģ����ѯ�������:\n");
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
		printf("\n��Ǹ��δ��ѯ����Ӧ��Ӱ��Ϣ��\n"); 
	}
	
		printf("\n����������ز˵�\n");
		getch();
		
} 

void outputAllmovie(int mn)			//���ȫ����Ӱ��ϸ��Ϣ�ĺ���
{
	int i;
	printf("\nȫ����Ӱ����ϸ��Ϣ��\n");
	for(i=0;i<mn;i++)
	{
		Outputonemovie(i,mn);
		printf("\n�����������!\n");
		getch;		
	}
	printf("\nȫ����Ӱ��Ϣ������!\n");
	printf("\n�����������\n");
	getch(); 
}

void outputBrief(int mn) 			//���ȫ����Ӱ��Ҫ��Ϣ�ĺ���
{
	int i;
	printf("\nȫ����Ӱ�ļ�Ҫ��Ϣ\n");
	printf("\n��� ��Ӱ��� ��Ӱ����     Ʊ��          ��ӳ����\n");
	for(i=0;i<mn;i++)
	{
		printf("%2d   %-8d %-12s  %-2.2f    ",i+1,movie[i].IMDB,movie[i].name,movie[i].price);
		printf("%2d��%2d��%2d��-%2d��%2d��%2d��",movie[i].print_dangqi.syear,movie[i].print_dangqi.smonth,movie[i].print_dangqi.sday,movie[i].print_dangqi.eyear,movie[i].print_dangqi.emonth,movie[i].print_dangqi.eday);
		printf("\n");
	} 
	printf("\n�����������\n");
	getch(); 
}

void Createticket(int i)					//����Ʊ���� 
{
	printf("ӰƬ��ţ�");
	scanf("%d",&ticket[i].ITDB);
	getchar();
	printf("ӰƬ���ƣ�");
	gets(ticket[i].name);
	printf("���Ʊ�ţ�");
	scanf("%d",&ticket[i].id);
	getchar(); 
	printf("��ӳ����ţ�");
	gets(ticket[i].room_num);
	printf("��ӳ���ڣ��� �� ��\n");
	scanf("%d %d %d",&ticket[i].print_date.year,&ticket[i].print_date.month,&ticket[i].print_date.day);
	getchar();
	printf("��ӳʱ�䣺Сʱ ����\n");
	scanf("%d %d",&ticket[i].print_time.hour,&ticket[i].print_time.minute);
	getchar();
	printf("Ʊ�ۣ�");
	scanf("%f",&ticket[i].price);
	getchar();
	printf("��Ʊ����");
	scanf("%d",&ticket[i].chargenum);
	getchar();
	printf("��Ʊ��Ϊ��\n");
	printf("%d\n",100-ticket[i].chargenum); 
	
}

int LoadTickets(void)					//����ȫ����Ʊ����Ϣ 
{
	FILE *ft;
	int tn=0; //mn��¼��Ʊ���� 
	if((ft=fopen("ticket.txt","r+"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		return(tn); //ʧ�ܷ���ֵΪ0 
	}
	while(!feof(ft)) //�ļ�û�н���ʱ���ж����ݲ��� 
		if(fread(&ticket[tn],STICKET_LEN,1,ft)) 
			tn++; //���ļ���ÿ����һ����Ʊ����Ʊ������һ 
	fclose(ft);
	return tn;
}

void Saveoneticket(int i)				//����һ����Ʊ��Ϣ 
{
	FILE *ft;
	if((ft=fopen("ticket.txt","r+"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1); 
	}
	fseek(ft,STICKET_LEN *i,0); //��λ����i����Ʊ
	fwrite(&ticket[i],STICKET_LEN,1,ft); //����i����Ʊд���ļ�
	fclose(ft); 
}

void Saveallticket(int tn)				//����ȫ����Ʊ��Ϣ 
{
	FILE *ft;
	if((ft=fopen("ticket.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}
	fwrite(ticket,STICKET_LEN,tn,ft);
	fclose(ft);
}

int Originalticket(void)					//��ʼ����Ʊ��Ϣ 
{
	int n;
	char c='y';
	for(n=0;c=='y'||c=='Y';n++)
	{
		printf("\n����Ʊ%d����Ϣ��\n",n+1);
		Createticket(n);
		printf("\n���������밴'y',ֹͣ�����밴'n':");
		c=getchar();
		getchar();
	}
	Saveallticket(n);
	return n;
}
 
int Addticket(int tn)					//������Ʊ��Ϣ 
{
	char c='y';
	FILE *ft;
	if((ft=fopen("ticket.txt","w"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1);
	}
	while(c=='y'||c=='Y')
	{
		printf("\n������������Ʊ����Ϣ��\n");
		Createticket(tn);
		fwrite(&ticket[tn],STICKET_LEN,1,ft);
		tn++;
		printf("\n����������������Ʊ����Ϣô��<y/n>\n");
		c=getchar();
		getchar();
	}
	printf("\n�����������\n");
	getch();
	fclose(ft);
	return tn;
}

void Modifyticket(int tn)				//�޸���Ʊ��Ϣ 
{
	int select,k=-1;
	int itdb,c1='y',c2;
	if(tn==0)
	{
		printf("\n��Ʊ��ϢΪ�գ��޷����в�����\n");
		return; //���ع���Ա�˵� 
	}
	while(c1=='y'||c1=='Y')
	{
		c2='y';
		printf("\n������Ҫ�޸ĵ���Ʊ�ı�ţ�\n");
		scanf("%d",&itdb);
		for(int i=0;i<tn;i++)
		if(ticket[i].ITDB==itdb)
		{
			k=i;
			break;
		}
		if(k<0) //������ticket��û�ҵ���Ӧ�ĵ�Ӱ
			printf("\n����������������룡\n");
		else //�ҵ���Ʊ�����в��� 
		{
			printf("\n��ʾ��Ӱ��Ϣ��\n");
			Outputoneticket(k);
			while(c2=='y'||c2=='Y')
			{
				printf("\n��Ӱ��Ϣ�������£�\n");
				printf("--------------------------\n");
				printf("1.��Ʊ���      4.��ӳ����\n");
				printf("2.ӰƬ����      5.��ӳʱ��\n");
				printf("3.��ӳ�����    6.��Ʊ��\n");
				printf("7.�۸�          8.���Ʊ��\n");
				printf("--------------------------\n");
				printf("\n��ѡ��Ҫ�޸ĵ������1-8��: \n");
				scanf("%d",&select);
				getchar();
				switch(select)
				{
					case 1:printf("��Ʊ��ţ�"); scanf("%d",&ticket[k].ITDB); break;
					case 2:printf("ӰƬ���ƣ�"); gets(ticket[k].name); break;
					case 3:printf("��ӳ����ţ�"); gets(ticket[k].room_num); break;
					case 4:printf("��ӳ���ڣ�"); scanf("%d %d %d",&ticket[k].print_date.year,&ticket[k].print_date.month,&ticket[k].print_date.day); break;
					case 5:printf("��ӳʱ�䣺"); scanf("%d %d",&ticket[k].print_time.hour,&ticket[k].print_time.minute);break;
					case 6:printf("��Ʊ����"); scanf("%d",&ticket[k].chargenum); break;
					case 7:printf("�۸�"); scanf("%f",&ticket[k].price); break;
					case 8:printf("���Ʊ�ţ�"); scanf("%d",&ticket[k].id); break; 
					default :printf("\n��������������ѡ��\n");		
				}
				printf("\n��Ҫ�����޸ĸ���Ʊ��������Ϣô?<y/n>: \n");
				c2=getchar();
				getchar();
			}	
		}
		Saveoneticket(k);
		printf("\n��Ҫ�����޸�������Ʊ����Ϣô��<y/n>\n");
		c1=getchar();
		getchar();
	}
	printf("\n�����������\n");
	getch();
}

int Deleteticket(int tn)					//ɾ����Ʊ��Ϣ 
{
	int i,k=-1,j;
	int itdb,c1='y',c2;
	if(tn==0)
	{
		printf("\n��Ʊ��ϢΪ�գ��޷����в�����\n");
		return(tn);
	}
	while(c1=='y'||c1=='Y')
	{
		c2='n';
		printf("������Ҫɾ����Ʊ�ı�ţ�");
		scanf("%d",&itdb);
		for(i=0;i<tn;i++)
			if(ticket[i].ITDB==itdb)
			{	k=i;
				break;
			}
		if(k<0)		//k<0��ʾû�ҵ� 
			printf("\n�������Ʊ�����������������룡\n");
		else
		{
			printf("��ʾ����Ʊ����Ϣ: \n");
			Outputoneticket(k); 
			printf("\nȷ��Ҫɾ������Ʊ��ȫ����Ϣô��<y/n>:");
			c2=getchar();
			getchar();
			if(c2=='y') //c2Ϊy��ȷ��ɾ�� 
			{
				for(i=k;i<tn;i++)
					ticket[i]=ticket[i+1];
				tn--; //��Ʊ��Ϣ����һ 
				printf("ɾ���ɹ�!");
			}
			else //c2Ϊn����ɾ�� 
				printf("\nɾ��ȡ��\n");
			printf("\n����ɾ��������Ʊ����Ϣô��<y/n>\n");
			c1=getchar();
			getchar();
		}
	}
	Saveallticket(tn); //����ɾ�������Ϣ 
	printf("\n�����������\n");
	getch(); //��������Զ���ȡ�����ûس� 
	return(tn); //����ɾ�������Ʊ���� 
}

void Outputoneticket(int i)				//���һ����Ʊ��ȫ����Ϣ 
{	
	printf("\n");
	printf("ӰƬ��ţ�\n");
	printf("%d\n",ticket[i].ITDB); 
	printf("ӰƬ����: ");
	puts(ticket[i].name);
	printf("���Ʊ�ţ�");
	printf("%d\n",ticket[i].id);
	printf("��ӳ�����: ");
	puts(ticket[i].room_num);
	printf("��ӳ����: ");
	printf("%d��%d��%d��",ticket[i].print_date.year,ticket[i].print_date.month,ticket[i].print_date.day);
	printf("\n");
	printf("��ӳʱ��: ");
	printf("%dʱ%d��",ticket[i].print_time.hour,ticket[i].print_time.minute);
	printf("\n");
	printf("�۸�");
	printf("%.2f\n",ticket[i].price);
	printf("��Ʊ��: ");
	printf("%d\n",ticket[i].chargenum);
}

void outputAllticket(int tn)		//���ȫ����Ʊ��ϸ��Ϣ�ĺ���
{
	int i;
	printf("\nȫ����Ʊ����ϸ��Ϣ��\n");
	for(i=0;i<tn;i++)
	{
		Outputoneticket(i);
		printf("\n�����������!\n");
		getch;		
	}
	printf("\nȫ����Ʊ��Ϣ������!\n");
	printf("\n�����������\n");
	getch(); 
}

void outputbrieft(int tn) 			//���ȫ����Ʊ��Ҫ��Ϣ�ĺ���
{
	int i;
	printf("\nȫ����Ʊ�ļ�Ҫ��Ϣ\n");
	printf("\n��� ��Ʊ���  ��Ӱ����     ��ӳ�����    ��ӳ����           ��ӳʱ�� \n"); 
	for(i=0;i<tn;i++)
	{
		printf("%2d    %-2d       %-2s        %2s  ",i+1,ticket[i].ITDB,ticket[i].name,ticket[i].room_num);
		printf("      %2d��%2d��%2d��    ",ticket[i].print_date.year,ticket[i].print_date.month,ticket[i].print_date.day);
		printf("%2dʱ%2d����",ticket[i].print_time.hour,ticket[i].print_time.minute);
		printf("\n");
	
	}	
	printf("\n�����������\n");
	getch(); 
}

void Searchticketmenu(int tn)				//Ʊ��ѯ���� 
{
	system("cls"); 
	int choice=0;
	while(1)
	{
	printf("---------------------------\n");
	printf("    ��ӭ����Ʊ����ѯϵͳ   \n");
	printf("��ӰƬ���ƺͷ�ӳ���ڲ�ѯ--1\n");
	printf("��ӰƬ���Ʋ�ѯ������Ʊ��--2\n");
	printf("��һ�����ڲ�ѯ����Ʊ��----3\n");
	printf("��һ�����ڲ�ѯһ��������--4\n");
	printf("��һ�����ڲ�ѯһ��Ʊ��----5\n");
	printf("�˳���ѯϵͳ--------------0\n");
	printf("---------------------------\n");
	printf("\n");
	printf("��ѡ���ܣ�1-5����");
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
		default :printf("\n��������������ѡ��\n"); 
	}
	}
} 

void Searchticket1(int tn) 					// ����ӰƬ���ƺͷ�ӳ����(��xxxx����xx����xx)�������ӰƬ�����Ʊ����Ϣ
{
	char ssname[30];
	int  ssyear,ssmonth,ssday,i,k,num=0;
	printf("������ӰƬ����: ");
	gets(ssname);
	printf("�������ӳ����(�� �� ��): ");
	scanf("%d %d %d",&ssyear,&ssmonth,&ssday);
	getchar(); 
	while(ssyear<2000||ssmonth<=0||ssday<=0)
		{
			printf("�ܱ�Ǹ�����������ݻ����·ݻ����շݸ�ʽ���ԣ�\n");
			printf("���������룡\n"); 
			scanf("%d %d %d",&ssyear,&ssmonth,&ssday);
			getchar();
		}
		
	for(i=0;i<tn;i++)
	{
		k=0;
		if((strcmp(ticket[i].name,ssname)==0)&&(ssyear==ticket[i].print_date.year)&&(ticket[i].print_date.month==ssmonth)&&(ticket[i].print_date.day==ssday))
		{
			k=i;
			printf("ӰƬ���ƣ�%s �ۿ����������룺 %d,%.2f ��ӳ����ţ�%s",ticket[k].name,ticket[k].chargenum,ticket[k].price*ticket[k].chargenum*1.0,ticket[k].room_num);
			printf("\n");
			num+=1;
		}
	}
	if(num==0)
	{
		printf("��Ǹ��δ�ҵ�����ϵĵ�ӰƱ����Ϣ");
		return;
	}
	printf("\n�����������\n");
	getch();
}

void Searchticket2(int tn) 					//����ӰƬ���ƣ������ӰƬ�ڷ�ӳ�����ڵ�Ʊ����Ϣ(�ۿ�������Ʊ������)��

{
	char name[30];
	int peoplenum=0,num=0,i,k;
	float totalincome=0;
	printf("������ӰƬ���ƣ�\n");
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
		printf("��Ǹ��δ�ҵ�����ϵĵ�ӰƱ����Ϣ");
		return;
	}
	else
	{
		printf("���Ʊ����Ϣ���£�\n");
		printf("\n�ۿ�����:%d��     Ʊ������:%.2fԪ\n",peoplenum,totalincome);
	}
	printf("\n�����������\n");
	getch();
}

void Searchticket3(int tn) 				            //����һ������(��xxxx����xx����xx)���������ÿһ��ӰƬ�Ĺۿ�������Ʊ������
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
	printf("�����������ѯ�����ڣ��� �� �գ���");
	scanf("%d %d %d",&year,&month,&day);
	getchar(); 
	while(year<0||month<=0||day<=0||month>12||day>31||(year%4==0&&year%100!=0&&year%400==0&&month>rmonth[month-1])||(year%4!=0&&year%100==0&&year%400!=0&&month>frmonth[month-1]))
		{
			printf("�ܱ�Ǹ������������ڲ��Ϸ���\n");
			printf("���������룡\n"); 
			printf("����������Ҫ��ѯ�����ڣ���.��.�գ�:");
			scanf("%d %d %d",&year,&month,&day);
			getchar(); 
		}
	while(year<2000&&year>0)
		{
			printf("�ܱ�Ǹ,����������ںϷ���С�����ǵ�ӰԺ����С����ݣ�\n");
			printf("���������룡\n"); 
			printf("����������Ҫ��ѯ�����ڣ���.��.�գ�:");
			scanf("%d %d %d",&year,&month,&day);
			getchar();
		}
	printf("��Ӧ��Ϣ���£�\n");
	printf(" ��Ӱ����  �ۿ�����  Ʊ������\n");	
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
	printf("�ܹۿ�������%d  ��Ʊ�����룺%.2f\n",peoplenum,totalincome);
	printf("\n�����������\n");
	getch();
}

void Searchticket4(int tn) 					//����һ������(��xxxx����xx)��ͳ�Ƹ��µ�ӰԺ��Ʊ�����롣
{
	int year,month;
	char dian;
	float totalincome,income;
	int i=0; 
	int peoplenum;
	printf("����������Ҫ��ѯ�����ڣ��� �£�:");
	scanf("%d %d",&year,&month);
	getchar();
		while(year<=0||month<=0||month>12||(year%4==0&&year%100!=0&&year%400==0&&month>rmonth[month-1])||(year%4!=0&&year%100==0&&year%400!=0&&month>frmonth[month-1]))
		{
			printf("�ܱ�Ǹ������������ڲ��Ϸ���\n");
			printf("���������룡:\n"); 
			printf("����������Ҫ��ѯ�����ڣ���.�£�:");
			scanf("%d %d",&year,&month);
			getchar();
		}
		while(year<2000&&year>0)
		{
			printf("�ܱ�Ǹ,����������ںϷ���С�����ǵ�ӰԺ����С����ݣ�\n");
			printf("���������룡"); 
			printf("����������Ҫ��ѯ�����ڣ���.�£�:");
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
	printf("\n%d��%d�µ�Ʊ�����빲�ƣ�%.2fԪ\n",year,month,totalincome);
	printf("\n�����������\n");
	getch();
}

void Searchticket5(int tn) 					//����һ������(��2013��)��ͳ���ڸ�����ڷ�ӳ��ÿ��ӰƬ��Ʊ��������
{
	int year;
	int peoplenum=0;
	float income,totalincome=0;
	float temp;
	struct tik ti[100];
	int i,k=0,j,q;
	printf("����������Ҫ��ѯ�����ڣ���xxxx����");
	scanf("%d",&year);
	getchar();
	while(year<=0)
		{
			printf("�ܱ�Ǹ������������ڲ��Ϸ���\n");
			printf("���������룡\n"); 
			printf("����������Ҫ��ѯ�����ڣ���xxxx��:");
			scanf("%d",&year);
			getchar();
		}
	while(year<2000&&year>0)
		{
			printf("�ܱ�Ǹ,����������ںϷ���С�����ǵ�ӰԺ����С����ݣ�\n");
			printf("���������룡\n"); 
			printf("����������Ҫ��ѯ�����ڣ��꣩:");
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
	printf("\nӰƬ����   Ʊ������\n");
	for(i=0;i<=k;i++)
	{
		printf("%s   %.2f\n",ti[i].name,ti[i].in);
	} 
	printf("%d���Ʊ�����빲�ƣ�%.2fԪ",year,totalincome);
	FILE *fp;
	if((fp=fopen("rank.txt","w+"))==NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(1); 
	}
	fseek(fp,SMOVIE_LEN *i,0); //��λ����i����Ӱ
	for(j=0;j<=k;j++)
		fprintf(fp,"%s  %.2f\n",ti[j].name,ti[j].in); //����i����Ӱд���ļ�
	fclose(fp); 
	printf("\n�����������\n");
	getch();
}


int main()
{
	int select,mn,tn,rn;
	mn=LoadMovies();
	if(mn==0)
		printf("��Ӱ��ϢΪ�գ�\n\n");
	tn=LoadMovies();
	if(tn==0)
		printf("Ʊ��ϢΪ�գ�\n\n");
	int *pmn=&mn;
	int *ptn=&tn;
	while(1)
	{
		printf("\n");
		printf("\t--------------------\n");
		printf("\t                    \n");
		printf("\t   ��ӰԺ����ϵͳ   \n");
		printf("\t                    \n");
		printf("\t       1.����       \n");
		printf("\t       0.�ǳ�       \n");
		printf("\t                    \n");
		printf("\t--------------------\n");
		printf("\t��ѡ��");
		scanf("%d",&select);
		getchar();
		switch(select)
		{
			case 1:menu(&mn,&tn);
			case 0:printf("ллʹ�ã��ټ���\n"); exit(1);
			default:printf("\n��������������ѡ��\n");
		} 
	}
	return 0;
}

