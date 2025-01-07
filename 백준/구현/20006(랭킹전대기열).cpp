#include <bits/stdc++.h>
using namespace std;

struct player{
    int l;
    string n;
    player (int _l, string _n){
        l = _l;
        n = _n;
    }
};

int p, m;

vector<player>arr;
vector<player>room[301];
bool check[301];

int COMP_BY_NAME(player x, player y){
    return x.n < y.n;
}

int main(){
    cin >> p >> m;
    for (int i=0; i<p; i++){
        int level; string name;
        cin >> level >> name;
        arr.push_back(player(level, name));
    }

    int r = 0;  
    int cnt = 1;
    
    for (int i=0; i<arr.size(); i++){
        if (check[i]) continue;

        int first_player_level = arr[i].l;
        room[r].push_back(player(arr[i].l, arr[i].n));
        check[i] = true;
        
        cnt = 1;
        for (int j=i+1; j<arr.size(); j++){
            if (cnt < m){
                if (!check[j] && arr[j].l >= first_player_level - 10 && arr[j].l <= first_player_level + 10){
                cnt++;
                room[r].push_back(player(arr[j].l, arr[j].n)); 
                check[j] = true;
                }
            }
        }
        if (cnt == m){
                sort(room[r].begin(), room[r].end(), COMP_BY_NAME);
                cout << "Started!" << '\n';
                for (int t=0; t<room[r].size(); t++){
                    cout << room[r][t].l << " " << room[r][t].n << '\n';
                }
        } else {
            cout << "Waiting!" << '\n';
            sort(room[r].begin(), room[r].end(), COMP_BY_NAME);
            for (int i=0; i<room[r].size(); i++){
                cout << room[r][i].l << " " << room[r][i].n << '\n';
            }
        }
        r++;
        cnt = 1;
    }
}