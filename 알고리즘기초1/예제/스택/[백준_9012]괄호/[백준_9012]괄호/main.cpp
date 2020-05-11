#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        string str;
        cin >> str;
        
        int count_left = 0;
        int count_right = 0;
        for(char s : str){
            if(s=='('){
                count_left++;
            }else if(s==')'){
                count_right++;
            }
        }
        if(count_left==count_right){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';

        }
    }
    return 0;
}
