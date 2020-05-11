#include <iostream>
#define LEN 1000001

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    bool check[LEN];
    
    for(int i=2; i<LEN; i++){
        if(check[i]==false){
            for(int j=i*2; j<LEN; j+=i){
                check[j]=true;
            }
        }
    }
    
    int t;
    cin >> t;
    while(t--){
        int even;
        cin >> even;
    
        int count=0;
        for(int i=3; i<=even/2; i++){
            int small = even - i;
            int big = even - small;
            if(!check[small]&&!check[big]){
                count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
