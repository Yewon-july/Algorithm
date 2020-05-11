#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    
    vector<int> v;
    for(int i=1; !q.empty(); i++){
        if(i%k==0){
            v.push_back(q.front());
            q.pop();
        }else{
            q.push(q.front());
            q.pop();
        }
    }
    for(int i=0; i<n; i++){
        if(i==0){
            cout << "<"<< v[i] <<", ";
        }else if(i==n-1){
            cout << v[i] << ">";
        }else{
            cout << v[i] << ", ";
        }
    }
    return 0;
}
