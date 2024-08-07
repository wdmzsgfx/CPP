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
class SeqStack //˳��ջ�ඨ��
{ 
	public:
	SeqStack(int sz=50); //���캯��
	~SeqStack() { delete []elements; } //��������
	void Push(const T& x); //��ջ
	bool Pop(T& x); //��ջ
	bool getTop(T& x); //ȡջ��Ԫ��
	bool IsEmpty() const { return (top == -1)?true:false; }
	bool IsFull() const { return (top == maxSize-1)?true:false;  }
	int getSize()const { return top+1; }
	void MakeEmpty() { top= -1; }
	void output();
	
	private:
	T *elements; //ջԪ�ش������
	int top; //ջ��ָ��
	int maxSize; //ջ�������
	void overflowProcess(); //ջ���������
};

template <class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz)
{ 
	elements=new T[maxSize];
	assert(elements!=NULL);//���ԣ���̬�洢����ɹ���� 
}

template <class T>
void SeqStack<T>::overflowProcess() //ջ�����������
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
	//��ջ����, ��Ԫ��x����ջ��, �����������
	if (IsFull() == true) overflowProcess(); //ջ��
	elements[++top] = x; //ջ��ָ���ȼ�1, x�ٽ�ջ
}

template <class T>
bool SeqStack<T>::Pop(T& x)
{ 
	//��ջ���գ�����ջ��Ԫ�ص�ֵ��ջ��ָ����1
	if (IsEmpty() == true) return false;
	x = elements[top--]; //ջ��ָ����1
	return true; //��ջ�ɹ�
}

template <class T>
bool SeqStack<T>::getTop(T& x)
{ 	//��ջ�����������ظ�ջջ��Ԫ�ص�ֵ
	if (IsEmpty() == true) return false;
	x = elements[top]; return true;
}


template <class T>
void SeqStack<T>::output()
{ 
	cout<<"top="<<top<<endl;
	if(top== -1) cout<<"��ջ��";
	else { for(int i=0; i<=top; i++)
	cout<<setw(5)<<elements[i]; }
	cout<<endl;
}

bool Match(char *expression) //����ƥ�� 
{ 
	SeqStack<char> S(100); char ch, x;
	int i, length=strlen(expression);
	for(i=0; i<length; i++)
	{ 
		ch=expression[i];
		if(ch=='(' ) S.Push(ch);
		else if(ch==')' )
			if ( S.Pop(x)==false)
				{ cerr<<"���Ų�ƥ��"<<endl;
				return false; }
	}
	if(S.IsEmpty()==false)
	{ cerr<<"����ƥ��ʧ��"<<endl; return false; }
}

class Calculator
{
	public:
		Calculator(int sz): s(sz){}//���캯�� 
		void Run(string e); //ִ�б��ʽ����
		void FrontRun(string e); //ǰ׺���� 
		string MediumToPost(string e); //��׺ת��׺ 
		
	private:
		 SeqStack<char> s; //ջ������ 
		 char DoOperator(char op,char left,char right); //�γ�����ָ����м��� 
		 bool ComparePriority(char l1,char r1); //�Ƚ��������ȼ� 
};

char Calculator::DoOperator(char op,char left,char right)
{
	switch(op)
		{
			case '!': //������ 
				if(left == 'T')
				return 'F';
				else
				return 'T';
				break;
			case '&': //������ 
				if(left == 'T'&&right == 'T')
				return 'T';
				else
				return 'F';
				break;
			case '|': //������ 
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
		 {cerr<<"��������д���"<<endl;}
	}
	if(!(Match(aa)))
	{
		cout<<"���ʽ�������"<<endl;
	}
	for(i=strlen(aa)-1;i>=0;i--)
	{
		if(aa[i]=='T'||aa[i]=='F') //����T/F��ջ 
			s.Push(aa[i]);
		else if(aa[i] != ' ')
		{
			char c1;
			s.Pop(c1);
			char temp;
			if(aa[i] == '!') //������ֻ��Ҫһ��Ԫ�� 
			{
				temp= DoOperator(aa[i],c1,' '); //�洢�м������� 
			}	
			else
			{
				char c2; //����ջ���ڶ���Ԫ�� 
				s.Pop(c2); 
				temp = DoOperator(aa[i],c1,c2);
			}
			s.Push(temp);
		}
	}
	s.getTop(value);
	cout<<"���Ϊ"<<value<<endl;
	s.MakeEmpty();
} 

