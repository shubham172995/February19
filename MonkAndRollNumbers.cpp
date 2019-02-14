/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    std::vector<std::string> a(n);
    std::vector<long long> b(n);
    for(int i=0;i<n;i++){
        scanf("%lld", &b[i]);
        std::cin>>a[b[i]%n];
    }
    int q;
    scanf("%d", &q);
    while(q--){
        long long x;
        scanf("%lld", &x);
        std::cout<<a[x%n]<<std::endl;
    }
    return 0;
}