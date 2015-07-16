#include <stdio.h>
#include <stdlib.h>
  
long long int  _mergeSort(int arr[], int temp[], int left, int right);
long long int merge(int arr[], int temp[], int left, int mid, int right);

long long int mergeSort(int arr[], int array_size){
	int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
	}

long long int _mergeSort(int arr[], int temp[], int left, int right){
	int mid;
	long long int inv_count = 0;
	if (right > left){
		mid = (right + left)/2;
		inv_count  = _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid+1, right);
		inv_count += merge(arr, temp, left, mid+1, right);
		}
	return inv_count;
	}

long long int merge(int arr[], int temp[], int left, int mid, int right){
	int i, j, k;
	long long int inv_count = 0;
	i = left; /* i is index for left subarray*/
	j = mid;  /* i is index for right subarray*/
	k = left; /* i is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)){
		if (arr[i] <= arr[j]){
			temp[k++] = arr[i++];
			}
		else{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
			}
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	return inv_count;
	}
 
int main(int argc, char* argv[]){
	FILE *open;
	open=fopen(argv[1],"r");
	int line=0;
	int i=0;
	int arr[1000000];
	while(!feof(open)){
		int read;
		fscanf(open,"%d",&read);
		if(feof(open))
			break;
		arr[i++]=read;
		line+=1;
		}
	printf(" Number of inversions are %lld \n", mergeSort(arr, line));
	return 0;
	}
