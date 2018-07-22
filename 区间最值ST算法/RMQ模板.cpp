#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

#define num 100000//������󳤶�
#define LOG ((int)log2(num))//���鳤����2Ϊ�׵Ķ���
 
/*���������±��1��ʼ
ע���ϵı�������֧��log2��ͨ������(1<<(j++))<=num��ȷ���±꼴�� 
*/
int x[num+1]; 
int MAX[num+1][LOG+1];//ע���ϵı��������ܲ�֧�����鳤������ȷ��������������������LOG�ĳ������� 
int MIN[num+1][LOG+1];
int len;//����ʵ��ʹ�ó��� 

void init()//��ʼ������������init�� 
{
	int f=(int)log2(len),i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
		MIN[i][0]=x[i];//��i��ͷ����Ϊ2^0����ֵ��Ȼ���Լ� 
	}
	for(j=1;j<=f;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//ע�ⷶΧ��������δ���������±���м�������� 
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]); 
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//���ֳɳ�����ȵ����������� 
		}
	}
}

int answer(int i,int j,bool what)//��i��j��ֵ��whatΪ1��ʾ�����ֵ��Ϊ0��ʾ����Сֵ 
{
	int k=(int)log2(j-i+1);
	if(what)
	{
		return max(MAX[i][k],MAX[j-(1<<k)+1][k]);
	}
	else
	{
		return min(MIN[i][k],MIN[j-(1<<k)+1][k]);
	}
}

int main()
{
	
	return 0; 
}




















