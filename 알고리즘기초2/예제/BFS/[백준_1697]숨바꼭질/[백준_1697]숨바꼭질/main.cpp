//
//  main.cpp
//  [백준_1697]숨바꼭질
//
//  Created by Yewon on 2020. 5. 19..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int dist[100001];
int dx[] = {-1, 1, 0};

//정점: 위치
//간선: 현 위치에서 1초 후에 도착할 수 있는 위치

void BFS(int x, int k){
    queue<int> q;
    q.push(x);
    dist[x] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        if(x==k){
            return;
        }
        for(int i=0; i<3; i++){
            int tx = x + dx[i];
            if(i==2) tx += x;
            if(tx >= 0 && tx <= 100000){
                if(dist[tx]==0){
                    dist[tx] = dist[x] + 1;
                    q.push(tx);
                }
            }
            
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    BFS(n, k);
    
    cout << dist[k]-1 << endl;
    
    return 0;
}
