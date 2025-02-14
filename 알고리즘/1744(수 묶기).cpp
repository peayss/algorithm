// -1 1 2 3 
// 3 2 1 / -1

// 음수 / 0 / 양수 따로 저장?
// 음수(-1)면 0으로 묶거나 
// 음수끼리 곱하면 양수 -> 가장 작은수끼리 곱해야 함
// 이웃 수랑 묶어야 최대
// -1 1 6 = 6
// 5 4 3 2 1 0
// 20 6 1 0 = 27
// 1 0 -1
// 1 1 -> 2
// 묶는거 vs 안묶고 모두 더한거 -> 최대값 출력

#include<bits/stdc++.h>
using namespace std;

priority_queue<int>pos;
priority_queue<int, vector<int>, greater<int>> neg;

int main(){
    int sum = 0, n, one=0, zero=0;
    cin >> n;
    for (int i=0; i<n; i++){
        int num; cin >> num;
        if (num == 0) zero++;
        else if (num == 1) one++;
        else if (num < 0) neg.push(num);
        else pos.push(num);
        sum += num;
    }
    //cout << "sum : " << sum << '\n';
    int temp_sum = 0;
    while (pos.size() > 1){ // 양수 계산
        int a = pos.top(); pos.pop();
        int b = pos.top(); pos.pop();
        temp_sum += (a*b);
        //cout << "a : " << a << " b : " << b << '\n';
    }
    if (!pos.empty()) {
        temp_sum += pos.top();
        //cout << "pos.top() : "<< pos.top() << '\n';
    }
    //cout << "양수 sum : " << temp_sum << '\n';

    while (neg.size() > 1) { // 음수 계산
        int a = neg.top(); neg.pop();
        int b = neg.top(); neg.pop();
        temp_sum += (a*b);
    }
    if (!neg.empty() && zero == 0) temp_sum += neg.top();
    //cout << "음수 sum : " << temp_sum << '\n';
    temp_sum += one;
    cout << (temp_sum > sum ? temp_sum : sum);    
}