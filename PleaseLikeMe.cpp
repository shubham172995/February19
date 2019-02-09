#include<bits/stdc++.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long double l, d, s, c;
		std::cin>>l>>d>>s>>c;
		s=s*std::pow(c+1, d-1);
		if(s>=l)
			printf("ALIVE AND KICKING\n");
		else printf("DEAD AND ROTTING\n");
	}
	return 0;
}