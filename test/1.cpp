#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int rtype ;


//归并排序 
void merge(rtype *s,int m,int low,int high)
{
	int i=low,j=m+1,p=0;
	rtype *s1;
	s1=(rtype *)malloc((high-low+1)*sizeof(rtype));
	if (!s1) printf("申请空间失败");
	while(i<=m&&j<=high)
	{
		s1[p++]=(s[i]<=s[j])?s[i++]:s[j++];
	}
	while(i<=m) s1[p++]=s[i++];
	while(j<=high) s1[p++]=s[j++];
	for (p=0,i=low;i<=high;p++,i++)
	{
		s[i]=s1[p];
	}
	free(s1);
}

void mergesort(rtype s[],int low,int high)
{
	int mid;
	if (low<high)
	{
		mid=(low+high)/2;
		mergesort(s,low,mid);
		mergesort(s,mid+1,high);
		merge(s,mid,low,high);
	}
}


//二分查找O(lgn) 
bool bseek(rtype s[],rtype x,int low,int high)
{
	int i=low;
	int j=high;
	while(i<j)
	{
		if (x==(s[i]+s[j]))
		{
			printf("\n该数组中%d和%d相加等于%d",s[i],s[j],x);
			return true;
		}
		else if (x<(s[i]+s[j])) --j;
		else ++i;
	}
}


main()
{
	int a[6]={10,11,2,1,14,9};
	int low=0;
	int high=5;
	int x; 
	
	printf("before sort:");
	for (int i=low;i<=high;i++)
	printf("%d ",a[i]);
	printf("\n");
	
	
	mergesort(a,low,high);
	printf("after sort:");
	for (int i=low;i<=high;i++)
	printf("%d ",a[i]);
	printf("\n");
	
	
	printf("input the sum:");
	scanf("%d",&x);
	bseek(a,x,low,high);
	//printf("%d",wh);
}













