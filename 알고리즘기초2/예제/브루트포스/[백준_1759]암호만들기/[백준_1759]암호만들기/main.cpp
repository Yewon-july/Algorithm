#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(string arr){
    int consonant=0;
    int vowel=0;
    for(char p : arr){
        if(p=='a'||p=='e'||p=='o'||p=='u'||p=='i'){
            vowel += 1;
        }else consonant += 1;
    }
    if(vowel>=1 && consonant>=2){
        return true;
    }else return false;
}
    
void go(int n, vector<char> &arr, string password, int i){
    if(password.length()==n){
        if(check(password)){
            cout << password << '\n';
        }
        return;
    }
    if(i >= arr.size()) return;
    go(n, arr, password+arr[i], i+1);
    go(n, arr, password, i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int l, c;
    cin >> l >> c;
    vector<char> v(c);
    
    for(int i=0; i<c; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),less<char>());
    go(l, v, "", 0);
    
    return 0;
}





/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//순열을 사용해서 푼 문제
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int l, c;
    cin >> l >> c;
    
    vector<char> alpha(c);
    vector<int> comb(c, 1);
    for(int i=l; i<c; i++){
        comb[i]=0;
    }
    for(int i=0; i<c; i++){
        cin >> alpha[i];
    }
    sort(alpha.begin(), alpha.end(), less<>());
    sort(comb.begin(), comb.end(), greater<>());
    bool vowel;
    int consonant;
    do{
        vowel = false;
        consonant = 0;
        for(int i=0; i<c; i++){
            if(comb[i]==1){
                if(alpha[i]=='a'||alpha[i]=='e'||alpha[i]=='i'||alpha[i]=='o'||alpha[i]=='u'){
                vowel = true;
                }else{
                    consonant+=1;
                }
            }
        }
        if(vowel&&consonant>=2){
            for(int i=0; i<c; i++){
                if(comb[i]==1){
                    cout << alpha[i];
                }
            }
            cout << '\n';
        }
    }while(prev_permutation(comb.begin(), comb.end()));
    
    return 0;
}
*/
