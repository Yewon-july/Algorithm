#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal(vector<int> &a){
    int temp = 0;
    for(int i=1; i<a.size(); i++){
        temp += abs(a[i]-a[i-1]);
    }
    return temp;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    int ans = 0;
    do{
        int temp = cal(v);
        ans = max(ans, temp);
    }while(next_permutation(v.begin(), v.end()));
    
    cout << ans << endl;
    return 0;
}
