#include <bits/stdc++.h>
#define MAX 101
#define INF 999999
using namespace std;

int arr[MAX][MAX];
vector<int> adj[MAX];

int n,m;

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }

     for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (arr[i][j] > arr[i][k]+arr[k][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
    int total = 0, min_total = 99999, result;
    for (int i=1; i<=n; i++){
        total = 0;
        for (int j=1; j<=n; j++){
            total += arr[i][j];
        }
        if (total < min_total){
            min_total = total;
            result = i;
        }
    }
    cout << result;
}