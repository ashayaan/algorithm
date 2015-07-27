#include<stdio.h>
#include<stdlib.h>
long long int comp=0;

void swap(int *a,int *b){
	int t;	
	t=*a;
	*a=*b;
	*b=t;
	}

int  median(int a,int b,int c){
	if(a<b){
		if(b<c)
			return b;
		if(a<c)
			return c;
		return a;
		}
	else{
		if(a<c)
			return a;
		if(b<c)
			return c;
		return b;
		}
	}

int partition(int array[],int l,int r){
	int mid=(l+r-1)/2;
	int pivot=median(array[l],array[mid],array[r-1]);
	int index;
	if(pivot==array[l])
		index=l;
	else if(pivot==array[mid])
		index=mid;
	else
		index=r-1;
	swap(&array[l],&array[index]);
	int i=l+1;
	int j=0;
	for(j=l+1;j<r;j++){
		comp+=1;
		if(array[j]<pivot){
			swap(&array[j],&array[i]);
			i+=1;
			}
		}
	swap(&array[l],&array[i-1]);
	return i;
	}

int quicksort(int array[],int l,int r){
	if(l<r){
		int p=partition(array,l,r);
		quicksort(array,l,p-1);
		quicksort(array,p,r);	
		}
	}

int main(int argc,char *argv[]){
	FILE *open;
	open=fopen(argv[1],"r");
	int line=0,i=0;
	int array[1000000];
	while(!feof(open)){
		int read;
		fscanf(open,"%d",&read);
		if(feof(open))
			break;
		array[i++]=read;
		line+=1;
		}
	//printf("%d",array[line-1]);
	quicksort(array,0,line);
	for(i=0;i<line;i++)
		printf("%d\n",array[i]);
	printf("%lld\n",comp);
	return 0;
	}
