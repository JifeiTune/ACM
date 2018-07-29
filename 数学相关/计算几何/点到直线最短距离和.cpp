#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;
/*
UVA - 11168
Airport
有很多个点，求一条直线，使得所有点都在该直线一侧
并且所有点到直线距离的平均值最小
求个凸包就是，所求直线必然是凸包某边所在直线
本代码是暴力求的，白书上有快得多的方法 
*/
// 计算几何模板 
const double eps = 1e-8; 
const double inf = 1e20; 
const double pi = acos(-1.0); 
const int maxp = 10100; 
//判断浮点数是否为0，因为有浮点数有误差所以通过极小值判断 
int sgn(double x){ 
  if(fabs(x) < eps)return 0; 
  if(x < 0)return -1; 
  else return 1; 
} 
//浮点数平方 
inline double sqr(double x){return x*x;} 
/* 
点 
* Point 
* Point()                 -  Empty constructor 
* Point(double _x,double _y)  -    constructor 
* input()               -  double input 
* output()              -  %.2f output 
* operator ==           - compares x and y 
* operator <            - compares first by x, then by y 
* operator -            -  return new Point after subtracting 
  curresponging x and y 
* operator ^            - cross product of 2d points 
* operator *            -  dot product 
* len()                 -  gives length from origin 
* len2()                -  gives square of length from origin 
* distance(Point p)     -  gives distance from p 
* operator + Point b  -    returns new Point after adding 
  curresponging x and y 
* operator * double k -    returns new Point after multiplieing x and 
   y by k 
* operator / double k -    returns new Point after divideing x and y 
  by k 
* rad(Point a,Point b)-    returns the angle of Point a and Point b 
  from this Point 
* trunc(double r)       -  return Point that if truncated the 
  distance from center to r 
* rotleft()             -  returns 90 degree     w rotated point 
* rotright()            -  returns 90 degree cw rotated point 
* rotate(Point p,double angle) -     returns Point after rotateing the 
   Point centering at p by angle radian       w 
*/ 
struct Point{ 
  double x,y; 
  Point(){} 
  Point(double _x,double _y){ 
       x = _x; 
       y = _y; 
  } 
  void input(){ 
       scanf("%lf%lf",&x,&y); 
  } 
  void output(){ 
       printf("%.2f %.2f\n",x,y); 
  } 
  bool operator == (Point b)const{ 
       return sgn(x-b.x) == 0 && sgn(y-b.y) == 0; 
  } 
  bool operator < (Point b)const{ 
       return sgn(x-b.x)== 0?sgn(y-b.y)<0:x<b.x; 
  } 
  Point operator -(const Point &b)const{ 
       return Point(x-b.x,y-b.y); 
  } 
  //叉积 
  double operator ^(const Point &b)const{ 
       return x*b.y -  y*b.x; 
  } 
  //点积 
  double operator *(const Point &b)const{ 
       return x*b.x + y*b.y; 
  } 
  //返回长度 
  double len(){ 
       return hypot(x,y);//库函数 
  } 
  //返回长度的平方 
  double len2(){ 
       return x*x + y*y; 
  } 
  //返回两点的距离 
  double distance(Point p){ 
       return hypot(x-p.x,y-p.y); 
  } 
  Point operator +(const Point &b)const{ 
       return Point(x+b.x,y+b.y); 
  } 
  Point operator *(const double &k)const{ 
       return Point(x*k,y*k); 
  } 
  Point operator /(const double &k)const{ 
       return Point(x/k,y/k); 
  } 
  //计算 pa 和 pb 的夹角 
  //就是求这个点看 a,b 所成的夹角 
  //测试 LightOJ1203 
  double rad(Point a,Point b){ 
       Point p = *this; 
       return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) )); 
  } 
  //化为长度为 r 的向量 
  Point trunc(double r){ 
      double l = len(); 
      if(!sgn(l))return *this; 
       r /= l; 
       return Point(x*r,y*r); 
  } 
  //逆时针旋转 90 度 
  Point rotleft(){ 
       return Point(-y,x); 
  } 
  //顺时针旋转 90 度 
  Point rotright(){ 
       return Point(y,-x); 
  } 
  //绕着 p 点逆时针旋转 angle 
  Point rotate(Point p,double angle){ 
       Point v = (*this) -  p; 
      double c= cos(angle), s = sin(angle); 
       return Point(p.x + v.x*c  -  v.y*s,p.y + v.x*s + v.y*c); 
  } 
}; 
/* 
* Stores two points 
* Line()                            - Empty constructor 
* Line(Point _s,Point _e)           - Line through _s and _e 
* operator ==                       - checks if two points are same 
* Line(Point p,double angle)        -  one end p , another end at 
  angle degree 
* Line(double a,double b,double c) -    Line of equation ax + by + 
  = 0 
* input()                           - inputs s and e 
* adjust()                          -  orders in such a way that s < e 
* length()                          -  distance of se 
* angle()                           - return 0 <= angle < pi 
* relation(Point p)                 -  3 if point is on line 
*                                     1 if point on the left of line 
*                                     2 if point on the right of line 
* pointonseg(double p)              - return true if point on segment 
* parallel(Line v)                  - return true if they are 
  parallel 
* segcrossseg(Line v)               - returns 0 if does not intersect 
*                                     returns 1 if non-standard 
  intersection 
*                                     returns 2 if intersects 
* linecrossseg(Line v)              - line and seg 
* linecrossline(Line v)             -  0 if parallel 
*                                     1 if coincides 
*                                     2 if intersects 
* crosspoint(Line v)                - returns intersection point 
* dispointtoline(Point p)           -  distance from point p to the 
  line 
* dispointtoseg(Point p)            -  distance from p to the segment 
* dissegtoseg(Line v)               -  distance of two segment 
* lineprog(Point p)                 - returns projected point p on se 
   line 
* symmetrypoint(Point p)            - returns reflection point of p 
  over se 
* 
*/ 
struct Line{ 
  Point s,e; 
  Line(){} 
  Line(Point _s,Point _e){ 
      s = _s; 
      e = _e; 
  } 
  bool operator ==(Line v){ 
       return (s == v.s)&&(e == v.e); 
  } 
  //根据一个点和倾斜角 angle 确定直线,0<=angle<pi 
  Line(Point p,double angle){ 
      s = p; 
      if(sgn(angle-pi/2) == 0){ 
           e = (s + Point(0,1)); 
       } 
      else{ 
           e = (s + Point(1,tan(angle))); 
       } 
  } 
  //ax+by+c=0 
  Line(double a,double b,double c){ 
      if(sgn(a) == 0){ 
           s = Point(0,-c/b); 
           e = Point(1,-c/b); 
       } 
      else if(sgn(b) == 0){ 
           s = Point(-c/a,0); 
           e = Point(-c/a,1); 
       } 
      else{ 
           s = Point(0,-c/b); 
           e = Point(1,(-  -a)/b); 
       } 
  } 
  void input(){ 
      s.input(); 
      e.input(); 
  } 
  void adjust(){ 
       if(e < s)swap(s,e); 
  } 
  //求线段长度 
  double length(){ 
       return s.distance(e); 
  } 
  //返回直线倾斜角 0<=angle<pi 
  double angle(){ 
      double k = atan2(e.y-s.y,e.x-s.x); 
       if(sgn(k) < 0)k += pi; 
       if(sgn(k-pi) == 0)k -= pi; 
       return k; 
  } 
  //点和直线关系 
  //1 在左侧 
  //2 在右侧 
  //3 在直线上 
  int relation(Point p){ 
       int c= sgn((p-s)^(e-s)); 
       if(c< 0)return 1; 
      else if( c> 0)return 2; 
      else return 3; 
  } 
  // 点在线段上的判断 
  bool pointonseg(Point p){ 
       return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0; 
  } 
  //两向量平行 (对应直线平行或重合) 
  bool parallel(Line v){ 
       return sgn((e-s)^(v.e-v.s)) == 0; 
  } 
  //两线段相交判断 
  //2 规范相交 
  //1 非规范相交 
  //0 不相交 
  int segcrossseg(Line v){ 
       int d1 = sgn((e-s)^(v.s-s)); 
       int d2 = sgn((e-s)^(v.e-s)); 
       int d3 = sgn((v.e-v.s)^(s-v.s)); 
       int d4 = sgn((v.e-v.s)^(e-v.s)); 
       if( (d1^d2)==-2 && (d3^d4)==-2 )return 2; 
       return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) || 
           (d2==0 && sgn((v.e-s)*(v.e-e))<=0) || 
           (d3==0 && sgn((s-v.s)*(s-v.e))<=0) || 
           (d4==0 && sgn((e-v.s)*(e-v.e))<=0); 
  } 
  //直线和线段相交判断 
  //-*this line -v seg 
  //2 规范相交 
  //1 非规范相交 
  //0 不相交 
  int linecrossseg(Line v){ 
       int d1 = sgn((e-s)^(v.s-s)); 
       int d2 = sgn((e-s)^(v.e-s)); 
       if((d1^d2)==-2) return 2; 
       return (d1==0||d2==0); 
  } 
  //两直线关系 
  //0 平行 
  //1 重合 
  //2 相交 
  int linecrossline(Line v){ 
       if((*this).parallel(v)) 
           return v.relation(s)==3; 
       return 2; 
  } 
  //求两直线的交点 
  //要保证两直线不平行或重合 
  Point crosspoint(Line v){ 
      double a1 = (v.e-v.s)^(s-v.s); 
      double a2 = (v.e-v.s)^(e-v.s); 
       return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1 
          )); 
  } 
  //点到直线的距离 
  double dispointtoline(Point p){ 
       return fabs((p-s)^(e-s))/length(); 
  } 
  //点到线段的距离 
  double dispointtoseg(Point p){ 
       if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0) 
           return min(p.distance(s),p.distance(e)); 
       return dispointtoline(p); 
  } 
  //返回线段到线段的距离 
  //前提是两线段不相交，相交距离就是 0 了 
  double dissegtoseg(Line v){ 
       return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v 
          .dispointtoseg(s),v.dispointtoseg(e))); 
  } 
  //返回点 p 在直线上的投影 
  Point lineprog(Point p){ 
       return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) ); 
  } 
  //返回点 p 关于直线的对称点 
  Point symmetrypoint(Point p){ 
       Point q = lineprog(p); 
       return Point(2*q.x-p.x,2*q.y-p.y); 
  } 
};  

