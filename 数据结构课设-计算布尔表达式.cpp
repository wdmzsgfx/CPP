#include <bits/stdc++.h>
#include <cstdio>
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxStack=100;
const int Increament=100;
 
template <class T>
class SeqStack //顺序栈类定义
{ 
	public:
	SeqStack(int sz=50); //构造函数
	~SeqStack() { delete []elements; } //析构函数
	void Push(const T& x); //进栈
	bool Pop(T& x); //出栈
	bool getTop(T& x); //取栈顶元素
	bool IsEmpty() const { return (top == -1)?true:false; }
	bool IsFull() const { return (top == maxSize-1)?true:false;  }
	int getSize()const { return top+1; }
	void MakeEmpty() { top= -1; }
	void output();
	
	private:
	T *elements; //栈元素存放数组
	int top; //栈顶指针
	int maxSize; //栈最大容量
	void overflowProcess(); //栈的溢出处理
};

template <class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz)
{ 
	elements=new T[maxSize];
	assert(elements!=NULL);//断言：动态存储分配成功与否 
}

template <class T>
void SeqStack<T>::overflowProcess() //栈满，溢出处理
{ 
	T *newArray = new T[maxSize+Increament];
	assert(newArray!=NULL);
	for (int i = 0; i <= top; i++)
		newArray[i] = elements[i];
	maxSize = maxSize+Increament;
	delete [ ]elements;
	elements = newArray;
}

template <class T>
void SeqStack<T>::Push(const T& x)
{ 
	//若栈不满, 则将元素x插入栈顶, 否则溢出处理
	if (IsFull() == true) overflowProcess(); //栈满
	elements[++top] = x; //栈顶指针先加1, x再进栈
}

template <class T>
bool SeqStack<T>::Pop(T& x)
{ 
	//若栈不空，返回栈顶元素的值，栈顶指针退1
	if (IsEmpty() == true) return false;
	x = elements[top--]; //栈顶指针退1
	return true; //退栈成功
}

template <class T>
bool SeqStack<T>::getTop(T& x)
{ 	//若栈不空则函数返回该栈栈顶元素的值
	if (IsEmpty() == true) return false;
	x = elements[top]; return true;
}


template <class T>
void SeqStack<T>::output()
{ 
	cout<<"top="<<top<<endl;
	if(top== -1) cout<<"空栈！";
	else { for(int i=0; i<=top; i++)
	cout<<setw(5)<<elements[i]; }
	cout<<endl;
}

bool Match(char *expression) //括号匹配 
{ 
	SeqStack<char> S(100); char ch, x;
	int i, length=strlen(expression);
	for(i=0; i<length; i++)
	{ 
		ch=expression[i];
		if(ch=='(' ) S.Push(ch);
		else if(ch==')' )
			if ( S.Pop(x)==false)
				{ cerr<<"括号不匹配"<<endl;
				return false; }
	}
	if(S.IsEmpty()==false)
	{ cerr<<"括号匹配失败"<<endl; return false; }
}

class Calculator
{
	public:
		Calculator(int sz): s(sz){}//构造函数 
		void Run(string e); //执行表达式计算
		void FrontRun(string e); //前缀计算 
		string MediumToPost(string e); //中缀转后缀 
		
	private:
		 SeqStack<char> s; //栈对象定义 
		 char DoOperator(char op,char left,char right); //形成运算指令，进行计算 
		 bool ComparePriority(char l1,char r1); //比较运算优先级 
};

char Calculator::DoOperator(char op,char left,char right)
{
	switch(op)
		{
			case '!': //非运算 
				if(left == 'T')
				return 'F';
				else
				return 'T';
				break;
			case '&': //与运算 
				if(left == 'T'&&right == 'T')
				return 'T';
				else
				return 'F';
				break;
			case '|': //或运算 
				if(left == 'F'&&right == 'F')
				return 'F';
				else
				return 'T';
				break;
			default:
				return ' ';
		}
};

