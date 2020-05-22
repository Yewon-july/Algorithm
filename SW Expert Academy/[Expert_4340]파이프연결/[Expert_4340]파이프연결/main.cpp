
#include <iostream>
#include <cstdio>
using namespace std;
//실패 강의 다 듣고 풀어보기

int pipe[7][4]={
    {0, 0, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 1},
    {0, 0, 1, 1}
};

int arr[50][50];


//i, j는 자신 위치
//필수적으로 1이어야 하는 곳
int result = 250000;
void cal(int i, int j, int man, int count, int n){
    if(arr[i][j]==0){
        cout << i << j << count << " arr[i][j]==0 돌아가는중" << endl;

    }
    if(i==0&&j==0){
        cout << i << j << count << "i==0&&j==0 돌아가는중" << endl;
        if(arr[i][j]>=1 && arr[i][j]<=2){
            arr[i][j]=1;
             cal(i, j+1, 0, count+1, n);
        }else{
            arr[i][j]=4;
             cal(i+1, j+1, 1, count+1, n);
        }
    }else if(i==n&&j==n){
        if((man==0&&(arr[i][j]>=3&&arr[i][j]<=6))||(man==3&&(arr[i][j]>=1&&arr[i][j]<=2))){
            return;
        }
        cout << i << j << count << "(i==n&&j==n) 돌아가는중" << endl;
        result = result > count+1 ? count+1 : result;
    }else if(i>n || j>n){
        cout << i << j << count << "(i>n || j>n) 돌아가는중" << endl;
        return ;
    }else{
        if(man==0){
            if(arr[i][j]>=1 && arr[i][j]<=2){
                arr[i][j]=1;
                if(j<n-1){
                    cal(i, j+1, 0, count+1, n);
                }
            }else{
                arr[i][j]=4;
                cout << i << j << count << "(man==0) 돌아가는중" << endl;
                if(i<n-1){
                    cal(i+1, j, 3, count+1, n);
                }
                cout << i << j << count << "(man==0) 돌아가는중" << endl;
                arr[i][j]=5;
                if(i>0){
                    cal(i-1, j, 1, count+1, n);
                }
            }
        }else if (man==1){
            if(arr[i][j]>=1 && arr[i][j]<=2){
                arr[i][j]=2;
                if(i<n-1){
                    cal(i+1, j, 1, count+1, n);
                }
            }else{
                arr[i][j]=3;
                if(j<n-1){
                    cal(i, j+1, 0, count+1, n);
                }
                arr[i][j]=4;
                if(j>0){
                    cal(i, j-1, 2, count+1, n);
                }
            }
        }else if(man==2){
            if(arr[i][j]>=1 && arr[i][j]<=2){
                arr[i][j]=1;
                if(i>0){
                    cal(i-1, j, 2, count+1, n);
                }
            }else{
                arr[i][j]=3;
                if(i<n-1){
                    cal(i+1, j, 3, count+1, n);
                }
                arr[i][j]=6;
                if(i>0){
                    cal(i-1, j, 1, count+1, n);
                }
            }
        }else{
            if(arr[i][j]>=1 && arr[i][j]<=2){
                arr[i][j]=2;
                if(i<n-1){
                    cal(i-1, j, 3, count+1, n);
                }
            }else{
                arr[i][j]=5;
                cout << i << j << count << "(man==3) 돌아가는중" << endl;

                if(j>0){
                    cal(i, j-1, 2, count+1, n);
                }
                arr[i][j]=6;
                cout << i << j << count << "(man==0) 돌아가는중" << endl;
                if(j<n-1){
                    cal(i, j+1, 0, count+1, n);
                }
            }
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("sample_sample_input.txt", "r", stdin);
    
    int t;
    cin >> t;
    for(int a=0; a<t; a++){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
            }
        }
        
        cal(0, 0, 0, 0, n);
        
        cout << '#' << a << ' ' << result << endl;
        result = 250000;
    }
    
    return 0;
}
