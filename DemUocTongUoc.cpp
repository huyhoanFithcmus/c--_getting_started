#include <bits/stdc++.h>

using namespace std;

long long countUoc(int num)
{
    long long count = 0;
    for (int i = 1; i <= num; i++)
        if (num % i == 0) count++;
    return count;
}

long long sumUoc(int num)
{
    long long sum = 0;
    for (int i = 1; i <= num; i++)
        if (num % i == 0) sum += i;
    return sum;
}

int main()  {
    int n;
    cin >> n;
    cout << countUoc(n) << endl;
    cout << sumUoc(n) << endl;
    return 0;
}
