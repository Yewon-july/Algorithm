#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    int t;
    cin >> t;
    
    vector<int> v1(t);
    vector<int> ans(t);
    
    stack<int> stk;
    
    for(int i=0; i<t; i++){
        cin >> v1[i];
    }
    
    stk.push(0);
    for(int i=1; i<t; i++){
        if(stk.empty()){
            stk.push(i);
        }
        while(!stk.empty() && v1[int(stk.top())]<v1[i]){
            ans[int(stk.top())] = v1[i];
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        ans[int(stk.top())] = -1;
        stk.pop();
    }
    
    for(int i=0; i<t; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
