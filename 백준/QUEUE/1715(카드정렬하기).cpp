#include <iostream>
#include <queue>

using namespace std;

int main (){
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순
    int n, num;
    int sum = 0, count = 0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> num;
        pq.push(num);
    }
    
    while (pq.size()>1){
        int temp = 0;
        for (int i = 0; i < 2; i++){
            temp += pq.top();
            pq.pop();
        }
        pq.push(temp);
        sum += temp;
    }
    cout << sum;
}