#include<stdio.h>

void delete(int *a,int n,int pos) //ֻд����Ӧ����
{
	int i;
	for(i=pos;i<n;i++)      
	{    
	  a[i]=a[i+1];          //��pos����ʼ��ÿ��Ԫ�ر���һ������ 
	}                       //�Ӷ�ɾ��pos����Ԫ�� 
	n=n-1; 
}                          
