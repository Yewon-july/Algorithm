#include <iostream>

using namespace std;

long long dl[100001];
long long dr[100001];
int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
        
        dl[i] = arr[i];
    }
    

    return 0;
}
