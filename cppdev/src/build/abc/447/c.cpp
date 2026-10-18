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

void solve(){
  string s, t;
  cin >> s >> t;
  s+='a';
  t+='a';

  ll s_idx = 0;
  ll t_idx = 0;

  ll prev_s_idx = 0;
  ll prev_t_idx = 0;

  ll ans = 0;

  while(true){
    while(s_idx < s.size()){
    //while(true){
      if(s.at(s_idx) != 'A') break;
      s_idx++;
    }

    while(t_idx < t.size()){
    //while(true){
      if(t.at(t_idx) != 'A') break;
      t_idx++;
      //if(t_idx == t.size()-1) break;
    }

    if(s.at(s_idx) != t.at(t_idx)){
      cout << -1 << endl;
      return;
    }

    ll s_a_sz = s_idx - prev_s_idx - 1;
    ll t_a_sz = t_idx - prev_t_idx - 1;

    ans += abs(s_a_sz - t_a_sz);

    if(s_idx == s.size()-1 || t_idx == t.size()-1){
      ans += s.size()-1 - s_idx;
      ans += t.size()-1 - t_idx;
      break;
    }

    prev_s_idx = s_idx;
    prev_t_idx = t_idx;
    s_idx++;
    t_idx++;
  }

  cout << ans << endl;

}

int main() {

  solve();

  return 0;  
}
