// Rerooting
// https://youtu.be/zG1L4vYuGrg?t=7092
// TODO: vertex info, edge info
struct Rerooting {
  struct DP {
    DP() {}
    DP operator+(const DP& a) const {
      // edit here
    }
    DP addRoot() const {
      // edit here
    }
  };
  
  int n;
  vector<vector<int>> to;
  vector<vector<DP>> dp;
  vector<DP> ans;
  Rerooting(int n=0):n(n),to(n),dp(n),ans(n) {}
  void addEdge(int a, int b) {
    to[a].push_back(b);
    to[b].push_back(a);
  }
  void init() {
    dfs(0);
    bfs(0);
  }

  DP dfs(int v, int p=-1) {
    DP dpSum;
    dp[v] = vector<DP>(to[v].size());
    rep(i,to[v].size()) {
      int u = to[v][i];
      if (u == p) continue;
      dp[v][i] = dfs(u,v);
      dpSum = dpSum + dp[v][i];
    }
    return dpSum.addRoot();
  }
  void bfs(int v, const DP& dpP=DP(), int p=-1) {
    int deg = to[v].size();
    rep(i,deg) if (to[v][i] == p) dp[v][i] = dpP;

    vector<DP> dpSumL(deg+1);
    rep(i,deg) dpSumL[i+1] = dpSumL[i] + dp[v][i];
    vector<DP> dpSumR(deg+1);
    for (int i = deg-1; i >= 0; --i)
      dpSumR[i] = dpSumR[i+1] + dp[v][i];
    ans[v] = dpSumL[deg].addRoot();

    rep(i,deg) {
      int u = to[v][i];
      if (u == p) continue;
      DP d = dpSumL[i] + dpSumR[i+1];
      bfs(u, d.addRoot(), v);
    }
  }
};
