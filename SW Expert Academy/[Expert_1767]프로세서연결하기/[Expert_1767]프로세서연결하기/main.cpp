#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int n;
int G[12][12];
vector<pair<int, int>> core;
int ans = -1;
int tot = -1;

void go(int count, int sum, int total){
    if(count==core.size()){
//        cout << "total: " << total<< endl;
//        cout << "sum: " << sum<< endl;
        if(tot == -1 || (tot != -1 && tot <= total)){
            if((total==tot && (ans != -1 && ans >= sum)) || (total > tot) || ans == -1 ){
                tot = total;
                ans = sum;
            }
        }
        return;
    }
    
    int x = core[count].first;
    int y = core[count].second;
    //cout << "x, y " << x << ' ' << y << endl;
    
    //check whether it can go
    //left, bottom, right, top
    bool no[] = {false, false, false, false};
    for(int i=0; i<n; i++){
        if(G[x][i] != 0){
            if(i < y){
                no[0] = true;
            }
            if(i > y){
                no[2] = true;
            }
        }
        if(G[i][y] != 0){
            if(i < x){
                no[3] = true;
            }
            if(i > x){
                no[1] = true;
            }
        }
    }
    
    int cnt = 0;
    for(int i=0; i<4; i++){
        if(no[i]) cnt += 1;
    }
    
    if(cnt==4){
        //cout << "no change" << endl;
        go(count+1, sum, total);
        //cout << false << endl << endl;
    }
    
    for(int i=0; i<4; i++){
        if(!no[i]){
            if(i==0){
                for(int j=0; j<y; j++){
                    G[x][j] = 2;
                }
               // cout << "left x y " << x << " " << y << endl;//
                go(count + 1, sum + y, total+1);
                for(int j=0; j<y; j++){
                    G[x][j] = 0;
                }
            }
            if(i==1){
                for(int j=x+1; j<n; j++){
                    G[j][y] = 2;
                }
              // cout << "down x y " << x << " " << y << endl;
                go(count + 1, sum +n-x-1, total+1);
                for(int j=x+1; j<n; j++){
                    G[j][y] = 0;
                }
            }
            if(i==2){
                for(int j=y+1; j<n; j++){
                    G[x][j] = 2;
                }
              //  cout << "right x y " << x << " " << y << endl;
                go(count + 1, sum +n-y-1, total+1);
                for(int j=y+1; j<n; j++){
                    G[x][j] = 0;
                }
            }
            if(i==3){
                for(int j=0; j<x; j++){
                    G[j][y] = 2;
                }
             //   cout << "up x y " << x << " " << y << endl;

                go(count + 1,sum +x, total+1);
                for(int j=0; j<x; j++){
                    G[j][y] = 0;
                }
            }

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("sample_input.txt", "r", stdin);
    
    int t;
    cin >> t;
    
    for(int i=1; i<=t; i++){
        memset(G, 0, sizeof(G));
        ans = -1;
        tot = -1;
        core.clear();
        
        cin >> n;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> G[i][j];
                if(G[i][j]==1){
                    if(i > 0 && j > 0 && i < n-1 && j < n-1){
                        core.push_back(make_pair(i, j));
                    }
                }
            }
        }
//        for(int i=0; i<n; i++){
//            for(int j=0; j<n; j++){
//                cout << G[i][j] << " ";
//            }
//            cout << endl;
//        }
        
        go(0, 0, 0);
    
        cout << '#' << i << ' ' << ans << '\n';
    }
    
    return 0;
}
