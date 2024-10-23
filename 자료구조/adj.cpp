#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int main(){
    vector<int> adj[MAX];
    int vertex, edge;
    cin >> vertex >> edge;
    for (int i=0; i<edge; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}