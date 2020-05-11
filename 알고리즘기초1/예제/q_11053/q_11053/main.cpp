#include <iostream>

using namespace std;

int arr[1001];
int d[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int ans = d[0];
    for(int i=0; i<n; i++){
        d[i]=1;
        for(int j=i; j>=0; j--){
            if(arr[i]>arr[j]){
                d[i] = max(d[i], d[j]+1);
            }
        }
        if(d[i]>ans){
            ans = d[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
