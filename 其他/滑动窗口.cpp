#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<queue>
using namespace std;

/*
�̶����ȵ����������е���ֵ
�����������ԭ�����л�����
ʹ�û������ڸ�Ч���

�������һ���ʱ�����Ԫ��ɾ��Ԫ�أ��ұ�����Ԫ��
����������Сֵ�������������һ��������3 2 1���ᷢ����1���ò���ɾ��ǰ
���ڻ�������Сֵ����������3 2��ȡ������Ӧ��ʱɾ��
Ҳ���ǣ��������ұ�Ҫ����һ��Ԫ��ʱ��Ӧɾ��ǰ�����б������Ԫ��
�ڽ���Ԫ�ط������Ҷˣ����Ǵ�����Ԫ�����ǵ����ģ������Ԫ�ؾ�����Сֵ
ע�⣬������Ԫ�ظ�����һ�����ڴ��ڳߴ�
����ߵ�Ԫ�ز�һ���Ǵ��ڿ�סԭ����ʱ������ߵ�Ԫ��
��������ʱ�ж������Ԫ���Ƿ�Ҫɾ�����ж��Ƿ����ԭ�����д�����˵�һ��Ԫ�ؼ��� 
*/

int main()
{
	//����ÿ���󴰿�����Сֵ 
	int x[10]={3,4,1,8,0,1,3,7,6,4};
	int len=3;//�������ڳ���
	int size=10;//ԭ���г��� 
	int i,j,k,tem;
	deque<int> dq;
	//Ԥ������ô��ڳ�ʼֵ 
	dq.push_back(x[0]);
	for(i=1;i<len;i++)
	{
		while(!dq.empty()&&dq.back()>x[i])
		{
			dq.pop_back();
		}
		dq.push_back(x[i]);
	}
	cout<<dq.front()<<' ';
	//��ʼ���� 
	for(i=len;i<size;i++)
	{
		if(dq.front()==x[i-len])
		{
			dq.pop_front();
		}
		while(!dq.empty()&&dq.back()>x[i])
		{
			dq.pop_back();
		}
		dq.push_back(x[i]);
		cout<<dq.front()<<' ';
	}
	return 0; 
}














