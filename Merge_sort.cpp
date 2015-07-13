#include<iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int array[],int l,int r){
	if(l<r){
		int m=(l+r)/2;
		mergeSort(array,l,m);
		mergeSort(array,m+1,r);
		merge(array,l,m,r);
		}
	}

int main(){
	int array[10]={10,9,8,7,6,5,4,3,2,1};
	mergeSort(array,0,9);
	int i;
	for(i=0;i<10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
	}
