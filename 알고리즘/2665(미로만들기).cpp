#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

struct Node{
    int x,y,cost;
    bool operator<(const Node &n) const{
        return cost > n.cost;
    }
};

int arr[51][51];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
priority_queue<Node> pq;
int visited[51][51], dist[51][51];
int n; 

void dijkstra(int x, int y, int c){
    pq.push({x,y,c});
    while (!pq.empty()){
        Node now = pq.top(); pq.pop();
        // if (visited[x][y]) continue;
        // visited[x][y] = 1;

        for (int i=0; i<4; i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (dist[nx][ny] > arr[nx][ny] + now.cost){
                dist[nx][ny] = arr[nx][ny] + now.cost;
                pq.push({nx,ny,arr[nx][ny] + now.cost});
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        string s; cin >> s;
        for (int j=0; j<n; j++){
            arr[i][j] = (s[j] == '1') ? 0 : 1;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            dist[i][j] = INF;
        }
    }
    //visited[0][0] = 1;
    dist[0][0] = 0;
    dijkstra(0,0,0);
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << dist[n-1][n-1];
}