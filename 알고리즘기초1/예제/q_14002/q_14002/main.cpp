#include <iostream>
#include <stack>

using namespace std;

int arr[1001];
int d[1001];
int idx[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        d[i] = 1;
        idx[i]=i;
        
        for(int j=i; j>=0; j--){
            if(arr[i]>arr[j] && d[j]+1>d[i]){
                d[i] = d[j] + 1;
                idx[i] = j;
            }
        }
        
        if(d[ans]<d[i]){
            ans = i;
        }
    }
    
    stack<int> s;
    while(1){
        s.push(arr[ans]);
        if(ans == idx[ans]){
            break;
        }
        ans = idx[ans];
    }
    
    cout << s.size() << '\n';
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
