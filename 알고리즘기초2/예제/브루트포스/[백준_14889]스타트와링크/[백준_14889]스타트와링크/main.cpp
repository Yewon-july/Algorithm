#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[20][20];
int dif = -1;

void go(vector<bool> &check, int n, int current){
    int count = 0;
    for(int i=0; i<n; i++){
        if(check[i]) count += 1;
    }
    if(count==n/2 && current<n){
        int teamA=0;
        int teamB=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if( check[i] && check[j]){
                    teamA += S[i][j] + S[j][i];
                }else if(!check[i] && !check[j]){
                    teamB += S[i][j] + S[j][i];
                }
            }
        }
        if(dif == -1 || dif > abs(teamA-teamB)){
            dif = abs(teamA-teamB);
        }
        return;
    }
    if(current>=n) return;
    
    check[current]=false;
    go(check, n, current+1);
    check[current]=true;
    go(check, n, current+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            cin >> S[i][j];
        }
    }
    vector<bool> teamA(n, false);

    go(teamA, n, 0);
    cout << dif << '\n';
    
    return 0;
}
