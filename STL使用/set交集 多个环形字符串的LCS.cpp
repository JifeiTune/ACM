#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
/*
2018����������B��
��n�����δ�������������У����ж��������ֵ�����С��
n<=10������<=8
�������ǳ�С��ֱ��ö��ÿ�������ַ�������ʼ����ö��ÿһ��������
����n��set�У����ȡ��������
*/
using namespace std;

set<string> all[10];
int N;
char x[20];

void Enum(int len,int p)//ö�ٵ�ǰ��Ϊlen�Ļ����ַ����������У�����all[p]
{
    int i,j,k,tem;
    string str;
    for(i=0;i<len-1;i++)
    {
        x[len+i]=x[i];//����
    }
    for(i=0;i<len;i++)//��iΪ����ڳ�Ϊlen���Ӵ���ö��������
    {
        tem=(1<<len)-1;
        for(j=1;j<=tem;j++)
        {
            str="";
            for(k=0;k<len;k++)
            {
                if(j&(1<<k))
                {
                    str.push_back(x[i+k]);
                }
            }
            all[p].insert(str);
        }
    }
}

int main()
{
    int i,len,MAX;
    set<string> tem;
    L:while(~scanf("%d",&N))
    {
        for(i=0;i<N;i++)
        {
            all[i].clear();
            scanf("%s",x);
            len=strlen(x);
            Enum(len,i);
        }
        tem=all[0];
        for(i=1;i<N;i++)//�����󽻼�
        {
            tem.clear();
            set_intersection(all[i-1].begin(),all[i-1].end(),all[i].begin(),all[i].end(),inserter(tem,tem.begin()));
            if(tem.size()==0)
            {
                printf("0\n");
                goto L;
            }
            swap(tem,all[i]);
        }
        set<string>::iterator it=all[N-1].begin(),pos;
        MAX=0;
        //cout<<all[N-1].size();
        while(it!=all[N-1].end())
        {
            if((*it).length()>MAX)
            {
                pos=it;
                MAX=(*it).length();
            }
            ++it;
        }
        cout<<*pos<<'\n';
    }
    return 0;
}




