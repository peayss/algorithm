#include <bits/stdc++.h>
#define MAX 101
#define INF 99999999
using namespace std;

int n,m;
int d[MAX][MAX];

void floyd_washall(){
    for (int k=1; k<=n; k++){ // k: 거쳐가는 노드
        for (int i=1; i<=n; i++){ // i: 출발지 노드
            for (int j=1; j<=n; j++){ // j: 도착지 노드
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c); // 중복 간선 처리
    }
    floyd_washall();
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (d[i][j] == INF) cout << 0 << " ";
            else cout << d[i][j] << " ";
        }
        cout << '\n';
    }
}