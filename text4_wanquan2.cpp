#include<iostream>
#include <assert.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

template <class T>
class SeqQueue    //ѭ�������ඨ��
{ 
  public:
     SeqQueue(int sz=1000000);		//���캯��
     ~SeqQueue() { delete []elements; }   //��������
     bool EnQueue(const T& x);
	 bool DeQueue(T& x);
     bool getFront(T& x);		
     bool IsEmpty() const { return (front==rear); }
     bool IsFull() const { return ((rear+1)%maxSize == front); }   
     int getSize()const {  return (rear-front+maxSize)%maxSize;  }
     void makeEmpty() {  front=rear=0;  }
     void output();
   
  private:    
     T *elements;			//Ԫ�ش������
     int front,rear;				
     int maxSize;               	//�����������
     
}; 

template <class T>

SeqQueue<T>::SeqQueue(int sz): front(0), rear(0), maxSize(sz)      //���캯��
{
	elements = new T[maxSize];		
    assert ( elements != NULL );
}

template <class T>
bool SeqQueue<T>::EnQueue(const T& x) 
{          
//�����в���, ��x���뵽�ö��ж�β, ���򷵻�      
	if (front == (rear + 1) % maxSize)
	{
		return false; 
	 } 
elements[rear] = x; //����x
rear = (rear+1) % maxSize; //βָ���1
return true;	
}


template <class T>
bool SeqQueue<T>::DeQueue(T& x) 
{ //�����в��������˶�ͷԪ�ز�������ֵ
     if (front == rear) return false;
x = elements[front]; //ȡ��ͷԪ��
front = (front+1) % maxSize; //��ͷָ���1
return true;
}

template <class T>
bool SeqQueue<T>::getFront(T& x)  
{   //�����в����������ظö��ж�ͷԪ�ص�ֵ
     if (IsEmpty() == true) return false;    //���п�
	 x = elements[front];		    //���ض�ͷԪ��
	 return true;
} 



template <class T> 
struct BinTreeNode 	      //����������ඨ��
{     
     T data;	 		              //������
     BinTreeNode<T> *leftchild, *rightchild;   //����Ů������Ů����
     BinTreeNode ()                   //���캯��1
        { leftchild=NULL;  rightchild=NULL; }
	 BinTreeNode (T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) //���캯��2
        { data=x; leftchild=l; rightchild=r;}
};

template <class T> 
class BinaryTree 		//�������ඨ��
{
  public:
     BinaryTree () : root (NULL) { }	  //���캯��
     BinaryTree (T value) : RefValue(value), root(NULL)  { }  //���캯��
//	 BinaryTree (BinaryTree<T>& s);       //���ƹ��캯��
     ~BinaryTree () { Destroy(root); }	  //��������

    BinTreeNode<T> *getRoot () { return root; }    //ȡ��ָ��
	
	void getdata(BinTreeNode<T> * current,T& d) { d=current->data;}

    void PreOrder (BinTreeNode<T> * root);   //�������
	void InOrder (BinTreeNode<T> * root);    //�������
	void PostOrder (BinTreeNode<T> * root);   //�������
    void LevelOrder (BinTreeNode<T> *root);  //��α���
	 
	void CreatTree(BinTreeNode<T> *& root);   //�����������

	void creat() { CreatTree(root); }

    bool IsEmpty () { return root==NULL;}   //�ж������Ƿ�Ϊ��
    
	 int Height (BinTreeNode<T> * root) ; //�����߶�
     
	 int Size (BinTreeNode<T> * root); 	    //������
	 
	 bool Equal(BinTreeNode<T> * root1,BinTreeNode<T> * root2); 
	 bool Equal(BinaryTree<T>& other);//�ж��������Ƿ���� 

	 void Destroy(BinTreeNode<T> * root);   //���ٶ�����

	 BinTreeNode<T> * Find (BinTreeNode <T> *root,T item) ;	  //����item
	 
	 //BinTreeNode<T> * Parent (BinTreeNode <T> *root,BinTreeNode<T> *current);   //����item�ĸ����
     
	 //BinTreeNode<T> * LeftChild (BinTreeNode<T> *current);	     //��������Ů
     
	// BinTreeNode<T> * RightChild (BinTreeNode<T> *current);   //��������Ů
     
	 int Degree1(BinTreeNode<T> * root);   //�����Ϊ1�Ľ�����

	 int Degree2(BinTreeNode<T> * root);   //�����Ϊ2�Ľ�����

	 int leaves(BinTreeNode<T> * root);   //����Ҷ�ӽ��ĸ���

	  
	 void LevelNum(BinTreeNode<T> *root,int a[],int h);
	
