#include <iostream>
#include <vector>

using namespace std;
int n, m;

int horizontal(vector<vector<int>> &arr, int i, int j){
    int result = 0;
    if(j+1<m && i+1<n){
        int two = arr[i][j] + arr[i][j+1];
        //가로로 2개
        //정사각형
        if((two + arr[i+1][j] + arr[i+1][j+1]) > result)
            result = (two + arr[i+1][j] + arr[i+1][j+1]);
        if(j==0 || j+2<m){
            //ㅇㅇ__
            //_ㅇㅇ_ 모양
            if((two + arr[i+1][j+1] + arr[i+1][j+2]) > result)
                result = (two + arr[i+1][j+1] + arr[i+1][j+2]);
        }
        if(j>0 || j+2==m){
            //_ㅇㅇ_
            //ㅇㅇ__ 모양
            if((two + arr[i+1][j-1] + arr[i+1][j]) > result)
                result = (two + arr[i+1][j-1] + arr[i+1][j]);
            
        }
    }
    //가로로 3개
    if(j+2<m){
        int three = arr[i][j] + arr[i][j+1] + arr[i][j+2];
        if(i+1<n){
            if(three + arr[i+1][j]>result)
                result = three + arr[i+1][j];
            if(three + arr[i+1][j+1]>result)
                result = three + arr[i+1][j+1];
            if(three + arr[i+1][j+2]>result)
                result = three + arr[i+1][j+2];
        }
        if(i!=0){
            if(three + arr[i-1][j]>result)
                result = three + arr[i-1][j];
            if(three + arr[i-1][j+1]>result)
                result = three + arr[i-1][j+1];
            if(three + arr[i-1][j+2]>result)
                result = three + arr[i-1][j+2];
            
        }
    }
    //가로로 4개
    if(j+3<m){
        if(arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3] > result){
            result = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3];
        }
    }
    return result;
}
int vertical(vector<vector<int>> &arr, int i, int j){
    int result = 0;
    if(j+1<m && i+1<n){
        int two = arr[i][j] + arr[i+1][j];
        //세로로 2개
        //정사각형은 가로로에서 했으니까 제외
        if(i==0 || i+2<n){
            //ㅇ_
            //ㅇㅇ
            //_ㅇ 모양
            if((two + arr[i+1][j+1] + arr[i+2][j+1]) > result)
                result = (two + arr[i+1][j+1] + arr[i+2][j+1]);
        }
        if(i>0 || i+2==n){
            //_ㅇ
            //ㅇㅇ
            //ㅇ_
            if((two + arr[i-1][j+1] + arr[i][j+1]) > result)
                result = (two + arr[i-1][j+1] + arr[i][j+1]);
            
        }
    }
    //세로로 3개
    if(i+2<n){
        int three = arr[i][j] + arr[i+1][j] + arr[i+2][j];
        if(j+1<m){
            if(three + arr[i][j+1]>result)
                result = three + arr[i][j+1];
            if(three + arr[i+1][j+1]>result)
                result = three + arr[i+1][j+1];
            if(three + arr[i+2][j+1]>result)
                result = three + arr[i+2][j+1];
        }
        if(j!=0){
            if(three + arr[i][j-1]>result)
                result = three + arr[i][j-1];
            if(three + arr[i+1][j-1]>result)
                result = three + arr[i+1][j-1];
            if(three + arr[i+2][j-1]>result)
                result = three + arr[i+2][j-1];
            
        }
    }
    //세로로 4개
    if(i+3<n){
        if(arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j] > result){
            result = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j];
        }
    }
    return result;
}

int main(){
    cin >> n >> m;
    
    //배열 선언
    vector<vector<int>> arr(n, vector<int>(m, 0));
    //배열 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int v = vertical(arr, i, j);
            int h = horizontal(arr, i, j);
            if(v > result){
                result = v;
            }
            if(h > result){
                result = h;
            }
        }
    }
    
    cout << result << endl;
    
    
}
