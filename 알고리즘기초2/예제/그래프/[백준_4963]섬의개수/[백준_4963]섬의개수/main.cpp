//
//  main.cpp
//  [백준_4963]섬의개수
//
//  Created by Yewon on 2020. 5. 16..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};
int map[50][50];
bool check[50][50] = {false};
void BFS(int x, int y, int h, int w){
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=0 && ty>=0 && tx<h && ty<w){
                if(map[tx][ty]==1 && !check[tx][ty]){
                    check[tx][ty] = true;
                    q.push({tx, ty});
                }
            }
        }
    }
}

int main() {
    int w, h;
    cin >> w >> h;
    
    while(w!=0 && h!= 0){
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> map[i][j];
                check[i][j]=false;
            }
        }
        int cnt = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j]==1 && !check[i][j]){
                    cnt += 1;
                    BFS(i, j, h, w);
                }
            }
        }
        cout << cnt << endl;
        cin >> w >> h;
    }
    return 0;
}
