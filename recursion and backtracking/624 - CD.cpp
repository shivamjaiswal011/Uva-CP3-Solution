#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define     mod             1e9+7
#define     MOD             998244353
#define     ll             long long
#define     mp              make_pair
#define     F               first
#define     S               second
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
#define     ii              pair<int,int>
#define     que_max         priority_queue <int>
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int n, k, num, sum = 0;
vector<int> track, cur;
vector<vector<int> > ans;
vector<bool> vis;
map<int, int> m;
int pos = 0;


void backtrack( int sum, int idx)
{

  for (int i = idx; i < num; i++)
  {
    if (vis[i])continue;

    if (sum + track[i] <= n)
    {
      cur.push_back(track[i]);
      vis[i] = true;
      backtrack(sum + track[i], i + 1);
      vis[i] = false;
      cur.erase(cur.begin() + cur.size() - 1);
    }
  }

  if (cur.size() && m.find(sum) == m.end())
  {
    m[sum] = pos;
    ans.push_back(cur);
    pos++;
  }


}


int main()

{
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif

  IOS;

  while (cin >> n)
  {
    cin >> num;

    track.resize(num);
    vis.assign(num, false);
    cur.clear();
    ans.clear();
    m.clear();
    for (auto &i : track)
      cin >> i;

    sum = 0, pos = 0;

    backtrack(0, 0);

    auto g = m.rbegin();
    for (auto i : ans[g->second])
    {
      cout << i << " ";
    }
    cout << "sum:" << g->first << endl;
  }

}
