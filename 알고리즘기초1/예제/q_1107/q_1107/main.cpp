#include <iostream>
#include <cmath>
using namespace std;

bool broken[10] = {false};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int b;
        cin >> b;
        broken[b] = true;
    }
    
    
    
    return 0;
}
