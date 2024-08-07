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
class SeqQueue { //循环队列类定义
	public:
		SeqQueue(int sz=20); //构造函数
		~SeqQueue() {
			delete []elements;    //析构函数
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
		T *elements; //元素存放数组
		int front, rear; //头指针，尾指针
		int maxSize; //队列最大容量
};
template <class T>
SeqQueue<T>::SeqQueue(int sz)
	: front(0), rear(0), maxSize(sz) { //构造函数
	elements = new T[maxSize];
	assert ( elements != NULL );
}
template <class T>
bool SeqQueue<T>::EnQueue(T x) {
	//若队列不满, 则将x插入到该队列队尾, 否则返回false
	if (IsFull() == true) return false;
	elements[rear] = x; //插入x
	rear = (rear+1) % maxSize; //尾指针加1
	return true;
}
template <class T>
bool SeqQueue<T>::DeQueue(T& x) {
	//若队列不空则函数退队头元素并返回其值
	if ( IsEmpty() == true) return false;
	x = elements[front]; //取队头元素
	front = (front+1) % maxSize; //队头指针加1
	return true;
}
template <class T>
bool SeqQueue<T>::getFront(T& x) {
	//若队列不空则函数返回该队列队头元素的值
	if ( IsEmpty() ) return false; //队列空
	x = elements[front]; //取队头元素
	return true;
}
template <class T>
void SeqQueue<T>::output() { //从队头到队尾依次输出
	if( IsEmpty() ) {
		cout<<"队空"<<endl;
		return;
	}
	for(int i=front; i!=rear; i=(i+1)%maxSize)
		cout<<setw(5)<<elements[i];
	cout<<endl;
}
template <class T>
struct BinTreeNode {
	T data; //数据域
	BinTreeNode<T> *leftchild, *rightchild; //左右子女链域
	BinTreeNode () { //构造函数1
		leftchild=NULL;
		rightchild=NULL;
	}
	BinTreeNode( T x, BinTreeNode<T> *lp=NULL,
	             BinTreeNode<T> *rp=NULL) { //构造函数2
		data=x;
		leftchild=lp;
		rightchild=rp;
	}
};
template <class T>
class BinaryTree { //二叉树类
	public:
		BinaryTree () : root (NULL) { } //构造函数1
		BinaryTree (T value) { //构造函数2
			RefValue=value;
			root=NULL;
		}
		BinaryTree (BinaryTree<T>& s) { //复制构造函数
			root=CopyTree(s.root);
		}
		~BinaryTree () {
			Destroy(root);    //析构函数
		}
		BinTreeNode<T> *&getRoot() { //取根指针
			return root;
		}
		void PreOrder (BinTreeNode<T> * root); //先序遍历
		void InOrder (BinTreeNode<T> * root); //中序遍历
		void PostOrder (BinTreeNode<T> * root); //后序遍历
		void LevelOrder (BinTreeNode<T> *root); //层次遍历
		void CreatTree(BinTreeNode<T> *& root); //先序遍历建树
		bool IsEmpty () {
			return root==NULL;   //判二叉树是否为空
		}
		int Height (BinTreeNode<T> * root) ; //求树高度
		int Size (BinTreeNode<T> * root); //求结点数
		void Destroy(BinTreeNode<T> * root); //销毁二叉树
		void LevelNum(BinTreeNode<T> *root,int a[],int h);//利用先序遍历计算二叉树每一层的结点个数，参数a存放每层的结点个数， 参数h表示第几层
		int Width(BinTreeNode<T> *root);//找出数组中的最大值 
		BinTreeNode<T> * Find (BinTreeNode <T> *root,T item) ;  //在二叉树中搜索item
	protected:
		BinTreeNode<T> *root; //二叉树的根指针
		T RefValue; //数据输入停止标志
//拷贝一棵二叉树
		BinTreeNode<T> *CopyTree(BinTreeNode<T> *orignode);
};
template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> * root) {
	//先序遍历
	if (root != NULL) {
		cout<<root->data<<" "; //访问根结点
		PreOrder(root->leftchild); //遍历左子树
		PreOrder(root->rightchild); //遍历右子树
	}
}
template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> * root) {
	//中序遍历
	if (root != NULL) {
		InOrder(root->leftchild); //遍历左子树
		cout<<root->data<<" "; //访问根结点
		InOrder(root->rightchild); //遍历右子树
	}
}
template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> * root) {
	//后序遍历
	if (root != NULL) {
		PostOrder(root->leftchild); //遍历左子树
		PostOrder(root->rightchild); //遍历右子树
		cout<<root->data<<" "; //访问根结点
	}
}
template <class T>
int BinaryTree<T>::Size (BinTreeNode<T> * root) {
	if (root == NULL) return 0; //空树
	else
		return 1+Size(root->leftchild)+Size(root->rightchild);
}
template <class T>
int BinaryTree<T>::Height(BinTreeNode<T> * root) {
	if (root == NULL) return 0; //空树高度为0
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
   int a[10]={0},i,wid;        //wid存放最大值
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

