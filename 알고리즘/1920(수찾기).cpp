#include <bits/stdc++.h>
using namespace std;

vector<int>ans;
int n,m;

void binary_search(int num){
    int s = 0;
    int e = n-1;
    while (s <= e) {
        int m = (s+e)/2;
        if (ans[m] == num){
            cout << 1 << '\n';
            return;
        }
        else if (ans[m] > num){
            e = m-1;
        } else if (ans[m] < num){
            s = m+1;
        }
    }
    cout << 0 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        int a; cin >> a;
        ans.push_back(a);
    }
    sort(ans.begin(), ans.end());
    cin >> m;
    for (int i=0; i<m; i++){
        int a; cin >> a;
        binary_search(a);
    }
}