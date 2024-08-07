#include<iostream>
#include <assert.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

template <class T>
class SeqQueue    //循环队列类定义
{ 
  public:
     SeqQueue(int sz=1000000);		//构造函数
     ~SeqQueue() { delete []elements; }   //析构函数
     bool EnQueue(const T& x);
	 bool DeQueue(T& x);
     bool getFront(T& x);		
     bool IsEmpty() const { return (front==rear); }
     bool IsFull() const { return ((rear+1)%maxSize == front); }   
     int getSize()const {  return (rear-front+maxSize)%maxSize;  }
     void makeEmpty() {  front=rear=0;  }
     void output();
   
  private:    
     T *elements;			//元素存放数组
     int front,rear;				
     int maxSize;               	//队列最大容量
     
}; 

template <class T>

SeqQueue<T>::SeqQueue(int sz): front(0), rear(0), maxSize(sz)      //构造函数
{
	elements = new T[maxSize];		
    assert ( elements != NULL );
}

template <class T>
bool SeqQueue<T>::EnQueue(const T& x) 
{          
//若队列不满, 则将x插入到该队列队尾, 否则返回      
	if (front == (rear + 1) % maxSize)
	{
		return false; 
	 } 
elements[rear] = x; //插入x
rear = (rear+1) % maxSize; //尾指针加1
return true;	
}


template <class T>
bool SeqQueue<T>::DeQueue(T& x) 
{ //若队列不空则函数退队头元素并返回其值
     if (front == rear) return false;
x = elements[front]; //取队头元素
front = (front+1) % maxSize; //队头指针加1
return true;
}

template <class T>
bool SeqQueue<T>::getFront(T& x)  
{   //若队列不空则函数返回该队列队头元素的值
     if (IsEmpty() == true) return false;    //队列空
	 x = elements[front];		    //返回队头元素
	 return true;
} 



template <class T> 
struct BinTreeNode 	      //二叉树结点类定义
{     
     T data;	 		              //数据域
     BinTreeNode<T> *leftchild, *rightchild;   //左子女、右子女链域
     BinTreeNode ()                   //构造函数1
        { leftchild=NULL;  rightchild=NULL; }
	 BinTreeNode (T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) //构造函数2
        { data=x; leftchild=l; rightchild=r;}
};

template <class T> 
class BinaryTree 		//二叉树类定义
{
  public:
     BinaryTree () : root (NULL) { }	  //构造函数
     BinaryTree (T value) : RefValue(value), root(NULL)  { }  //构造函数
//	 BinaryTree (BinaryTree<T>& s);       //复制构造函数
     ~BinaryTree () { Destroy(root); }	  //析构函数

    BinTreeNode<T> *getRoot () { return root; }    //取根指针
	
	void getdata(BinTreeNode<T> * current,T& d) { d=current->data;}

    void PreOrder (BinTreeNode<T> * root);   //先序遍历
	void InOrder (BinTreeNode<T> * root);    //中序遍历
	void PostOrder (BinTreeNode<T> * root);   //后序遍历
    void LevelOrder (BinTreeNode<T> *root);  //层次遍历
	 
	void CreatTree(BinTreeNode<T> *& root);   //先序遍历建树

	void creat() { CreatTree(root); }

    bool IsEmpty () { return root==NULL;}   //判二叉树是否为空
    
	 int Height (BinTreeNode<T> * root) ; //求树高度
     
	 int Size (BinTreeNode<T> * root); 	    //求结点数
	 
	 bool Equal(BinTreeNode<T> * root1,BinTreeNode<T> * root2); 
	 bool Equal(BinaryTree<T>& other);//判断两棵树是否相等 

	 void Destroy(BinTreeNode<T> * root);   //销毁二叉树

	 BinTreeNode<T> * Find (BinTreeNode <T> *root,T item) ;	  //搜索item
	 
	 //BinTreeNode<T> * Parent (BinTreeNode <T> *root,BinTreeNode<T> *current);   //返回item的父结点
     
	 //BinTreeNode<T> * LeftChild (BinTreeNode<T> *current);	     //返回左子女
     
