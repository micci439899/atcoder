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
  int n, q; cin >> n >> q;

  set<tuple<ll, ll, ll>> st;
  rep(i, n){
    ll x, s; cin >> x >> s;
    st.insert({x, s, i});
  }

  while(q--){
    ll p; cin >> p;
    auto it = st.lower_bound({p, -1LL, -1LL});

    if(it == st.begin()){
      auto [x, s, i] = *it;
      cout << i+1 << endl;
      st.erase(it);
    }else if(it == st.end()){
      it--;
      auto [x, s, i] = *it;
      cout << i+1 << endl;
      st.erase(it);
    }else{
      auto it2 = it;
      it2--;
      auto [x1, s1, i1] = *it;
      auto [x2, s2, i2] = *it2;
      ll d1 = abs(x1 - p);
      ll d2 = abs(x2 - p);

      if(d1 < d2){
        cout << i1 + 1 << endl;
        st.erase(it);
      }else if(d1 > d2){
        cout << i2 + 1 << endl;
        st.erase(it2);
      }else{
        if(s1 == s2){
          cout << i2 + 1 << endl;
          st.erase(it2);
        }else if(s1 < s2){
          cout << i2 + 1 << endl;
          st.erase(it2);
        }else{
          cout << i1 + 1 << endl;
          st.erase(it);
        }
      }
    }
  }
}

int main() {

  solve();

  return 0;
}
