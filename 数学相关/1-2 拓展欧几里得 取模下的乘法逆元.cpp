#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

#define LL long long//����������дlong long���ڲ��ᳬ��ΧʱҲ�ɷ���ظ�Ϊint 

/*
��չŷ�����
�������x��y��ʹ��ax+by==d����abs(x)+abs(y)��С������d=gcd(a,b) 
*/
void Egcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(b==0)
	{
		d=a,x=1,y=0;
	}
	else
	{
		Egcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

/*
x��y�������Ƿǳ������ 
(x/y)%MODE����֤�������� != (x%MODE)/(y%MODE)
������Ҫ���y%MODE�ĳ˷���Ԫ��ת���ɳ˷�������ֲ����㲻��ȡ�࣬�������
*/ 
LL inv(LL a,LL MODE)//����a��MODE����Ԫ 
{
	LL d,x,y;
	Egcd(a,MODE,d,x,y);
	return d==1?(x+MODE)%MODE:-1;//-1��������Ԫ 
}

int main()
{
	
	LL a=12,b=3,MODE=7;//(a/b)%MODE 
	LL tem=inv(b,MODE);
	cout<<(a*tem)%MODE;
	return 0; 
}






