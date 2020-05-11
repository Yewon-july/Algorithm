#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    getline(cin, str);
    
    stack<char> stk;
    
    for(int i=0; i<int(str.length()); i++){
        if(str[i]=='<'){
            while(!stk.empty()){
                cout << stk.top();
                stk.pop();
            }
            while(str[i] != '>'){
                cout << str[i];
                i++;
            }
            cout << str[i];
            continue;
        }
        if(str[i] != ' '){
            stk.push(str[i]);
            continue;
        }
        if(str[i] == ' '){
            while(!stk.empty()){
                cout << stk.top();
                stk.pop();
            }
            cout << str[i];
            continue;
        }
    }
    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }

    return 0;
}
