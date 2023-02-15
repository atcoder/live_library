// Convex Hull Trick (max)
// https://youtu.be/TSvXG35mmRE?t=7853
struct CHT {
  struct Linear {
    ll a, b;
    Linear(ll a=0, ll b=0): a(a), b(b) {}
    ll operator()(ll x) const { return a*x+b;}
  };
  deque<Linear> ls;
  void add(ll a, ll b) {
    Linear l(a,b);
    assert(ls.size() == 0 || ls.back().a <= l.a);
    while (ls.size() >= 2) {
      const Linear& l1 = ls[ls.size()-2];
      const Linear& l2 = ls.back();
      if ((l.a-l2.a)*(l1.b-l2.b) < (l2.a-l1.a)*(l2.b-l.b)) break;
      ls.pop_back();
    }
    ls.push_back(l);
  }
  ll operator()(ll x) { // x: asc
    ll res = ls[0](x);
    while (ls.size() >= 2) {
      ll now = ls[1](x);
      if (now < res) break;
      res = now;
      ls.pop_front();
    }
    return res;
  }
};