#include <iostream>
using namespace std;

//int arr[15][12];
int res[4][15][12];

void loop(int n){
    
}

int *func(int (*arr)[12], int count, int a, int b){
    for(int i=0; i<count; i++){
        if(arr[a-i][b]>1){
            func(arr, arr[a-i][b], a-i, b);
        }
        if(arr[a][b-i]>1){
            func(arr, arr[a][b-i], a, b-i);
        }
        arr[a-i][b] = 0;
        arr[a][b-i] = 0;
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    
    int n, w, h;
    cin >> n >> w >> h;
    
    for(int j=0; j<h; j++){
        for(int k=0; k<w; k++){
            cin >> arr[j][k];
            res[0][j][k] =arr[j][k];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<w; j++){
            for(int k=0; k<w; k++){
                
            }
        }
        
    }
    return 0;
}
