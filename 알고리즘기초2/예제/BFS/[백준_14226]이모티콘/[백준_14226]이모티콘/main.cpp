#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
//어렵당,,

int d[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int s;
    cin >> s;
    
    memset(d, -1, sizeof(d));
    
    queue<pair<int, int>> q;
    q.push({1, 0});
    d[1][0] = 0;
    while(!q.empty()){
        int screen = q.front().first;
        int clip = q.front().second;
        q.pop();
        if(screen==s){
            cout << d[screen][clip] << endl;
            return 0;
        }
        if(d[screen][screen]==-1){
            d[screen][screen] = d[screen][clip] + 1;
            q.push({screen, screen});
            
        }
        if(d[screen-1][clip]==-1){
            d[screen-1][clip] = d[screen][clip] + 1;
            q.push({screen-1, clip});
            if(screen-1==s){
                cout << d[screen-1][clip] << endl;
                return 0;
            }
        }
        if(d[screen+clip][clip]==-1){
            d[screen+clip][clip] = d[screen][clip] + 1;
            q.push({screen+clip, clip});
            if(screen+clip==s){
                cout << d[screen+clip][clip] << endl;
                return 0;
            }
        }
    }
}
