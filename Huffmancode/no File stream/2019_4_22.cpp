#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1000

typedef struct node
{
	int l,r;
}tree;

typedef char* huffmancode;

int  n,total;
int  ori[maxn],f[maxn],fre[maxn],out[maxn];
char c[maxn],cd[100];
tree T[maxn];

huffmancode s[maxn];

void init()
{
	scanf("%d",&n);getchar();
	int i;

		
	for (i=1;i<=n;i++)
	{	scanf("%c",&c[i]);getchar();}
	
	for (i=1;i<=n;i++)
	{	scanf("%d",&fre[i]);f[i]=fre[i];}
	printf("--------------------------\n");
	for (i=1;i<=n;i++)
		printf("%d :[%c]==%d\n",i,c[i],fre[i]); 
}

void sort(int total)
{
	int i,j,t;
	char ch;
	for (i=1;i<total;i++)
	  for (j=i+1;j<=total;j++)
	    if (fre[i]>fre[j])
	    {
	    	t=fre[i];fre[i]=fre[j];fre[j]=t;
	    	t=ori[i];ori[i]=ori[j];ori[j]=t;
		}
}

int build(tree *T)
{
	int i,j;
	for (i=0;i<=maxn;i++)
	{
		T[i].l=-1;T[i].r=-1;
		ori[i]=i;
	}
	int sum=0;
	total=n;
	i=-1;
	while (sum<n)
	{
		sort(total);
		
		i=i+2;j=i+1;
		int ll,rr;
		ll=ori[i];rr=ori[j];
		int k=0;
		if (ll<=n) k++;if (rr<=n) k++;sum=sum+k;
				
		total++;
		T[total].l=ll;T[total].r=rr;
		c[total]='*';
		fre[total]=fre[i]+fre[j];
	}	
	//printf("--------------%d,%d,%d----------------\n",total,T[total].l,T[total].r);	
}

void putout(tree *T)
{
	int i,head,tail;
	head=0;tail=1;
	head++;
	out[head]=total;
	
	int floor[maxn];
	floor[head]=1;
	int maxfloor=-1;
	int sum=1;
	
	while (sum<total)
	{
		int k;
		k=out[head];
		
		if (T[k].l!=-1) 
		{
			tail++;
			out[tail]=T[k].l;
			floor[tail]=floor[head]+1;
			if (floor[tail]>maxfloor) maxfloor=floor[tail];
			sum++;
		}
		if (T[k].r!=-1)
		{
			tail++;
			out[tail]=T[k].r;
			floor[tail]=floor[head]+1;
			if (floor[tail]>maxfloor) maxfloor=floor[tail];
			sum++;
		}
		head++;
	}
	

	
	int j;
    printf("--------------huffmantree----------\n");
	for (i=1;i<=maxfloor;i++)
	{
		printf("floor%d  :",i);
		for (j=1;j<=tail;j++)
		  if (floor[j]==i) printf("%d ",out[j]);
		printf("\n");
	}
}

void Ecode(tree *T,int now,char *code,int len)
{
	int i;
	if (T[now].l==-1&&T[now].r==-1)
	{
		if (now<=n)
		{
			*(s+now)=(char *)malloc((len+2)*sizeof(char));
			for (i=0;i<=len+1;i++)
				*(*(s+now)+i)=code[i];	
		}
		return; 
	}
	
	char s1[100];
	for(i=0;i<=len;i++) s1[i]=code[i];
	
	if (T[now].l!=-1)
	{
		s1[len+1]='0';s1[len+2]='\0';
		Ecode(T,T[now].l,s1,len+1);
	}
    if (T[now].r!=-1)
	{
		s1[len+1]='1';s1[len+2]='\0';
		Ecode(T,T[now].r,s1,len+1);
	}	
}

int PreEcoding(tree *T)
{
	int len;
	cd[0]='\0';len=-1;
	Ecode(T,total,cd,len);
	
	int i;
	printf("---------code----------\n");
	for (i=1;i<=n;i++)
	{
		printf("%c ",c[i]);puts(*(s+i));
		//printf("%d\n",strlen(*(s+i))); 
	}
	printf("------------------------\n");
	
	return 0;
}

int get(char ch)
{
	int i;
	for (i=1;i<=n;i++)
		if (c[i]==ch) return(i);
	return 0;
}

void Ecoding(tree *T,char *st)
{
	char tran[maxn];
	int len=0,ls=strlen(st);
	int i;
	for(i=0;i<ls;i++)
	{
		int k=get(st[i]);
		strcpy(tran+len,*(s+k));
		len=strlen(tran);
	}
	printf("±àÂëÎª            £º");puts(tran);	
}

int checks(char *s1,char *s2)
{
	int len2=strlen(s2);
	int i;
	for (i=0;i<len2;i++)
	  if (s1[i]!=s2[i]) return 0;
	return 1;
}

int get1(char *ss,int *p)
{
	int i;
	for (i=1;i<=n;i++)
	{
		if (checks(ss,*(s+i)))
		{
			int len=strlen(*(s+i));
			*p=*p+len;
			return i;
		}
	} 
	return 0;
}

void Decoding(tree *T,char *st)
{	
	int pos=0;int len=strlen(st);
	char ans[maxn];
	int sum=0;
	while (pos<len)
	{
		int k=get1(st+pos,&pos);
		sum++;
		ans[sum]=c[k];
	}
	int i;
	printf("Ô­ÂëÎª            £º"); 
	for (i=1;i<=sum;i++) printf("%c",ans[i]);printf("\n");
	
}

int main()
{
	init();	
	build(T);	
	putout(T);
	PreEcoding(T);
	char st[maxn];
	getchar();
	printf("¶ÁÈëÒª±àÂëµÄ×Ö·û´®£º");gets(st);
	Ecoding(T,st);
	printf("¶ÁÈëÒªÆÆÒëµÄ±àÂë  £º");gets(st);
	Decoding(T,st); 
}
