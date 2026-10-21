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

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a%b);
}

void testcase(){
  string s; cin >> s;

  // string s1 = ""; s1 += s.front();
  // string s2 = ""; s2 += s.back();
  string s1 = "";
  string s2 = "";

  ll l = 0;
  ll r = (ll)s.size()-1;

  vector<string> t;
  while(true){
    if(l >= (ll)s.size() || r < 0) break;
    s1 = s1 + s.at(l);
    s2 = s.at(r) + s2;
    if(s1 == s2 && s != s1) t.push_back(s1);
    l++;
    r--;
  }

  if(t.size() == 0){
    cout << 0 << endl;
  }else if(t.size() == 1){
    cout << t.at(0).size() << endl;
  }else{
    vector<ll> x;
    rep(i, t.size()-1){
      ll diff = abs((ll)t.at(i).size() - (ll)t.at(i+1).size());
      x.push_back(diff);
    }

    ll ans = x.at(0);
    rep(i, x.size()){
      if(i == 0) continue;
      ans = gcd(ans, x.at(i));
    }
    cout << ans << endl;
  }


}

void solve(){
  ll q; cin >> q;
  while(q--){
    testcase();
  }
}

int main() {

  solve();

  return 0;
}