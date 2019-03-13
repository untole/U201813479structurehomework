#include<stdio.h>

int main()
{
	int a,i,x0,n;
	scanf("%d%d",&x0,&n);       //读入x0,n 
	int k=1,sum=0;              //k累乘，sum累加和 
	for (i=0;i<=n;i++) 
	{
		scanf("%d",&a);
		sum+=a*k;
		k=k*x0;                 //进行下一阶的运算 
	}
	printf("sum=%d\n",sum);
}                               //时间复杂度 O(n) 
