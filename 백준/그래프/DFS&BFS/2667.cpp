#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int vertex, edge, start;
int visited[25][25];
int arr[25][25];

int n, cnt;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int next_r, next_c;

void dfs(int r, int c){
    for (int i=0; i<4; i++){
        next_r = r + dr[i];
        next_c = c + dc[i];
        
        if (next_r < 0 || next_c < 0 || next_r >= n || next_c >= n) 
            continue;
            
        if (visited[next_r][next_c] == 0 && arr[next_r][next_c] == 1){
            visited[next_r][next_c] = 1;
            cnt++;
            dfs(next_r, next_c);
        }
    }
}

int main(){
    cin >> n;

    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<n; j++){
            if (s[j] == '1') arr[i][j] = 1;
        }
    }


    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] == 1 && visited[i][j] == 0){
                cnt = 1; visited[i][j] = 1;
                dfs(i, j);
                v.push_back(cnt);
            }
        }
    }
   
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
}