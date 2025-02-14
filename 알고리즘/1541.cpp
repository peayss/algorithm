#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int solve(){
    int sum = 0;
    int op = 1;
    for (int i=0; i<arr.size(); i++){
        if (arr[i] >= 0){
            sum += (arr[i]*op);
        } else if (arr[i] < 0) {
            op = -1;
            sum += arr[i];
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    
    int num = 0; 
    int op = 1; // 기본적으로 양수로 처리

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) { // 숫자일 경우
            num = num * 10 + (s[i] - '0'); 
        } else { // 연산자일 경우
            arr.push_back(num * op); // 숫자를 벡터에 저장
            num = 0; // 새로운 숫자 초기화
            op = (s[i] == '-') ? -1 : 1; // 마이너스일 경우 음수로 변경
        }
    }
    arr.push_back(num * op); // 마지막 숫자 추가

    // for (int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }

    int res = solve();
    cout << res;
}
