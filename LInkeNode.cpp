#include<bits/stdc++.h>
#include"LInkeNode.h"
using namespace std;
 
template <class T>
List<T>::List( List<T>& L)		//复制构造函数
{
    T  value;
	 LinkNode<T> *srcptr=L.getHead();
     LinkNode<T> *destptr=first=new LinkNode<T>;
     while ( srcptr ->link != NULL) 
     {    value = srcptr ->link->data;          
  		 destptr ->link = new LinkNode<T>(value);
           destptr=destptr ->link;
           srcptr=srcptr ->link;
	   }
     destptr ->link=NULL;
}


template <class T>
void List<T>::makeEmpty() 	//将链表置为空表
{
	  LinkNode<T> *q;
	  while ( first->link != NULL) 
     {    q = first->link;              //q指向被删结点
  		 first->link = q->link;   //从链上删除该结点
		 delete q;		            //释放结点空间
	  }
}


template <class T>
int List<T>::Length() const		//计算链表的长度
{
    LinkNode<T> *p=first->link;
	int count=0;
	while(p!=NULL)
	{
		  p=p->link;
		  count++;
	}
	return count;
}


template <class T>
LinkNode<T> *List<T>::Search(T x)  //搜索x
{
	 LinkNode<T> *current = first->link;
 	 while ( current != NULL ) 
       {  if(current->data == x )  break;
  	       else	current = current->link;  	
        }
 	 return current;
}


template <class T>
LinkNode<T> *List<T>::Locate ( int i )
{  //返回表中第 i 个元素的地址
   //若i<0 或 i>表中结点个数，则返回NULL。
	
	if (i < 0)  return NULL;		// i值不合理
	 LinkNode<T> *current = first;  
    int k = 0;
	 while ( current != NULL && k < i )
       {   current = current->link;	 k++;   }
     return current;    //返回第 i 个结点的地址或NULL
}


template <class T>
bool List<T>::getData(int i, T& x)  //取出第i元素值
{ 
	if(i<=0)  return false;

	LinkNode<T> *current=Locate(i);

	if(current==NULL) return false;
	else
	{  x=current->data;
	   return true;
	 }
}


template <class T>
void List<T>::setData(int i, T& x)		//更新第i元素值
{
    if(i<=0)  return ;

	LinkNode<T> *current=Locate(i);

	if(current==NULL) return ;
	else
	 current->data=x;
}


template <class T>
bool List<T>::Insert (int i, T& x)		//在第i元素后插入
{  
	LinkNode<T> *current=Locate(i);
	if(current==NULL) return false;
	LinkNode<T> *newNode=new LinkNode<T>(x);
	if(newNode==NULL)
	{
		cout<<"存储分配错误!"<<endl;
		exit(1);
	}
	newNode->link=current->link;
	current->link=newNode;
	return true;
}


template <class T>	         
bool List<T>::Remove (int i, T& x )  //删除第i个元素
{  //删除链表第i个元素, 通过引用参数x返回元素值
    
	LinkNode<T> *current = Locate(i-1);
	
	if ( current == NULL || current->link == NULL)   
         return false; 	//删除不成功 	
    LinkNode<T> *del = current->link; 
    current->link = del->link;
	x = del->data;	
    delete del;	
    return true;
}


/*
template <class T>
void List<T>::Sort()			   //排序
{}
*/

/*
template <class T>      //前插建立链表
void List<T>::inputFront (T endTag) 
{   
	 LinkNode<T> *newNode, *newF; 
     T val;
     newF = new LinkNode<T>;
	 newF->link=NULL;
	 first=newF;      //first->link默认值为NULL 
     cin >> val;
     while (val != endTag) 
     {    newNode = new LinkNode<T>(val);
           if (newNode == NULL)	
             { cerr<<"存储分配错误!"<<endl;   exit(1);  }
          newNode->link = newF->link;  //插在表前端
          newF->link = newNode;
          cin >> val;
     }
} 
*/

template <class T>      //前插建立链表,调用插入的基本操作实现
void List<T>::inputFront (T endTag) 
{   

     T val;
	  
     cin >> val;
     while (val != endTag) 
     {    
		 (*this).Insert(0,val);
          cin >> val;
     }

} 
/*
template <class T>      //前插建立链表,教材的代码
void List<T>::inputFront (T endTag) 
{   
	 LinkNode<T> *newNode; 
     T val;
	 makeEmpty();
    
     cin >> val;
     while (val != endTag) 
     {    newNode = new LinkNode<T>(val);
           if (newNode == NULL)	
             { cerr<<"存储分配错误!"<<endl;   exit(1);  }
          newNode->link = first->link;  //插在表前端
          first->link = newNode;
          cin >> val;
     }
} 

*/
/*
template <class T>    //后插建立链表
void List<T>::inputRear ( T endTag ) 
{  
	LinkNode<T> *newNode, *last;  T val;
    last = new LinkNode<T>;  //建立链表的附加头结点
    first=last;  //last->link=NULL;
	//L.setFirst(last);	  	     //为链表L的first赋值 
    cin >> val;
    while ( val != endTag )    	 //last指向当前的表尾
     {   newNode = new LinkNode<T>(val);
          if (newNode == NULL)	
           { cerr<<"存储分配错误!"<<endl;   exit(1);  }
         last->link = newNode;   last = newNode;
         cin >> val;			//插入到表末端
    }
    last->link = NULL;              	//表收尾     
}
*/

template <class T>      //后插建立链表,调用插入的基本操作实现
void List<T>::inputRear (T endTag) 
{   

     T val;
	 int i=0; 
     cin >> val;
     while (val != endTag) 
     {    
		 (*this).Insert(i,val);
          cin >> val;
		  i++;
     }

} 

/*

template <class T>    //后插建立链表，教材的代码
void List<T>::inputRear ( T endTag ) 
{  
	LinkNode<T> *newNode, *last;  
	T val;
    makeEmpty();
    last = first;  
	
    cin >> val;
    while ( val != endTag )    	 //last指向当前的表尾
     {   newNode = new LinkNode<T>(val);
          if (newNode == NULL)	
           { cerr<<"存储分配错误!"<<endl;   exit(1);  }
         last->link = newNode;   last = newNode;
         cin >> val;			//插入到表末端
    }
    last->link = NULL;              	//表收尾     
}

*/
template <class T>    //输出链表
void List<T>::output()
{
	LinkNode<T> *p=first->link;
	
	while(p!=NULL)
	{
	    cout<<p->data<<"  ";
		p=p->link;		  
	}
	cout<<endl;
}


template <class T>
List<T>& List<T>::operator=(List<T>& L) //重载赋值运算符
{
	 T  value;
	 LinkNode<T> *srcptr=L.getHead();
     LinkNode<T> *destptr=first=new LinkNode<T>;
     while ( srcptr ->link != NULL) 
     {    value = srcptr ->link->data;          
  		 destptr ->link = new LinkNode<T>(value);
           destptr=destptr ->link;
           srcptr=srcptr ->link;
	   }
     destptr ->link=NULL;
     return *this;
}
