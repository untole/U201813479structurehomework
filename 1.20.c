#include<stdio.h>

int main()
{
	int a,i,x0,n;
	scanf("%d%d",&x0,&n);       //����x0,n 
	int k=1,sum=0;              //k�۳ˣ�sum�ۼӺ� 
	for (i=0;i<=n;i++) 
	{
		scanf("%d",&a);
		sum+=a*k;
		k=k*x0;                 //������һ�׵����� 
	}
	printf("sum=%d\n",sum);
}                               //ʱ�临�Ӷ� O(n) 
