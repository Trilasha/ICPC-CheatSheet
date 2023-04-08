template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
double dist() const { return sqrt((double)dist2()); }
// angle to x-axis in interval [-pi, pi]
double angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes dist()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated 'a' radians ccw around the origin
P rotate(double a) const {
	return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
friend ostream& operator<<(ostream& os, P p) {
	return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P>
double lineDist(const P& a, const P& b, const P& p) {
return (double)(b-a).cross(p-a)/(b-a).dist();
}

/*
Returns the shortest distance between point p and the line segment from point s to e.
Point<double> a, b(2,2), p(1,1);
bool onSegment = segDist(a,b,p) < 1e-10;
*/
typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
if (s==e) return (p-s).dist();
auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> bool onSegment(P s, P e, P p) {
return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

/*
Usage:
vector<P> inter = segInter(s1,e1,s2,e2);
if (sz(inter)==1)
cout << "segments intersect at " << inter[0] << endl;
*/
template<class P> vector<P> segInter(P a, P b, P c, P d) {
auto oa = c.cross(d, a), ob = c.cross(d, b),
		oc = a.cross(b, c), od = a.cross(b, d);
// Checks if intersection is single non-endpoint point.
if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
	return {(a * ob - b * oa) / (ob - oa)};
set<P> s;
if (onSegment(c, d, a)) s.insert(a);
if (onSegment(c, d, b)) s.insert(b);
if (onSegment(a, b, c)) s.insert(c);
if (onSegment(a, b, d)) s.insert(d);
return {all(s)};
}

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
auto d = (e1 - s1).cross(e2 - s2);
if (d == 0) // if parallel
	return {-(s1.cross(e1, s2) == 0), P(0, 0)};
auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
return {1, (s1 * p + e1 * q) / d};
}

template<class P>
int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

/** Usage:
 * 	bool left = sideOf(p1,p2,q)==1;
 * */
template<class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
auto a = (e-s).cross(p-s);
double l = (e-s).dist()*eps;
return (a > l) - (a < -l);
}