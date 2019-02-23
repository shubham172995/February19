#include<bits/stdc++.h>

int main(){
	long w1, h1, w2, h2;
	std::cin>>w1>>h1>>w2>>h2;
	long res=0;
	res+=w1+2;
	res+=h1+h2+1;
	res+=h1;
	res+=w1+1-w2;
	res+=(h2-1);
	res+=w2+1;
	std::cout<<res<<std::endl;

}