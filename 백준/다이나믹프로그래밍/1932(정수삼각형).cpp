#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int arr[MAX][MAX]; // 삼각형 배열
int dp[MAX][MAX];
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    for (int i=1; i<n; i++){
        for (int j=0; j<=i; j++){
            if (j == 0) dp[i][j] = dp[i-1][j] + arr[i][j];
            else if (j == i) dp[i][j] = dp[i-1][j-1] + arr[i][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[i][j];
        }
    }

    int max = 0;
    for (int i=0; i<n; i++){
        if (dp[n-1][i] > max) max = dp[n-1][i];
    }
    cout << max;

}