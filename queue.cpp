#include <bits/stdc++.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class SeqQueue //循环队列类定义
{ 
	public:
	SeqQueue(int sz=20); //构造函数
	~SeqQueue() { delete []elements; } //析构函数
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
	T *elements; //元素存放数组
	int front, rear; //头指针，尾指针
	int maxSize; //队列最大容量
};

template <class T>
SeqQueue<T>::SeqQueue(int sz)
: front(0), rear(0), maxSize(sz) //构造函数
{
	elements = new T[maxSize];
	assert ( elements != NULL );
}
template <class T>
bool SeqQueue<T>::EnQueue(T x)
{ 
	//若队列不满, 则将x插入到该队列队尾, 否则返回false
	if (IsFull() == true) return false;
	elements[rear] = x; //插入x
	rear = (rear+1) % maxSize; //尾指针加1
	return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T& x)
{ 
	//若队列不空则函数退队头元素并返回其值
	if ( IsEmpty() == true) return false;
	x = elements[front]; //取队头元素
	front = (front+1) % maxSize; //队头指针加1
	return true;
}
template <class T>
bool SeqQueue<T>::getFront(T& x)
{	 //若队列不空则函数返回该队列队头元素的值
	if ( IsEmpty() ) return false; //队列空
	x = elements[front]; //取队头元素
	return true;
}

template <class T>
void SeqQueue<T>::output() //从队头到队尾依次输出
{ 
	if( IsEmpty() )
	{ cout<<"队空"<<endl; return; }
	for(int i=front; i!=rear; i=(i+1)%maxSize)
	cout<<setw(5)<<elements[i];
	cout<<endl;
}



int main()
{

	return 0;
}

