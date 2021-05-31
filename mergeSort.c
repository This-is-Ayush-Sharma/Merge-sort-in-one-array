#include<stdio.h>
void merge(int arr[],int low,int mid,int high);
void mergeSort(int arr[],int low,int high);
void print(int arr[],int length);


void merge(int arr[],int low,int mid,int high)
{
    int left_length=mid-low+1;
    int right_length=high-mid;
    int left[left_length],right[right_length];
    int i,j,k;
    for(i=0;i<left_length;i++)
    left[i]=arr[low+i];

    for(i=0;i<right_length;i++)
    right[i]=arr[mid+1+i];

    i=0,j=0,k=low;
    while(i<left_length && j<right_length)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else 
        {
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<left_length)
    {
        arr[k]=left[i];
        i++;k++;
    }

    while(j<right_length)
    {
        arr[k]=right[j];
        j++;k++;
    }
}

void mergeSort(int arr[],int low,int high)
{
    if(high>low)
    {
        int midd=(low+high)/2;
        mergeSort(arr,low,midd);
        mergeSort(arr,midd+1,high);
        merge(arr,low,midd,high);
    }
}

void print(int arr[],int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int len,arr[100];
    printf("please enter length\n");
    scanf("%d",&len);
    printf("please enter %d elements in an array\n",len);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,len-1);
    print(arr,len);    
    return 0;
}
