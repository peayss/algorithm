#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
queue<pair<int, int> > q;
int visited[101][101];
int dist[101][101];
int n,m,next_x,next_y;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(){
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n-1 && y == m-1){
            return;
        }

        for (int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if (next_x < 0 || next_y < 0 || next_x > n-1 || next_y > m-1) continue;
 
            if (!visited[next_x][next_y] && arr[next_x][next_y]){
                dist[next_x][next_y] = dist[x][y]+1;
                visited[next_x][next_y] = 1;
                q.push(make_pair(next_x,next_y));                
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j]-'0';
           // if (s[j] == '1') arr[i][j] = 1;
        }
    }
    visited[0][0] = 1;
    dist[0][0] = 1;
    q.push(make_pair(0,0));
    bfs();
    //print();
    cout << dist[n-1][m-1];
}