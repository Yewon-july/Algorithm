//
//  main.cpp
//  [백준_2146]다리만들기
//
//  Created by Yewon on 2020. 5. 18..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int S[100][100];
bool check[100][100];
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = -1;

void classify(int x, int y, int num){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    S[x][y] = num;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            if(tx >= 0 && ty >= 0 && tx < n && ty < n){
                
                if(S[tx][ty]==1 && !check[tx][ty]){
                    check[tx][ty] = true;
                    S[tx][ty] = num;
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
}
void find(int x, int y, int c){
    vector<vector<int>> fd(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    fd[x][y] = 0;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx >= 0 && ty >= 0 && tx < n && ty < n){
                if(S[tx][ty]!=c && fd[tx][ty]==-1){
                    if(S[tx][ty]!=0){
                        if(ans==-1 || (ans!= -1 && ans > fd[x][y])){
                            ans = fd[x][y];
                            return;
                        }
                    }else{
                        fd[tx][ty] = fd[x][y]+1;
                        q.push(make_pair(tx, ty));
                    }
                }
            }
        }
    }

}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }
    
    int cnt = 2;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!check[i][j] && S[i][j] != 0){
                classify(i, j, cnt);
                cnt += 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bool go = false;
            //check whether find or not
            for(int k=0; k<4; k++){
                int tx = i + dx[k];
                int ty = i + dy[k];
                if(tx >= 0 && ty >= 0 && tx < n && ty < n){
                    if(S[i][j] !=0 && S[tx][ty]==0){
                        go = true;
                        break;
                    }
                }
            }
            if(go) find(i, j, S[i][j]);
        }
    }
    
    cout << ans << endl;
    
    
    
    
    return 0;
}
