#include <bits/stdc++.h>
using namespace std;

vector<int>adj[20001];
queue<int>q;
vector<string>res;
int visited[20001   ];

void bfs(){

}

int main(){
    int k; cin >> k;
    for (int i=0; i<k; i++){
        int v,e; cin >> v >> e;
        adj[v].push_back(e);
        adj[e].push_back(v);

    }
}