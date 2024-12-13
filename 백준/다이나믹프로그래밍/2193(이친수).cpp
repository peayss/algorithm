#include <bits/stdc++.h>
#define MAX 91
using namespace std;

long long dp[MAX];

int main(){
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for (int i=3; i<MAX; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int n;
    cin >> n;
    cout << dp[n];
}