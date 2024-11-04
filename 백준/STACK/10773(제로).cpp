#include <bits/stdc++.h>
#define MAX 100000

using namespace std;
int arr[MAX];
stack<int> s;
int k, total = 0;

int main (){
    cin >> k;
    for (int i=0; i<k; i++){
        int a;
        cin >> a;
        if (a == 0 && !s.empty()) s.pop();
        else s.push(a);
    }

    while (!s.empty()){
        total += s.top();
        s.pop();
    }
    cout << total;
}