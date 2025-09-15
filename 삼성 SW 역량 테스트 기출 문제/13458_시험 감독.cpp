#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n;
vector<ll> a;
ll b, c;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // input
  cin >> n;
  a.reserve(n);
  for (ll i = 0; i < n; ++i) cin >> a[i];
  cin >> b >> c;

  for (ll i = 0; i < n; ++i) a[i] -= b;  // 각각의 시험장에 총감독관은 오직 1명만 있어야 한다.

  ll ans = n;  // 총감독관 n명
  for (ll i = 0; i < n; ++i) {
    if (a[i] <= 0) continue;
    ans += (a[i] + c - 1) / c;  // 필요한 부감독관 수를 더한다.
  }

  // output
  cout << ans;
  return 0;
}
