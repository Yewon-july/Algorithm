#include <iostream>

using namespace std;

int d[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    d[0][0] = 0;
    d[0][1] = 0;
    d[0][2] = 0;
    for(int i=1; i<=n; i++){
        int r, g, b;
        cin >> r >> g >> b;
        
        d[i][0] = min(d[i-1][1], d[i-1][2]) + r;
        d[i][1] = min(d[i-1][0], d[i-1][2]) + g;
        d[i][2] = min(d[i-1][0], d[i-1][1]) + b;
    }
    
    int result = min(d[n][0], d[n][1]);
    result = min(result, d[n][2]);
    
    cout << result << '\n';
    
    return 0;
}
