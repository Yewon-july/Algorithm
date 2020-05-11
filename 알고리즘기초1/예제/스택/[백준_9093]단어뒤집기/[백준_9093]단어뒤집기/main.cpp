#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    //getline을 사용할 것이기 때문에 cin.ignore()을 해준다.
    cin.ignore();
    
    while(t--){
        string str;
        getline(cin, str);
        str += '\n';
        stack<char> stk;
        for(char s : str){
            if(s == ' ' || s == '\n'){
                while(!stk.empty()){
                    cout << stk.top();
                    stk.pop();
                }
                cout << s;
            }else{
                stk.push(s);
            }
        }
    }
    return 0;
}
