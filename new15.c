#include<stdio.h>
 
int main() {
	int i,j,k,n;
	printf("Enter the no. of rows:\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		for (j=n;j>=1;j--) {
			if(j<=i)
			        printf("%d",j);
				 else
			        printf(" ");
		}
		printf("\n");
	}
	return 0;
}

