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

/*
vector<string> compress(string &s){
  ll level = 0;

  vector<string> res;
  char prv;
  bool has_xx = false;

  string t = "";
  rep(i, s.size()){
    char c = s.at(i);
    if(c == '(') level++;
    if(c == ')') level--;
    if(i > 0 && c == 'x'){
      if(prv == 'x'){
        has_xx = true;
      }
    }

    if(c == 'x') t.push_back(c);
    if(c == ')' && level == 0){
      res.push_back(t);
      t = "";
    }
    prv = c;
  }
  if(t.size() != 0) res.push_back(t);

  return res;
}
*/

/*
string compress(string &s){
  rep(i, s.size()){
    if(i > 0 && s.at(i) == 'x' && s.at(i-1) == 'x'){
      ll idx = 0;
      while(i-1-idx > 0 && i+1+idx < s.size()){
        if(s.at(i-1-idx) == '(' && s.at(i+1+idx) == ')'){
          idx++;
        }
      }
    }
  }
}
*/
/*
string compress(string &s){
  // bool is_all_left = false;
  rep(i, s.size()){
    // if(i > 0 && s.at(i) == 'x' && s.at(i-1) == 'x' && is_all_left){
    if(i > 1 && s.at(i-2) == '(' && s.at(i-1) == 'x' && s.at(i) == 'x'){
      ll idx = 0;
      while(i-1-idx > 0 && i+1+idx < s.size()){
        if(s.at(i-1-idx) == '(' && s.at(i+1+idx) == ')'){
          idx++;
        }else{
          break;
        }
      }
    }
    // if(s.at(i) != '(') is_all_left = false;
  }
}
*/
/*
string compress(string &s){
  if(s.size() < 4){
    string t = s;
    return t;
  }
  string t = "";
  ll idx = 0;
  bool xx_pattern = false;
  while(idx < s.size()-4){
    bool b1 = s.at(idx) == '(';
    bool b2 = s.at(idx+1) == 'x';
    bool b3 = s.at(idx+2) == 'x';
    bool b4 = s.at(idx+3) == ')';
    if(b1 && b2 && b3 && b4){
      xx_pattern = true;
      ll idx2 = idx;
      while(idx2 > 0 && idx2+4 < s.size()){
        if(s.at(idx2) == '(' && s.at(idx2+4) == ')'){
          idx2--;
        }else{
          break;
        }
      }
      idx = idx + 4 + abs(idx2);
      t.push_back('x');
      t.push_back('x');
    }else{
      xx_pattern = false;
      t.push_back(s.at(idx));
      t.push_back(s.at(idx+1));
      t.push_back(s.at(idx+2));
      t.push_back(s.at(idx+3));
      idx += 4;
    }
  }
  if(!xx_pattern){
    t.push_back(s.at(s.size()-4));
    t.push_back(s.at(s.size()-3));
    t.push_back(s.at(s.size()-2));
    t.push_back(s.at(s.size()-1));
  }
  return t;
}
*/

// stack<char> compress(string &s){
string compress(string &s){
  stack<char> stk;

  ll idx = 0;
  while(idx < s.size()){
    char c = s.at(idx);
    stk.push(c);
    if(stk.size() >= 4){
      char c3 = stk.top(); stk.pop();
      char c2 = stk.top(); stk.pop();
      char c1 = stk.top(); stk.pop();
      char c0 = stk.top(); stk.pop();
      bool b1 = c0 == '(';
      bool b2 = c1 == 'x';
      bool b3 = c2 == 'x';
      bool b4 = c3 == ')';
      if(b1 && b2 && b3 && b4){
        idx++;
        while(!stk.empty() && stk.top() == '(' && idx < s.size() && s.at(idx) == ')'){
          stk.pop();
          idx++;
        }
        stk.push('x');
        stk.push('x');
      }else{
        stk.push(c0);
        stk.push(c1);
        stk.push(c2);
        stk.push(c3);
        idx++;
      }
    }else{
      idx++;
    }
  }

  string t = "";
  while(!stk.empty()){
    char c = stk.top(); stk.pop();
    t.push_back(c);
  }
  reverse(t.begin(), t.end());
  return t;
}

void solve(){
  ll t;
  cin >> t;

  while(t--){
    string a, b;
    cin >> a >> b;

    // vector<string> a2 = compress(a);
    // vector<string> b2 = compress(b);
    string a2 = compress(a);
    string b2 = compress(b);
    // stack<char> a2 = compress(a);
    // stack<char> b2 = compress(b);

    out_yn(a2 == b2);

    // debug(a2);
    // debug(b2);


  }




}


int main() {

  solve();

  return 0;
}
