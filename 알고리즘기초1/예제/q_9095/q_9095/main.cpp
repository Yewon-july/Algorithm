#include <iostream>

using namespace std;

int d[11];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    d[0]=1;
    d[1]=1;
    d[2]=2;
    
    for(int i=3; i<=11; i++){
        d[i] = d[i-1]+d[i-2]+d[i-3];
    }
    
    while(t--){
        int num;
        cin >> num;
        
        cout << d[num] << '\n';
    }
    return 0;
}
