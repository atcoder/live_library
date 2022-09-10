// Aho-Corasick
// https://youtu.be/BYoRvdgI5EU?t=9633
struct Aho {
  using MP = unordered_map<char,int>;
  vector<MP> to;
  vector<int> cnt, fail;
  Aho(): to(1), cnt(1) {}
  int add(const string& s) {
    int v = 0;
    for (char c : s) {
      if (!to[v].count(c)) {
        to[v][c] = to.size();
        to.push_back(MP());
        cnt.push_back(0);
      }
      v = to[v][c];
    }
    cnt[v]++;
    return v;
  }
  void init() {
    fail = vector<int>(to.size(), -1);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (auto [c,u] : to[v]) {
        fail[u] = (*this)(fail[v],c);
        cnt[u] += cnt[fail[u]];
        q.push(u);
      }
    }
  }
  int operator()(int v, char c) const {
    while (v != -1) {
      auto it = to[v].find(c);
      if (it != to[v].end()) return it->second;
      v = fail[v];
    }
    return 0;
  }
  int operator[](int v) const { return cnt[v];}
};