void Calculator::FrontRun(string e)
{
	char aa[100];
	char value;
	strcpy(aa,e.c_str());
	int i;
	for(i=0;i<strlen(aa);i++)
	{
		if(aa[i] != 'F' && aa[i] != 'T' && aa[i] != '!' &&
		 aa[i] != '&' && aa[i] != '|' && aa[i] != ' ' &&
		 aa[i] != '(' && aa[i] != ')' )
		 {cerr<<"输入符号有错误！"<<endl;}
	}
	if(!(Match(aa)))
	{
		cout<<"表达式处理出错！"<<endl;
	}
	for(i=strlen(aa)-1;i>=0;i--)
	{
		if(aa[i]=='T'||aa[i]=='F') //遇到T/F进栈 
			s.Push(aa[i]);
		else if(aa[i] != ' ')
		{
			char c1;
			s.Pop(c1);
			char temp;
			if(aa[i] == '!') //非运算只需要一个元素 
			{
				temp= DoOperator(aa[i],c1,' '); //存储中间运算结果 
			}	
			else
			{
				char c2; //弹出栈顶第二个元素 
				s.Pop(c2); 
				temp = DoOperator(aa[i],c1,c2);
			}
			s.Push(temp);
		}
	}
	s.getTop(value);
	cout<<"结果为"<<value<<endl;
	s.MakeEmpty();
} 

string Calculator::MediumToPost(string e)
{
	char t,x,y,u,o,chuzhan;
	SeqStack<char> oper; //运算符栈 
	SeqStack<char> Medium; //中间结果栈 
	char transform[100];
	strcpy(transform,e.c_str()); //字符串转字符数组 
	int i;
	for(i=0;i<strlen(transform);i++)
	{
		if(transform[i] != 'F' && transform[i] != 'T' && transform[i] != '!' &&
		 transform[i] != '&' && transform[i] != '|' && transform[i] != ' ' &&
		 transform[i] != '(' && transform[i] != ')' )
		 {cerr<<"输入符号有错误！"<<endl;}
	}
	if(!(Match(transform)))
	{
		cout<<"表达式处理出错！"<<endl;
	}
	else
	{
		for(i=0;i<strlen(transform);i++) //从左到右扫描 
		{
			if(transform[i] == 'T' || transform[i] == 'F')
			{
				Medium.Push(transform[i]); //T,F入栈 
			}
			else if(transform[i] == '(')
			{
				oper.Push(transform[i]); //左括号入栈 
			}
			else if(transform[i] == ')')
			{
				oper.getTop(t);
				while(t != '(')
				{
					oper.Pop(x);
					Medium.Push(x);
					oper.getTop(t);
				}
				oper.Pop(chuzhan); //左括号出栈 
			}
			else if(transform[i] != ' ')
			{
				//运算符比较栈顶优先级，栈空或左括号入栈，优先级比栈顶高的入栈 
				//否则栈顶出栈进中间栈，然后再让运算符与栈顶比较优先级
				 while(true)
				 {
				 	oper.getTop(y);
				 	if(oper.IsEmpty() || y == '(' || ComparePriority(transform[i],y))
				 	{
				 		oper.Push(transform[i]);
				 		break;
					}
					else
					{
					 	oper.Pop(u);
					 	Medium.Push(u);
					}
				 }
			}
		}
	}
	//将运算符全部入中间栈
	while(!oper.IsEmpty())
	{
		oper.Pop(o);
		Medium.Push(o);	
	} 
	//中间栈数据依次出栈，并输出,结果的逆序为中缀表达式的后缀表达式
	int num;
	num=Medium.getSize();
	char temp[num]; 
	for(i=0;!Medium.IsEmpty();i++)
	{
		Medium.Pop(temp[i]);
	}
	string str="";
	for(i=strlen(temp)-1;i>=0;i--)
	{
		str += temp[i];
	} 
	oper.MakeEmpty();
	Medium.MakeEmpty();
	return str;
}

