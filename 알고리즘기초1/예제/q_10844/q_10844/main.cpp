#include <iostream>

using namespace std;

long long arr[101][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        if(i==1){
            arr[i][0]=0;
            for(int j=1; j<10; j++){
                arr[i][j]=1;
            }
            continue;
        }
        for(int k=0; k<10; k++){
            if(k==0){
                arr[i][k] = (arr[i-1][k+1]) % 1000000000;
            }
            else if(k==9){
                arr[i][k] = arr[i-1][k-1] % 1000000000;
            }
            else{
                arr[i][k] = (arr[i-1][k-1] + arr[i-1][k+1]) % 1000000000;
            }
        }
    }
    
    int result = 0;
    for(int i=0; i<10; i++){
        result = (result + arr[n][i]) % 1000000000;
    }
    
    cout << result << '\n';
    
    return 0;
}
