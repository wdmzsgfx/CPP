#include <bits/stdc++.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class SeqQueue //ѭ�������ඨ��
{ 
	public:
	SeqQueue(int sz=20); //���캯��
	~SeqQueue() { delete []elements; } //��������
	bool EnQueue(T x);
	bool DeQueue(T& x);
	bool getFront(T& x);
	bool IsEmpty() const { return (front==rear); }
	bool IsFull() const
	{ return ((rear+1)%maxSize == front); }
	int getSize()const
	{ return (rear-front+maxSize)%maxSize; }
	void makeEmpty() { front=rear=0; }
	void output();
	private:
	T *elements; //Ԫ�ش������
	int front, rear; //ͷָ�룬βָ��
	int maxSize; //�����������
};

template <class T>
SeqQueue<T>::SeqQueue(int sz)
: front(0), rear(0), maxSize(sz) //���캯��
{
	elements = new T[maxSize];
	assert ( elements != NULL );
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{ 
	//�����в���, ��x���뵽�ö��ж�β, ���򷵻�false
	if (IsFull() == true) return false;
	elements[rear] = x; //����x
	rear = (rear+1) % maxSize; //βָ���1
	return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T& x)
{ 
	//�����в��������˶�ͷԪ�ز�������ֵ
	if ( IsEmpty() == true) return false;
	x = elements[front]; //ȡ��ͷԪ��
	front = (front+1) % maxSize; //��ͷָ���1
	return true;
}
template <class T>
bool SeqQueue<T>::getFront(T& x)
{	 //�����в����������ظö��ж�ͷԪ�ص�ֵ
	if ( IsEmpty() ) return false; //���п�
	x = elements[front]; //ȡ��ͷԪ��
	return true;
}

template <class T>
void SeqQueue<T>::output() //�Ӷ�ͷ����β�������
{ 
	if( IsEmpty() )
	{ cout<<"�ӿ�"<<endl; return; }
	for(int i=front; i!=rear; i=(i+1)%maxSize)
	cout<<setw(5)<<elements[i];
	cout<<endl;
}



int main()
{

	return 0;
}