/* 
* n,p  Line l for each side 
* input(int _n)                           -  inputs _n size polygon 
* add(Point q)                            -  adds a point at end of 
  the list 
* getline()                               -  populates line array 
* cmp                                     -  comparision in 
  convex_hull order 
* norm()                                  -  sorting in convex_hull 
  order 
* getconvex(polygon &convex)              -  returns convex hull in 
  convex 
* Graham(polygon &convex)                 -  returns convex hull in 
  convex 
* isconvex()                              -  checks if convex 
* relationpoint(Point q)                  -  returns 3 if q is a 
  vertex 
*                                                    2 if on a side 
*                                                    1 if inside 
*                                                    0 if outside 
* convexcut(Line u,polygon &po)           -  left side of u in po 
* gercircumference()                      -  returns side length 
* getarea()                               -  returns area 
* getdir()                                -  returns 0 for cw, 1 for 
    w 
* getbarycentre()                         -  returns barycenter 
* 
*/ 
struct polygon{ 
  int n; 
  Point p[maxp]; 
  Line l[maxp]; 
  polygon()
  {
  	n=0; 
  }
  void input(int _n){ 
       n = _n; 
       for(int i = 0;i < n;i++) 
           p[i].input(); 
  } 
  void add(Point q){ 
       p[n++] = q; 
  } 
  void getline(){ 
       for(int i = 0;i < n;i++){ 
           l[i] = Line(p[i],p[(i+1)%n]); 
       }
  } 
  struct cmp{ 
       Point p; 
       cmp(const Point &p0){p = p0;} 
       bool operator()(const Point &aa,const Point &bb){ 
           Point a = aa, b = bb; 
           int d = sgn((a-p)^(b-p)); 
           if(d == 0){ 
               return sgn(a.distance(p)-b.distance(p)) < 0; 
           } 
           return d > 0; 
       } 
  }; 
  //进行极角排序 
  //首先需要找到最左下角的点 
  //需要重载号好 Point 的 < 操作符 (min 函数要用) 
  void norm(){ 
       Point mi = p[0]; 
       for(int i = 1;i < n;i++)mi = min(mi,p[i]); 
       sort(p,p+n,cmp(mi)); 
  } 
  //得到凸包 
  //得到的凸包里面的点编号是 0～n-1 的 
  //两种凸包的方法 
  //注意如果有影响，要特判下所有点共点，或者共线的特殊情况 
  //测试 LightOJ1203 LightOJ1239 
  void getconvex(polygon &convex){ 
       sort(p,p+n); 
       convex.n = n; 
       for(int i = 0;i < min(n,2);i++){ 
           convex.p[i] = p[i]; 
       } 
       if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n 
         --;//特判 
       if(n <= 2)return; 
       int &top = convex.n; 
       top = 1; 
       for(int i = 2;i < n;i++){ 
           while(top && sgn((convex.p[top]-p[i])^(convex.p[top-1]- 
              p[i])) <= 0) 
               top--; 
           convex.p[++top] = p[i]; 
       } 
       int temp = top; 
       convex.p[++top] = p[n-2]; 
       for(int i = n-3;i >= 0;i--){ 
           while(top != temp && sgn((convex.p[top]-p[i])^(convex.p 
              [top-1]-p[i])) <= 0) 
               top--; 
           convex.p[++top] = p[i]; 
       } 
       if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n 
         --;//特判 
       convex.norm();//原来得到的是顺时针的点，排序后逆时针 
  } 
  //得到凸包的另外一种方法 
  //测试 LightOJ1203 LightOJ1239 
  void Graham(polygon &convex){ 
       norm(); 
       int &top = convex.n; 
      top = 0; 
       if(n == 1){ 
           top = 1; 
           convex.p[0] = p[0]; 
           return; 
       } 
       if(n == 2){ 
           top = 2; 
           convex.p[0] = p[0]; 
           convex.p[1] = p[1]; 
           if(convex.p[0] == convex.p[1])top--; 
           return; 
       } 
       convex.p[0] = p[0]; 
       convex.p[1] = p[1]; 
      top = 2; 
       for(int i = 2;i < n;i++){ 
           while( top > 1 && sgn((convex.p[top-1]-convex.p[top-2]) 
              ^(p[i]-convex.p[top-2])) <= 0 ) 
               top--; 
           convex.p[top++] = p[i]; 
       } 
       if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n 
         --;//特判 
  } 
  //判断是不是凸的 
  bool isconvex(){ 
      bool s[2]; 
      memset(s,false,sizeof(s)); 
       for(int i = 0;i < n;i++){ 
           int j = (i+1)%n; 
           int k = (j+1)%n; 
           s[sgn((p[j]-p[i])^(p[k]-p[i]))+1] = true; 
           if(s[0] && s[2])return false; 
       } 
       return true; 
  } 
  //判断点和任意多边形的关系 
  // 3 点上 
  // 2 边上 
  // 1 内部 
  // 0 外部 
  int relationpoint(Point q){ 
       for(int i = 0;i < n;i++){ 
           if(p[i] == q)return 3; 
       } 
       getline(); 
       for(int i = 0;i < n;i++){ 
           if(l[i].pointonseg(q))return 2; 
       } 
       int cnt = 0; 
       for(int i = 0;i < n;i++){ 
           int j = (i+1)%n; 
           int k = sgn((q-p[j])^(p[i]-p[j])); 
           int u = sgn(p[i].y-q.y); 
           int v = sgn(p[j].y-q.y); 
           if(k > 0 && u < 0 && v >= 0)cnt++; 
           if(k < 0 && v < 0 && u >= 0)cnt--; 
       } 
       return cnt != 0; 
  } 
  //直线 u 切割凸多边形左侧 
  //注意直线方向 
  //测试：HDU3982 
  void convexcut(Line u,polygon &po){ 
       int &top = po.n;//注意引用 
       top = 0; 
       for(int i = 0;i < n;i++){ 
           int d1 = sgn((u.e-u.s)^(p[i]-u.s)); 
           int d2 = sgn((u.e-u.s)^(p[(i+1)%n]-u.s)); 
           if(d1 >= 0)po.p[top++] = p[i]; 
           if(d1*d2 < 0)po.p[top++] = u.crosspoint(Line(p[i],p[(i 
              +1)%n])); 
       } 
  } 
  //得到周长 
  //测试 LightOJ1239 
  double getcircumference(){ 
      double sum = 0; 
       for(int i = 0;i < n;i++){ 
           sum += p[i].distance(p[(i+1)%n]); 
       } 
       return sum; 
  } 
  //得到面积 
  double getarea(){ 
      double sum = 0; 
       for(int i = 0;i < n;i++){ 
           sum += (p[i]^p[(i+1)%n]); 
       } 
       return fabs(sum)/2; 
  } 
  //得到方向 
  // 1 表示逆时针，0 表示顺时针 
  bool getdir(){ 
      double sum = 0; 
       for(int i = 0;i < n;i++) 
           sum += (p[i]^p[(i+1)%n]); 
       if(sgn(sum) > 0)return 1; 
       return 0; 
  } 
  //得到重心 
  Point getbarycentre(){ 
       Point ret(0,0); 
      double area = 0; 
       for(int i = 1;i < n-1;i++){ 
           double tmp = (p[i]-p[0])^(p[i+1]-p[0]); 
           if(sgn(tmp) == 0)continue; 
           area += tmp; 
           ret.x += (p[0].x+p[i].x+p[i+1].x)/3*tmp; 
           ret.y += (p[0].y+p[i].y+p[i+1].y)/3*tmp; 
       } 
       if(sgn(area)) ret = ret/area; 
       return ret; 
  } 
}; 
//AB X AC 
double cross(Point A,Point B,Point C){ 
  return (B-A)^(C-A);//运算符重载了 
} 
//AB*AC 
double dot(Point A,Point B,Point C){ 
  return (B-A)*(C-A); 
}

int main()
{
	int N,n,i,j,k;
	double x,y,ans,tem;
	polygon newP;
	cin>>N;
	for(k=1;k<=N;k++)
	{
		cin>>n;
		polygon p;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x,&y);
			p.add(Point(x,y));
		}
		p.getconvex(newP);
		if(newP.n<=2)
		{
			printf("Case #%d: %.3f\n",k,0.0);
		}
		else
		{
			newP.getline();//得到所有直线
			ans=1e300;
			for(i=0;i<newP.n;i++)
			{
				tem=0;
				for(j=0;j<p.n;j++)
				{
					tem+=newP.l[i].dispointtoline(p.p[j]);
				}
				ans=min(ans,tem);
			}
			printf("Case #%d: %.3f\n",k,ans/n);
		}
	}
	return 0; 
}


