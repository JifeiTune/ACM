#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*
����һ��nλ��������ɾȥ���е�mλ����ʣ�µ�������Ƕ���
�൱�ڴ�nλ��ѡn-mλ��ʹ��ѡ����������ɵ�������谴��
ÿ��Ҫ�¼�һ����ʱ����ĩβ����ǰ��������С�����Ķ�ɾȥ��ע���������Ҫ�����㹻���ѡ�ģ�
*/

char x[100010];

int main(void)
{
    int m,n,i,j,num;
    char last;
    deque<char> ans;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
        {
            break;
        }
        ans.clear();
        m=n-m;//��ѡ�ĸ���
        num=m-1;//��Ҫѡ�ĸ���
        scanf("%s",x);
        ans.push_back(x[0]);//Ԥ��һ����ȥ
        for(i=1;i<n;i++)
        {
            if(num==n-i)//û��ѡ���ˣ�������
            {
                for(;i<n;i++)
                {
                    ans.push_back(x[i]);
                }
                break;
            }
            if(ans.back()<x[i])//��ĩβ
            {
                while(!ans.empty()&&ans.back()<x[i]&&num<n-i)//��С�ڵĶ�ɾ��
                {
                    ans.pop_back();
                    num++;
                }

            }
			ans.push_back(x[i]);//����
        	num--;
        }
        while(m--)//���ǰmλ
        {
            putchar(ans.front());
            ans.pop_front();
        }
        putchar('\n');
    }
    return 0;
}

