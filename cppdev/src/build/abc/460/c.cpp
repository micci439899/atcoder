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

void solve(){
  ll n, m; cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);
  vector<ll> b(m);
  rep(i, m) cin >> b.at(i);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  cout << 0 << endl;

/*
  int m_idx = 0;
  int cnt = 0;
  rep(i, n){
    bool target = true;
    for(int j = m_idx; j < m; j++){
      if(a.at(i)*2 <= b.at(j)){
        m_idx++;
      }else{
        target = false;
        break;
      }
    }
    if(target)cnt++;
    m_idx++;
  }
  cout << cnt << endl;
*/
/*
  int cnt = 0;
  int m_idx = 0;
  rep(i, n){
    auto it = lower_bound(b.begin()+m_idx, b.end(), a.at(i)*2);
    if(it == b.end()) break;
    // if(it == b.end()){
    //   cout << 0 << endl;
    //   return;
    // }
    cnt++;
    m_idx = (it - b.begin()) + 1;
    if(m_idx >= m){

    }
  }
  cout << cnt << endl;
*/

/*
  int m_idx = 0;
  int cnt = 0;
  rep(i, n){
    debug(i);
    debug(a.at(i));
    debug(m_idx);
    int target_idx = -1;
    for(int j = m_idx; j < m; j++){
      if(a.at(i)*2 >= b.at(j)){
        debug(b.at(j));
        target_idx = j;
        break;
      }
    }
    debug(target_idx);
    if(target_idx >= 0){
      m_idx = target_idx + 1;
      cnt++;
      if(m_idx >= m) break;
    }else{
      break;
    }
  }
  cout << cnt << endl;
*/

/*
  vector<ll> c(n);
  int idx = m-1;
  for(int i = a.size()-1; i >= 0; i--){
    int cnt = 0;
    for(int j = idx; j >= 0; j--){
      if(a.at(i)*2 <= b.at(j)){
        cnt++;
      }
    }
    c.at(i) = cnt;
  }
*/





}


int main() {

  solve();

  return 0;
}
