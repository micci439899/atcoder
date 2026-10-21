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

vector<pair<ll, ll>> do_rle(vector<ll> s){
  int n = s.size();
  vector<pair<ll, ll>> rle;
  if(s.size() == 1){
    rle.emplace_back(s.at(0), 1);
    return rle;
  }
  ll c = s.at(0);
  ll cnt = 1;
  for(int i = 1; i < n; i++){
    if(s.at(i) != c){
      rle.emplace_back(c, cnt);
      cnt = 1;
      c = s.at(i);
    }else{
      cnt++;
    }
    if(i == n-1) rle.emplace_back(c, cnt);
  }
  return rle;
}

void solve(){
  ll n, k; cin >> n >> k;

  vector<ll> s(n);
  rep(i, n){
    cin >> s.at(i);
  }

  vector<pair<ll, ll>> r = do_rle(s);
  vector<ll> ans;
  rep(i, r.size()){
    if(r.at(i).second >= k){
      rep(j, r.at(i).second) ans.push_back(r.at(i).first);
    }
  }
  out_vec(ans);

}


int main() {

  solve();

  return 0;
}
