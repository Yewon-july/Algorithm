#include <iostream>
#include <vector>

using namespace std;

long long arr[100001][3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        for(int i=1; i<=n; i++){
            if(i==1){
                arr[i][0] = 1;
                arr[i][1] = 0;
                arr[i][2] = 0;
                continue;
            }
            if(i==2){
                arr[i][0] = 0;
                arr[i][1] = 1;
                arr[i][2] = 0;
                continue;
            }
            if(i==3){
                arr[i][0] = 1;
                arr[i][1] = 1;
                arr[i][2] = 1;
                continue;
            }
           
            arr[i][0] = (arr[i-1][1] + arr[i-1][2]) % 1000000009 ;
            arr[i][1] = (arr[i-2][0] + arr[i-2][2]) % 1000000009;
            arr[i][2] = (arr[i-3][0] + arr[i-3][1]) % 1000000009;

        }
        long long result = (arr[n][0]+arr[n][1]+arr[n][2]) % 1000000009;
        cout << result << '\n';
    }
    return 0;
}
