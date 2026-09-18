#include<stdio.h>
void swap(int nums[],int i,int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
	
}

int partition(int nums[],int low,int high)
{
	int pivot = nums[low];
	int i = low;int j = high+1;
	while(i < j)
	{
	do
	{
		i++;
	}while(nums[i]<=pivot && i<high);
	
	do
	{
		j--;
	}while(nums[j] > pivot);
	if(i<j)
	{
		swap(nums,i,j);
	}
	
   }
   swap(nums,low,j);
  return j;
}
void QuickSort(int nums[],int low, int high)
{
	if(low<high)
	{
		int j = partition(nums,low,high);
		QuickSort(nums,low,j-1);
		QuickSort(nums,j+1,high);
	}	
}
int main()
{
	int nums[] = {4,3,1,6,5,2,8,9,7};
	int low = 0;
	int n = (sizeof(nums)/sizeof(nums[0]));
	QuickSort(nums,0,n-1);
	int i;
	for(i=0; i<n; i++)
  	 {
   	printf("%d ",nums[i]);
  	 }
	return 0;
}
