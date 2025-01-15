#include <bits/stdc++.h>
using namespace std;

int n, last = 0;
vector<int>arr;
vector<char>res;
stack<int>s;

int solve(){
    for (int i=0; i<n; i++){
        int now = arr[i];
        // push
        if (last < now){
            for (int j=last+1; j<=now; j++){
                s.push(j);
                res.push_back('+');
            }
            last = now;
        } 
        // pop
        if (!s.empty() && s.top() == now) {
            s.pop();
            res.push_back('-');
        } else return 0;
    }
    return 1;
}
void print(){
    for (int i=0; i<res.size(); i++) cout << res[i] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    if (solve()) print();
    else cout << "NO";
}