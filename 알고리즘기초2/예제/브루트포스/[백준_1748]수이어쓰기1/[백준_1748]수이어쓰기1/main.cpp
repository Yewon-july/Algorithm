#include <iostream>
#include <cmath>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    //n의 자릿수
    int len = 0;
    int temp = n;
    while(temp>0){
        len++;
        temp /= 10;
    }
    
    int ans=0;
    for(int i=1; i<=len; i++){
        //n의 자릿수 이전까지일 때
        if(i!=len){
            ans += i*pow(10, i-1)*9;
        }else{
            ans += i*(n-pow(10, i-1)+1);
        }
    }
    cout << ans << endl;
    return 0;
}
