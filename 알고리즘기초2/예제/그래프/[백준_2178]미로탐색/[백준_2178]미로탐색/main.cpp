#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int S[100][100];
bool check[100][100] = {false};
int ans[100][100];
int n;
int m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void BFS(int x, int y){
    ans[0][0] = 1;
    check[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=0 && ty>=0 && tx<n && ty<m){
                if(!check[tx][ty]&&S[tx][ty]==1){
                    check[tx][ty] = true;
                    ans[tx][ty] = ans[x][y]+1;
                    q.push({tx, ty});
                }
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &S[i][j]);
        }
    }
    
    BFS(0, 0);
    
    printf("%d\n", ans[n-1][m-1]);
    
    return 0;
}
