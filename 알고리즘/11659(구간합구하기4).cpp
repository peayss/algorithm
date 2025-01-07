#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int arr[MAX];
int sum[MAX];

int main(){
    int n, m;
    
    vector<int>answer;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    for (int i=1; i<=m; i++){
        int s, e;
        cin >> s >> e;
        answer.push_back(sum[e] - sum[s-1]);
    }
    for (int i=0; i<m; i++){
        cout << answer[i] << '\n';
    }  

}