#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    while(n != 0){
        
        vector<int> S(n);
        vector<int> com(n, 1);
        vector<int> temp;
        for(int i=0; i<n; i++){
            cin >> S[i];
        }
        for(int i=6; i<n; i++){
            com[i]=0;
        }
        sort(com.begin(), com.end(), greater<int>());
        do{
            for(int i=0; i<n; i++){
                if(com[i]==1){
                    cout << S[i] << ' ';
                }
            }
            cout << '\n';
        }while(prev_permutation(com.begin(), com.end()));
        cout << '\n';
        
        cin >> n;
    }
    return 0;
}
