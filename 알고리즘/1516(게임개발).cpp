#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int n, inDegree[MAX], result[MAX], _time[MAX];
vector<int>adj[MAX];
queue<int>q;

void topologySort(){
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int now = q.front(); q.pop();
        // 나와 이어져 있는 건물들 시간에 더해주기
        for (int next : adj[now]){
            result[next] = max(result[next], result[now]+_time[now]);
            if (--inDegree[next] == 0) q.push(next);
        }
    }
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int building; cin >> _time[i];
        cin >> building;
        while (building != -1){
            adj[building].push_back(i);
            inDegree[i]++;
            cin >> building;
        }
    }
    // 진입 차수 : 0 1 1 2 1
    topologySort();
    for (int i=1; i<=n; i++) cout << result[i] + _time[i] << '\n';
}