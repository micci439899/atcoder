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
  ll n, k; cin >> n >> k;

  vector<string> w(n);
  rep(i, n) cin >> w.at(i);

  rep(i, n){
    ll s = 0;
    rep(j, w.at(i).size()){
      s += w.at(i).at(j)-'a'+1;
    }

    if(s%2 != 0){
      if(k%2 != 0){
        reverse(w.at(i).begin(), w.at(i).end());
      }
    }else{
      ll ns = 0;
      rep(j, w.at(i).size()){
        w.at(i).at(j) = w.at(i).at(j) == 'z' ? 'a' : w.at(i).at(j)+1;
        ns += w.at(i).at(j)-'a'+1;
      }
      if(ns%2 != 0){
        if((k-1)%2 != 0){
          reverse(w.at(i).begin(), w.at(i).end());
        }
      }else{
        ll offset = (k-1)%26;
        rep(j, w.at(i).size()){
          w.at(i).at(j) = (w.at(i).at(j)-'a'+offset)%26+'a';
        }
      }
    }

    cout << w.at(i) << endl;
  }
}

int main() {

  solve();

  return 0;
}
