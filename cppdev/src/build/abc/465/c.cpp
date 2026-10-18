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
  string s; cin >> s;

  deque<int> deq;
  deq.push_back(0);

  bool is_r = true;
  for(int i = 1; i < n; i++){
    if(s.at(i-1) == 'o'){
      is_r = !is_r;
    }
    if(is_r){
      deq.push_back(i);
    }else{
      deq.push_front(i);
    }
  }

  int cnt = 0;
  for(auto c : s) {
    if(c == 'o')cnt++;
  }

  if(cnt%2 == 0){
    while(!deq.empty()){
      cout << deq.front()+1 << " ";
      deq.pop_front();
    }
    cout << endl;

  }else{
    while(!deq.empty()){
      cout << deq.back()+1 << " ";
      deq.pop_back();
    }
    cout << endl;

  }







/*
  deque<int> deq;
  // deq.push_back(0);

  // bool is_r = s.at(0) == 'x';
  bool is_r = true;
  for(int i = 0; i < n; i++){
    // if(s.at(i-1) == 'x' && s.at(i) == 'x' || s.at(i-1) == 'o' && s.at(i) == 'o'){
    //   is_r = !is_r;
    // }
    if(s.at(i) == 'o') is_r = !is_r;

    if(is_r){
      deq.push_back(i);
    }else{
      deq.push_front(i);
    }
  }

  while(!deq.empty()){
    cout << deq.front()+1 << " ";
    deq.pop_front();
  }
*/




}



int main() {

  solve();

  return 0;
}
