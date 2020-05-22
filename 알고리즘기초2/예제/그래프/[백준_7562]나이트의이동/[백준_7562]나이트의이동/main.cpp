//
//  main.cpp
//  [백준_7562]나이트의이동
//
//  Created by Yewon on 2020. 5. 16..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int Degree[300][300];
bool Check[300][300];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;
        int current_x, current_y;
        cin >> current_x >> current_y;
        int dest_x, dest_y;
        cin >> dest_x >> dest_y;
        
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                Check[i][j]=false;
                Degree[i][j] = -1;
            }
        }
        
        queue<pair<int, int>> q;
        q.push({current_x, current_y});
        Check[current_x][current_y]=true;
        Degree[current_x][current_y] = 0;
        while(!q.empty()){
            if(Check[dest_x][dest_y]) break;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<8; i++){
                int tx = x+dx[i];
                int ty = y+dy[i];
                if(tx>=0 && ty>=0 && tx<l && ty<l){
                    if(!Check[tx][ty]){
                        Check[tx][ty]=true;
                        Degree[tx][ty] = Degree[x][y]+1;
                        q.push({tx, ty});
                    }
                }
            }
            
        }
        cout << Degree[dest_x][dest_y] << '\n';
    }
    return 0;
}
