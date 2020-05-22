//재귀로 풀기
#include <iostream>
using namespace std;

int ans[9];

void mn(int idx, int sel, int n, int m){
    if(sel==m){
        for(int i=1; i<=m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }else{
        for(int i=ans[idx-1]+1; i<=n; i++){
            ans[idx] = i;
            mn(idx+1, sel+1, n, m);
            
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    mn(1, 0, n, m);
    return 0;
}
