#include <bits/stdc++.h>
using namespace std;

struct Node{
    int a, b, c;
    Node (int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    bool operator<(const Node &n) const{
        return c < n.c;
    }
};
int v,e,sum=0;
vector<Node>adj;
int parent[10001];

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
    cin >> v >> e;
    for (int i=0; i<e; i++){
        int a,b,c; cin >> a >> b >> c;
        adj.push_back(Node(a,b,c));
    }
    sort(adj.begin(), adj.end());
    for (int i=1; i<=v; i++) parent[i] = i;
    for (int i=0; i<e; i++){
        if (!isCycle(adj[i].a, adj[i].b)){
            sum += adj[i].c;
            unionParent(adj[i].a, adj[i].b);
        }
    }
    cout << sum;
}