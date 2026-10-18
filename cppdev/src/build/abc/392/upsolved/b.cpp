# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n, m;
  cin >> n >> m;

  set<int> s;
  rep(i, m){
    int a;
    cin >> a;
    s.insert(a);
  }

  vector<int> x;
  for(int i = 1; i <= n; i++){
    if(!s.count(i)){
      x.push_back(i);
    }
  }

  cout << x.size() << endl;
  rep(i, x.size()){
    cout << x.at(i) << " ";
  }
  cout <<  endl;







  return 0;

}











