#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

/*
�������ַ�������ÿ���ַ������й���ǰ��׺�ĳ��ȣ���С������� 

ö�ٹ���ǰ��׺���ȣ���ǰ��׺����ͬһ��hash������Ӧλ��λȨҪһ��
�ȶ�ԭ��hashһ�Σ������ǰ׺��
ö�ٹ���ǰ��׺����ʱ���ֱ���ǰ׺�ͣ�������λȨ�����ٱ�������ʹ����ͬ���ٱȽ��Ƿ���ͬ���� 
*/

stack<int> all;

char x[1000001];

typedef unsigned int ui;

ui base=131;
ui pre[1000001];

int main()
{
    int len,i;
    ui temp;
    while(~scanf("%s",x))
    {
    	temp=base; 
        len=strlen(x);
        pre[0]=x[0];
        for(i=1;i<len;i++)
        {
            pre[i]=pre[i-1]+temp*x[i];
            temp*=base;
        }
        all.push(len);//�Լ�������
        temp=base;
        for(i=1;i<len;i++)//ö�ٺ�׺��ʼλ��
        {
            if(pre[len-i-1]*temp==(pre[len-1]-pre[i-1]))//����temp������ÿλλȨ��ͬ
            {
                all.push(len-i);
            }
            temp*=base;
        }
        while(!all.empty())
        {
            printf("%d ",all.top());
            all.pop();
        }
        putchar('\n');
    }


    return 0;
}
