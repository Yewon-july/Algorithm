#include <iostream>

using namespace std;

int p[1001];
int d[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    d[0] = 0;
    p[0] = 0;
    for(int i=1; i<=n; i++){
        d[i] = p[i];
        for(int j=0; j<=i; j++){
            d[i] = min(d[i], p[i-j] + d[j]);
        }
    }
    
    cout << d[n] << '\n';
    
    return 0;
}
