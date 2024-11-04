#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<char> op;
int n, cnt=1;

int main() {
    cin >> n;
    
    for (int i=0; i<n; i++){

        int num;
        cin >> num;
        
        while (cnt <= num){
            s.push(cnt);
            cnt++;
            op.push_back('+');
        }

        if (s.top() == num){
            s.pop();
            op.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }
    for (int i=0; i<op.size(); i++){
        cout << op[i] << '\n';
    }
}