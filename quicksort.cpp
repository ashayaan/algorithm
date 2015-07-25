#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
	}

int partition(int array[],int l,int r){
	int pivot=array[l];
	int i=l+1;
	int j=0;
	for(j=l+1;j<r;j++){
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

int main(){
	int array[10]={9,7,6,8,4,3,5,2,1,0};
	int i=0;
	quicksort(array,0,10);
	for(i=0;i<10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
	}
