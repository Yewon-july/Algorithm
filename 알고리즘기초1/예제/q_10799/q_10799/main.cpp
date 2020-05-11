#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    cin >> str;
    
    stack<int> stk;
    int result=0;
    
    for(int i=0; i<int(str.length()); i++){
        if(str[i]=='('){
            stk.push(i);
        }else{
            if(i-stk.top()==1){
                stk.pop();
                result += int(stk.size());
            }else{
                stk.pop();
                result += 1;
            }
        }
    }
    
    cout << result << "\n";
    return 0;
}
