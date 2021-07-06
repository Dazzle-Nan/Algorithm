#include<stdio.h>
const int maxn=100;
void mergesort(int[],int,int);
void merge2(int[],int,int,int,int);
int main()
{
    int A[]= {66,12,33,57,64,27,18},B[]= {1,3,7,2,4,6};
    mergesort(A,0,6);
    merge2(B,0,2,3,5);
    for(int i=0; i<7; i++)
    {
        printf("%d\n",A[i]);
//        printf("%d",B[i]);
    }
    return 0;
}
void merge2(int a[],int left1,int right1,int left2,int right2)
{
    int lefttemp=left1,temp[maxn],index=0;
    while(left1<=right1&&left2<=right2)
//注意left1<=right1,一定是小于等于,因为是序号
    {
//        printf("%d\t%d\n",a[left1],a[left2]);
        if(a[left1]<a[left2])
//a[left1]<a[left2]小于或小于等于均可
            temp[index++]=a[left1++];
        else
            temp[index++]=a[left2++];
    }
    while(left1<=right1)
    {
        temp[index++]=a[left1++];
    }
    while(left2<=right2)
//应该是left2<=right2,因为
    {
        temp[index++]=a[left2++];
    }
    for(int i=0; i<index; i++)
//应该是i<index,因为index++
    {
        a[lefttemp+i]=temp[i];
//注意lefttemp和left不一致,别混肴
    }
}
void mergesort(int a[],int left,int right)
{
    int middle;
    if(left<right)
    {
        middle=(right+left)/2;
        mergesort(a,left,middle);
        mergesort(a,middle+1,right);
//注意middle+1,非middle
        merge2(a,left,middle,middle+1,right);
//深刻体会
    }
}
