#include<stdio.h>
int jishu(long long a,long long b);
int oushu(long long a,long long b);

int LongLongPower(long long a,long long b,int m)
{
    int Answer=1,Answer1;
    for(int i=0; i<b; i++)
    {
        Answer=Answer*a;
        Answer1=Answer%m;
    }
//0到b-1次
    Answer=Answer%m;
    printf("%d\t",Answer1);
    return Answer;
}
int jishu(long long a,long long b)
{
    int Answer;
    if(b==1)
        Answer=a;
    else
        Answer=a*oushu(a,b-1);
    return Answer;
}
int oushu(long long a,long long b)
{
    int Answer;
    if(b%4!=0)
        Answer=jishu(a,b/2)*jishu(a,b/2);
    else
        Answer=oushu(a,b/2)*oushu(a,b/2);
    return Answer;
}
//快速幂的迭代写法
int diedai(long long a,long long b)
{
    int Answer=1;
    while(b!=1)
    {
        int middle=a;
        if (b&1==0)
            Answer=Answer*middle;
        middle=middle*middle;
        b=b>>1;
        printf("\n8>>1=%d",8>>1);
    }
    return Answer;
}
int main()
{
    long long a,b;
    int m,Answer;
    scanf("%lld%lld%d",&a,&b,&m);
    Answer=LongLongPower(a,b,m);
    printf("%d\t%d",Answer,3*3*3%5);
    if(b%2!=0)
        Answer=jishu(a,b);
    else
        Answer=oushu(a,b);
    printf("\n%d",Answer);
    diedai(a,b);
    printf("\n%d",Answer);
    return 0;
}
//变量大写开头
//函数名小写
//函数局部变量同名开头不大写
