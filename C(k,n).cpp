#include <bits/stdc++.h>

using namespace std;

long long C(int k, int n) 
{
    if (k == 0 || k == n) return 1;
    return C(k-1, n-1) + C(k, n-1);
}

long long C_v2(int k, int n) 
{
    long long C[n+1][k+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

int main()
{
    int k, n;
    cout << "Nhap k: ";
    cin >> k;
    cout << "Nhap n: ";
    cin >> n;
    // cout << C(k, n);
    cout << C_v2(k, n);
    return 0;
}

// Path: C(k,n).cpp