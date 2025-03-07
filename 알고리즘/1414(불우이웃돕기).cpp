#include <bits/stdc++.h>
using namespace std;

struct Node{
    int a,b,c;
    Node(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    bool operator<(const Node &n) const{
        return c < n.c;
    }
};
vector<Node>adj;
int parent[51];
int findParent(int node){
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node]);
}
void unionParent(int node1, int node2){
    node1 = findParent(node1);
    node2 = findParent(node2);
    if (node1 < node2) parent[node2] = node1;
    else parent[node1] = node2;
}
bool isCycle(int node1, int node2){
    node1 = findParent(node1);
    node2 = findParent(node2);
    if (node1 == node2) return true;
    else return false;
}
int main(){
    int n; cin >> n;
    int arr[n+1][n+1];
    int sum = 0;
    for (int i=0; i<n; i++){
        string s; cin >> s;
        for (int j=0; j<n; j++){
            if (s[j] >= 'a' && s[j] <= 'z') arr[i+1][j+1] = s[j]-'0'-48;
            else if (s[j] >= 'A' && s[j] <= 'Z') arr[i+1][j+1] = s[j]-'0'+10;
            else arr[i+1][j+1] = 0;
            sum += arr[i+1][j+1];
        }
    }
    for (int i=1; i<=n; i++){
        int now = i;
        for (int j=1; j<=n; j++){
            if (i!=j && arr[i][j] != 0) {
                adj.push_back(Node(i,j,arr[i][j]));
            }
        }
    }
    sort(adj.begin(), adj.end());
    int total = 0, cnt = 0;
    for (int i=1; i<=n; i++) parent[i] = i;
    for (int i=0; i<adj.size(); i++){
        if(!isCycle(adj[i].a, adj[i].b)){
            total += adj[i].c;
            cnt++;
            unionParent(adj[i].a, adj[i].b);
        } 
    }
    if (cnt < n-1) cout << -1;
    else cout << sum - total;
}