	 int Width(BinTreeNode<T> *root);   //����������Ŀ��


	 

protected:
     BinTreeNode<T> *root; 	//�������ĸ�ָ��
     T RefValue;	 	//��������ֹͣ��־
	 
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
void BinaryTree<T>::PreOrder (BinTreeNode<T> * root)   //�������
{
     if (root != NULL)
	 {
		cout<<root->data<<" ";     //���ʸ����
		PreOrder(root->leftchild);   //�������������
		PreOrder(root->rightchild); //�������������
	 }
}

template <class T>
void BinaryTree<T>::InOrder (BinTreeNode<T> * root)   //�������
{
     if (root != NULL)
	 {
		InOrder(root->leftchild);   //�������������
		cout<<root->data<<" ";     //���ʸ����
		InOrder(root->rightchild); //�������������
	 }
}

template <class T>
void BinaryTree<T>::PostOrder (BinTreeNode<T> * root)   ///�������
{
     if (root != NULL)
	 {
		PostOrder(root->leftchild);   //�������������
		PostOrder(root->rightchild); //�������������
		cout<<root->data<<" ";     //���ʸ����
	 }
}

template <class T>
void BinaryTree<T>::LevelOrder (BinTreeNode<T> *root)   //��α���
{
    if (root == NULL) return;
     SeqQueue< BinTreeNode<T> * > Q;
     BinTreeNode<T> *p = root;   
     Q.EnQueue (p); 	//����������
     while ( !Q.IsEmpty() ) 
     {   Q.DeQueue (p);             //��ͷ������
          cout<<p->data<<" ";  //������ӽ�������
          if (p->leftchild != NULL)  //�����ӽ��������
               Q.EnQueue (p->leftchild);  //���������
          if (p->rightchild != NULL) 
	     Q.EnQueue (p->rightchild);
         }     

}


template <class T>
void BinaryTree<T>::CreatTree(BinTreeNode<T> *& root) //�����������
{
   T item;
   cin>>item;
   T RefValue='#';
   if(item!=RefValue)
   {  	
   		root=new BinTreeNode<T>(item);
      	if(root ==NULL)
	  	{ 
	  	cerr<<"������ʧ�ܣ�\n";
	    exit(1);  
		}
		CreatTree(root->leftchild);
       	CreatTree(root->rightchild);

   }
   else root=NULL;
}


template <class T>
int BinaryTree<T>::Size (BinTreeNode<T> * root)  //���ú����������������Ľ�����
{
     if (root == NULL) return 0;	       //����
     else 
		 return 1+Size(root->leftchild) + Size(root->rightchild);
}


template <class T>
int  BinaryTree<T>::Height ( BinTreeNode<T> *  root) //���ú�������㷨����������ĸ߶Ȼ����
{
     if (root == NULL) return 0;	//�����߶�Ϊ0
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
BinTreeNode<T>*  BinaryTree<T>::Find (BinTreeNode <T> *root,T item) 	  //����item
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
BinTreeNode<T> * BinaryTree<T>::LeftChild (BinTreeNode<T> *current)  //��������Ů
{  

   if(current==NULL ) return NULL;
   return current->leftchild;
}

  template <class T>
BinTreeNode<T> * BinaryTree<T>::RightChild (BinTreeNode<T> *current)  //��������Ů
{  

   if(current==NULL) return NULL;
   return current->rightchild;
}
*/
//


//-------------------------------------------------------------------------------------

template <class T>
int BinaryTree<T>::Degree1(BinTreeNode<T> * root)   //�����Ϊ1�Ľ�����
{  
	if (root==NULL) return 0;
   if((root->leftchild==NULL&&root->rightchild!=NULL)||(root->leftchild!=NULL&&root->rightchild==NULL))   
        return  1+Degree2(root->leftchild)+Degree2(root->rightchild);
   else
       return  Degree2(root->leftchild)+Degree2(root->rightchild);
}



template <class T>
int BinaryTree<T>::Degree2(BinTreeNode<T> * root)   //�����Ϊ2�Ľ�����
{  if (root==NULL) return 0;
   if( root->leftchild!=NULL && root->rightchild!=NULL)   
        return  1+Degree2(root->leftchild)+Degree2(root->rightchild);
   else
       return  Degree2(root->leftchild)+Degree2(root->rightchild);
}


template <class T>
int BinaryTree<T>::leaves (BinTreeNode<T> * root)   //����Ҷ�ӽ��ĸ���
{  if (root==NULL)  return 0;
     if( root->leftchild==NULL && root->rightchild==NULL)   return 1;
     return leaves(root->leftchild)+leaves(root->rightchild);
}

 
	  


//------------------------------------------------------

template <class T>
void BinaryTree<T>::LevelNum(BinTreeNode<T> *root,int a[],int h)   //���������������������Ŀ��
{
	 // ��������
}

template <class T>
int BinaryTree<T>::Width(BinTreeNode<T> *root)
{
	int a[10]={0},i,wid;
	LevelNum(root,a,1);
      // ��������
    return wid;
}

//-------------------------------------------------------

 

 


//template <class T>
//BinaryTree<T>::BinaryTree (BinaryTree<T>& s);       //���ƹ��캯��
int main(int argc, char** argv) {
	BinaryTree<char> T1;
	T1.creat();
	if (T1.getRoot() == NULL)
	{
		cout<<"YES"<<endl;
	}
     SeqQueue< BinTreeNode<char> * > Q;
     BinTreeNode<char> *p =T1.getRoot();   
     Q.EnQueue (p); 	//����������
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
