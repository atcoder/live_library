// Permutation
// https://youtu.be/-j02o6__jgs?t=7302
struct Perm : vector<int> {
#define n (int)(size())
#define p (*this)
  Perm(int _n): vector<int>(_n) {
    iota(begin(), end(), 0);
  }
  template<class...Args> Perm(Args...args): vector<int>(args...) {}
  Perm(initializer_list<int> a): vector<int>(a.begin(),a.end()) {}
  Perm operator+(const Perm& a) const {
    Perm r(n);
    for (int i = 0; i < n; ++i) r[i] = p[a[i]];
    return r;
  }
  Perm& operator+=(const Perm& a) {
    return *this = (*this)+a;
  }
  Perm operator-() const {
    Perm r(n);
    for (int i = 0; i < n; ++i) r[p[i]] = i;
    return r;
  }
  Perm operator-(const Perm& a) const {
    return *this + -a;
  }
  Perm& operator-=(const Perm& a) {
    return *this += -a;
  }
  // next permutation
  bool operator++() {
    return next_permutation(begin(),end());
  }
#undef n
#undef p
};