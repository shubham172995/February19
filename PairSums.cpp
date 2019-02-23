/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>
using namespace std;
vector<int> b(9000000);
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);int ans=0;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        ++b[a[i]];
    }
    for(int i=0;i<n;i++)
    {if(b[a[i]]){
        int j=k-a[i];
        if(j<0)continue;
        --b[a[i]];
        if(b[j]){
        ans=1;
        break;}
    }}
    puts(ans==1?"YES\n":"NO\n");
    return 0;
}
