#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
ģ����kuangbin�ģ�ûʱ���Լ�д�ˡ��� 

�������ŵ��ˡ���
���������Է������ 
���̾��������ֶ���Ĺ��̡��� 
*/
using namespace std;

#define eps 1e-9 
#define MAXN 220//���̸�����δ֪Ԫ�����Ľϴ�ֵ
//����0��ʼ 
double a[MAXN][MAXN];//ϵ������ 
double x[MAXN];//��ʽ�ұߵ�ֵ, ���֮�� x ��ľ��ǽ�� 
int equ,var;//��������δ֪Ԫ����
/*
* ���� 0 ��ʾ�޽�������
1 ��ʾ��Ψһ�� 
*/ 
int Gauss(){ 
     int i,j,k,col,max_r; 
     for(k=0,col=0;k<equ&&col<var;k++,col++){ 
          max_r=k; 
          for(i=k+1;i<equ;i++) 
            if(fabs(a[i][col])>fabs(a[max_r][col])) 
              max_r=i; 
          if(fabs(a[max_r][col])<eps)return 0; 
          if(k!=max_r){ 
              for(j=col;j<var;j++) 
                swap(a[k][j],a[max_r][j]); 
              swap(x[k],x[max_r]); 
          } 
          x[k]/=a[k][col]; 
          for(j=col+1;j<var;j++)a[k][j]/=a[k][col]; 
          a[k][col]=1; 
          for(i=0;i<equ;i++) 
            if(i!=k){ 
                x[i]-=x[k]*a[i][col]; 
                for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col]; 
                a[i][col]=0; 
            } 
     } 
     return 1; 
} 


int main()
{
	int i;
	equ=2,var=2;
	a[0][0]=1,a[0][1]=2;
	a[1][0]=0,a[1][1]=0;
	x[0]=2,x[1]=0; 
	cout<<Gauss()<<endl;
	for(i=0;i<2;i++)
	{
		printf("%f ",x[i]);
	}
	
	return 0; 
}


