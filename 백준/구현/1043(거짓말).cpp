#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n,m, truth_num;
int truth[MAX];
vector <int> party[MAX]; // [파티 번호][사람]

int main() {
    cin >> n >> m; // 사람 수, 파티 수
    cin >> truth_num; // 진실을 아는 사람 수
    for (int i=1; i<=truth_num; i++){
        int n;
        cin >> n;
        truth[n] = 1;
    }
    for (int i=0; i<m; i++){ // 파티 정보
        int n;
        cin >> n;
        for (int j=0; j<n; j++){
            int p;
            cin >> p;
            party[i].push_back(p);
        }
    }

    int flag = 0;
    for (int i=0; i<m; i++) { // 마지막으로 한 번 더 반복
        for (int i=0; i<m; i++){
            for (int j=0; j<party[i].size(); j++){
                flag = 0;
                if (truth[party[i][j]] == 1) flag = 1;  
                if (flag) {
                    for (int x=0; x<party[i].size(); x++){
                        truth[party[i][x]] = 1;
                    }
                }
            }
        }
    }

    int cnt = 0;
    flag = 0;

    for (int i=0; i<m; i++){
        flag = 0;
        for (int j=0; j<party[i].size(); j++){
            if (truth[party[i][j]] == 1) flag = 1;   
        }
        if (!flag) cnt++;
    }

    cout << cnt;
}