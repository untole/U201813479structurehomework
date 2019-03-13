#include<stdio.h>

int main()
{
	int x,y,z,tmp;
	scanf("%d%d%d",&x,&y,&z);
	if (x<y)
	{
		tmp=x;x=y;y=tmp;
	}
	if (x<z)
	{
		tmp=x;x=z;z=tmp;
	}
	if (y<z)
	{
		tmp=y;y=z;z=tmp;
	}
	printf("%d,%d,%d\n",x,y,z); 
}
