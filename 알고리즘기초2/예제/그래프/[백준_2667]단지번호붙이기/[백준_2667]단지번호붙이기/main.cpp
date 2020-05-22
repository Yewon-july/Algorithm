//
//  main.cpp
//  [백준_2667]단지번호붙이기
//
//  Created by Yewon on 2020. 5. 16..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

int Address[25][25];
int Check[25][25] = {0};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n;
int ans[25*25];

void BFS(int x, int y, int cnt){
    queue<pair<int, int>> q;
    q.push({x, y});
    Check[x][y] = cnt;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            if(x+dx[k]>=0&&y+dy[k]>=0&&x+dx[k]<n&&y+dy[k]<n){
                if(Address[x+dx[k]][y+dy[k]]==1 && Check[x+dx[k]][y+dy[k]]==0){
                    q.push({x+dx[k], y+dy[k]});
                    Check[x+dx[k]][y+dy[k]] = cnt;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &Address[i][j]);
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Address[i][j]==1 && Check[i][j]==0){
                cnt += 1;
                BFS(i, j, cnt);
            }
        }
    }
    
    printf("%d\n",cnt);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans[Check[i][j]]+=1;
        }
    }
    sort(ans+1, ans+cnt+1);
    for (int i=1; i<=cnt; i++) {
        printf("%d\n",ans[i]);
    }
    
    return 0;
}
