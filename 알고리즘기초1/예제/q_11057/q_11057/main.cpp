#include <iostream>

using namespace std;

int d[1001][10];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0; i<10; i++){
        d[1][i] = 1;
    }
    
    int n;
    cin >> n;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            d[i][j] = 0;
            for(int k=j; k<10; k++){
                d[i][j] += d[i-1][k];
            }
            d[i][j] %= 10007;
        }
    }
    
    int result = 0;
    for(int i=0; i<10; i++){
        result += d[n][i];
        result %= 10007;
    }
    
    cout << result << '\n';
    
    return 0;
}
