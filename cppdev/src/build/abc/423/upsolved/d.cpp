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
int ctoi(char c){return int(c-'0');}
char itoc(int x){return x+'0';}

// reference
// https://atcoder.jp/contests/abc423/editorial/13871
void solve(){
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  vector<ll> b(n);
  vector<ll> c(n);

  rep(i, n){
    cin >> a.at(i) >> b.at(i) >> c.at(i);
  }

  // 退店時間、人数
  min_priority_queue<pll> pq;

  // 店内にいる人数
  ll p_num = 0;

  // 入店時間
  ll t = 0;

  vector<ll> ans(n, -1);

  rep(i, n){
    chmax(t, a.at(i));

    // 空くまで待つ
    while(p_num + c.at(i) > k){
      pll elem = pq.top(); pq.pop();
      chmax(t, elem.first);
      p_num -= elem.second;
    }

    ans.at(i) = t;
    pq.emplace(t+b.at(i), c.at(i));
    p_num += c.at(i);
  }

  rep(i, n){
    cout << ans.at(i) << endl;
  }



}

int main() {

  solve();

  return 0;
}
