#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
///실패 나중에 다시 풀어보기

bool check[10] = {false};

bool ok(int x, int y, char c){
    if(c=='>'){
        if(x<y) return false;
    }
    if(c=='<'){
        if(x>y) return false;
    }
    return true;
}
int small = -1;
int big = -1;
void go(vector<char> &brac, int index, int n, vector<int> &res){
    if(index==n+1){
        int temp = 0;
        for(int i=0; i<n; i++){
            temp += pow(10, n-i-1);
        }
        if(small==-1 || (small!=-1 && temp < small)) small = temp;
        if(big==-1 || (big!=-1 && temp > big)) big = temp;

        return;
    }
    else{
        for(int i=0; i<n; i++){
            if(check[i]) continue;
            if(index==0 || ok(res[index-1], i, brac[index-1])){
                check[i] = true;
                res.push_back(i);
                go(brac, index+1, n, res);
                res.pop_back();
                check[i]=false;
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<char> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    vector<int> r;
    go(v, 0, n, r);
    
    cout << setfill('0') << setw(3) << small << '\n';
    cout << setfill('0') << setw(3) << big << '\n';

    
    return 0;
}
