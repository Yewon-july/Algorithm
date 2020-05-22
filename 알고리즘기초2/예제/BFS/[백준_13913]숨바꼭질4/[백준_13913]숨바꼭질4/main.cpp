#include <iostream>
#include <queue>

using namespace std;
int n, k;

int d[100001];
int from[100001];
int dx[] = {-1, 1, 0};

void BFS(int x){
    queue<int> q;
    q.push(x);
    d[x] = 1;
    
    while(!q.empty()){
        x = q.front();
        q.pop();
        if(x == k){
            return;
        }
        for(int i=0; i<3; i++){
            int tx = x + dx[i];
            if(i==2) tx += x;
            if(tx >=0 && tx <= 100000){
                if(d[tx]==0){
                    d[tx] = d[x] + 1;
                    q.push(tx);
                    from[tx] = x;
                }
            }
        }
        
    }
}

void print(int f){
    if(f==n){
        cout << f << " ";
        return;
    }
    print(from[f]);
    cout << f << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;
    
    BFS(n);
    
    cout << d[k]-1 << endl;
    
    print(k);
    
    return 0;
}
