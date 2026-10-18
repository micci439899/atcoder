#include <bits/stdc++.h>
using namespace std;


/*
bool is_palindrome(string s) {
  for(int i = 0; i < ((int)s.size()+1) / 2; i++) {
    if (s.at(i) != s.at(s.size() - i - 1)) {
      return false;
    }
  }
  return true;
}


string convert_base(long long num, int base) {
  string ans = "";
  while(num > 0) {
    long long a = num % base;
    ans = to_string(a) + ans;
    num = num / base;
  }
  return ans;
}
*/

bool is_palindrome(long long num, int base) {
  vector<int> x;
  while (num > 0) {
    x.push_back(num % base);
    num = num / base;
  }
  for (int i = 0; i < (x.size()+1)/2; i++) {
    if (x.at(i) != x.at(x.size() - i -1)) {
      return false;
    }
  }
  return true;
}


long long build_palindrome(long long x, bool is_odd) {
  long long res = x;
  if (is_odd) {
    x /= 10;
  }
  while (x > 0) {
    res = res * 10 +  x % 10;
    x /= 10;
  }
  return res;
}

int main() {
  int A;
  long long N;
  cin >> A >> N;

  int digit = (int)log10(N) + 1;

  long long ans = 0;
  for (int d = 1; d <= digit; d++) {
    int half_digit = (d + 1) / 2;
    bool is_odd = d % 2 == 1;

    long long start = (long long)pow(10, half_digit - 1);
    long long end = (long long)pow(10, half_digit);

    for (long long i = start; i < end; i++) {
      long long pal = build_palindrome(i, is_odd);
      //long long pal = build_pal(i, is_odd);
      if (N < pal) {
        break;
      }
      //string pal_converted = convert_base(pal, A);
      //if (is_palindrome(pal_converted)) {
      if (is_palindrome(pal, A)) {
        ans += pal;
      }
      //if (is_pal_base(pal, A)) {
      //  ans += pal;
      //}
    }
  }
  cout << ans << endl;
  
  // TLE
  /*
  int cnt = 0;
  for (int i = 1; i < N; i++) {
    string s = to_string(i);
    bool is_p = is_palindrome(s);
    
    if(is_p) {
      string s_A = convert_base(i, A);
      bool is_p2 = is_palindrome(s_A);
      if(is_p2) {
        cout << i << " " << s_A << endl;
        cnt += i;
      }
    }
  }
  cout << cnt << endl;
  */
  

  
}
