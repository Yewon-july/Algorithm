#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("sample_sample_input.txt", "r", stdin);
    
    int t;
    cin >> t;
    //cout << "t: " << t << endl;
    for(int i=1; i<=t; i++){
        bool num[10] = {false};
        bool op[4] = {false};
        int dist[1000] = {0};
        //cout << dist[0] << endl;
        
        int n, o, m;
        cin >> n >> o >> m;
     //   cout << "n o m" << n << o << m << endl;
        
        for(int j=0; j<n; j++){
            int av;
            cin >> av;
     //       cout << av << endl;
            num[av] = true;
            dist[av] = 1;
        }
        
        for(int j=0; j<o; j++){
            int av;
            cin >> av;
     //       cout << av << endl;

            op[av-1] = true;
        }
        
        int target;
        cin >> target;
        
        for(int j=0; j<10; j++){
            if(dist[j]!=0){
                for(int k=0; k<10; k++){
                    if(k!=0&&num[k]){
                        dist[k*10+j] = dist[j] + 1;
                    }
                }
            }
        }
        for(int j=10; j<100; j++){
            if(dist[j]!=0){
                for(int k=0; k<10; k++){
                    if(k!=0 && num[k]){
                        dist[k*100+j]=dist[j]+1;
                    }
                }
            }
        }
        
        //cout << "target: " << target << endl;
        if(dist[target]!=0){
            cout <<'#' << i << ' ' << dist[target] << '\n';
            continue;
        }
        for(int j=4; j<=m; j++){
            if(dist[target]!=0) break;
            for(int a=0; a<=999; a++){
                if(dist[a] == 0 || dist[a]>=j-1) continue;
                for(int b=a; b<=999; b++){
                    if(dist[b] == 0 || dist[b] >= j-1) continue;
                    if(op[0] && (a+b>=0 && a+b<=999) &&dist[a+b]==0){
                        if(dist[a]<4 && dist[b]<4){
                            int res = dist[a] + dist[b] + 2;
                            if(res<=m) dist[a+b] =res;
                        }else{
                            int res = dist[a] + dist[b] + 1;
                            if(res<=m) dist[a+b] =res;
                        }
                    }
                    if(op[1]&& (b-a>=0 && b-a<=999) && dist[b-a]==0){

                        if(dist[a]<4 && dist[b]<4){
                            int res = dist[b] + dist[a] + 2;
                            if(res<=m) dist[b-a] = res;
                        }else{
                            int res = dist[b] + dist[a] + 1;
                            if(res<=m) dist[b-a] = res;
                        }
                    }
                    if(op[2] && (a*b>=0 && a*b<=999) && dist[a*b]==0){
                        if(dist[a]<4 && dist[b]<4){
                            int res = dist[b] + dist[a] + 2;
                            if(res<=m) dist[b*a] = res;
                        }else{
                            int res = dist[b] + dist[a] + 1;
                            if(res<=m) dist[b*a] = res;
                        }
                    }
                    if(op[3]  && a != 0 && (b/a>=0 && b/a<=999)&& dist[b/a]==0){
                        
                        if(dist[a]<4 && dist[b]<4){
                            int res = dist[b] + dist[a] + 2;
                            if(res<=m) dist[b/a] = res;
                        }else{
                            int res = dist[b] + dist[a] + 1;
                            if(res<=m) dist[b/a] = res;
                        }
                    }
                }
            }
        }
        if(dist[target]==0 || dist[target]>m) dist[target] = -1;
        cout << '#' << i << ' ' << dist[target] << '\n';
    }
}




/*

 #include <iostream>
 using namespace std;
 
 int main() {
     int T;
     cin >> T;
     for (int t = 1; t <= T; t++){
         int arr[1000] = { 0 };
         bool check[1000] = { false };
         bool op[4] = { 0 }; //+ - * /
     
         int N, O, M, target;
         cin >> N >> O >> M;
         
         for (int i = 0; i < N; i++) {
             int x;
             cin >> x;
             arr[x] = 1;
             check[x] = true;
         }
     
         for (int i = 0; i < O; i++) {
             int x;
             cin >> x;
             op[x - 1] = true;
         }
     
         cin >> target;
     
         for (int i = 1; i < 10; i++)
             if (arr[i])
                 for (int j = 0; j < 10; j++)
                     if (arr[j]){
                         arr[i * 10 + j] = 2;
                         check[i * 10 + j] = true;

                     }
         
         for (int i = 10; i < 100; i++)
             if (arr[i])
                 for (int j = 0; j < 10; j++)
                     if (arr[j]){
                         arr[i * 10 + j] = 3;
                         check[i * 10 + j] = true;
                     }
         
         if (arr[target]) {
             cout << "#" << t << " " << arr[target] << '\n';
             continue;
         }
         
         int r = -1;
         for (int i = 3; i < M; i++) {
             for (int j = 999; j > 0; j--) {
                 if (!arr[j] || arr[j] + 2 > i) continue;
                 for (int k = 999; k > 0; k--) {
                     if (!check[k] || arr[k] + arr[j] + 1 > i) continue;
         
                     if (op[0])
                         if (j + k < 1000)
                             if (!arr[j + k])
                                 arr[j + k] = arr[j] + arr[k] + 1;
         
                     if (op[1])
                         if(j - k >= 0)
                             if (!arr[j - k])
                                 arr[j - k] = arr[j] + arr[k] + 1;
         
                     if (op[2])
                         if (j * k < 1000)
                             if (!arr[j * k])
                                 arr[j * k] = arr[j] + arr[k] + 1;
         
                     if (op[3])
                         if (!arr[j / k])
                             arr[j / k] = arr[j] + arr[k] + 1;
         
                     if (arr[target]) {
                         r = i + 1;
                         break;
                     }
                 }
                 if (arr[target]) break;
             }
             if (arr[target]) break;
         }
     
     cout << "#" << t << " " << r << '\n';
     }
     
     return 0;
 }
*/
