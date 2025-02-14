#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순
    cin >> n;
    for (int i=0; i<n; i++){
        int num; cin >> num;
        pq.push(num);
    }
    int sum = 0;
    while (pq.size() > 1){
        int temp = 0;
        for (int i=0; i<2; i++){
            temp += pq.top(); pq.pop();
        }
        pq.push(temp);
        sum += temp;
    }
    cout << sum;
}