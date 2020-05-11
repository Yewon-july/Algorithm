#include <iostream>
#include <queue>

using namespace std;

int d[1001][3];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    queue<int> r, g, b;
    for(int i=0; i<n; i++){
        int rgb[3];
        cin >> rgb[0] >> rgb[1] >> rgb[2];
        r.push(rgb[0]);
        g.push(rgb[1]);
        b.push(rgb[2]);
    }
    int result = -1;
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            if(i==0){
                d[i][0] = r.front();
                d[i][1] = g.front();
                d[i][2] = b.front();
            }
            else{
                d[i][0] = min(d[i-1][1], d[i-1][2]) + r.front();
                d[i][1] = min(d[i-1][0], d[i-1][2]) + g.front();
                d[i][2] = min(d[i-1][0], d[i-1][1]) + b.front();
            }
            r.push(r.front());
            g.push(g.front());
            b.push(b.front());
            r.pop();
            g.pop();
            b.pop();
        }
        r.push(r.front());
        g.push(g.front());
        b.push(b.front());
        r.pop();
        g.pop();
        b.pop();
        int temp =d[n-1][2] > min(d[n-1][0], d[n-1][1]) ? min(d[n-1][0], d[n-1][1]) : d[n-1][2];
        if((result == -1) || (result != -1 && result > temp)){
            result = temp;
        }
    }
    cout << result << '\n';
    
    return 0;
}
