#include <iostream>

using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    int i=0;
    for(i=1; i*i<=n; i++ ){
        arr[i] = i*i;
    }
    i--;
    
    int cnt=0;
    int sml = -1;
    
    while(i>0){
        for(int j=i; j>0; j--){
            while(arr[j]<=n){
                n-=arr[j];
                cnt++;
            }
        }
        if(sml==-1 || cnt < sml){
            sml = cnt;
        }
        i--;
    }
    
    cout << sml << endl;
    
    return 0;
}
