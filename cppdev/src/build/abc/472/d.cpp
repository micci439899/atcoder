# include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void solve(){
  ll h, w, k; cin >> h >> w >> k;

  vector<string> s(h);
  rep(i, h) cin >> s.at(i);

  vector<ll> r;
  vector<ll> c;
  rep(i, h){
    bool safe = true;
    rep(j, w){
      if(s.at(i).at(j) == '#'){
        safe = false;
        break;
      }
    }
    if(safe){
      r.push_back(i);
    }
  }

  rep(j, w){
    bool safe = true;
    rep(i, h){
      if(s.at(i).at(j) == '#'){
        safe = false;
        break;
      }
    }
    if(safe){
      c.push_back(j);
    }
  }

  vector<vector<bool>> ans(h, vector<bool>(w, false));

  queue<tuple<ll, ll, ll>> que;
  rep(i, r.size())rep(j, c.size()){
    ans.at(r.at(i)).at(c.at(j)) = true;
    que.push({r.at(i), c.at(j), 0});
  }

  auto is_within = [&](ll i, ll j){
    if(i < 0 || h-1 < i) return false;
    if(j < 0 || w-1 < j) return false;
    return true;
  };

  while(!que.empty()){
    auto [i, j, kk] = que.front(); que.pop();
    if(kk >= k) continue;
    rep(l, 4){
      ll ni = i + dy.at(l);
      ll nj = j + dx.at(l);
      if(!is_within(ni, nj)) continue;
      if(s.at(ni).at(nj) == '#') continue;
      if(ans.at(ni).at(nj)) continue;
      ans.at(ni).at(nj) = true;
      que.push({ni, nj, kk+1});
    }
  }

  ll cnt = 0;
  rep(i, h)rep(j, w)if(ans.at(i).at(j)) cnt++;
  cout << cnt << endl;
}

int main() {

  solve();

  return 0;
}
