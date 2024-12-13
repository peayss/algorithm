#include <bits/stdc++.h>
#define MAX 301
using namespace std;

int dp[MAX];
int arr[MAX];

int main(){

    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int num;
    cin >> num;
    for (int i=1; i<=num; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1], dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
    for (int i=4; i<=num; i++){
        int a = dp[i - 3] + arr[i - 1] + arr[i];
        int b = dp[i - 2] + arr[i];
        dp[i] = max(a,b);
    }
    cout << dp[num];
}