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

int janken(char x, char y){
  if(x == y) return 0;
  if(x == 'G' && y == 'C' || x == 'C' && y == 'P' || x == 'P' && y == 'G'){
    return 1;
  }else{
    return -1;
  }
}

bool cmp(pii a, pii b){
  if(a.first < b.first) return true;
  if(a.first == b.first){
    return a.second > b.second;
  }else{
    return false;
  }
  // if(a.first > b.first) return true;
  // if(a.second <= b.second) return true;
  // return false;
};


void solve(){
  int n, m; cin >> n >> m;

  vector<string> a(2*n);
  vector<pii> rank(2*n);
  rep(i, 2*n){
    cin >> a.at(i);
    rank.at(i) = {0, i};
    // string a; cin >> a;
  }

  rep(i, m){
    rep(j, n){
      int p1_idx = rank.at(2*j).second;
      int p2_idx = rank.at(2*j+1).second;
      int res = janken(a.at(p1_idx).at(i), a.at(p2_idx).at(i));

      if(res > 0){
        rank.at(2*j).first++;
      }else if(res < 0){
        rank.at(2*j+1).first++;
      }

    }
    sort(rank.rbegin(), rank.rend(), cmp);
  }

  rep(i, 2*n){
    cout << rank.at(i).second + 1 << endl;
  }



}

int main() {

  solve();

  return 0;
}
