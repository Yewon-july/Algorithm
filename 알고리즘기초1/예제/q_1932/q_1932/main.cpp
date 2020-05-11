#include <iostream>
#include <vector>

using namespace std;

long long d[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            int t;
            cin >> t;
            if(i==0){
                d[0][0] = t;
                continue;
            }
            if(j==0){
                d[i][j] = d[i-1][j] + t;
            }
            else if(j==i){
                d[i][j] = d[i-1][j-1] + t;
            }
            else{
                d[i][j] = max(d[i-1][j-1]+t, d[i-1][j]+t);
            }
        }
    }
    long long result=d[n-1][0];
    for(int i=1; i<n; i++){
        if(d[n-1][i]>result){
            result = d[n-1][i];
            
        }
    }
    cout << result << '\n';
    return 0;
}
