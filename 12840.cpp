#include <iostream>

using namespace std;

void display(int h, int m, int s) {
  cout << h << ' ' << m << ' ' << s << '\n';
}


void addS(int& h, int& m, int& s, int as) {
  s += as;
  if (s > 59) {
    m += s / 60;
    s %= 60;
  }

  if (m > 59) {
    h += m / 60;
    m %= 60;
  }

  if (h > 23) {
    h %= 24;
  }
}

void subS(int& h, int& m, int& s, int ss) {
  s -= ss;
  if (s < 0) {
    m += s / 60;
    s %= 60;
    if (s < 0) {
      m -= 1;
      s = (s + 60) % 60;
    }
  }
  if (m < 0)  {
    h += m / 60;
    m %= 60;
    if (m < 0) {
      h -= 1;
      m = (m + 60) % 60;
    }
  }
  if (h < 0) {
    h = (h % 24 + 24) % 24;
  }
}




int
main(void) {
  ios::sync_with_stdio(false);cin.tie(0);

  int h, m, s; cin >> h >> m >> s;
  int q; cin >> q;

  for (int i = 0; i < q; i++) {
    int t; cin >> t;
    if (t == 1) {
      int c; cin >> c;
      addS(h, m, s, c);
    }
    else if (t == 2) {
      int c; cin >> c;
      subS(h, m, s, c);
    }
    else {
      display(h, m, s);
    }
  }
  return 0;
}
