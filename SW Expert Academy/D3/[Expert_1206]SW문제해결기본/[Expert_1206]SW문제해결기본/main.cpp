#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//테스트케이스 횟수 제한
#define TEST_CASE_NUM 10

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("user_output.txt", "wt", stdout);
    
    for(int i=1; i<=TEST_CASE_NUM; i++){
        int len;
        cin >> len;
        
        vector<int> tc(len);
        for(int i=0; i<len; i++){
            cin >> tc[i];
        }
        
        int ans = 0;
        for(int i=2; i<len-2; i++){
            if(tc[i]-tc[i-2]<=0 || tc[i]-tc[i-1]<=0 || tc[i]-tc[i+1]<=0 || tc[i]-tc[i+2]<=0){
                continue;
            }
            int min_1 = min(tc[i]-tc[i-2], tc[i]-tc[i-1]);
            int min_2 = min(tc[i]-tc[i+1], tc[i]-tc[i+2]);
            ans += min(min_1, min_2);
        }
        
        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}
