#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

int n,m, inDegree[MAX], result[MAX];
vector<int>adj[MAX];
queue<int>q;

void topologySort(){
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0) q.push(i);
    }
    for (int i=1; i<=n; i++){
        if (q.empty()) return;
        int x = q.front(); q.pop();
        result[i] = x;
        for (int j=0; j<adj[x].size(); j++){
            int next = adj[x][j];
            if (--inDegree[next] == 0) q.push(next);
        }
    }
    for (int i=1; i<=n; i++){
        cout << result[i] << " ";
    }
}
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        inDegree[b]++;
    }
    topologySort();
}