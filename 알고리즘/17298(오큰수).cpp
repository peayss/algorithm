#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

stack<int>s;
vector<int>arr;
int nge[MAX];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, now;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    s.push(0);
    for (int i=1; i<n; i++){ 
        int now = arr[i];
        while (!s.empty() && arr[s.top()] < now){
            nge[s.top()] = now;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()){
        nge[s.top()] = -1;
        s.pop();
    }
    for (int i=0; i<n; i++) cout << nge[i] << " ";
}