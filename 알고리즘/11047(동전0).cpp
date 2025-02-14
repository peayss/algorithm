#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k;
    vector<int>coin;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        int amount; cin >> amount;
        coin.push_back(amount); 
    }
    int temp = k, now = k, cnt = 0;
    while (temp > 0){
        for (int i=n-1; i>=0; i--){
            if (coin[i] <= temp){
                cnt += temp / coin[i];
                temp %= coin[i];
            }
        }
    }
    cout << cnt;
}