//
//  main.cpp
//  [백준_7576]토마토
//
//  Created by Yewon on 2020. 5. 16..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int S[1000][1000];
int Degree[1000][1000] = {0};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


//bfs 문제 많이 풀어보고 익히기
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    queue<pair<int, int>> num1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> S[i][j];
            Degree[i][j] = -1;
            if(S[i][j]==1){
                num1.push({i, j});
                Degree[i][j] = 0;
            }
        }
    }
    
    while(!num1.empty()){
        int x = num1.front().first;
        int y = num1.front().second;
        num1.pop();
        for(int i=0; i<4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx>=0 && ty>=0 && tx<n && ty<m){
                if(Degree[tx][ty]==-1 && S[tx][ty]==0){
                    Degree[tx][ty] = Degree[x][y]+1;
                    num1.push({tx, ty});
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(Degree[i][j]==-1 && S[i][j]==0){
                cout << -1 << '\n';
                return 0;
            }
            if(ans < Degree[i][j]){
                ans = Degree[i][j];
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
