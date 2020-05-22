//
//  main.cpp
//  [백준_10971]외판원순회2
//
//  Created by Yewon on 2020. 5. 13..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> per(n);
    
    for(int i=0; i<n; i++){
        per[i] = i;
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    long long ans = -1;
    do{
        bool tf = true;
        long long temp=0;
        for(int i=1; i<n; i++){
            if(v[per[i-1]][per[i]]==0){
                tf = false;
                break;
            }
            temp += v[per[i-1]][per[i]];
        }
        if(v[per[n-1]][per[0]]==0){
            tf=false;
        }
        if(tf){
            temp += v[per[n-1]][per[0]];
            if(ans==-1 || temp<ans){
                ans = temp;
            }
        }
    }while(next_permutation(per.begin(), per.end()));
    
    cout << ans << '\n';
    return 0;
}
// 1000000 1000000 0 1000000 1000000 1000000 1000000 1000000 1000000 1000000
