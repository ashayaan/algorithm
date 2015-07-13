#include<iostream>
using namespace std;

int countInversion(int array[],int temp[],int left,int mid,int right){
	int i,j,k;
	int inv=0;
	i=left;
	k=left;
	j=mid;
	while((i<=mid-1) && (j<=right)){
		if(array[i]<=array[j]){
			temp[k++]=array[i++];
			}
		else{
			temp[k++]=array[j++];
			inv=inv+(mid-i);
			}
		}
	while(i<=mid-1)
		temp[k++]=array[i++];
	while(j<=right)
		temp[k++]=array[j++];
	return inv;
	}


int inversion(int array[],int temp[],int left,int right){
	int mid,inv=0;
	if(right>left){
		mid=(left+right)/2;
		inv=inversion(array,temp,left,mid);
		inv+=inversion(array,temp,mid+1,right);
		inv+=countInversion(array,temp,left,mid+1,right);
		}
	return inv;
	}

int main(){
	int array[5]={1,3,5,2,4};
	int temp[5];
	int inv;
	inv=inversion(array,temp,0,5);
	cout<<inv<<endl;
	return 0;
	}
	
