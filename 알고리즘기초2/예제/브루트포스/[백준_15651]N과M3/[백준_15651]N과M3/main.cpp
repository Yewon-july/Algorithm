#include <iostream>
using namespace std;
int ans[8];
void nm(int idx, int n, int m){
    if(idx>m){
        for(int i=1; i<=m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }else{
        for(int i=1; i<=n; i++){
            ans[idx] = i;
            nm(idx+1, n, m);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    nm(1, n, m);
    
    return 0;
}
