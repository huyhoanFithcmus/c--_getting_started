#include <bits/stdc++.h>

using namespace std;

long long A(int k, int n)
{
    if (k == 0) return 1;
    if (n == 0) return 0;
    return A(k, n-1) + k*A(k-1, n-1);
}

long long A_v2(int k, int n)
{
    long long a[k+1][n+1];
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0) a[i][j] = 1;
            else if (j == 0) a[i][j] = 0;
            else a[i][j] = a[i][j-1] + i*a[i-1][j-1];
    return a[k][n];
}

int main()
{
    int k, n;
    cin >> k >> n;
    // cout << A(k, n) << endl;
    cout << A_v2(k, n) << endl;
    return 0;
}