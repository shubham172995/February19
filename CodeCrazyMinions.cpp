#include<bits/stdc++.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		std::string s;
		std::cin>>s;
		int ans=2;	
		int l=s.length();
		 for(int i=1;i<s.length();i++)
        {
            ans+=((s[i]-s[i-1]+26)%26)+1;
        }
		if(ans<=(l*11))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}