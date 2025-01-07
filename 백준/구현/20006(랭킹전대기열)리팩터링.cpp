#include <bits/stdc++.h>
using namespace std;

struct player{
    int l;
    string n;
    player (int _l, string _n){
        l = _l;
        n = _n;
    }
    bool operator<(const player &p) const{
        return n < p.n;
    }
};

// vector<player>arr;
vector<player>room[301];
int first_player_level_arr[301];
int r = 0;
int p, m;

void create(int level, string name){
    room[r].push_back(player(level, name));
    first_player_level_arr[r] = level;
    r++;
}
bool enter(int level, string name){
    for (int i=0; i<r; i++){
        if (room[i].size() < m && level >= first_player_level_arr[i] - 10 && level <= first_player_level_arr[i] + 10){
            room[i].push_back(player(level, name));
            return true;
        }
    }
    return false;
}
void print(int room_num){
    if (room[room_num].size() == m) cout << "Started!" << '\n';
    else cout << "Waiting!" << '\n';
    sort(room[room_num].begin(), room[room_num].end());
    for (int t=0; t<room[room_num].size(); t++){
        cout << room[room_num][t].l << " " << room[room_num][t].n << '\n';
    }
}

int main(){
    cin >> p >> m;
    for (int i=0; i<p; i++){
        int level; string name;
        cin >> level >> name;
        // arr.push_back(player(level, name));
        if (!enter(level, name)){
            create(level, name);
        }
    }
    for (int i=0; i<r; i++){
        print(i);
    }
}