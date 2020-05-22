//
//  main.cpp
//  [백준_16947]서울지하철2호선
//
//  Created by Yewon on 2020. 5. 17..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstringq>
using namespace std;

vector<int> edges[3001];
int Check[3001] = {0};
vector<int> cycle;
int n;


void go(int start, int cur, int prev, vector<int> cyc){
    if(Check[cur]==1 && cur == start){
        for(int i=0; i<cyc.size(); i++){
            cycle.push_back(cyc[i]);
        }
        return;
    }
    if(Check[cur]==1) return;
    Check[cur] = 1;
    for(int i=0; i<edges[cur].size(); i++){
        if(edges[cur][i] != prev ){
            cyc.push_back(edges[cur][i]);
            go(start, edges[cur][i], cur, cyc);
            cyc.pop_back();
        }
    }
}

void BFS(int cur){
    queue<int> q;
    q.push(cur);
    bool Check_bfs[3001] = {false};
    int dist[3001] = {0};
    Check_bfs[cur] = true;
    
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(Check[cur]==1){
            cout << dist[cur] << ' ';
            return;
        }
        
        for(int i=0; i<edges[cur].size(); i++){
            if(!Check_bfs[edges[cur][i]]&&dist[edges[cur][i]]==0){
                Check_bfs[edges[cur][i]] = true;
                dist[edges[cur][i]] = dist[cur]+1;
                q.push(edges[cur][i]);
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    for(int i=0; i<n; i++){
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    for(int i=1; i<=n; i++){
        if(cycle.size()==0){
            vector<int> v;
            v.push_back(i);
            memset(Check, 0, sizeof(Check));
            go(i, i, -1, v);
        }
    }
    
    memset(Check, 0, sizeof(Check));
    
    for(int i=0; i<cycle.size(); i++){
        Check[cycle[i]] = 1;
    }

    for(int i=1; i<=n; i++){
        BFS(i);
    }
    
    return 0;
}
