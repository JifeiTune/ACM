#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<set> 
/*
mutiset允许重复元素，删除时使用M.erase(M.find(x))的形式否则等于x的元素全部被删除 
set不允许 
二者都支持高效地增删查（结合了数组与链表的优势）

画画图就会发现 
区间交：最右的左端点L，最左的右端点R，交集为[L,R]，L>R表示交集为空集
矩形交：最下的上边纵坐标TT，最上的下边纵坐标BB，最右的左边横坐标LL，最左的右边横坐标RR
只有当TT>=BB&&RR>=LL时有交集
本题求任意一点，该点再n-1个矩形的交集内，枚举删除矩形，找到一个满足的即可 
*/
using namespace std;

struct Node
{
	int X1,Y1,X2,Y2;
}x[132675];

int main()
{
	int n,i,ans,X1,Y1,X2,Y2,TT,BB,LL,RR;
	multiset<int> T,B,L,R;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x[i].X1,&x[i].Y1,&x[i].X2,&x[i].Y2);
		T.insert(x[i].Y2);
		B.insert(x[i].Y1);
		L.insert(x[i].X1);
		R.insert(x[i].X2);
		T.size();
	}
	for(i=1;i<=n;i++)//枚举删矩形 
	{
		T.erase(T.find(x[i].Y2));
		B.erase(B.find(x[i].Y1));
		L.erase(L.find(x[i].X1));
		R.erase(R.find(x[i].X2));
		TT=*(T.begin());
		T.size();
		BB=*(B.rbegin());
		LL=*(L.rbegin());
		RR=*(R.begin());
		if(TT>=BB&&RR>=LL)
		{
			printf("%d %d",LL,TT);//左上角
			//printf("%d %d %d %d\n",TT,BB,LL,RR);
			break; 
		}
		T.insert(x[i].Y2);
		B.insert(x[i].Y1);
		L.insert(x[i].X1);
		R.insert(x[i].X2);
	}
	return 0; 
}


