#include <bits/stdc++.h>
using namespace std;

int parent[201];
int arr[201][201];
vector<int>route;

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
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) parent[i] = i;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                if (!isCycle(i,j)) unionParent(i,j);
            }
        }
    }
    for (int i=1; i<=m; i++){ // 여행경로
        int t; cin >> t;
        route.push_back(t);
    }
    int res = parent[route[0]];
    int flag = 0;
    for (int i=0; i<route.size()-1; i++){
        if (parent[route[i]] != parent[route[i+1]]){
            flag = 1; 
            break;
        }
    }
    if (flag) cout << "NO";
    else cout << "YES";
}