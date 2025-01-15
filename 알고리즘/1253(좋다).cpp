// 음수도 가능!
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    vector<ll>arr;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());    
    int cnt = 0;
    for (int i=0; i<n; i++){ 
        ll now = arr[i];
        int start = 0;
        int end = n-1; 

        while (start < end){
            if (start == i) { start++; continue;}
            if (end == i) { end--; continue;}

            ll total = arr[start] + arr[end];
            if (total == now){
                cnt++; 
                break;
            } else if (total < now) start++;
            else end--;
        }
    }
    cout << cnt;
}