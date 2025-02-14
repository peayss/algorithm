#include <bits/stdc++.h>
using namespace std;

struct Node {
    int end;
    int value;
};
int n,m;
vector<Node>adj[100001];
int visited[100001];
int sum = 0, maxDist, maxNode;

void dfs(int start, int dist){    
    if (maxDist < dist){
        maxDist = dist;
        maxNode = start;
    }

    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i].end;
        int value = adj[start][i].value;
        //cout << "start : " << start << "\n";
        //cout << "next : " << next << "\n";
        if (!visited[next]){
            //cout << "방문할 노드는 : " << next << '\n';
            //cout << "dist : " << dist << '\n';
            visited[next] = 1;
            dfs(next, dist + value);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        int s; cin >> s;
        while (1){
            int e,v; 
            cin >> e;
            if (e == -1) break;
            cin >> v;
            adj[s].push_back({e,v});
        }
    }
    // 가장 먼 노드 찾기
    visited[1]=1;
    dfs(1,0);
    //cout << maxNode;
    memset(visited, 0, sizeof(visited));
    maxDist = 0;
    visited[maxNode]=1;
    dfs(maxNode,0);
    cout << maxDist;
}
