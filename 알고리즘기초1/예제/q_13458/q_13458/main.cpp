#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    int A[1000001];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    int B, C;
    cin >> B;
    cin >> C;
    
    int count = 0;
    for(int i=0; i<N; i++){
        A[i] = A[i] - B;
        if(A[i]>0){
            if(A[i]%C!=0){
                count += (A[i]/C) + 1;
            }else{
                count += (A[i]/C);
            }
        }
    }
    count += N;
    
    cout << count;
    
    return 0;
}