	// BinTreeNode<T> * RightChild (BinTreeNode<T> *current);   //返回右子女
     
	 int Degree1(BinTreeNode<T> * root);   //计算度为1的结点个数

	 int Degree2(BinTreeNode<T> * root);   //计算度为2的结点个数

	 int leaves(BinTreeNode<T> * root);   //计算叶子结点的个数

	  
	 void LevelNum(BinTreeNode<T> *root,int a[],int h);
	
	 int Width(BinTreeNode<T> *root);   //计算二叉树的宽度


	 

protected:
     BinTreeNode<T> *root; 	//二叉树的根指针
     T RefValue;	 	//数据输入停止标志
	 
};

template <class T>
void BinaryTree<T>::Destroy(BinTreeNode<T> * root)
{
	if(root!=NULL)
	{  Destroy(root->leftchild);
	   Destroy(root->rightchild);
	   delete root;
	   }
}


template <class T>
void BinaryTree<T>::PreOrder (BinTreeNode<T> * root)   //先序遍历
{
     if (root != NULL)
	 {
		cout<<root->data<<" ";     //访问根结点
		PreOrder(root->leftchild);   //先序遍历左子树
		PreOrder(root->rightchild); //先序遍历右子树
	 }
}

template <class T>
void BinaryTree<T>::InOrder (BinTreeNode<T> * root)   //中序遍历
{
     if (root != NULL)
	 {
		InOrder(root->leftchild);   //先序遍历左子树
		cout<<root->data<<" ";     //访问根结点
		InOrder(root->rightchild); //先序遍历右子树
	 }
}

template <class T>
void BinaryTree<T>::PostOrder (BinTreeNode<T> * root)   ///后序遍历
{
     if (root != NULL)
	 {
		PostOrder(root->leftchild);   //先序遍历左子树
		PostOrder(root->rightchild); //先序遍历右子树
		cout<<root->data<<" ";     //访问根结点
	 }
}

template <class T>
void BinaryTree<T>::LevelOrder (BinTreeNode<T> *root)   //层次遍历
{
    if (root == NULL) return;
     SeqQueue< BinTreeNode<T> * > Q;
     BinTreeNode<T> *p = root;   
     Q.EnQueue (p); 	//根结点入队列
     while ( !Q.IsEmpty() ) 
     {   Q.DeQueue (p);             //队头结点出队
          cout<<p->data<<" ";  //输出出队结点的数据
          if (p->leftchild != NULL)  //若出队结点有左孩子
               Q.EnQueue (p->leftchild);  //左孩子入队列
          if (p->rightchild != NULL) 
	     Q.EnQueue (p->rightchild);
         }     

}


template <class T>
void BinaryTree<T>::CreatTree(BinTreeNode<T> *& root) //先序遍历建树
{
   T item;
   cin>>item;
   T RefValue='#';
   if(item!=RefValue)
   {  	
   		root=new BinTreeNode<T>(item);
      	if(root ==NULL)
	  	{ 
	  	cerr<<"分配结点失败！\n";
	    exit(1);  
		}
		CreatTree(root->leftchild);
       	CreatTree(root->rightchild);

   }
   else root=NULL;
}


template <class T>
int BinaryTree<T>::Size (BinTreeNode<T> * root)  //利用后序遍历计算二叉树的结点个数
{
     if (root == NULL) return 0;	       //空树
     else 
		 return 1+Size(root->leftchild) + Size(root->rightchild);
}


template <class T>
int  BinaryTree<T>::Height ( BinTreeNode<T> *  root) //利用后序遍历算法计算二叉树的高度或深度
{
     if (root == NULL) return 0;	//空树高度为0
	 else 
	 {
  	      int i = Height(root->leftchild);
          int j = Height(root->rightchild);
	      return (i < j) ? j+1 : i+1; 
	}
}
template <class T>
bool BinaryTree<T>::Equal(BinaryTree<T>& other)
{
	return Equal(root,other.root);
}
template <class T>
bool BinaryTree<T>::Equal(BinTreeNode<T> *  root1,BinTreeNode<T> *  root2)
{
	if(root1==NULL&&root2==NULL)
	{
		return true;
	}
	if(root1==NULL||root2==NULL)
	{
		return false;
	}
	if(root1->data !=root2->data)
	{
		return false;
	}
	if(root1->data ==root2->data )
	{
		Equal(root1->leftchild ,root2->leftchild );
		Equal(root1->rightchild,root2->rightchild);
	}
}

