#include<stdio.h>
int merge2(int * c,int * d,int * e)
{
    int i=0,j=0,f=0;
    while(i<4&&j<4)
    {
        if(c[i]>d[j])
        {
//            e[f]=d[j];
//            j=j+1;
//            f=f+1;
//简洁
            e[f++]=d[j++];
        }
        else
        {
            e[f]=c[i];
            i=i+1;
            f=f+1;
        }
    }
//优雅
    while(i<4)
    {
        e[f++]=c[i++];
    }
    while(j<4)
    {
        e[f++]=d[j++];
    }
    for(int i=0; i<8; i++)
    {
        printf("\n%d",e[i]);
    }
}
int main()
{
    int a[6]= {1,2,3,4,5,6},b=6,i,j;
    int c[4]= {1,5,7,9};
    int d[4]= {2,4,6,10};
    int e[8]= {};
    for(int i=0; i<6; i++)
    {
        for(int j=i+1; j<6; j++)
//防重复,保证不同位置
        {
            if(a[i]+a[j]==8)
                printf("%d\t%d\n",a[i],a[j]);
        }
    }
    for(int i=0; i<6; i++)
    {
//    printf("\n查错");
        for(int j=i+1; j<b; j++)
//防重复,保证不同位置
        {
            if(a[i]+a[j]==8)
            {
                printf("\n%d\t%d",a[i],a[j]);
                b=j;
//j取到j0-1,b应该取j
//                printf("\n%d",b);
                break;
            }
        }
    }
    printf("\n");
    i=0;
    j=5;
//||=== Build file: "no target" in "no project" (compiler: unknown) ===|
//C:\Users\Dazzle\Desktop\新建文件夹\4.6.1什么是TwoPointers.c||In function 'main':|
//C:\Users\Dazzle\Desktop\新建文件夹\4.6.1什么是TwoPointers.c|31|error: 'i' undeclared (first use in this function)|
//C:\Users\Dazzle\Desktop\新建文件夹\4.6.1什么是TwoPointers.c|31|note: each undeclared identifier is reported only once for each function it appears in|
//C:\Users\Dazzle\Desktop\新建文件夹\4.6.1什么是TwoPointers.c|32|error: 'j' undeclared (first use in this function)|
//||=== Build failed: 2 error(s), 0 warning(s) (0 minute(s), 0 second(s)) ===|
    while(i<j)
    {
        if(a[i]+a[j]>8)
            j=j-1;
        else if(a[i]+a[j]<8)
            i=i+1;
        else
        {
            printf("\n%d\t%d",a[i],a[j]);
            j=j-1;
            i=i+1;
        }
    }
    merge2(c,d,e);
    return 0;
}

