// The template file is below
// https://github.com/micci439899/atcoder

#include <bits/stdc++.h>
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
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, unordered_map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void f(ll n, vector<ll> a, vector<ll> b){

  ll a_num = -1;
  ll idx = -1;
  rep(i, n){
    if(a.at(i) != b.at(i)){
      idx = i;
      a_num = a.at(i);
      break;
    }
  }

  a.erase(a.begin()+idx);

  ll a_num2 = -1;
  ll idx2 = -1;
  for(int i = idx; i < n-1; i++){
    if(a.at(i) != b.at(i)){
      idx2 = i;
      a_num2 = a.at(i);
      break;
    }
  }

  if(idx2 >= 0){
    a.insert(a.begin()+idx2, a_num);

    if(a == b){
      out_yn(true);
      return;
    }else{
      out_yn(false);
      return;
    }


  }else{
    out_yn(b.back() == a_num);
  }


}

void solve(){
  ll n; cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  vector<ll> b(n);
  rep(i, n) cin >> b.at(i);

  if(a == b){
    out_yn(true);
    return;
  }

  vector<ll> c = b;
  vector<ll> d = a;

  ll a_num = -1;
  ll idx = -1;
  rep(i, n){
    if(a.at(i) != b.at(i)){
      idx = i;
      a_num = a.at(i);
      break;
    }
  }

  a.erase(a.begin()+idx);

  ll a_num2 = -1;
  ll idx2 = -1;
  for(int i = idx; i < n-1; i++){
    if(a.at(i) != b.at(i)){
      idx2 = i;
      a_num2 = a.at(i);
      break;
    }
  }

  if(idx2 >= 0){
    a.insert(a.begin()+idx2, a_num);

    if(a == b){
      out_yn(true);
      return;
    }else{
      f(n, c, d);
    }
  }else{
    out_yn(b.back() == a_num);
  }





/*
  vector<ll> c = a;
  vector<ll> d = b;

  ll b_num = -1;
  ll idx = -1;
  rep(i, n){
    if(a.at(i) != b.at(i)){
      idx = i;
      b_num = b.at(i);
      break;
    }
  }

  b.erase(b.begin()+idx);

  // debug(idx);
  // debug(a);
  // debug(b);

  ll idx2 = -1;
  rep(i, n-1){
    if(a.at(i) != b.at(i)){
      idx2 = i;
      break;
    }
  }

  if(idx2 > 0){
    b.insert(b.begin()+idx2, b_num);

    if(a == b){
      out_yn(true);
      return;
    }else{



{
  ll c_num = -1;
  ll idx = -1;
  rep(i, n){
    if(c.at(i) != d.at(i)){
      idx = i;
      c_num = c.at(i);
      break;
    }
  }

  c.erase(c.begin()+idx);


  ll idx2 = -1;
  rep(i, n-1){
    if(c.at(i) != d.at(i)){
      idx2 = i;
      break;
    }
  }

  if(idx2 > 0){
    c.insert(c.begin()+idx2, c_num);

    if(c == d){
      out_yn(true);
      return;
    }
  }else{
    out_yn(d.back() == c_num);
    return;
  }


}











    }






  }else{
    out_yn(a.back() == b_num);
    return;
  }
*/




/*
  ll a_num = -1;
  ll idx = -1;
  rep(i, n){
    if(a.at(i) != b.at(i)){
      idx = i;
      a_num = a.at(i);
      break;
    }
  }

  if(idx == n-1){
    out_yn(false);
    return;
  }

  ll idx2 = -1;
  for(int i = idx+1; i < n; i++){
    if(a.at(i) != b.at(i-1)){
      idx2 = i;
      break;
    }
  }

  debug(idx);
  debug(a_num);
  debug(idx2);
  debug(b.at(idx2+1));

  if(a_num != b.at(idx2-1)){
    out_yn(false);
    return;
  }

  for(int i = idx2+1; i < n; i++){
    if(a.at(idx2) != b.at(idx2-1)){
      out_yn(false);
      return;
    }
  }

  out_yn(true);
*/

/*
  bool has_diff = false;
  ll a_num = -1;
  ll b_num = -1;

  ll b_idx = 0;
  rep(a_idx, n){
    if(b_idx == n){

      out_yn(a.at(a_idx) == b_num);
      return;

    }
    if(a.at(a_idx) != b.at(b_idx)){
      if(!has_diff){
        has_diff = true;
        a_num = a.at(a_idx);
        b_num = a.at(b_idx);
        debug(a_num);
        debug(b_num);
        debug(a_idx);
        debug(b_idx);
        b_idx++;
        if(b_idx == n){
          out_yn(false);
          return;
        }
      }else{
        if(a.at(a_idx))
      }
    }
    b_idx++;
  }
*/


/*
  ll a_idx = 0;
  rep(b_idx, n){
    if(a.at(a_idx) != b.at(b_idx) && !has_diff){
      has_diff = true;
      num = a.at(a_idx);
      a_idx++;

    }else if(a.at(a_idx) != b.at(b_idx)){
      if(num != b.at(b_idx)){
        out_yn(false);
        return;
      }
    }

    a_idx++;
  }
  out_yn(true);
*/
}

int main() {
  solve();
  return 0;
}
