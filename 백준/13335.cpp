//해결x
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,w,l;
    int cnt = 0;
    vector<int> truck;
    stack<int> stack;

    cin >> n >> w >> l;
    for (int i=0; i<n; i++){
        int truck_weight;
        cin >> truck_weight;
        truck.push_back(truck_weight);
    }

    stack.push(truck[0]);
    cnt++;
    for(int i=0; i<n-1; i++){
        if (truck[i] + truck[i+1] <= l && stack.size() < l){
            stack.push(truck[i+1]);
            cnt++;
        } else {
            cnt++;
            stack.pop();
            if (stack.size()==0) {
                stack.push(truck[i+1]);
                cnt++;
            }
        }
    }
    cout << cnt + 2;


}