#include <iostream>
#include <cstring>
#define N 100
using namespace std;
 
typedef struct node
{
	char data;
	struct node *left, *right;
}BT;
 
BT *createbt(char *in, char *pre, int k);	// 根据输入二点中序表达式和前序表达式创建一颗二叉树
void showBt(BT *T);		// 展示一颗二叉树，以A(B, C(D, E))这样加了括号的前序遍历来实现
void *destroy(BT *T);	// 销毁二叉树
bool iscomplete(BT *T);	// 判断这颗树是不是完全二叉树
int height(BT *T);		// 计算树的高度
int leaf(BT *T);	// 计算叶子的数量
int width(BT *T);		// 计算树的宽度
void layer(BT *T);		// 层次遍历
void preorder(BT *T);	// 前序遍历
void inorder(BT *T);	// 中序遍历
void postorder(BT *T);	// 后序遍历	
void getPath(BT *T, BT **path, int top)		// 输出根节点到所有叶子节点的路径(递归)
void getPath(BT *T);	// 输出根节点到所有叶子节点的路径(非递归)
BT *lca(BT *T, char a, char b);		// 返回节点数据为a和b的两个节点的最近公共祖先

BT *createbt(char *in, char *pre, int k)
{
	if (k <= 0)
		return NULL;
	else
	{
		BT *node = new BT;
		node->data = pre[0];	// 前序表达地第一个元素就是这颗子树地根节点
		int i;
		for (i = 0; in[i] != pre[0]; ++ i);		// 根据一个计数器i获取中序表达式中node->data的位置
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
		node->data = pre[0];	// 前序表达地第一个元素就是这颗子树地根节点
		int i;
		for (i = 0; in[i] != pre[0]; ++ i);		// 根据一个计数器i获取中序表达式中node->data的位置
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
		if (T->left || T->right)	// 判断一下当前递归到的节点有没有字节点，如果没有子节点，我们就不需要打上括号了
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
	else if (!T->left && !T->right)	// 当前节点为叶子，那么叶子的数量当然是1
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
		int count = rear - front;	// 通过队列的front和rear直接得出当前层的节点数量
		max_wid = max(max_wid, count);	// 更新当前的最大宽度
		
		while (count --)	// 根据count将当前层的所有节点弹出，把它们的子节点入队，完成层次遍历的队列更新
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
		p = q[front ++];	// 队首元素出队
		cout << p->data << " ";
		
		// 将出队的元素的子节点入队
		if (p->left)
			q[rear ++] = p->left;
		if (p->right)
			q[rear ++] = p->right;
	}
}

void preorder(BT *T)	// 前序遍历 
{
	if (T)
	{
		cout << T->data << " ";
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(BT *T)	// 中序遍历 
{
	if (T)
	{
		preorder(T->left);
		cout << T->data << " ";
		preorder(T->right);
	}
}

void postorder(BT *T)	// 后序遍历 
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






