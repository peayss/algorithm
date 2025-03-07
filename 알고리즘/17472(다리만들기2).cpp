// *모든 다리 길이의 최솟값 출력 -> 최소신장트리 활용
// 1. dfs/bfs를 돌려서 섬 개수 확인 및 번호 적어주기
// 2. 첫번째 섬부터 dx,dy로 움직이며 닿는 섬 확인
// 3. 이어주기

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int a, b, c;
    Node (int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    bool operator<(const Node &n) const{
        return c < n.c;
    }
};
int parent[7], arr[11][11], visited[11][11];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<Node>adj;
int n,m;

int getParent(int node){
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}
void unionParent(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) parent[node2] = node1;
    else parent[node1] = node2;
}
bool isCycle(int node1, int node2){
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) return true;
    else return false;
}
void dfs(int x, int y, int c){
    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (arr[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] = 1;
            arr[nx][ny] = c;
            dfs(nx,ny,c);
        }
    }
}
void move(int x, int y, int d){
    int nx = x, ny = y, length = 0;
    while (1){
        nx += dx[d];
        ny += dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == arr[x][y]) return;
        if (arr[nx][ny] == 0) length++;
        else if (arr[nx][ny] > 0) {
            if (length >= 2) {
                adj.push_back(Node(arr[x][y], arr[nx][ny], length));
                 cout << "다리 추가: " << arr[x][y] << " -> " << arr[nx][ny] 
                      << " 길이: " << length << '\n';
            }
            return; 
        }
        // else if (length >= 2 && arr[nx][ny] > 0) {
        //     adj.push_back({arr[x][y], arr[nx][ny], length}); // 출발 도착 거리
        //     cout << arr[x][y] << "  " << arr[nx][ny] <<  " "  << length <<'\n';
        //     return;
        // }
    }   
}
int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    int c = 1, cnt = 0, sum = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] && !visited[i][j]){
                arr[i][j] = c;
                visited[i][j] = 1;
                dfs(i,j,c);
                c++;
                cnt++;
            }
        }
    }
    // for (int i=0; i<n; i++){
    //     for (int j=0; j<m; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            for (int d=0; d<4; d++){
                if (arr[i][j] != 0)
                    move(i,j,d);
            }
        }
    }
    for (int i=1; i<=cnt; i++) parent[i] = i;
    sort(adj.begin(), adj.end());
    for (int i=0; i<adj.size(); i++){
        for (int i=0; i<adj.size(); i++){
            if (!isCycle(adj[i].a, adj[i].b)){
                unionParent(adj[i].a, adj[i].b);
                // cout << "union -> " << adj[i].a << " , " << adj[i].b << '\n';
                // cout << "cost : " << adj[i].c << '\n';
                sum += adj[i].c;
            }
        }
    }
    
    //for (int i=1; i<=cnt; i++) cout << parent[i] << " ";
    int res = parent[1];
    int flag = 0;
    for (int i=2; i<=cnt; i++){
        if (parent[i] != res) {
            flag = 1;
        }
    }
    if (flag) cout << -1;
    else cout << sum;
}