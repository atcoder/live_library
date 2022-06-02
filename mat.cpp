// https://youtu.be/ylWYSurx10A?t=2352
template<typename T>
struct Matrix {
  int h, w;
  vector<vector<T>> d;
  Matrix() {}
  Matrix(int h, int w, T val=0): h(h), w(w), d(h, vector<T>(w,val)) {}
  Matrix& unit() {
    assert(h == w);
    rep(i,h) d[i][i] = 1;
    return *this;
  }
  const vector<T>& operator[](int i) const { return d[i];}
  vector<T>& operator[](int i) { return d[i];}
  Matrix operator*(const Matrix& a) const {
    assert(w == a.h);
    Matrix r(h, a.w);
    rep(i,h)rep(k,w)rep(j,a.w) {
      r[i][j] += d[i][k]*a[k][j];
    }
    return r;
  }
  Matrix pow(long long t) const {
    assert(h == w);
    if (!t) return Matrix(h,h).unit();
    if (t == 1) return *this;
    Matrix r = pow(t>>1);
    r = r*r;
    if (t&1) r = r*(*this);
    return r;
  }
  // https://youtu.be/-j02o6__jgs?t=11273
  /* mint only
  mint det() {
    assert(h == w);
    mint res = 1;
    rep(k,h) {
      for (int i = k; i < h; ++i) {
        if (d[i][k] == 0) continue;
        if (i != k) {
          swap(d[i],d[k]);
          res = -res;
        }
      }
      if (d[k][k] == 0) return 0;
      res *= d[k][k];
      mint inv = mint(1)/d[k][k];
      rep(j,h) d[k][j] *= inv;
      for (int i = k+1; i < h; ++i) {
        mint c = d[i][k];
        for (int j = k; j < h; ++j) d[i][j] -= d[k][j]*c;
      }
    }
    return res;
  }
  //*/
};