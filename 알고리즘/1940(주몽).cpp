#include <bits/stdc++.h>
using namespace std;

vector<int>arr;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int start = 0, end = n-1, total;
    while(start < end && end < n){
        total = arr[start] + arr[end];
        if (total == m) {
            cnt++;
            start++;
            end = n-1;
        }
        if (total < m) {
            start++;
            end = n-1;
        }
        if (total > m) end--;
    }
    // while(start <= end && end < n){
    //     total = arr[start] + arr[end];
    //     if (total == m) cnt++;
    //     if (end == n - 1){
    //         start++;
    //         end = start + 1;
    //     } else end++;
    // }
    cout << cnt;
}