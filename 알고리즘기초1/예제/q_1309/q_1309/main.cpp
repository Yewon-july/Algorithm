#include <iostream>

using namespace std;

int d[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    d[0] = 1;
    for(int i=1; i<=n; i++){
        if(i==1){
            d[i] = d[i-1] + 2;
            continue;
        }
        d[i] =  (d[i-1]*2 + d[i-2]) % 9901;
    }
    cout << d[n] << '\n';
    return 0;
}
