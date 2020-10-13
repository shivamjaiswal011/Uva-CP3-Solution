#include <bits/stdc++.h>

using namespace std;
#define     mod            (int)1e9+7
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     F               first
#define     S               second
#define     t()             int test;cin>>test;while(test--)
#define     ii              pair<int,int>
#define     que_max         priority_queue <int>
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"
#define     sz(x)           (int)(x).size()
#define     matrix          vector<vector<long long> >

int  a, b, lineCounter;

vector<int> row;

bool place(int r, int c)
{
	for (int prev = 0; prev < c; prev++)
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
			return false;

	return true;
}

void backtrack(int c) {
	if (c == 8 && row[b] == a)
	{
		cout << setw(2);
		cout  << ++lineCounter << "      " << row[0] + 1;

		for (int j = 1; j < 8; j++)
		{
			cout << " " << row[j] + 1 ;
		}

		cout << endl;
	}
	for (int r = 0; r < 8; r++)
		if (place(r, c))
		{
			row[c] = r;
			backtrack(c + 1);
		}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	IOS;

	int z = 0;

	t()
	{
		if (z)
		{
			cout << endl;
		}

		cin >> a >> b;
		a--, b--;

		row.assign(8, 0);

		lineCounter = 0;

		cout << "SOLN       COLUMN" << endl;

		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;

		backtrack(0);

		z++;
	}
	return 0;
}