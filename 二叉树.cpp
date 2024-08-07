# include <iostream>
#include<cstdlib>
#include <assert.h>
#include<iomanip>
using namespace std;
void out_of_memory(void) {
	cerr << "Error: Out of memory" << endl ;
	exit( 1 ) ;
}
template <class T>
class SeqQueue { //ѭ�������ඨ��
	public:
		SeqQueue(int sz=20); //���캯��
		~SeqQueue() {
			delete []elements;    //��������
		}
		bool EnQueue(T x);
		bool DeQueue(T& x);
		bool getFront(T& x);
		bool IsEmpty() const {
			return (front==rear);
		}
		bool IsFull() const {
			return ((rear+1)%maxSize == front);
		}
		int getSize()const {
			return (rear-front+maxSize)%maxSize;
		}
		void makeEmpty() {
			front=rear=0;
		}
		void output();
	private:
		T *elements; //Ԫ�ش������
		int front, rear; //ͷָ�룬βָ��
		int maxSize; //�����������
};
template <class T>
SeqQueue<T>::SeqQueue(int sz)
	: front(0), rear(0), maxSize(sz) { //���캯��
	elements = new T[maxSize];
	assert ( elements != NULL );
}
template <class T>
bool SeqQueue<T>::EnQueue(T x) {
	//�����в���, ��x���뵽�ö��ж�β, ���򷵻�false
	if (IsFull() == true) return false;
	elements[rear] = x; //����x
	rear = (rear+1) % maxSize; //βָ���1
	return true;
}
template <class T>
bool SeqQueue<T>::DeQueue(T& x) {
	//�����в��������˶�ͷԪ�ز�������ֵ
	if ( IsEmpty() == true) return false;
	x = elements[front]; //ȡ��ͷԪ��
	front = (front+1) % maxSize; //��ͷָ���1
	return true;
}
template <class T>
bool SeqQueue<T>::getFront(T& x) {
	//�����в����������ظö��ж�ͷԪ�ص�ֵ
	if ( IsEmpty() ) return false; //���п�
	x = elements[front]; //ȡ��ͷԪ��
	return true;
}
template <class T>
void SeqQueue<T>::output() { //�Ӷ�ͷ����β�������
	if( IsEmpty() ) {
		cout<<"�ӿ�"<<endl;
		return;
	}
	for(int i=front; i!=rear; i=(i+1)%maxSize)
		cout<<setw(5)<<elements[i];
	cout<<endl;
}
template <class T>
struct BinTreeNode {
	T data; //������
	BinTreeNode<T> *leftchild, *rightchild; //������Ů����
	BinTreeNode () { //���캯��1
		leftchild=NULL;
		rightchild=NULL;
	}
	BinTreeNode( T x, BinTreeNode<T> *lp=NULL,
	             BinTreeNode<T> *rp=NULL) { //���캯��2
		data=x;
		leftchild=lp;
		rightchild=rp;
	}
};
template <class T>
class BinaryTree { //��������
	public:
		BinaryTree () : root (NULL) { } //���캯��1
		BinaryTree (T value) { //���캯��2
			RefValue=value;
			root=NULL;
		}
		BinaryTree (BinaryTree<T>& s) { //���ƹ��캯��
			root=CopyTree(s.root);
		}
		~BinaryTree () {
			Destroy(root);    //��������
		}
		BinTreeNode<T> *&getRoot() { //ȡ��ָ��
			return root;
		}
		void PreOrder (BinTreeNode<T> * root); //�������
		void InOrder (BinTreeNode<T> * root); //�������
		void PostOrder (BinTreeNode<T> * root); //�������
		void LevelOrder (BinTreeNode<T> *root); //��α���
		void CreatTree(BinTreeNode<T> *& root); //�����������
		bool IsEmpty () {
			return root==NULL;   //�ж������Ƿ�Ϊ��
		}
		int Height (BinTreeNode<T> * root) ; //�����߶�
		int Size (BinTreeNode<T> * root); //������
		void Destroy(BinTreeNode<T> * root); //���ٶ�����
		void LevelNum(BinTreeNode<T> *root,int a[],int h);//��������������������ÿһ��Ľ�����������a���ÿ��Ľ������� ����h��ʾ�ڼ���
		int Width(BinTreeNode<T> *root);//�ҳ������е����ֵ 
		BinTreeNode<T> * Find (BinTreeNode <T> *root,T item) ;  //�ڶ�����������item
	protected:
		BinTreeNode<T> *root; //�������ĸ�ָ��
		T RefValue; //��������ֹͣ��־
//����һ�ö�����
		BinTreeNode<T> *CopyTree(BinTreeNode<T> *orignode);
};
template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> * root) {
	//�������
	if (root != NULL) {
		cout<<root->data<<" "; //���ʸ����
		PreOrder(root->leftchild); //����������
		PreOrder(root->rightchild); //����������
	}
}
template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> * root) {
	//�������
	if (root != NULL) {
		InOrder(root->leftchild); //����������
		cout<<root->data<<" "; //���ʸ����
		InOrder(root->rightchild); //����������
	}
}
template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> * root) {
	//�������
	if (root != NULL) {
		PostOrder(root->leftchild); //����������
		PostOrder(root->rightchild); //����������
		cout<<root->data<<" "; //���ʸ����
	}
}
template <class T>
int BinaryTree<T>::Size (BinTreeNode<T> * root) {
	if (root == NULL) return 0; //����
	else
		return 1+Size(root->leftchild)+Size(root->rightchild);
}
template <class T>
int BinaryTree<T>::Height(BinTreeNode<T> * root) {
	if (root == NULL) return 0; //�����߶�Ϊ0
	else {
		int i = Height(root->leftchild);
		int j = Height(root->rightchild);
		return (i < j) ? j+1 : i+1;
	}
}
template <class T>
void BinaryTree<T>::Destroy(BinTreeNode<T> * root) {
	if( root!=NULL ) {
		Destroy(root->leftchild);
		Destroy(root->rightchild);
		delete root;
	}
}
template <class T>
BinTreeNode<T> * BinaryTree<T>::
CopyTree( BinTreeNode<T> *orignode) {
	if(orignode==NULL) return NULL;
	BinTreeNode<T> *temp=new BinTreeNode<T>;
	temp->data=orignode->data;
	temp->leftchild=CopyTree(orignode->leftchild);
	temp->rightchild=CopyTree(orignode->rightchild);
	return temp;
}
template <class T>
void BinaryTree<T>::CreatTree(BinTreeNode<T> *& root) {
	T item;
	cin>>item;
	if(item!=RefValue) {
		root=new BinTreeNode<T>(item);
		CreatTree(root->leftchild);
		CreatTree(root->rightchild);
	} else root=NULL;
}
template <class T>
void BinaryTree<T>::LevelOrder(BinTreeNode<T> *root) {
	if (root == NULL) return;
	SeqQueue< BinTreeNode<T> * > Q;
	BinTreeNode<T> *p = root;
	Q.EnQueue (p); 
	while ( !Q.IsEmpty() ) {
		Q.DeQueue (p); 
		cout<<p->data<<" ";
		if (p->leftchild != NULL) 
			Q.EnQueue (p->leftchild); 
		if (p->rightchild != NULL)
			Q.EnQueue (p->rightchild);
	}
}

