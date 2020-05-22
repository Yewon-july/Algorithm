
/*
 #include <iostream>
 #include <vector>
 using namespace std;
 //인접 리스트
 vector<int> e[2000];
 //간선리스트
 vector<pair<int, int>> p_list;
 bool matrix[2000][2000];
 
 int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 cout.tie(nullptr);
 
 int n, m;
 cin >> n >> m;
 
 for(int i=0; i<m; i++){
 int from, to;
 cin >> from >> to;
 p_list.push_back({from, to});
 p_list.push_back({to, from});
 e[from].push_back(to);
 e[to].push_back(from);
 matrix[from][to] = true;
 matrix[to][from] = true;
 }
 for(int i=0; i<m*2; i++){
 for(int j=0; j<m*2; j++){
 int A = p_list[i].first;
 int B = p_list[i].second;
 
 int C = p_list[j].first;
 int D = p_list[j].second;
 
 if(A==B||A==C||A==D||B==C||B==D||C==D) continue;
 
 if(!matrix[B][C]) continue;
 
 for(int E : e[D]){
 if (A == E || B == E || C == E || D == E) {
 continue;
 }
 cout << 1 << '\n';
 return 0;
 }
 
 }
 }
 cout << 0 << '\n';
 return 0;
 }
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[2000];

bool check[2000] = {false};
bool tf = false;

void go(int count, int index, int n){
    if(count==4){
        tf = true;
    }
    if(tf)return;
    for(int i=0; i<edges[index].size(); i++){
        if(check[edges[index][i]])continue;

        check[index] = true;
        go(count+1, edges[index][i], n);
        check[index] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<edges[i].size(); j++){
            check[i] = true;
            go(1, edges[i][j], n);
            check[i] = false;
        }
    }
    
    if(tf) cout << 1 << '\n';
    if(!tf) cout << 0 << '\n';
    return 0;
}

