#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<cstring>
/*
UVA - 12304
2D Geometry 110 in 1!
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
  //����������㿴 a,b ���ɵļн� 
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
  //���� p ����ʱ����ת angle 
  Point rotate(Point p,double angle){ 
       Point v = (*this) -  p; 
      double    c= cos(angle), s = sin(angle); 
       return Point(p.x + v.x*  -  v.y*s,p.y + v.x*s + v.y*c); 
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
//Բ 
struct circle{ 
  Point p;//Բ�� 
  double r;//�뾶 
  circle(){} 
  circle(Point _p,double _r){ 
       p = _p; 
       r = _r; 
  } 
  circle(double x,double y,double _r){ 
       p = Point(x,y); 
       r = _r; 
  } 
  //�����ε����Բ 
  //��Ҫ Point �� + / rotate() �Լ� Line �� crosspoint() 
  //���������ߵ��д��ߵõ�Բ�� 
  //���ԣ�UVA12304 
  circle(Point a,Point b,Point c){ 
       Line u = Line((a+b)/2,((a+b)/2)+((b-a).rotleft())); 
       Line v = Line((b+c)/2,((b+c)/2)+((c-b).rotleft())); 
       p = u.crosspoint(v); 
       r = p.distance(a); 
  } 
  //�����ε�����Բ 
  //���� bool t û�����ã�ֻ��Ϊ�˺��������Բ�������� 
  //���ԣ�UVA12304 
  circle(Point a,Point b,Point c,bool t){ 
       Line u,v; 
      double m = atan2(b.y-a.y,b.x-a.x), n = atan2(c.y-a.y,c.x-a. 
          x); 
       u.s = a; 
       u.e = u.s + Point(cos((n+m)/2),sin((n+m)/2)); 
      v.s = b; 
       m = atan2(a.y-b.y,a.x-b.x) , n = atan2(c.y-b.y,c.x-b.x); 
      v.e = v.s + Point(cos((n+m)/2),sin((n+m)/2)); 
       p = u.crosspoint(v); 
       r = Line(a,b).dispointtoseg(p); 
  } 
  //���� 
  void input(){ 
       p.input(); 
       scanf("%lf",&r); 
  } 
  //��� 
  void output(){ 
       printf("%.2lf %.2lf %.2lf\n",p.x,p.y,r); 
  } 
  bool operator == (circle v){ 
       return (p==v.p) && sgn(r-v.r)==0; 
  } 
  bool operator < (circle v)const{ 
       return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0)); 
  } 
  //��� 
  double area(){ 
       return pi*r*r; 
  } 
  //�ܳ� 
  double circumference(){ 
       return 2*pi*r; 
  } 
  //���Բ�Ĺ�ϵ 
  //0 Բ�� 
  //1 Բ�� 
  //2 Բ�� 
  int relation(Point b){ 
      double dst = b.distance(p); 
       if(sgn(dst-r) < 0)return 2; 
      else if(sgn(dst-r)==0)return 1; 
       return 0; 
  } 
  //�߶κ�Բ�Ĺ�ϵ 
  //�Ƚϵ���Բ�ĵ��߶εľ���Ͱ뾶�Ĺ�ϵ 
  int relationseg(Line v){ 
      double dst = v.dispointtoseg(p); 
       if(sgn(dst-r) < 0)return 2; 
      else if(sgn(dst-r) == 0)return 1; 
       return 0; 
  } 
  //ֱ�ߺ�Բ�Ĺ�ϵ 
  //�Ƚϵ���Բ�ĵ�ֱ�ߵľ���Ͱ뾶�Ĺ�ϵ 
  int relationline(Line v){ 
      double dst = v.dispointtoline(p); 
       if(sgn(dst-r) < 0)return 2; 
      else if(sgn(dst-r) == 0)return 1; 
       return 0; 
  } 
  //��Բ�Ĺ�ϵ 
  //5 ���� 
  //4 ���� 
  //3 �ཻ 
  //2 ���� 
  //1 �ں� 
  //��Ҫ Point �� distance 
  //���ԣ�UVA12304 
  int relationcircle(circle v){ 
      double d = p.distance(v.p); 
       if(sgn(d-r-v.r) > 0)return 5; 
       if(sgn(d-r-v.r) == 0)return 4; 
      double l = fabs(r-v.r); 
       if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3; 
       if(sgn(d-l)==0)return 2; 
       if(sgn(d-l)<0)return 1; 
  } 
  //������Բ�Ľ��㣬���� 0 ��ʾû�н��㣬���� 1 ��һ�����㣬2 ���������� 
  //��Ҫ relationcircle 
  //���ԣ�UVA12304 
  int pointcrosscircle(circle v,Point &p1,Point &p2){ 
       int rel = relationcircle(v); 
       if(rel == 1 || rel == 5)return 0; 
       double d = p.distance(v.p); 
       double l = (d*d+r*r-v.r*v.r)/(2*d); 
       double h = sqrt(r*r-l*l); 
       Point tmp = p + (v.p-p).trunc(l); 
       p1 = tmp + ((v.p-p).rotleft().trunc(h)); 
       p2 = tmp + ((v.p-p).rotright().trunc(h)); 
       if(rel == 2 || rel == 4) 
           return 1; 
       return 2; 
  } 
  //��ֱ�ߺ�Բ�Ľ��㣬���ؽ������ 
  int pointcrossline(Line v,Point &p1,Point &p2){ 
       if(!(*this).relationline(v))return 0; 
       Point a = v.lineprog(p); 
       double d = v.dispointtoline(p); 
       d = sqrt(r*r-d*d); 
       if(sgn(d) == 0){ 
           p1 = a; 
           p2 = a; 
           return 1; 
       } 
       p1 = a + (v.e-v.s).trunc(d); 
       p2 = a -  (v.e-v.s).trunc(d); 
       return 2; 
  } 
  //�õ��� a,b ���㣬�뾶Ϊ r1 ������Բ 
  int gercircle(Point a,Point b,double r1,circle &c1,circle &c2){ 
       circle x(a,r1),y(b,r1); 
       int t = x.pointcrosscircle(y,c1.p,c2.p); 
       if(!t)return 0; 
       c1.r = c2.r = r; 
       return t; 
  } 
  //�õ���ֱ�� u ���У����� q, �뾶Ϊ r1 ��Բ 
  //���ԣ�UVA12304 
  int getcircle(Line u,Point q,double r1,circle &c1,circle &c2){ 
       double dis = u.dispointtoline(q); 
       if(sgn(dis-r1*2)>0)return 0; 
       if(sgn(dis) == 0){ 
           c1.p = q + ((u.e-u.s).rotleft().trunc(r1)); 
           c2.p = q + ((u.e-u.s).rotright().trunc(r1)); 
           c1.r = c2.r = r1; 
           return 2; 
       } 
       Line u1 = Line((u.s + (u.e-u.s).rotleft().trunc(r1)),(u.e + 
           (u.e-u.s).rotleft().trunc(r1))); 
       Line u2 = Line((u.s + (u.e-u.s).rotright().trunc(r1)),(u.e 
          + (u.e-u.s).rotright().trunc(r1))); 
       circle  cc= circle(q,r1); 
       Point p1,p2; 
       if(!cc.pointcrossline(u1,p1,p2))  cc.pointcrossline(u2,p1,p2) 
          ; 
       c1 = circle(p1,r1); 
       if(p1 == p2){ 
           c2 = c1; 
           return 1; 
       } 
       c2 = circle(p2,r1); 
       return 2; 
  } 
  //ͬʱ��ֱ�� u,v ���У��뾶Ϊ r1 ��Բ 
  //���ԣ�UVA12304 
  int getcircle(Line u,Line v,double r1,circle &c1,circle &c2, 
     circle &c3,circle &c4){ 
       if(u.parallel(v))return 0;//��ֱ��ƽ�� 
       Line u1 = Line(u.s + (u.e-u.s).rotleft().trunc(r1),u.e + (u 
          .e-u.s).rotleft().trunc(r1)); 
       Line u2 = Line(u.s + (u.e-u.s).rotright().trunc(r1),u.e + ( 
          u.e-u.s).rotright().trunc(r1)); 
       Line v1 = Line(v.s + (v.e-v.s).rotleft().trunc(r1),v.e + (v 
          .e-v.s).rotleft().trunc(r1)); 
       Line v2 = Line(v.s + (v.e-v.s).rotright().trunc(r1),v.e + ( 
          v.e-v.s).rotright().trunc(r1)); 
       c1.r = c2.r = c3.r = c4.r = r1; 
       c1.p = u1.crosspoint(v1); 
       c2.p = u1.crosspoint(v2); 
       c3.p = u2.crosspoint(v1); 
       c4.p = u2.crosspoint(v2); 
       return 4; 
  } 
  //ͬʱ�벻�ཻԲ cx,cy ���У��뾶Ϊ r1 ��Բ 
  //���ԣ�UVA12304 
  int getcircle(circle cx,circle cy,double r1,circle &c1,circle & 
     c2){ 
       circle x(cx.p,r1+cx.r),y(cy.p,r1+cy.r); 
       int t = x.pointcrosscircle(y,c1.p,c2.p); 
       if(!t)return 0; 
       c1.r = c2.r = r1; 
       return t; 
  } 

  //��һ����Բ������ (���жϵ��Բ�Ĺ�ϵ) 
  //���ԣ�UVA12304 
  int tangentline(Point q,Line &u,Line &v){ 
       int x = relation(q); 
       if(x == 2)return 0; 
       if(x == 1){ 
           u = Line(q,q + (q-p).rotleft()); 
           v = u; 
           return 1; 
       } 
       double d = p.distance(q); 
       double l = r*r/d; 
       double h = sqrt(r*r-l*l); 
       u = Line(q,p + ((q-p).trunc(l) + (q-p).rotleft().trunc(h))) 
          ; 
       v = Line(q,p + ((q-p).trunc(l) + (q-p).rotright().trunc(h)) 
          ); 
       return 2; 
  } 
  //����Բ�ཻ����� 
  double areacircle(circle v){ 
       int rel = relationcircle(v); 
       if(rel >= 4)return 0.0; 
       if(rel <= 2)return min(area(),v.area()); 
       double d = p.distance(v.p); 
       double hf = (r+v.r+d)/2.0; 
       double ss = 2*sqrt(hf*(hf-r)*(hf-v.r)*(hf-d)); 
       double a1 = acos((r*r+d*d-v.r*v.r)/(2.0*r*d)); 
       a1 = a1*r*r; 
       double a2 = acos((v.r*v.r+d*d-r*r)/(2.0*v.r*d)); 
       a2 = a2*v.r*v.r; 
       return a1+a2-ss; 
  } 
  //��Բ�������� pab ���ཻ��� 
  //���ԣ�POJ3675 HDU3982 HDU2892 
  double areatriangle(Point a,Point b){ 
       if(sgn((p-a)^(p-b)) == 0)return 0.0; 
       Point q[5]; 
       int len = 0; 
       q[len++] = a; 
       Line l(a,b); 
       Point p1,p2; 
       if(pointcrossline(l,q[1],q[2])==2){ 
           if(sgn((a-q[1])*(b-q[1]))<0)q[len++] = q[1]; 
           if(sgn((a-q[2])*(b-q[2]))<0)q[len++] = q[2]; 
       } 
       q[len++] = b; 
       if(len == 4 && sgn((q[0]-q[1])*(q[2]-q[1]))>0)swap(q[1],q 
          [2]); 
       double res = 0; 
       for(int i = 0;i < len-1;i++){ 
           if(relation(q[i])==0||relation(q[i+1])==0){ 
               double arg = p.rad(q[i],q[i+1]); 
               res += r*r*arg/2.0; 
           } 

           else{ 
               res += fabs((q[i]-p)^(q[i+1]-p))/2.0; 
           } 
       } 
       return res; 
  } 
}; 

bool CMP(circle x,circle y)
{
	if(x.p.x==y.p.x)
	{
		return x.p.y<=y.p.y;
	}
	return x.p.x<=y.p.x;
}

int main()
{
	char q[100];
	while(~scanf("%s",q))
	{
		if(strcmp(q,"CircumscribedCircle")==0)//�����Բ 
		{
			double X1,Y1,X2,Y2,X3,Y3;
			scanf("%lf%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,&X3,&Y3);
			circle c(Point(X1,Y1),Point(X2,Y2),Point(X3,Y3));
			printf("(%.6f,%.6f,%.6f)\n",c.p.x,c.p.y,c.r);
		}
		else if(strcmp(q,"InscribedCircle")==0)//������Բ 
		{
			double X1,Y1,X2,Y2,X3,Y3;
			scanf("%lf%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,&X3,&Y3);
			circle c(Point(X1,Y1),Point(X2,Y2),Point(X3,Y3),1);
			printf("(%.6f,%.6f,%.6f)\n",c.p.x,c.p.y,c.r);
		}
		else if(strcmp(q,"TangentLineThroughPoint")==0)//��������Բ��������x��н� 
		{
			double Xc,Yc,r,Xp,Yp;
			Line L1;
			Line L2;
			scanf("%lf%lf%lf%lf%lf",&Xc,&Yc,&r,&Xp,&Yp);
			circle c(Point(Xc,Yc),r);
			int ans=c.tangentline(Point(Xp,Yp),L1,L2);
			if(ans==0)
			{
				printf("[]\n");
			}
			else if(ans==1)
			{
				printf("[%.6f]\n",sgn(L1.angle())?0.0:L1.angle()*180.0/pi);
			}
			else
			{
				double a1=sgn(L1.angle())?L1.angle()*180.0/pi:0.0;
				double a2=sgn(L2.angle())?L2.angle()*180.0/pi:0.0;
				if(a1>a2)
				{
					swap(a1,a2);
				}
				printf("[%.6f,%.6f]\n",a1,a2);
			}
		}
		else if(strcmp(q,"CircleThroughAPointAndTangentToALineWithRadius")==0)//��̶��뾶�����������붨ֱ�����е�Բ��Բ������ 
		{
			double Xp,Yp,X1,Y1,X2,Y2,r;
			scanf("%lf%lf%lf%lf%lf%lf%lf",&Xp,&Yp,&X1,&Y1,&X2,&Y2,&r);
			circle c1,c2;
			Line L(Point(X1,Y1),Point(X2,Y2));
			int ans=c1.getcircle(L,Point(Xp,Yp),r,c1,c2);//getcircle(L,Point(Xp,Yp),r,c1,c2);
			if(ans==0)
			{
				printf("[]\n");
			}
			else if(ans==1)
			{
				printf("[(%.6f,%.6f)]\n",c1.p.x,c1.p.y);
			}
			else
			{
				circle x[2]={c1,c2};
				sort(x,x+2,CMP);
				printf("[(%.6f,%.6f),(%.6f,%.6f)]\n",x[0].p.x,x[0].p.y,x[1].p.x,x[1].p.y);
			}
		}
		else if(strcmp(q,"CircleTangentToTwoLinesWithRadius")==0)//��̶��뾶����������ƽ��ֱ���ཻ��Բ������ 
		{
			double X1,Y1,X2,Y2,X3,Y3,X4,Y4,r;
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,&X3,&Y3,&X4,&Y4,&r);
			circle c1,c2,c3,c4;
			Line L1(Point(X1,Y1),Point(X2,Y2)),L2(Point(X3,Y3),Point(X4,Y4));
			int ans=c1.getcircle(L1,L2,r,c1,c2,c3,c4);
			//������4�� 
			circle x[4]={c1,c2,c3,c4};
			sort(x,x+4,CMP);
			printf("[(%.6f,%.6f),(%.6f,%.6f),(%.6f,%.6f),(%.6f,%.6f)]\n",
			x[0].p.x,x[0].p.y,x[1].p.x,x[1].p.y,x[2].p.x,x[2].p.y,x[3].p.x,x[3].p.y);
		}
		else if(strcmp(q,"CircleTangentToTwoDisjointCirclesWithRadius")==0)//��̶��뾶�����������뽻԰�����е�Բ��Բ������ 
		{
			double X1,Y1,r1,X2,Y2,r2,r;
			scanf("%lf%lf%lf%lf%lf%lf%lf",&X1,&Y1,&r1,&X2,&Y2,&r2,&r);
			circle t1(X1,Y1,r1),t2(X2,Y2,r2);
			circle c1,c2;
			int ans=c1.getcircle(t1,t2,r,c1,c2);
			if(ans==0)
			{
				printf("[]\n");
			}
			else if(ans==1)
			{
				printf("[(%.6f,%.6f)]\n",c1.p.x,c1.p.y);
			}
			else
			{
				circle x[2]={c1,c2};
				sort(x,x+2,CMP);
				printf("[(%.6f,%.6f),(%.6f,%.6f)]\n",x[0].p.x,x[0].p.y,x[1].p.x,x[1].p.y);
			}
		}
	}
	return 0; 
}













