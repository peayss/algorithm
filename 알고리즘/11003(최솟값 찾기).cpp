#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value, idx;
    Node (int _value, int _idx){
        value = _value;
        idx = _idx;
    }
    bool operator<(const Node &n) const{
        return value > n.value;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int N, L;
    priority_queue<Node>pq;
    cin >> N >> L;
    
    for (int i=1; i<=N; i++){
        int num;
        cin >> num;
        pq.push(Node(num, i));
        while (!pq.empty() && pq.top().idx < i-L+1)
        {
            pq.pop();
        }
        cout << pq.top().value << " ";
    }    
}