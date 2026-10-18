# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const int INF = INT_MAX / 2;

vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}

// ABC184Eとほぼ同じ
// reference
// https://drken1215.hatenablog.com/entry/2020/11/23/071100
// https://betrue12.hateblo.jp/entry/2018/12/08/000020
int main() {
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  // 2次元座標から1次元に変換
  // e.g.)
  // (0, 0), (0, 1), (1, 0), (1, 1)
  // を
  // 0, 1, 2, 3
  auto flatten_idx = [&](int i, int j) -> int {
    return i*w + j;
  };

  // 1次元から2次元に変換
  // 関数名の統一感...
  auto idx_to_2d = [&](int idx) -> pair<int, int> {
    int i = idx / w;
    int j = idx % w;
    return {i, j};
  };

  // 超頂点と繋ぐ
  vector<vector<int>> tele(26);
  rep(i, h)rep(j, w){
    char c = s.at(i).at(j);
    if(islower(c)){
      int idx = flatten_idx(i, j);
      tele.at(c-'a').push_back(idx);
    }
  }

  // 実グリッド + 超頂点
  vector<int> dist(h*w+26, INF);
  dist.at(0) = 0;

  deque<int> que;
  que.push_back(flatten_idx(0, 0));

  while(!que.empty()){
    int idx = que.front();
    que.pop_front();

    int current_dist = dist.at(idx);

    if(idx < h*w){
      // 超頂点じゃないとき

      auto [i, j] = idx_to_2d(idx);
      char c = s.at(i).at(j);

      // アルファベットのとき
      if(islower(c)){
        // 次の超頂点のindex
        int next_idx = h*w + c-'a';
        if(dist.at(next_idx) > current_dist+1){
          dist.at(next_idx) = current_dist+1;
          que.push_back(next_idx);
        }
      }

      // 上下左右
      rep(k, 4){
        int ni = i + dy.at(k);
        int nj = j + dx.at(k);

        if(!is_within(nj, ni, w, h)) continue;
        if(s.at(ni).at(nj) == '#') continue;

        int next_idx = flatten_idx(ni, nj);

        if(dist.at(next_idx) > current_dist+1){
          dist.at(next_idx) = current_dist+1;
          que.push_back(next_idx);
        }
      }
    } else {
      // 超頂点のとき

      int super_idx = idx - h*w;

      for(auto next_idx : tele.at(super_idx)){
        if(dist.at(next_idx) > current_dist){
          dist.at(next_idx) = current_dist;
          que.push_front(next_idx);
        }
      }
    }
  }

  int ans = dist.at(h*w-1) == INF ? -1 : dist.at(h*w-1);
  cout << ans << endl;

  return 0;
}
