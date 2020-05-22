#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10001];
bool next_permutation_yewon(int v[], int n){
    int i=n-1;
    while(v[i]<v[i-1]&&i>0) i-=1;
    if(i==0) return false;
    int j=n-1;
    for(j=n-1; j>i; j--){
        if(v[j]>v[i-1]) break;
    }
    int smallest = j;
    for(j=smallest; j>i; j--){
        if(v[smallest]>v[j]) smallest = j;
    }
    swap(v[smallest], v[i-1]);
    sort(v+i, v+n, less<int>());
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    bool tf = next_permutation_yewon(a, n);
    if(!tf){
        cout << -1 << '\n';
    }else{
        for(int i=0; i<n; i++){
            cout << a[i] << ' ';
        }
    }
    return 0;
}
