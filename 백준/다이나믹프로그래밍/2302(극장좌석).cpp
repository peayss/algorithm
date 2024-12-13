#include <bits/stdc++.h>
#define MAX 41
using namespace std;

int arr[MAX];
int dp[MAX] = {1, 1, 2};

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    for (int i=1; i<=n; i++){
        arr[i] = i;
    }
    for (int i=0; i<m; i++){
        int num;
        cin >> num;
        arr[num] = -1;
    }
    for (int i=3; i<=MAX; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int total = 1;
    int cnt = 0;
    for (int i=1; i<=n; i++){
        cnt++;
        if (arr[i] == -1){
            total *= dp[cnt-1];
            cnt = 0;
        }
        if (i == n){
            total *= dp[cnt];
        }
    }
    cout << total;
}