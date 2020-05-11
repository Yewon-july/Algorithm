#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int E, S, M;
    cin >> E >> S >> M;
    
    int e=0, s=0, m=0;
    while(1){
        if(E==S && S==M && E==M){
            cout << E << '\n';
            break;
        }
        while((E<=S && E<=M) && !(E==S && S==M && E==M)){
            E += 15;
        }
        while((M<=S && M<=E)&& !(E==S && S==M && E==M)){
            M += 19;
        }
        while((S<=M && S<=E)&& !(E==S && S==M && E==M)){
            S += 28;
        }

    }
    return 0;
}
