#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans=0;

void go(vector<int> &t, vector<int> &p, int i, int sum){
    if(i>t.size()){
        return;
    }
    if(i==t.size()){
        if(sum>ans) ans = sum;
        return;
    }
    
    go(t, p, i+1, sum);
    go(t, p, i+t[i], sum+p[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> t(n);
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }
    
    go(t, p, 0, 0);
    cout << ans << '\n';
    return 0;
}
