#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    string result;
    
    stack<int> stk;
    int count = 0;
    
    while(t--){
        int cur;
        cin >> cur;
        if(cur > count){
            while(count<cur){
                stk.push(count+1);
                result += "+ \n";
                count += 1;
            }
            result +=  "- \n";
            stk.pop();
        }else{
            if(cur == stk.top()){
                stk.pop();
                result += "- \n";
            }
            else{
                result = "NO \n";
                break;
            }
        }
    }
    cout << result << "\n";
    return 0;
}
