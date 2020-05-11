#include <iostream>

using namespace std;

long long d[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    //max 넣어보기
    int t;
    cin >> t;
    
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    for(int i=3; i<1000001; i++){
        d[i] = (d[i-1] + d[i-2] + d[i-3]) % 1000000009;
    }
    while(t--){
        int n;
        cin >> n;
        
        cout << d[n] << '\n';
    }
    return 0;
}
