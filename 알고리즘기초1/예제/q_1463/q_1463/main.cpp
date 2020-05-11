#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int x;
    cin >> x;
    
    int arr[x+1];
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(int i=4; i<x+1; i++){
        if(i%6==1 || i%6==4||i%6==5){
            arr[i] = 1 + arr[i-1];
        }
        else if (i%6==0 || i%6==3){
            arr[i] = 1 + arr[i/3];
        }
        else if (i%6==2){
            arr[i] = 1 + arr[i/2];
        }
    }
    cout << arr[x] << '\n';
    return 0;
}
