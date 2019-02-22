#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, foo, bar;
    scanf("%d %d %d", &n, &foo, &bar);
    int both = 0;
    int alice = 0;
    int bob = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (x % foo == 0 && x % bar == 0) {
        ++both;
      } else if (x % foo == 0) {
        ++bob;
      } else if (x % bar == 0) {
        ++alice;
      }
    }
    if (!both) {
      puts(bob > alice ? "BOB" : "ALICE");
    } else {
      puts(bob >= alice ? "BOB" : "ALICE");
    }
  }
  return 0;
}