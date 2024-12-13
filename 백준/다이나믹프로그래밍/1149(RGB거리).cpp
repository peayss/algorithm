#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int arr[MAX][3];
int dp[MAX][3];
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0]; dp[0][1] = arr[0][1]; dp[0][2] = arr[0][2];
    for (int i=1; i<n; i++){
        for (int j=0; j<n; j++){
            if (j == 0) dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + arr[i][j];
            if (j == 1) dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + arr[i][j];
            if (j == 2) dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + arr[i][j];
        }
    }
    int result = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    cout << result;
}