// Z-algorithm
// https://snuke.hatenablog.com/entry/2014/12/03/214243
// https://youtu.be/Uqtxz1KTKOQ?t=9214
struct Z {
  int n;
  string s;
  vector<int> z;
  Z() {}
  Z(const string& s): s(s) { init();}
  void init() {
    n = s.size();
    z = vector<int>(n);
    z[0] = n;
    for (int i = 1, j = 0; i < n;) {
      while (i+j < n && s[i+j] == s[j]) ++j;
      z[i] = j;
      if (j) {
        int k = 1;
        while (i+k < n && k+z[k] < j) {
          z[i+k] = z[k];
          k++;
        }
        i += k; j -= k;
      } else i++;
    }
  }
  int operator[](int i) const { return z[i];}
};
