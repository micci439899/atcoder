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
  int n; cin >> n;
  ll k; cin >> k;

  string alpha = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

  vector<string> w(n);
  rep(i, n) cin >> w.at(i);

  rep(i, n){
    ll pos_sm = 0;
    rep(j, w.at(i).size()){
      pos_sm += w.at(i).at(j) - 'a' + 1;
    }
    if(pos_sm%2 == 0){
      if(w.at(i).size()%2 == 0){
        ll kk = k%26;

        rep(j, w.at(i).size()){
          int idx = w.at(i).at(j) -'a' + kk;
          // debug(w.at(i).at(j));
          // debug(w.at(i).at(j) -'a');
          // debug(kk);
          // debug(idx);
          w.at(i).at(j) = alpha.at(idx);
        }
        cout << w.at(i) << endl;        

      }else{
        rep(j, w.at(i).size()){
          int idx = w.at(i).at(j) -'a' + 1;
          w.at(i).at(j) = alpha.at(idx);
        }
        cout << w.at(i) << endl;        
      }
    }else{
      bool rev = k%2 == 1;
      if(rev){
        reverse(w.at(i).begin(), w.at(i).end());
      }
      cout << w.at(i) << endl;
    }
  }


}



int main() {

  solve();

  return 0;
}
