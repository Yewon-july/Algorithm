#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<char> left, right;
    string str;
    cin >> str;
    
    for(int i=0; i<int(str.length()); i++){
        left.push(str[i]);
    }
    
    int t;
    cin >> t;
    cin.ignore();
    
    while(t--){
        string com;
        getline(cin, com);
        if(com[0]=='L'){
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        }
        else if(com[0]=='D'){
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        }
        else if(com[0]=='B'){
            if(!left.empty()){
                left.pop();
            }
        }
        else if(com[0]=='P'){
            left.push(com[2]);
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    
    return 0;
}
