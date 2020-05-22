
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];

bool prev_permutation_yewon(int a[], int n){
    int i=n-1;
    for(i=n-1; i>0; i--){
        if(a[i]<a[i-1]) break;
    }
    if(i==0) return false;
    int j=n-1;
    for(j=n-1; j>=i; j--){
        if(a[j]<a[i-1]) break;
    }
    int biggest = j;
    for(j=biggest; j>=i; j--){
        if(a[j]<a[i-1]&&a[j]>a[biggest]) biggest = j;
    }
    swap(a[i-1], a[biggest]);
    sort(a+i, a+n, greater<int>());
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool tf = prev_permutation_yewon(arr, n);
    if(!tf){
        cout << -1 << endl;
    }else{
        for(int i=0; i<n; i++){
            cout << arr[i] << ' ';
        }
    }
    return 0;
}
