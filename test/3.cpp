#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void quickSort(int a[],int low,int high)
{
	int i,j;
	int flag;
	i=low;
	j=high;
	flag=a[low];
	while (i<j){
		while(i<j&&a[j]>=flag)
			j--;
		if (i<j)
		{
			a[i]=a[j];i++;
		}
		while(i<j&&a[i]<flag)
			i++;
		if (i<j)
		{
			a[j]=a[i];j--;
		}
		a[i]=flag;
		quickSort(a,low,i-1);
		quickSort(a,i+1,high);	
	}
}

main(){
	int *a;
	int i=0;
	int j;
	a=(int *)malloc(20*sizeof(int));
	printf("输入需要排序的数：\n");
	while(1){
		scanf("%d",&a[i++]);
		char c=getchar();
		if (c=='\n')
		break;
	}
	quickSort(a,0,i-1);
	printf("快速排序后的数列为：\n");
	for (j=0;j<i;j++)
	{
		printf("%d ",a[j]);
	}
	free(a);
}






//(1)数组元素都相同时，比较次数：1+2+3+4+...+n-1=(n^2-n)/2
//(2)最坏情况：数组基本有序时 ，选取第一个元素为pivot
  //最好情况：如果每次划分过程产生的区间大小都为n/2，T(n)=2T(n/2)+θ(n)即o(nlogn) 





