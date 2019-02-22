/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<math.h>
#include <vector>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(long long N)
{
    // create vector F1
    vector<ll> F1(K+1);
    F1[1] = 1;
    F1[2] = 1;

    // create matrix T
    matrix T(K+1, vector<ll>(K+1));
    T[1][1] = 0, T[1][2] = 1;
    T[2][1] = 1, T[2][2] = 1;

    // raise T to the (N-1)th power
    if (N == 1)
        return 1;
    T = pow(T, N-1);

    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}

int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}

int main(){
    int i=1;
    int MOD=1000000007;
    int t;
    scanf("%d", &t);
    long long ans=0;
    /*int fib[10000000];
    //int k=3;fib[1]=1;fib[2]=2;
    while(k<10000000){
       //fib[k]=findMMI_fermat(fib[k-1]+fib[k-2], MOD);
       fib[k]=((fib[k-1]%MOD)+(fib[k-2]%MOD))%MOD;
        ++k;
    }
    int fib1[10000000];
    fib1[0]=fib[9999998]+fib[9999999];
    fib1[1]=fib1[0]+fib[9999999];
    k=2;
    while(k<10000000){
       //fib[k]=findMMI_fermat(fib[k-1]+fib[k-2], MOD);
       fib1[k]=((fib1[k-1]%MOD)+(fib1[k-2]%MOD))%MOD;
        ++k;
    }*/
    //std::cout<<fib[9999998]<<std::endl<<fib[9999999]<<std::endl<<fib1[0]<<std::endl;
    while(t--){
        unsigned long long n, num, den;num=den=0;
        scanf("%lld", &n);
        if(n==1||n==2){
            num=1;
            den=2;
        }
        else{
            den=fast_pow(2, n, MOD);
            //std::cout<<den<<std::endl;
            //num=((long long)pow(2, n))%MOD;
            num=den;
           // if(n<10000000)
            num=(num%MOD-(fib(n+1)%MOD)+MOD)%MOD;
            //std::cout<<fib(n+1)<<std::endl;
            //else
            //num=(num%MOD-(fib1[n-10000000]%MOD)+MOD)%MOD;
            //num=den-fib[n];
            //std::cout<<den<<std::endl<<num<<std::endl;
        }
        den=findMMI_fermat(den, MOD);
        ans=(num*den)%MOD;
        std::cout<<ans<<std::endl;
    }
    return 0;
}