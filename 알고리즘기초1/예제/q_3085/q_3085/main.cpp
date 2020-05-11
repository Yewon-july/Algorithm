#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(vector<string> &v){
    int ans = 1;
    int count = 1;
    for(int i=0; i<v.size(); i++){
        count = 1;
        for(int j=1; j<v.size(); j++){
            if(v[i][j-1]==v[i][j]){
                count++;
            }else{
                count = 1;
            }
            if(count > ans){
                ans = count;
            }
        }
        count=1;
        for(int j=1; j<v.size(); j++){
            if(v[j][i]==v[j-1][i]){
                count++;
            }else{
                count = 1;
            }
            if(count > ans){
                ans = count;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> v(n);
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int result = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j+1<n){
                swap(v[i][j], v[i][j+1]);
                if(result < check(v)){
                    result = check(v);
                }
                swap(v[i][j], v[i][j+1]);
            }
            if(i+1<n){
                swap(v[i][j], v[i+1][j]);
                if(result < check(v)){
                    result = check(v);
                }
                swap(v[i][j], v[i+1][j]);
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}
