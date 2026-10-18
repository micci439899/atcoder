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

// Z algorithm
// https://snuke.hatenablog.com/entry/2014/12/03/214243
// 文字列sが与えられたとき、s全体とs[i:s.size()-1]（sのi番目から末尾まで）の最長共通接頭辞の長さを返す
// O(s.size())
// e.g.)
// aaabaaaab
// 921034210
vector<ll> z_algorithm(string &s){
  vector<ll> res(s.size(), 0);
  res.at(0) = s.size();
  int i = 1, j = 0;

  while(i < s.size()){
    // sの先頭からとi番目からを比較
    while(i+j < s.size() && s.at(j) == s.at(i+j)) j++;
    res.at(i) = j;

    // 先頭が異なる文字
    if(j == 0){ i++; continue; }

    // 計算済みの箇所（読み切れてない...）
    int k = 1;
    while(i+k < s.size() && k + res.at(k) < j) { res.at(i+k) = res.at(k); k++; }
    i += k; j-= k;
  }

  return res;
}

void solve(){
  int t;
  cin >> t;

  while(t--){
    string a, b; cin >> a >> b;

    string s = b + a + a;

    vector<ll> res = z_algorithm(s);

    bool is_ok = false;
    int sz = a.size();
    rep(i, sz){
      if(res.at(sz + i) >= sz){
        cout << i << endl;
        // return;
        is_ok = true;
        break;
      }
    }
    if(!is_ok) cout << -1 << endl;
  }

}

int main() {

  solve();

  return 0;
}
