#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int arr[2][MAX];
int dp[2][MAX];

int main(){
    int t, n;
    cin >> t;
    while (t--){
        fill(&arr[0][0], &arr[1][MAX], 0);
        cin >> n;
        for (int i=0; i<2; i++){
            for (int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        dp[0][0] = arr[0][0]; dp[1][0] = arr[1][0];
        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];
        for (int i=2; i<n; i++){
            dp[0][i] = max({dp[1][i-2], dp[1][i-1]})+arr[0][i];
            dp[1][i] = max({dp[0][i-2], dp[0][i-1]})+arr[1][i];
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }
}