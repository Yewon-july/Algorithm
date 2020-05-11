#include <iostream>
#include <vector>

using namespace std;

int d[100001][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> arr0(n);
        vector<int> arr1(n);
        
        for(int i=0; i<n; i++){
            cin >> arr0[i];
        }
        for(int i=0; i<n; i++){
            cin >> arr1[i];
        }
        
        d[0][0] = arr0[0];
        d[0][1] = arr1[0];
        for(int i=1; i<n; i++){
            if(i==1){
                d[i][0] = d[i-1][1] + arr0[i];
                d[i][1] = d[i-1][0] + arr1[i];
                continue;
            }
            d[i][0] = max(d[i-1][1]+arr0[i], d[i-2][1] + arr0[i]);
            d[i][1] = max(d[i-1][0]+arr1[i], d[i-2][0] + arr1[i]);
        }
        cout << max(d[n-1][0], d[n-1][1]) << '\n';
        for(int i=0; i<n; i++){
            arr0[i]=-1;
            arr1[i]=-1;
        }
    }
    
    return 0;
}
