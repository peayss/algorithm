#include <bits/stdc++.h>
#define MAX 101
#define INF 99999999
using namespace std;

int n,m;
int d[MAX][MAX];
vector<int>res;

void floyd_washall(){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }          
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    for (int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        d[a][b] = 1; 
        d[b][a] = 1;
    }
    floyd_washall();
    // for (int i=1; i<=n; i++){
    //     for (int j=1; j<=n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    int min = INF, total = 0, result;
    for (int i=1; i<=n; i++){
        total = 0;
        for (int j=1; j<=n; j++){
            total += d[i][j];
        }
        if (total < min) min = total;
        res.push_back(total);
    }
    for (int i=0; i<n; i++){
        if (res[i] == min) {
            result = i;
            break;
        }
    }
    cout << result + 1;
}