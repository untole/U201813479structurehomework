#include<stdio.h>

void delete(int *a,int n,int pos) //只写出对应函数
{
	int i;
	for(i=pos;i<n;i++)      
	{    
	  a[i]=a[i+1];          //从pos处开始，每个元素被后一个覆盖 
	}                       //从而删除pos处的元素 
	n=n-1; 
}                          
