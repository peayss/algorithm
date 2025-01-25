#include <bits/stdc++.h>
using namespace std;

queue<int>q;

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        q.push(i);
    }
    while (q.size() > 1){
        q.pop(); // 1 pop
        int next = q.front(); // 2
        q.pop(); // 2
        q.push(next); // 3 4 2
    }
    cout << q.front(); 
}