string Calculator::MediumToPost(string e)
{
	char t,x,y,u,o,chuzhan;
	SeqStack<char> oper; //�����ջ 
	SeqStack<char> Medium; //�м���ջ 
	char transform[100];
	strcpy(transform,e.c_str()); //�ַ���ת�ַ����� 
	int i;
	for(i=0;i<strlen(transform);i++)
	{
		if(transform[i] != 'F' && transform[i] != 'T' && transform[i] != '!' &&
		 transform[i] != '&' && transform[i] != '|' && transform[i] != ' ' &&
		 transform[i] != '(' && transform[i] != ')' )
		 {cerr<<"��������д���"<<endl;}
	}
	if(!(Match(transform)))
	{
		cout<<"���ʽ�������"<<endl;
	}
	else
	{
		for(i=0;i<strlen(transform);i++) //������ɨ�� 
		{
			if(transform[i] == 'T' || transform[i] == 'F')
			{
				Medium.Push(transform[i]); //T,F��ջ 
			}
			else if(transform[i] == '(')
			{
				oper.Push(transform[i]); //��������ջ 
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
				oper.Pop(chuzhan); //�����ų�ջ 
			}
			else if(transform[i] != ' ')
			{
				//������Ƚ�ջ�����ȼ���ջ�ջ���������ջ�����ȼ���ջ���ߵ���ջ 
				//����ջ����ջ���м�ջ��Ȼ�������������ջ���Ƚ����ȼ�
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
	//�������ȫ�����м�ջ
	while(!oper.IsEmpty())
	{
		oper.Pop(o);
		Medium.Push(o);	
	} 
	//�м�ջ�������γ�ջ�������,���������Ϊ��׺���ʽ�ĺ�׺���ʽ
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
		 {cerr<<"��������д���"<<endl;}
	}
	if(!(Match(aa)))
	{
		cout<<"���ʽ�������"<<endl;
	}
	for(i=0;i<strlen(aa);i++)
	{
		if(aa[i]=='T'||aa[i]=='F') //����T/F��ջ 
			s.Push(aa[i]);
		else if(aa[i] != ' ')
		{
			char c1;
			s.Pop(c1);
			char temp;
			if(aa[i] == '!') //������ֻ��Ҫһ��Ԫ�� 
			{
				temp= DoOperator(aa[i],c1,' '); //�洢�м������� 
			}	
			else
			{
				char c2; //����ջ���ڶ���Ԫ�� 
				s.Pop(c2); 
				temp = DoOperator(aa[i],c1,c2);
			}
			s.Push(temp);
		}
	}
	s.getTop(value);
	cout<<"���Ϊ"<<value<<endl;
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
	printf("���㲼�����ʽ,���磺(T|T)&F&(F|T),�������Ϊ F��\n");
	printf("���� T ��ʾ True��F ��ʾ False�����ʽֻ���������������\n");
	printf("����ʾnot��&��ʾand,|��ʾor�����ȼ��ĸߵ�������!->&->|,\n");
	printf("���ʽ�����ã��������ŵ����ȼ���ߡ�\n");
	printf("\n");
}

void annotation()
{
	cout <<"��������ʹ��"<<endl; 
}

void menu()
{
	printf("*********************************\n");
	printf("     ��ӭʹ�ò������ʽ������    \n");
	printf("\n"); 
	printf("����1��ǰ׺���ʽ����\n");
	printf("����2����׺���ʽ����\n");
	printf("����3����׺���ʽ����\n");
	printf("����4��ʹ�ð���\n");
	printf("�˳�ϵͳ��0\n");
	printf("*********************************\n");
	int k;
	cout<<"��ѡ��Ҫʹ�õĹ��ܣ�";
	cin >> k;
	while(k!=0)
	{
		if(k==1)
		{
			Calculator TEST(100);
			string test;
			cout<<endl;
			cout<<"������Ҫ����ı��ʽ��" ; 
			cin >> test;
			TEST.FrontRun(test);
			cout << endl;
			cout<<"��ѡ��Ҫʹ�õĹ��ܣ�";
			cin >> k;
		}
		else if(k==2)
		{
			Calculator TEST(100);
			string test,newtest;
			cout<<endl;
			cout<<"������Ҫ����ı��ʽ��" ; 
			cin >> test;
			newtest = TEST.MediumToPost(test);
			TEST.Run(newtest);
			cout << endl;
			cout<<"��ѡ��Ҫʹ�õĹ��ܣ�";
			cin >> k;
		}
		else if(k==3)
		{
			Calculator TEST(100);
			string test;
			cout<<endl;
			cout<<"������Ҫ����ı��ʽ��" ; 
			cin >> test;
			TEST.Run(test);
			cout << endl;
			cout<<"��ѡ��Ҫʹ�õĹ��ܣ�";
			cin >> k;
		}
		else if(k==4)
		{
			help();
			cout<<"��ѡ��Ҫʹ�õĹ��ܣ�";
			cin >> k;
		}
		else
		{
			cout<<"�����������������:";
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

