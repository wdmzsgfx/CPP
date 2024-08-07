#include <iostream>
#include <cstring>
#define N 100
using namespace std;
 
typedef struct node
{
	char data;
	struct node *left, *right;
}BT;
 
BT *createbt(char *in, char *pre, int k);	// �����������������ʽ��ǰ����ʽ����һ�Ŷ�����
void showBt(BT *T);		// չʾһ�Ŷ���������A(B, C(D, E))�����������ŵ�ǰ�������ʵ��
void *destroy(BT *T);	// ���ٶ�����
bool iscomplete(BT *T);	// �ж�������ǲ�����ȫ������
int height(BT *T);		// �������ĸ߶�
int leaf(BT *T);	// ����Ҷ�ӵ�����
int width(BT *T);		// �������Ŀ��
void layer(BT *T);		// ��α���
void preorder(BT *T);	// ǰ�����
void inorder(BT *T);	// �������
void postorder(BT *T);	// �������	
void getPath(BT *T, BT **path, int top)		// ������ڵ㵽����Ҷ�ӽڵ��·��(�ݹ�)
void getPath(BT *T);	// ������ڵ㵽����Ҷ�ӽڵ��·��(�ǵݹ�)
BT *lca(BT *T, char a, char b);		// ���ؽڵ�����Ϊa��b�������ڵ�������������

BT *createbt(char *in, char *pre, int k)
{
	if (k <= 0)
		return NULL;
	else
	{
		BT *node = new BT;
		node->data = pre[0];	// ǰ����ص�һ��Ԫ�ؾ�����������ظ��ڵ�
		int i;
		for (i = 0; in[i] != pre[0]; ++ i);		// ����һ��������i��ȡ������ʽ��node->data��λ��
		node->left = createbt(in, pre + 1, i);
		node->right = createbt(in + i + 1, pre + i + 1, k - i - 1);
		return node;
	}
}

BT *createbt(char *in, char *pre, int k)
{
	if (k <= 0)
		return NULL;
	else
	{
		BT *node = new BT;
		node->data = pre[0];	// ǰ����ص�һ��Ԫ�ؾ�����������ظ��ڵ�
		int i;
		for (i = 0; in[i] != pre[0]; ++ i);		// ����һ��������i��ȡ������ʽ��node->data��λ��
		node->left = createbt(in, pre + 1, i);
		node->right = createbt(in + i + 1, pre + i + 1, k - i - 1);
		return node;
	}
}

void showBt(BT *T)
{
	if (T)
	{
		cout << T->data << " ";
		if (T->left || T->right)	// �ж�һ�µ�ǰ�ݹ鵽�Ľڵ���û���ֽڵ㣬���û���ӽڵ㣬���ǾͲ���Ҫ����������
		{
			cout << "(";
			showBt(T->left);
			cout << ",";
			showBt(T->right);
			cout << ")";
		}
	}
}
 
void *destroy(BT *T)
{
	if (T)
	{
		destroy(T->left);
		destroy(T->right);
		delete T;
	}
}

bool iscomplete(BT *T)
{
	if (!T)
		return false;
		
	BT *q[N], *p;
	int front, rear;
	front = rear = 0;
	q[rear ++] = T;
	bool flag = false;
	
	while (front != rear)
	{
		p = q[front ++];
		
		if (!p->left && !p->right)
			flag = true;
		else if (!p->left && p->right)
			return false;
		else if (p->left && !p->right)
		{
			if (flag)
				return false;
			else
				flag = true;
		}
		else
		{
			if (flag)
				return false;
		}
		
		if (p->left)
			q[rear ++] = p->left;
		if (p->right)
			q[rear ++] = p->right;	
	}
	return true;
}
 
int height(BT *T)
{
	if (!T)
		return 0;
	else
		return max(height(T->left) + 1, height(T->right) + 1);
}

int leaf(BT *T)
{
	if (!T)		
		return 0;
	else if (!T->left && !T->right)	// ��ǰ�ڵ�ΪҶ�ӣ���ôҶ�ӵ�������Ȼ��1
		return 1;
	else
		return leaf(T->left) + leaf(T->right);
}

int width(BT *T)
{
	BT *q[N], *p;
	int front, rear;
	front = rear = 0;
	q[rear ++] = T;
	
	int max_wid = 0;
	
	while (front != rear)
	{
		int count = rear - front;	// ͨ�����е�front��rearֱ�ӵó���ǰ��Ľڵ�����
		max_wid = max(max_wid, count);	// ���µ�ǰ�������
		
		while (count --)	// ����count����ǰ������нڵ㵯���������ǵ��ӽڵ���ӣ���ɲ�α����Ķ��и���
		{
			p = q[front ++];
			if (p->left)
				q[rear ++] = p->left;
			if (p->right)
				q[rear ++] = p->right;
		}
	}
	return max_wid;
}

void layer(BT *T)
{
	BT *q[N], *p;
	int front, rear;
	front = rear = 0;
	q[rear ++] = T;
	
	while (front != rear)
	{
		p = q[front ++];	// ����Ԫ�س���
		cout << p->data << " ";
		
		// �����ӵ�Ԫ�ص��ӽڵ����
		if (p->left)
			q[rear ++] = p->left;
		if (p->right)
			q[rear ++] = p->right;
	}
}

void preorder(BT *T)	// ǰ����� 
{
	if (T)
	{
		cout << T->data << " ";
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(BT *T)	// ������� 
{
	if (T)
	{
		preorder(T->left);
		cout << T->data << " ";
		preorder(T->right);
	}
}

void postorder(BT *T)	// ������� 
{
	if (T)
	{
		preorder(T->left);
		preorder(T->right);
		cout << T->data << " ";
	}
}

void getPath(BT *T, BT **path, int top)
{	
	if (!T)
		return;
	else if (!T->left && !T->right)
	{
		for (int i = 0; i <= top; ++ i)
			cout << path[i]->data << " ";
		cout << T->data << endl;
	}
	else
	{
		path[++ top] = T;
		getPath(T->left, path, top);
		getPath(T->right, path, top);
	}
} 

BT* lca(BT *T, char a, char b)
{
	if (!T)
		return NULL;
	if (T->data == a || T->data == b)
		return T;
	
	BT *l = lca(T->left, a, b);
	BT *r = lca(T->right, a, b);
	
	if (!l && !r)
		return NULL;
	else if (l && r)
		return T;
	else if (!l && r)
		return r;
	else if (l && !r);
		return l;
}

int main()
{
	
	return 0;
}






