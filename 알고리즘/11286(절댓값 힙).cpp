#include <bits/stdc++.h>
using namespace std;

struct compare {
    bool operator()(int num1, int num2){
        int inum1 = abs(num1);
        int inum2 = abs(num2);

        if (inum1 > inum2) return true;
        else if (inum1 == inum2) {
            if (num1 > num2) return true;
            else return false;
        } else return false;
    }
};
vector<int>res;
priority_queue<int, vector<int>, compare> pq;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) res.push_back(0);
            else {
                res.push_back(pq.top());
                pq.pop();
            }
            continue;
        }
        pq.push(num);        
    }
    for (int i=0; i<res.size(); i++) cout << res[i] << "\n";
}