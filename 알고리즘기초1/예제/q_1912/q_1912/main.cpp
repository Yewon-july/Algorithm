#include <iostream>

using namespace std;

int arr[100001];
int temp[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    temp[0] = arr[0];
    int ans = arr[0];
    for(int i=1; i<n; i++){
        temp[i] = max(temp[i-1]+arr[i], arr[i]);
        if(temp[i]>ans){
            ans = temp[i];
        }
    }
    cout << ans << '\n';
    
    return 0;
}
