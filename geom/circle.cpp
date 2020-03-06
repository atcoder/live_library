// Circle
// coding: https://youtu.be/TdR816rqc3s?t=1750
// comment: https://youtu.be/TdR816rqc3s?t=11609
struct Circle {
  V o; double r;
  Circle(V o=V(), double r=0) : o(o), r(r) {}
  vector<V> crossPoint(const Circle& c) {
    V v = c.o-o;
    double l = v.norm();
    if (equal(l, 0)) return {};
    if (equal(l+r+c.r, max({l,r,c.r})*2)) {
      if (equal(l+r,c.r)) return {o - v*(r/l)};
      return {o + v*(r/l)};
    }
    if (l+r+c.r < max({l,r,c.r})*2) return {};
    double x = (l*l + r*r - c.r*c.r) / (2*l);
    double y = sqrt(r*r - x*x);
    V mid = o + v*(x/l);
    v = v.rotate90();
    return {mid + v*(y/l), mid - v*(y/l)};
  }
  bool isInside(const V& p) const {
    return (p-o).norm() < r+eps;
  }
};