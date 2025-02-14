#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<ll>>pq;
int main(){
    ll n,m; cin >> n >> m;
    for (int i=0; i<n; i++){
        ll num; cin >> num;
        pq.push(num);
    }
    for (int i=0; i<m; i++){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll sum = a + b;
        pq.push(sum); pq.push(sum);
    }
    ll res = 0;
    while (!pq.empty()){
        res += pq.top(); pq.pop();
    }
    cout << res;
}