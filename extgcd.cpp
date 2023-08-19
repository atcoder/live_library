// ai+bj=g
// https://youtu.be/fDJpXN2R75A?t=6895
ll extgcd(ll a, ll b, ll& i, ll& j) {
  if (b == 0) { i = 1; j = 0; return a;}
  ll p = a/b, g = extgcd(b,a-b*p,j,i);
  j -= p*i;
  return g;
}