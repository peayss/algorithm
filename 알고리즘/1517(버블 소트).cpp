#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll n, cnt = 0;
vector<ll>A;
ll tmp[500001];

void merge(ll s, ll e){
    ll mid = (s+e)/2;
    ll i = s, j = mid + 1, k = s;
    while (i <= mid && j <= e) {
        if (A[i] <= A[j]) tmp[k++] = A[i++];
        else {
            tmp[k++] = A[j++];
            cnt += mid - i + 1;
            //cout << "A[i] : " << A[i] << " A[j]: " << A[j] << '\n';
            //cout << "cnt : " << cnt << '\n';
        }
    }
    while (i <= mid) tmp[k++] = A[i++];
    while (j <= e) tmp[k++] = A[j++];
    for (int i=s; i<=e; i++){
        A[i] = tmp[i];
    }
}
void merge_sort(int s, int e){
    if (s < e) {
        ll mid = (s+e)/2;
        merge_sort(s,mid);
        merge_sort(mid+1,e);
        merge(s,e);
    }
}
int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        ll a; cin >> a;
        A.push_back(a);
    }
    merge_sort(0,n-1);
    cout << cnt;
}