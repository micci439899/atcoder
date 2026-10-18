# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

// 素集合データ構造（Union-Find）
struct DisjointSetUnion {
  vector<int> parents;
  vector<int> sizes;

  // 初期化子リスト
  DisjointSetUnion(int n) : parents(n, -1), sizes(n, 1) {}

  // xが属しているグループの代表（根）を取得
  int find(int x) {
    if(parents.at(x) == -1) return x;

    // 経路圧縮
    parents.at(x) = find(parents.at(x));
    return parents.at(x);
  }

  // xとyが同じグループに属しているかどうか
  bool is_same(int x, int y) {
    return find(x) == find(y);
  }

  // xが属しているグループとyが属しているグループを併合する
  // xとyが既に同じグループに属しているときfalse、そうでないときtrueを返す
  bool unite(int x, int y) {
    int x_r = find(x);
    int y_r = find(y);

    if(x_r == y_r) return false;

    // union by size（木の深さをなるべく小さくする）
    if(sizes.at(x_r) < sizes.at(y_r)) swap(x_r, y_r);

    parents.at(y_r) = x_r;
    sizes.at(x_r) += sizes.at(y_r);
    return true;
  }

  // xが属しているグループの要素数を返す
  int size(int x) {
    return sizes.at(find(x));
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  DisjointSetUnion dsu(n);

  // 黒: true、白: false
  vector<bool> colors(n, false);

  // 各グループにおける黒色の頂点の数
  // 更新されていく要素が減っていく想定
  vector<int> black_cnts(n, 0);

  while(q--){
    int q_type;
    cin >> q_type;
    if(q_type == 1){
      int u, v;
      cin >> u >> v;
      u--; v--;

      if(!dsu.is_same(u, v)){
        int u_r = dsu.find(u);
        int u_b_cnt = black_cnts.at(u_r);
        int v_r = dsu.find(v);
        int v_b_cnt = black_cnts.at(v_r);

        dsu.unite(u, v);

        int upd_r = dsu.find(u);
        black_cnts.at(upd_r) = u_b_cnt + v_b_cnt;
      }

    }else if(q_type == 2){
      int v;
      cin >> v;
      v--;

      colors.at(v) = !colors.at(v);
      int v_r = dsu.find(v);

      if(colors.at(v)){
        black_cnts.at(v_r)++;
      }else{
        black_cnts.at(v_r)--;
      }

    }else{
      int v;
      cin >> v;
      v--;

      int v_r = dsu.find(v);
      out_yn(black_cnts.at(v_r) > 0);
    }
  }



  return 0;  
}









