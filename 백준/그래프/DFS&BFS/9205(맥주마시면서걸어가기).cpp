#include <bits/stdc++.h>
using namespace std;

int t, n, house_x, house_y, festival_x, festival_y;
int total = 20;

struct store{
    int x, y;
    store (int _x, int _y){
        x = _x;
        y = _y;
    }
};

queue<pair<int, int> > q;
vector<store> adj;
int res[50];
int visited_store[100];

int bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (abs(festival_x - x) + abs(festival_y - y) <= 1000) return 1;

        for (int j=0; j<adj.size(); j++){
            if (abs(adj[j].x - x) + abs(adj[j].y - y) <= 1000 && !visited_store[j]){
                visited_store[j] = 1;
                q.push(make_pair(adj[j].x, adj[j].y));
            }
        } 
    }
    return 0;
}

int main(){
    cin >> t;
    for (int z=0; z<t; z++){
        cin >> n;
        cin >> house_x >> house_y;

        adj.clear();
        for (int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            adj.push_back(store(x,y));
        }
        cin >> festival_x >> festival_y;
        memset(visited_store, 0, sizeof(visited_store));
        while (!q.empty()) q.pop();
        
        q.push(make_pair(house_x,house_y));
        if (bfs()) res[z] = 1;
    }
    for (int i=0; i<t; i++){
        if (res[i] == 1) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }
}