void Calculator::Run(string e)
{
	char aa[100];
	char value;
	strcpy(aa,e.c_str());
	int i;
	for(i=0;i<strlen(aa);i++)
	{
		if(aa[i] != 'F' && aa[i] != 'T' && aa[i] != '!' &&
		 aa[i] != '&' && aa[i] != '|' && aa[i] != ' ' &&
		 aa[i] != '(' && aa[i] != ')' )
		 {cerr<<"输入符号有错误！"<<endl;}
	}
	if(!(Match(aa)))
	{
		cout<<"表达式处理出错！"<<endl;
	}
	for(i=0;i<strlen(aa);i++)
	{
		if(aa[i]=='T'||aa[i]=='F') //遇到T/F进栈 
			s.Push(aa[i]);
		else if(aa[i] != ' ')
		{
			char c1;
			s.Pop(c1);
			char temp;
			if(aa[i] == '!') //非运算只需要一个元素 
			{
				temp= DoOperator(aa[i],c1,' '); //存储中间运算结果 
			}	
			else
			{
				char c2; //弹出栈顶第二个元素 
				s.Pop(c2); 
				temp = DoOperator(aa[i],c1,c2);
			}
			s.Push(temp);
		}
	}
	s.getTop(value);
	cout<<"结果为"<<value<<endl;
	s.MakeEmpty();
}

bool Calculator::ComparePriority(char l1,char r1)
{
	int p1=0,p2=0;
	switch(l1)
	{
		case '!':
			p1=3;
			break;
		case '&':
			p1=2;
			break;
		case '|':
			p1=1;
			break;
	}
	switch(r1)
	{
		case '!':
			p2=3;
			break;
		case '&':
			p2=2;
			break;
		case '|':
			p2=1;
			break;
	}
	return p1-p2>0;
}

void help()
{
	printf("\n");
	printf("计算布尔表达式,例如：(T|T)&F&(F|T),其计算结果为 F。\n");
	printf("其中 T 表示 True，F 表示 False，表达式只包含三种运算符：\n");
	printf("！表示not，&表示and,|表示or，优先级的高低依次是!->&->|,\n");
	printf("表达式允许用（），括号的优先级最高。\n");
	printf("\n");
}

void annotation()
{
	cout <<"仅做测试使用"<<endl; 
}

void menu()
{
	printf("*********************************\n");
	printf("     欢迎使用布尔表达式计算器    \n");
	printf("\n"); 
	printf("功能1：前缀表达式计算\n");
	printf("功能2：中缀表达式计算\n");
	printf("功能3：后缀表达式计算\n");
	printf("功能4：使用帮助\n");
	printf("退出系统：0\n");
	printf("*********************************\n");
	int k;
	cout<<"请选择要使用的功能：";
	cin >> k;
	while(k!=0)
	{
		if(k==1)
		{
			Calculator TEST(100);
			string test;
			cout<<endl;
			cout<<"请输入要计算的表达式：" ; 
			cin >> test;
			TEST.FrontRun(test);
			cout << endl;
			cout<<"请选择要使用的功能：";
			cin >> k;
		}
		else if(k==2)
		{
			Calculator TEST(100);
			string test,newtest;
			cout<<endl;
			cout<<"请输入要计算的表达式：" ; 
			cin >> test;
			newtest = TEST.MediumToPost(test);
			TEST.Run(newtest);
			cout << endl;
			cout<<"请选择要使用的功能：";
			cin >> k;
		}
		else if(k==3)
		{
			Calculator TEST(100);
			string test;
			cout<<endl;
			cout<<"请输入要计算的表达式：" ; 
			cin >> test;
			TEST.Run(test);
			cout << endl;
			cout<<"请选择要使用的功能：";
			cin >> k;
		}
		else if(k==4)
		{
			help();
			cout<<"请选择要使用的功能：";
			cin >> k;
		}
		else
		{
			cout<<"输入错误，请重新输入:";
			cin >> k;
		}
	}
	exit(0); 
}

int main()
{	
	menu();
	return 0;
}

