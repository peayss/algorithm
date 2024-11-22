#include <bits/stdc++.h>
#define MAX 91
using namespace std;

long long F[MAX];

long long fib(int n) // F[1]...F[n]까지 사용
{
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    if (F[n - 1] == 0)            // memo에서 fn-1 확인
        F[n - 1] = fib(n - 1); // memo에 없으면 호출
    if (F[n - 2] == 0)            // memo에서 fn-2 확인
        F[n - 2] = fib(n - 2); // memo에 없으면 호출
    return F[n - 1] + F[n - 2];
}

int main(void)
{
    int n;
    cin >> n;
    cout << fib(n);
}
