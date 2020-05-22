#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[10][10];
int n;
int ans[10];

bool ok(int index){
    int sum = 0;
    for (int i=index; i>=0; i--) {
        sum += ans[i];
        if (S[i][index] == 0) {
            if (sum != 0) return false;
        } else if (S[i][index] < 0) {
            if (sum >= 0) return false;
        } else if (S[i][index] > 0) {
            if (sum <= 0) return false;
        }
    }
    return true;
}

bool go(int index) {
    if (index == n) {
        return true;
    }
    if (S[index][index] == 0) {
        ans[index] = 0;
        return ok(index) && go(index+1);
    }
    for (int i=1; i<=10; i++) {
        ans[index] = S[index][index]*i;
        if (ok(index) && go(index+1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    char t;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            cin >> t;
            if(t=='+'){
                S[i][j]=1;
            }
            if(t=='-'){
                S[i][j]=-1;
            }
            if(t=='0'){
                S[i][j]=0;
            }
        }
    }
    go(0);
    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    
    return 0;
}
