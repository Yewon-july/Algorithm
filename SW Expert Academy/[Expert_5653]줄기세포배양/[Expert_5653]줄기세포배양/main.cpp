#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int G[350][350];
int D[350][350];
int A[350][350];
int C[350][350];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void go(int x, int y, int cnt){
    for(int i=0; i<4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(G[tx][ty]==0){
            G[tx][ty] = G[x][y];
            A[tx][ty] = G[x][y];
            D[tx][ty] = G[x][y];
            C[tx][ty] = cnt;
         //   cout << "G[tx][ty]==0 tx, ty" << tx << " " << ty << endl;

        }else{
            if(C[tx][ty]==cnt && G[tx][ty] < G[x][y]){
                G[tx][ty] = G[x][y];
                A[tx][ty] = G[x][y];
                D[tx][ty] = G[x][y];
              //  cout << "G[tx][ty]<G[x][y] tx, ty" << tx << " " << ty << " " << G[x][y]<< endl;

            }
        }
    }
}


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("sample_input.txt", "r", stdin);
    int t;
    cin >> t;
    for(int a=1; a<=t; a++){
      //  cout << "test" << a << endl << endl;
        int n, m, k;
        cin >> n >> m >> k;
       // cout << "t n m k " <<t << " " <<n << " " << m << " " << k << endl;
        memset(G, 0, sizeof(G));
        memset(A, 0, sizeof(A));
        memset(D, 0, sizeof(D));
        memset(C, 0, sizeof(C));
        for(int i=150; i<150+n; i++){
            for(int j=150; j<150+m; j++){
                cin >> G[i][j];
              //  cout << G[i][j] << " ";
                A[i][j] = G[i][j];
                D[i][j] = G[i][j];
                C[i][j] = 0;
            }
           /// cout << endl;
        }
        
        int count = 1;
        while(k--){
         //   cout << "count: " << count << endl;
            for(int i=150-(count/2); i<n+150+(count/2); i++){
                for(int j=150-(count/2); j<m+150+(count/2); j++){
                    if(D[i][j]>0){
                        if(C[i][j]!=count){
                            D[i][j] -= 1;
                        }
                       // cout << "D[i][j]>0: i, j" << D[i][j] << " " << i << " " << j << endl;
                    }else{
                        if(A[i][j]>0){
                           // cout << "A[i][j]>0: i, j " << A[i][j] << " " << i << " " << j << endl;
                            go(i, j, count);
                            A[i][j] -= 1;
                        }
                    }
                }
            }
//            for(int i=150-(count/2); i<n+150+(count/2); i++){
//                for(int j=150-(count/2); j<m+150+(count/2); j++){
//                    cout << G[i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
            count += 1;
        }
        int ans = 0;
        for(int i=150-(count/2); i<n+150+(count/2); i++){
            for(int j=150-(count/2); j<150 + m+(count/2); j++){
                if(A[i][j]>0){
                    ans += 1;
                }
            }
        }
        cout << '#' << a << ' ' << ans << '\n';
//        cout << endl;
    }
    
    return 0;
}
