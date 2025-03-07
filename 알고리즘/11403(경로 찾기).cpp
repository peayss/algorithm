#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n;
int d[MAX][MAX];
void floyd_washall(){
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (d[i][k] == 1 && d[k][j] == 1){
                    d[i][j] = 1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }
    floyd_washall();
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (d[i][j] > 0) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
}