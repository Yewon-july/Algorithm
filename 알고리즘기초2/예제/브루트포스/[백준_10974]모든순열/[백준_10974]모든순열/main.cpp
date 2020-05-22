//
//  main.cpp
//  [백준_10974]모든순열
//
//  Created by Yewon on 2020. 5. 13..
//  Copyright © 2020년 Yewon. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for(int i=0; i<n; i++){
       v[i] = i+1;
    }
    do{
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }while(next_permutation(v.begin(), v.end()));
    
    return 0;
}
