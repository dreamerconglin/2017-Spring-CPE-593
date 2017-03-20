#include <iostream>
using namespace std;

long long int FilterPrime(long long int a, long long int b){

    long long int sum = 0;
    long long int num = sqrt(double(b));

    bool* Prime = new bool[num+1];
    bool* FilterPrime = new bool[b-a+1];

    for(long long int i = 2; i <= num; ++i)
        Prime[i] = true;
    for(long long int i = 0; i <= (b-a); ++i)
        FilterPrime[i] = true;

    for(long long int j = 2; j <= num; ++j)
        if(Prime[j] == true)
            for(long long int m = 2; j*m <= num; ++m)
                Prime[j*m] = false;

    for(long long int j = 2; j <= num; ++j)
        if(Prime[j] == true){
            long long int m;
            if(a/j <= 2)
                m = 2;
            else if(a%j == 0)
                m = a/j;
            else if(a%j != 0)
                m = a/j+1;
            for(; j*m <= b; ++m)
                FilterPrime[j*m-a] = false;
        }
    if(a <= 1)
        FilterPrime[1-a] = false;

    for(long long int k = 0; k <= b-a; ++k)
        if(FilterPrime[k] == true)
            ++sum;

    delete[] Prime;
    delete[] FilterPrime;

    return sum;
}
int main(){
    long long int a,b;
    cin >> a >> b;
    cout << FilterPrime(a,b) << endl;
    system("pause");
    return 0;
}
