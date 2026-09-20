#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int l, int mid, int h)
{
	int m = mid-l+1;
	int n = h - mid;
	int a[m];
	int b[n];
	int i, j, k;
		
	for(i =0; i<m; i++)
	{
		a[i] = arr[l+i];
	}
	
	for(j =0; j<n; j++)
	{
		b[j] = arr[mid+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<m && j<n)
	{
		if(a[i] < b[j])
		{
			arr[k++] = a[i++];
		}
		else
		{
			arr[k++] = b[j++];	
		}
	}
	while(i < m)
    {
        arr[k++] = a[i++];
    }
    while(j < n)
    {
        arr[k++] = b[j++];
    }
	
}
void mergeSort(int arr[],int l, int h)
{
	if(l<h)
	{
		int mid = (l+h)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,h);
		merge(arr,l,mid,h);
	}
	
}
int main()
{
	int arr[] = {2,3,1,5,6,4,7,9,8};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr,0,n-1);
	
	printf("Sorted Array: ");
	int i =0;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
	return 0;
}
