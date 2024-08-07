#include<bits/stdc++.h>
#include"LInkeNode.h"
using namespace std;
 
template <class T>
List<T>::List( List<T>& L)		//���ƹ��캯��
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
void List<T>::makeEmpty() 	//��������Ϊ�ձ�
{
	  LinkNode<T> *q;
	  while ( first->link != NULL) 
     {    q = first->link;              //qָ��ɾ���
  		 first->link = q->link;   //������ɾ���ý��
		 delete q;		            //�ͷŽ��ռ�
	  }
}


template <class T>
int List<T>::Length() const		//��������ĳ���
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
LinkNode<T> *List<T>::Search(T x)  //����x
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
{  //���ر��е� i ��Ԫ�صĵ�ַ
   //��i<0 �� i>���н��������򷵻�NULL��
	
	if (i < 0)  return NULL;		// iֵ������
	 LinkNode<T> *current = first;  
    int k = 0;
	 while ( current != NULL && k < i )
       {   current = current->link;	 k++;   }
     return current;    //���ص� i �����ĵ�ַ��NULL
}


template <class T>
bool List<T>::getData(int i, T& x)  //ȡ����iԪ��ֵ
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
void List<T>::setData(int i, T& x)		//���µ�iԪ��ֵ
{
    if(i<=0)  return ;

	LinkNode<T> *current=Locate(i);

	if(current==NULL) return ;
	else
	 current->data=x;
}


template <class T>
bool List<T>::Insert (int i, T& x)		//�ڵ�iԪ�غ����
{  
	LinkNode<T> *current=Locate(i);
	if(current==NULL) return false;
	LinkNode<T> *newNode=new LinkNode<T>(x);
	if(newNode==NULL)
	{
		cout<<"�洢�������!"<<endl;
		exit(1);
	}
	newNode->link=current->link;
	current->link=newNode;
	return true;
}


template <class T>	         
bool List<T>::Remove (int i, T& x )  //ɾ����i��Ԫ��
{  //ɾ�������i��Ԫ��, ͨ�����ò���x����Ԫ��ֵ
    
	LinkNode<T> *current = Locate(i-1);
	
	if ( current == NULL || current->link == NULL)   
         return false; 	//ɾ�����ɹ� 	
    LinkNode<T> *del = current->link; 
    current->link = del->link;
	x = del->data;	
    delete del;	
    return true;
}


/*
template <class T>
void List<T>::Sort()			   //����
{}
*/

/*
template <class T>      //ǰ�彨������
void List<T>::inputFront (T endTag) 
{   
	 LinkNode<T> *newNode, *newF; 
     T val;
     newF = new LinkNode<T>;
	 newF->link=NULL;
	 first=newF;      //first->linkĬ��ֵΪNULL 
     cin >> val;
     while (val != endTag) 
     {    newNode = new LinkNode<T>(val);
           if (newNode == NULL)	
             { cerr<<"�洢�������!"<<endl;   exit(1);  }
          newNode->link = newF->link;  //���ڱ�ǰ��
          newF->link = newNode;
          cin >> val;
     }
} 
*/

template <class T>      //ǰ�彨������,���ò���Ļ�������ʵ��
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
template <class T>      //ǰ�彨������,�̲ĵĴ���
void List<T>::inputFront (T endTag) 
{   
	 LinkNode<T> *newNode; 
     T val;
	 makeEmpty();
    
     cin >> val;
     while (val != endTag) 
     {    newNode = new LinkNode<T>(val);
           if (newNode == NULL)	
             { cerr<<"�洢�������!"<<endl;   exit(1);  }
          newNode->link = first->link;  //���ڱ�ǰ��
          first->link = newNode;
          cin >> val;
     }
} 

*/
/*
template <class T>    //��彨������
void List<T>::inputRear ( T endTag ) 
{  
	LinkNode<T> *newNode, *last;  T val;
    last = new LinkNode<T>;  //��������ĸ���ͷ���
    first=last;  //last->link=NULL;
	//L.setFirst(last);	  	     //Ϊ����L��first��ֵ 
    cin >> val;
    while ( val != endTag )    	 //lastָ��ǰ�ı�β
     {   newNode = new LinkNode<T>(val);
          if (newNode == NULL)	
           { cerr<<"�洢�������!"<<endl;   exit(1);  }
         last->link = newNode;   last = newNode;
         cin >> val;			//���뵽��ĩ��
    }
    last->link = NULL;              	//����β     
}
*/

template <class T>      //��彨������,���ò���Ļ�������ʵ��
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

template <class T>    //��彨�������̲ĵĴ���
void List<T>::inputRear ( T endTag ) 
{  
	LinkNode<T> *newNode, *last;  
	T val;
    makeEmpty();
    last = first;  
	
    cin >> val;
    while ( val != endTag )    	 //lastָ��ǰ�ı�β
     {   newNode = new LinkNode<T>(val);
          if (newNode == NULL)	
           { cerr<<"�洢�������!"<<endl;   exit(1);  }
         last->link = newNode;   last = newNode;
         cin >> val;			//���뵽��ĩ��
    }
    last->link = NULL;              	//����β     
}

*/
template <class T>    //�������
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
List<T>& List<T>::operator=(List<T>& L) //���ظ�ֵ�����
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
