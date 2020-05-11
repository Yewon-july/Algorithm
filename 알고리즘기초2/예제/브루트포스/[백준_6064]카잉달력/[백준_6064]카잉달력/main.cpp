#include <iostream>

using namespace std;

//greatest common divisor
//최대 공약수
int gcd(int a, int b){
    while(b != 0){
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    //테스트 케이스 횟수 입력
    int t;
    cin >> t;
    //테스트 케이스 개수만큼 반복
    while(t--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        //greatest common division 구하기
        int gcd_mn = gcd(m, n);
        
        //least common multiple
        //최소공배수 = 최소공약수 * (a/최소공약수) * (b/최소공약수)
        long long lcm = gcd_mn * (m/gcd_mn) * (n/gcd_mn);
        long long j = x;
        bool avail = false;
        for(int i=0; j <= lcm; i++){
            if((j-1)%n+1==y){
                avail = true;
                break;
            }
            j = (i+1)*m + x;

        }
        if(avail){
            cout << j << endl;
        }else{
            cout << -1 << endl;
        }
        
    }
    return 0;
}
