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
  ll n; cin >> n;
  vector<string> t(n);
  rep(i, n) cin >> t.at(i);

  ll k; cin >> k;
  vector<ll> p(k);
  rep(i, k){
    cin >> p.at(i);
    p.at(i)--;
  }

  auto is_op = [](string token) -> bool {
    return token == "+" || token == "-" || token == "*" || token == "/";
  };

  auto operate = [](string op, string a, string b) -> string {
    if(op == "+"){
      return to_string(stoll(a) + stoll(b));
    }else if(op == "-"){
      return to_string(stoll(a) - stoll(b));
    }else if(op == "*"){
      return to_string(stoll(a) * stoll(b));
    }else if(op == "/"){
      return to_string(stoll(a) / stoll(b));
    }else{
      // undefined
      return "";
    }
  };

  auto f = [&](vector<string> t) -> ll {
    vector<string> s;
    rep(i, n){
      s.push_back(t.at(i));
      while(s.size() >= 3 
        &&  is_op(s.at(s.size()-3))
        && !is_op(s.at(s.size()-2))
        && !is_op(s.at(s.size()-1))){
        string b = s.back(); s.pop_back();
        string a = s.back(); s.pop_back();
        string op = s.back(); s.pop_back();
        s.push_back(operate(op, a, b));
      }
    }
    return stoll(s.back());
  };

  cout << f(t) << endl;


  rep(i, k){
    if(t.at(p.at(i)) == "+"){
      t.at(p.at(i)) = "-";
    }else if(t.at(p.at(i)) == "-"){
      t.at(p.at(i)) = "+";
    }else if(t.at(p.at(i)) == "*"){
      t.at(p.at(i)) = "/";
    }else if(t.at(p.at(i)) == "/"){
      t.at(p.at(i)) = "*";
    }
  }

  cout << f(t) << endl;

}

/*
ll f(string c1, string c2, string op){
  ll i1 = c1.front() != '-' ? stoll(c1) : -1 * stoll(c1.substr(1));
  ll i2 = c2.front() != '-' ? stoll(c2) : -1 * stoll(c2.substr(1));
  if(op == "+"){
    return i1 + i2;
  }else if(op == "-"){
    return i1 - i2;
  }else if(op == "*"){
    return i1 * i2;
  }else{
    if(i1 >= 0 && i2 > 0 || i1 <= 0 && i2 < 0){
      return i1 / i2;
    }else{
      return i1 / i2;
    }
  }
}

string rev(string s1){
  if(s1 == "+") return "-";
  if(s1 == "-") return "+";
  if(s1 == "*") return "/";
  if(s1 == "/") return "*";
  return "";
}

void solve(){
  ll n; cin >> n;
  vector<string> t(n);
  rep(i, n) cin >> t.at(i);

  ll k; cin >> k;
  vector<ll> p(k);
  rep(i, k){
    cin >> p.at(i);
    p.at(i)--;
  }

  stack<pair<string, bool>> stk;

  ll p_idx = 0;
  rep(i, n){
    bool is_changed = false;
    if(p_idx < p.size() && p.at(p_idx) == i){
      is_changed = true;
      p_idx++;
    }
    stk.push({t.at(i), is_changed});
  }

  ll ans1 = 0;
  ll ans2 = 0;

  vector<pair<string, bool>> cs;
  while(!stk.empty()){
    auto [c, is_changed] = stk.top(); stk.pop();
    if(c == "+" || c == "-" || c == "*" || c == "/"){
      auto [y, y_idx] = cs.back();
      cs.pop_back();
      auto [x, x_idx] = cs.back();
      cs.pop_back();
      ll f_res = f(x, y, c);
      debug(x);
      debug(y);
      debug(f_res);
      ans1 += f_res;
      if(is_changed){
        ans2 += f(x, y, rev(c));
      }
      stk.push({to_string(f_res), false});

      rep(i, cs.size()){
        stk.push(cs.at(i));
      }
      cs.clear();
    }else{
      cs.push_back({c, is_changed});
      debug(cs);
    }
  }
  cout << ans1 << endl;
  cout << ans2 << endl;
}
*/

int main() {

  solve();

  return 0;
}
