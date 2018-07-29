#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<cstring>
/*
UVA - 11178
Morley's Theorem
*/
using namespace std;
//Բ 
const double eps = 1e-8; 
const double inf = 1e20; 
const double pi = acos(-1.0); 
const int maxp = 1010; 
//�жϸ������Ƿ��0����Ϊ�и��������������ͨ����Сֵ�ж� 
//ע���൱�ڷ��ط���λ��0�򷵻�0������0����1 
int sgn(double x){ 
  if(fabs(x) < eps)return 0; 
  if(x < 0)return -1; 
  else return 1; 
} 
//������ƽ�� 
inline double sqr(double x){return x*x;} 
/* 
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
  //��� 
  double operator ^(const Point &b)const{ 
       return x*b.y -  y*b.x; 
  } 
  //��� 
  double operator *(const Point &b)const{ 
       return x*b.x + y*b.y; 
  } 
  //���س��� 
  double len(){ 
       return hypot(x,y);//�⺯�� 
  } 
  //���س��ȵ�ƽ�� 
  double len2(){ 
       return x*x + y*y; 
  } 
  //��������ľ��� 
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
  //���� pa �� pb �ļн� 
  //�������������a,b ���ɵļн� 
  //���� LightOJ1203 
  double rad(Point a,Point b){ 
       Point p = *this; 
       return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) )); 
  } 
  //��Ϊ����Ϊ r ������ 
  Point trunc(double r){ 
      double l = len(); 
      if(!sgn(l))return *this; 
       r /= l; 
       return Point(x*r,y*r); 
  } 
  //��ʱ����ת 90 �� 
  Point rotleft(){ 
       return Point(-y,x); 
  } 
  //˳ʱ����ת 90 �� 
  Point rotright(){ 
       return Point(y,-x); 
  } 
  //����p����ʱ����ת angle 
  Point rotate(Point p,double angle){ 
       Point v = (*this) -  p; 
      double  c= cos(angle), s = sin(angle); 
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
  //����һ�������б�� angle ȷ��ֱ��,0<=angle<pi 
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
  //���߶γ��� 
  double length(){ 
       return s.distance(e); 
  } 
  //����ֱ����б�� 0<=angle<pi 
  double angle(){ 
      double k = atan2(e.y-s.y,e.x-s.x); 
       if(sgn(k) < 0)k += pi; 
       if(sgn(k-pi) == 0)k -= pi; 
       return k; 
  } 
  //���ֱ�߹�ϵ 
  //1 ����� 
  //2 ���Ҳ� 
  //3 ��ֱ���� 
  int relation(Point p){ 
       int   c= sgn((p-s)^(e-s)); 
       if(  c< 0)return 1; 
      else if(  c> 0)return 2; 
      else return 3; 
  } 
  // �����߶��ϵ��ж� 
  bool pointonseg(Point p){ 
       return sgn((p-s)^(e-s)) == 0 && sgn((p-s)*(p-e)) <= 0; 
  } 
  //������ƽ�� (��Ӧֱ��ƽ�л��غ�) 
  bool parallel(Line v){ 
       return sgn((e-s)^(v.e-v.s)) == 0; 
  } 
  //���߶��ཻ�ж� 
  //2 �淶�ཻ 
  //1 �ǹ淶�ཻ 
  //0 ���ཻ 
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
  //ֱ�ߺ��߶��ཻ�ж� 
  //-*this line -v seg 
  //2 �淶�ཻ 
  //1 �ǹ淶�ཻ 
  //0 ���ཻ 
  int linecrossseg(Line v){ 
       int d1 = sgn((e-s)^(v.s-s)); 
       int d2 = sgn((e-s)^(v.e-s)); 
       if((d1^d2)==-2) return 2; 
       return (d1==0||d2==0); 
  } 
  //��ֱ�߹�ϵ 
  //0 ƽ�� 
  //1 �غ� 
  //2 �ཻ 
  int linecrossline(Line v){ 
       if((*this).parallel(v)) 
           return v.relation(s)==3; 
       return 2; 
  } 
  //����ֱ�ߵĽ��� 
  //Ҫ��֤��ֱ�߲�ƽ�л��غ� 
  Point crosspoint(Line v){ 
      double a1 = (v.e-v.s)^(s-v.s); 
      double a2 = (v.e-v.s)^(e-v.s); 
       return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1 
          )); 
  } 
  //�㵽ֱ�ߵľ��� 
  double dispointtoline(Point p){ 
       return fabs((p-s)^(e-s))/length(); 
  } 
  //�㵽�߶εľ��� 
  double dispointtoseg(Point p){ 
       if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0) 
           return min(p.distance(s),p.distance(e)); 
       return dispointtoline(p); 
  } 
  //�����߶ε��߶εľ��� 
  //ǰ�������߶β��ཻ���ཻ������� 0 �� 
  double dissegtoseg(Line v){ 
       return min(min(dispointtoseg(v.s),dispointtoseg(v.e)),min(v 
          .dispointtoseg(s),v.dispointtoseg(e))); 
  } 
  //���ص� p ��ֱ���ϵ�ͶӰ 
  Point lineprog(Point p){ 
       return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) ); 
  } 
  //���ص� p ����ֱ�ߵĶԳƵ� 
  Point symmetrypoint(Point p){ 
       Point q = lineprog(p); 
       return Point(2*q.x-p.x,2*q.y-p.y); 
  } 
}; 


int main()
{
	int T;
	double X1,Y1,X2,Y2,X3,Y3;
	Point A,B,C,D,E,F,G;
	Line AE,AF,BD,BF,CD,CE;
	double ABC,BAC,CAB;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,&X3,&Y3);
		A.x=X1,A.y=Y1;
		B.x=X2,B.y=Y2;
		C.x=X3,C.y=Y3;
		//��Ŀ��֤A��B��C����ʱ��˳��
		ABC=A.rad(B,C);
		BAC=B.rad(A,C);
		CAB=C.rad(A,B);
		AF=Line(A,B.rotate(A,ABC/3));
		AE=Line(A,C.rotate(A,-ABC/3));
		BD=Line(B,C.rotate(B,BAC/3));
		BF=Line(B,A.rotate(B,-BAC/3));
		CE=Line(C,A.rotate(C,CAB/3));
		CD=Line(C,B.rotate(C,-CAB/3));
		D=BD.crosspoint(CD);
		E=AE.crosspoint(CE);
		F=AF.crosspoint(BF);
		printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",D.x,D.y,E.x,E.y,F.x,F.y);
	}
	return 0; 
}