template <class T>
void BinaryTree<T>::LevelNum(BinTreeNode<T> *root,int a[],int h)
{
	if(root==NULL)
	{
		return;
	}
	a[h]++;
	LevelNum(root->leftchild,a,h+1);
	LevelNum(root->rightchild,a,h+1);
}
template <class T>
int BinaryTree<T>::Width(BinTreeNode<T> *root)
{
   int a[10]={0},i,wid;        //wid������ֵ
   LevelNum(root,a,1);
   wid=0;
   for(int i=1;i<10;i++)
   {
   		if(wid<a[i])
   		{
   			wid=a[i];
		}
   }
	return wid;
}
template <class T>
BinTreeNode<T> * BinaryTree<T>::Find(BinTreeNode <T> *root,T item) 
{
	if(root!=NULL)
	{
		if(root->data==item)
		{
			return root;
		}
		if(Find(root->leftchild,item)!=NULL)
		{
			return Find(root->leftchild,item);
		}
		if(Find(root->rightchild,item)!=NULL)
		{
			return Find(root->rightchild,item);
		}
	}
	return NULL;
}
int main() {
	
	BinaryTree<char> TREE('#');
	BinTreeNode<char> *root=TREE.getRoot();
	TREE.CreatTree(root);
	TREE.getRoot()=root;
	char cha;
	while(true)
	{
		cin>>cha;
		if(cha=='#')
		{
			break;
		}
		if(TREE.Find(root,cha)==NULL)
		{
			cout<<"failure"<<endl;
		}
		else
		{
			cout<<"success"<<endl;
		}
	}
	return 0;
}

