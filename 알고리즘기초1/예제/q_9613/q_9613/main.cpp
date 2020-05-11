#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(b != 0){
        return GCD(b, a%b);
    }
    else return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cin.ignore();
        
        int v[111];
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        long long sum = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                sum +=  GCD(v[i], v[j]);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
