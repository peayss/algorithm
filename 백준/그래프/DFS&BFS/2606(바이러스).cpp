#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

vector<int> adj[MAX];
int visited[MAX];
int start, v, e;
int cnt = 0;
void dfs(int start){
    for (int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if (!visited[next]){
            visited[next] = 1;
            cnt++;
            dfs(next);
        }
    }
}
int main(){
    cin >> v >> e;
    for (int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    visited[1] = 1;
    dfs(1);
    cout << cnt;
}