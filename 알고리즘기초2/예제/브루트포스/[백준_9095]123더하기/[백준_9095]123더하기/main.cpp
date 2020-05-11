#include <iostream>

using namespace std;

int d[11];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    //브루트포스 말고 동적 할당으로 풀음
    while(t--){
        int n;
        cin >> n;
        
        for(int i=1; i<=n; i++){
            if(i==1){
                d[i]=1;
            }
            else if(i==2){
                d[i] = d[i-1] + 1;
            }
            else if(i==3){
                d[i] = d[i-2] + d[i-1] + 1;
            }
            else{
                d[i] = d[i-3] + d[i-2] + d[i-1];
            }
        }
        
        cout << d[n] << endl;
    }
    
    return 0;
}
