#include<cstdio>
#include<cstring>
/*
�ʴ�x�У���y�����˼��Σ����ֵĲ�ͬλ�ÿ��ص�
��Ȼ������KMP���������hash���� 
hash�죬����Ϊ�ַ�������Ϳ��Կ���һ��?������
���ֱ�ӱȽϣ��ǡ���λ�ġ�����hash��һ������ֱ�Ӱ�ֵ�Ƚϣ�һ�ξ���
���Զ�ԭ����ƥ�䴮ȡͬһ��hash��������ÿһλ�ֱ������ͬ��λȨ�����Ƚ��Ƿ����
��Ȼԭ��������ÿ���������ø�ǰ׺�ͱ��棬ÿ��������õ�xk*(h^k)+x(k+1)*(h^(k+1))����
��ģʽ����һ��ʼ��y0*(h^0)+y1*(h^1)+y2*(h^2)������ÿ�αȽϺ��ٳ���h�����ܵõ�ͬһ��hash 

һ�ж�����Ȼ�������ʹ����ǰ׺��ʱ�ļ�
*/

char x[1000001];//��ƥ��
char y[1000001];
unsigned int pre[1000001]={0};//x0*(h^0)+x1*(h^1)+x2*(h^2)������ǰ׺��
unsigned int hs;
int lenx,leny;

int Cal()
{
    int ans=0,i,base=131;
    unsigned int temp=base,sum=0;
    pre[0]=x[0];
    for(i=1;i<lenx;i++)
    {
        pre[i]=pre[i-1]+x[i]*temp;
        temp*=base;
    }
    temp=1;
    for(i=0;i<leny;i++)
    {
        sum+=y[i]*temp;
        temp*=base;
    }
    for(i=leny-1;i<lenx;i++)//��ʼ�ֶ�ƥ��
    {
        if(sum==(pre[i]-pre[i-leny]))
        {
            ++ans;
        }
        sum*=base;
    }
    return ans;
}

int main()
{
    gets(x),gets(y);
    lenx=strlen(x);
    leny=strlen(y);
    printf("%d",Cal());
    return 0;
}
