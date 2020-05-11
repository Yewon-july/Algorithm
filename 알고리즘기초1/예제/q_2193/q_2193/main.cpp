#include <iostream>

using namespace std;

long long arr[91][2];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        if(i==1){
            arr[i][0] = 0;
            arr[i][1] = 1;
            continue;
        }
        arr[i][0] = arr[i-1][0] + arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    
    cout << arr[n][0] + arr[n][1] << '\n';
    
    return 0;
}
