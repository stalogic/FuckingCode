#include <iostream>
using namespace std;

int cnt_bit(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int cnt = 0;

void count(int i, int j, int k, int visit[], int m, int n)
{
    if (i >= 0 && i < m && j >= 0 && j < n && visit[i * n + j] == 0)
    {
        visit[i * n + j] = 1;
        if (cnt_bit(i) + cnt_bit(j) <= k)
        {
            cnt++;
            count(i - 1, j, k, visit, m, n);
            count(i + 1, j, k, visit, m, n);
            count(i, j + 1, k, visit, m, n);
            count(i, j - 1, k, visit, m, n);
        }
    }
}

int main()
{
    int m = 20, n = 20, k = 15;
    int visit[m * n];
    for(int i=0;i<m*n;i++) visit[i]=0;      //这里可以使用memset(visit,0,m*n*sizeof(int))
    count(0, 0, k, visit, m, n);
    cout << cnt << endl;
    return 0;
}