// 점화식 : F[n] = F[n-1] + F[n-2];
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;
long long F[MAX];

int main(){
    int n;
    cin >> n;
    F[1] = 1; F[2] = 2;
    for (int i=3; i<=n; i++){
        F[i] = (F[i-1] + F[i-2]) % 10007;
    }
    cout << F[n];
}