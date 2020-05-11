#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("sample_input.txt", "r", stdin);
    
    int t;
    cin >> t;
    for(int a=1; a<=t; a++){
        int n, k;
        cin >> n >> k;
        
        deque<char> d;
        
        string num_hex;
        cin >> num_hex;
        
        for(char c : num_hex){
            d.push_back(c);
        }
        
        vector<int> v;
        while(1){
            int count=0;
            bool exist = false;
            for(int i=0; i<n; i+=n/4){
                string temp = "";
                for(int j=i; j<i+n/4; j++){
                    temp += d[j];
                }
                int res = stoi(temp, nullptr, 16);
                for(int j=0; j<v.size(); j++){
                    if(res==v[j]){
                        count++;
                        exist = true;
                        break;
                    }
                }
                if(!exist){
                    v.push_back(res);
                    sort(v.begin(), v.end(), greater<int>());
                }
                exist = false;
            }
            if(count==4){
                break;
            }
            d.push_back(d.front());
            d.pop_front();
        }
        cout << "#" << a <<" " << dec << v[k-1] << '\n';
        
        
        
    }
    return 0;
}
