#include <bits/stdc++.h>
using namespace std;

int arr[1025][1025];
vector<int> res;
int n,m;

void prefix_sum(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            arr[i][j] = arr[i][j-1] + arr[i-1][j] + arr[i][j] - arr[i-1][j-1];
        }
    }
}
int calc(int x1, int y1, int x2, int y2){
    int res = arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
    return res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    
    prefix_sum();
    
    for (int i=1; i<=m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int num = calc(x1, y1, x2, y2);
        res.push_back(num);
    }
    for (int i=0; i<res.size(); i++){
        cout << res[i] << '\n';
    }
}