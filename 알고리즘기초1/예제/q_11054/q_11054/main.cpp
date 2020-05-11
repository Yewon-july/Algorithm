#include <iostream>

using namespace std;

int a[1001];
int asc[1001];
int des[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        
        if(i==0){
            asc[i] = 1;
            continue;
        }
        
        int res_asc = 0;
        for(int j=0; j<i; j++){
            if(a[j]<a[i] && asc[j]>res_asc){
                res_asc = asc[j];
            }
        }
        asc[i] = res_asc + 1;
    }
    
    int result=0;
    for(int i=n-1; i>=0; i--){
        
        if(i==n-1){
            des[i] = 1;
            result = des[i] + asc[i] - 1;
            continue;
        }
        int res_des = 0;
        for(int j=n-1; j>i; j--){
            if(a[j]<a[i] && des[j]>res_des){
                res_des = des[j];
            }
        }
        des[i] = res_des + 1;
        
        if(result < asc[i]+des[i] - 1){
            result = asc[i] + des[i] - 1;
        }
    }
    cout << result << '\n';
    
    return 0;
}
