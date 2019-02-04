#include<iostream>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, c, q;
		scanf("%d %d %d", &n, &c, &q);
		for(int i=0;i<q;i++){
			int l, r;
			scanf("%d %d", &l, &r);
			if(c<l||c>r)
				continue;
			else{
				int temp=c-l;
				c=r-temp;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}