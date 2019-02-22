/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<iostream>
#include<math.h>

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
    /*while(i<=100000)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        i++;
    }*/
    int t;
    scanf("%d", &t);
    long long ans=0;
    unsigned long long fib[10000000];
    int k=3;fib[1]=1;fib[2]=2;
    while(k<10000000){
       //fib[k]=findMMI_fermat(fib[k-1]+fib[k-2], MOD);
       fib[k]=(fib[k-1]+fib[k-2])%MOD;
        ++k;
    }
    //std::cout<<fib[41]<<std::endl<<pow(2, 40)<<std::endl;
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
            //num=(long long)pow(2, n)-fib[n];
            num=den-fib[n];
            //std::cout<<den<<std::endl<<num<<std::endl;
        }
        den=findMMI_fermat(den, MOD);
        ans=(num*den)%MOD;
        std::cout<<ans<<std::endl;
    }
    return 0;
}