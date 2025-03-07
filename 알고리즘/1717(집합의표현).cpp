#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int parent[MAX];

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
    for (int i=0; i<m; i++){
        int q,a,b;
        cin >> q >> a >> b;
        if (q == 0){
            if (!isCycle(a,b)){
                unionParent(a,b);
            }
        }
        if (q == 1){
            if (!isCycle(a,b)) cout << "NO" << '\n';
            else cout << "YES" << '\n';
        }
    }
}