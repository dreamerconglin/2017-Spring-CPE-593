#include <iostream>
#include <vector>
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

int cal_ch(int n, int r){

    vector <vector <int> > val(n+1,vector<int>(r+1,-1));
    /*   Initialize a 2 dimension array to memory
     *    0 1 2 3 ... r
     *   0
     *   1
     *   2
     *   3
     *   .
     *   .
     *   .
     *   n
     */

    for(int i = 0; i <= r; i++){
        val[0][i] = 1;           // choose(0,i)=1
        val[i][i] = 1;           // choose(i,i)=1
    }

    for(int i = 0; i <= n; i++)
        val[i][0] = 1;           // choose(i,0)=1

    return ch(n ,r , val);
}


int main(){
    int n,r;

    cout<<"Enter in n: ";
    cin>>n;

    cout<<"Enter in r: ";
    cin>>r;

    cout<<"Choose(n,r) = "<<cal_ch(n,r)<<endl;

    return 0;
}
