AtCoder解説放送ライブラリ集
----
## これは何？
[解説放送](https://www.youtube.com/channel/UCtG3StnbhxHxXfE6Q4cPZwQ)で作ったライブラリを公開しています。

## 目次

### ユーティリティ
|名前|コード|説明|
|:--|:--|:--|
|テンプレート|[template.cpp](template.cpp)||
|ModInt|[mint.cpp](mint.cpp)|自動でmodを取ってくれる整数型|
|座標圧縮|[cc.cpp](cc.cpp)|座標に昇順に番号を振る|
|順列|[perm.cpp](perm.cpp)|置換の合成や逆元等|

### データ構造
|名前|コード|説明|
|:--|:--|:--|
|BIT|[bit.cpp](bit.cpp)|Binary Indexed Tree (Fenwick Tree)|
|UnionFind|[uf.cpp](uf.cpp)|Union Find (DSU)|
|CHT|[cht.cpp](cht.cpp)|Convex Hull Trick|

### 数学
|名前|コード|説明|
|:--|:--|:--|
|GCD/LCM|[gcd.cpp](gcd.cpp)|最大公約数と最小公倍数|
|extgcd|[extgcd.cpp](extgcd.cpp)|Ai+Bj=gcd(A,B)なるi,jを求める|
|Combination|[comb.cpp](comb.cpp)|nCkをmod素数で求める|
|Matrix|[mat.cpp](mat.cpp)|行列|
|素数|[prime.cpp](prime.cpp)|素数列挙と素因数分解|
|FPS|[fps.cpp](fps.cpp)|形式的べき級数|

### グラフ
|名前|コード|説明|
|:--|:--|:--|
|LCA|[lca.cpp](lca.cpp)|最小共通祖先|
|全方位木DP|[rerooting.cpp](rerooting.cpp)|全方位木DP|

### 文字列
|名前|コード|説明|
|:--|:--|:--|
|KMP|[mp.cpp](mp.cpp)|文字列検索アルゴリズム（正確にはMP）|
|Z|[z.cpp](z.cpp)|Z-algorithm|
|Aho-Corasick|[aho.cpp](aho.cpp)|文字列集合へのマッチを検出する|

### 幾何
|名前|コード|説明|
|:--|:--|:--|
|基本|[geom.cpp](geom.cpp)|幾何のベース＋目次|
|Vector|[geom/vector.cpp](geom/vector.cpp)|ベクトル（点を扱う際にも使う）|
|Line|[geom/line.cpp](geom/line.cpp)|直線・線分|
|Circle|[geom/circle.cpp](geom/circle.cpp)|円|