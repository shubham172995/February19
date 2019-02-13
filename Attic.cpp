#include<bits/stdc++.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		std::string p;
		std::cin>>p;
		int days=0;
		int l=p.length();int k=0;
		int start=0, end=0;
		for(int i=1;i<l;i++){
			if(p[i]=='.'&&p[i-1]=='#')
				start=i;
			if(p[i]=='.'&&p[i+1]=='#'){
				end=i;
				int temp=end-start+1;
				if(temp>k){
					++days;
					k=temp;
				}
			}
		}
		printf("%d\n", days);
	}
	return 0;
}