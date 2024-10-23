#include <iostream>
#include <vector>
#include <queue>
#define MAX 10000

using namespace std;

vector<int> adj[MAX];
queue<int> q;
int vertex, edge, start;
int visited[MAX];

void dfs(int start){
    cout << start << " ";
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if (visited[next] == 0){
            visited[next] = 1;
            dfs(next);
        }
    }
}

void bfs(int start){
    q.push(start);
    visited[start] = 1;
    cout << start << ' ';
    while(!q.empty()){
        int now = q.front(); 
        q.pop();

        for(int i=0; i<adj[now].size(); i++){
            int next = adj[now][i];
            if (visited[next] == 0)
            {
                q.push(next);
                visited[next] = 1;
                cout << next << ' ';
            }
        }
    }
}

int main(){
    cin >> vertex >> edge >> start;
    for (int i=0; i<edge; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= vertex; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    visited[start] = 1;
    dfs(start);
    memset(visited, 0, sizeof(visited));
    cout << '\n';
    bfs(start);
}