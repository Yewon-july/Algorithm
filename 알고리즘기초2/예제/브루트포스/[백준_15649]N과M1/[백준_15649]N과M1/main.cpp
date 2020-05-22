//재귀함수를 사용하여 문제 풀기
#include <iostream>
using namespace std;

int check[9]={false};
int ans[9];

void nm(int index, int n, int m){
    if(index==m+1){
        for(int i=1; i<=m; i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return ;
    }else{
        for(int i=1; i<=n; i++){
            if(check[i]) continue;
            check[i]=true;
            ans[index]=i;
            nm(index+1, n, m);
            check[i]=false;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    nm(1, n, m);
    
    return 0;
}