template <class T>
BinTreeNode<T>*  BinaryTree<T>::Find (BinTreeNode <T> *root,T item) 	  //搜索item
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==item)
	{
		return root;
	}
	BinTreeNode <T> *result=Find(root->leftchild,item);
	if(result!=NULL)
	{
		return result;
	}
	
	return Find(root->rightchild,item);
}
/*
template <class T>
BinTreeNode<T> * BinaryTree<T>::LeftChild (BinTreeNode<T> *current)  //返回左子女
{  

   if(current==NULL ) return NULL;
   return current->leftchild;
}

  template <class T>
BinTreeNode<T> * BinaryTree<T>::RightChild (BinTreeNode<T> *current)  //返回右子女
{  

   if(current==NULL) return NULL;
   return current->rightchild;
}
*/
//


//-------------------------------------------------------------------------------------

template <class T>
int BinaryTree<T>::Degree1(BinTreeNode<T> * root)   //计算度为1的结点个数
{  
	if (root==NULL) return 0;
   if((root->leftchild==NULL&&root->rightchild!=NULL)||(root->leftchild!=NULL&&root->rightchild==NULL))   
        return  1+Degree2(root->leftchild)+Degree2(root->rightchild);
   else
       return  Degree2(root->leftchild)+Degree2(root->rightchild);
}



template <class T>
int BinaryTree<T>::Degree2(BinTreeNode<T> * root)   //计算度为2的结点个数
{  if (root==NULL) return 0;
   if( root->leftchild!=NULL && root->rightchild!=NULL)   
        return  1+Degree2(root->leftchild)+Degree2(root->rightchild);
   else
       return  Degree2(root->leftchild)+Degree2(root->rightchild);
}


template <class T>
int BinaryTree<T>::leaves (BinTreeNode<T> * root)   //计算叶子结点的个数
{  if (root==NULL)  return 0;
     if( root->leftchild==NULL && root->rightchild==NULL)   return 1;
     return leaves(root->leftchild)+leaves(root->rightchild);
}

 
	  


//------------------------------------------------------

template <class T>
void BinaryTree<T>::LevelNum(BinTreeNode<T> *root,int a[],int h)   //利用先序遍历计算二叉树的宽度
{
	 // 补充完整
}

template <class T>
int BinaryTree<T>::Width(BinTreeNode<T> *root)
{
	int a[10]={0},i,wid;
	LevelNum(root,a,1);
      // 补充完整
    return wid;
}

//-------------------------------------------------------

 

 


//template <class T>
//BinaryTree<T>::BinaryTree (BinaryTree<T>& s);       //复制构造函数
int main(int argc, char** argv) {
	BinaryTree<char> T1;
	T1.creat();
	if (T1.getRoot() == NULL)
	{
		cout<<"YES"<<endl;
	}
     SeqQueue< BinTreeNode<char> * > Q;
     BinTreeNode<char> *p =T1.getRoot();   
     Q.EnQueue (p); 	//根结点入队列
     int flag=0;
     while ( !Q.IsEmpty() ) 
     { 	
	 	Q.DeQueue (p);
		if(p->leftchild!=NULL)
		{
			if(flag==1)
			{
				flag=2;
				break;
			}
			Q.EnQueue (p->leftchild); 
		}
		else
		{
			flag=1;
	   }       
		if(p->rightchild!=NULL)
		{
			if(flag==1)
			{
				flag=2;
				break;
			}
			Q.EnQueue (p->rightchild); 
		}
		else
		{
			flag=1;
	   }       
	 } 
	 if(flag==2)
	 {
	 	cout<<"NO";
	   }  
	   else
	   {
	   	cout<<"YES";
	   }
	  
	return 0;
}
