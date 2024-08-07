#include<bits/stdc++.h>

using namespace std;
const int N=1010;

bool is_prime(int x)//�Գ����ж�����
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

void divide(int x)//�ֽ������� 
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int primes[N], cnt;     // primes[]�洢��������
bool st[N];         // st[x]�洢x�Ƿ�ɸ��

void get_primes(int n) //���ط�ɸ���� 
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i; j <= n; j += i)
            st[j] = true;
    }
}

void get_primes1(int n) //���Է�ɸ���� 
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int gcd(int a,int b)//���Լ�� ŷ������㷨 
{
	return b?gcd(b,a%b):a;
	//��С��������
	//a*b/gcd(a,b) 
}


int qmi(int m, int k, int p) //������ 
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}







int main()
{
	int n;
	cin >> n;
	divide(n);
	return 0;
}

