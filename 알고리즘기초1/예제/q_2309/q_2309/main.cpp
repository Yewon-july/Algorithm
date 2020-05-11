#include <iostream>
#include <algorithm>

using namespace std;
int arr[9];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int sum = 0;
    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+9);
    bool success = false;
    for(int i=0; i<8 && !success; i++){
        for(int j=i+1; j<9 && !success; j++){
            if(sum - arr[i] - arr[j] == 100){
                for(int k=0; k<9; k++){
                    if(k!=i && k!=j){
                        cout << arr[k] << endl;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}
