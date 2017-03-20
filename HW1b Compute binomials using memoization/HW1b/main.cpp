#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int ch(int n ,int r, vector <vector <int> > &value){

    if(value[n][r] != -1){
        return value[n][r];              // Use memoization
    }

    else{
        value[n][r] = ch(n - 1 ,r , value) + ch(n - 1 ,r - 1, value);          // Recursion
    }

    return value[n][r];                // Return the value

}

int cal_ch(int n, int r,vector <vector <int> > &val){

    for(int i = 0; i <= r; i++){
        val[0][i] = 1;           // choose(0,i)=1
        val[i][i] = 1;           // choose(i,i)=1
    }

    for(int i = 0; i <= n; i++)
        val[i][0] = 1;           // choose(i,0)=1

    return ch(n ,r , val);
}


int main(){

    srand((int)time(NULL));    //利用时间函数time()，产生每次不同的随机数种子
    int n[100000000],r[100000000],ans[100000000];
    for(int i=0; i<100000000;i++){
        n[i]=rand()%52+1;
        r[i]=rand()%n[i]+1;//rand()%50用于产生0-49之间的随机数
    }

    vector <vector <int> > val(53,vector<int>(53,-1));

    cal_ch(52,52,val);

    for(int i=0; i<100000000;i++){
        ans[i]=val[n[i]][r[i]];
    }

    return 0;
}
