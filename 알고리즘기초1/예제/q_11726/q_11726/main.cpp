#include <iostream>

using namespace std;

int arr[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    arr[0]=1;
    arr[1]=1;
    
    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        arr[i] = arr[i] % 10007;
    }
    
    cout << arr[n];
    
    return 0;
}
