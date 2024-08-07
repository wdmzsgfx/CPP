#include<iostream>
using namespace std;
const int N = 100010;
int a[N];
int n;
void QuickSort(int a[], int l, int r){
    if (l >= r) return;
    int x = a[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j){
        do i ++; while (a[i] < x);
        do j --; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    QuickSort(a, l, j);
    QuickSort(a, j + 1, r);
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);
    return 0;
}



/*
#include<iostream>

using namespace std;
const int N=1e6+10;
int a[N];
int n;

void quick_sort(int a[],int left,int right)
{
	if(left>=right)return;
	int i=left-1,j=right+1;
	int temp=a[(left+right)/2];
	while(i<j)
	{
		do i++;while(a[i]<temp);
		do j--;while(a[j]>temp);
		if(i<j)swap(a[i],a[j]);
	}
	quick_sort(a,left,j);
	quick_sort(a,j+1,right);
}
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	return 0;
}
*/
