#include <iostream>
#include <queue>
#include<algorithm>
#include <set>

using namespace std;

int test_case, N;
int check[1000001];
void solve()
{
	cin >> N;
	priority_queue<pair<int, int>> q_high; // 내림차순
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q_low; // 오름차순
	for (int i = 0; i < N; i++) {
		char order;
		int num;
		cin >> order >> num;
		if (order == 'I') {
			q_high.push(make_pair(num, i));
			q_low.push(make_pair(num, i));
			check[i] = 1;
		}
		else if (order == 'D') {
			if (num == -1) {
				while (!q_low.empty()) {
					int X = q_low.top().second;
					if (check[X] == 0) q_low.pop();
					else if (check[X] == 1 && q_low.size() > 0)
					{
						int X = q_low.top().second;
						check[X] = 0;
						break;
					}
				}				
			}
			else {
				while (!q_high.empty()) {
					int X = q_high.top().second;
					if (check[X] == 0) q_high.pop();
					else if (check[X] == 1 && q_high.size() > 0)
					{
						int X = q_high.top().second;
						check[X] = 0;
						break;
					}
				}
			}
		}
	}
	while (!q_low.empty()) {
		int X = q_low.top().second;
		if (check[X] == 1) break;
		q_low.pop();
	}
	while (!q_high.empty()) {
		int X = q_high.top().second;
		if (check[X] == 1) break;
		q_high.pop();
	}
	if (q_high.empty() && q_low.empty()) cout << "EMPTY" << "\n";
	else cout << q_high.top().first << " " << q_low.top().first << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		solve();
	}
}