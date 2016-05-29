/*
Problem: Windmill Animation
Link: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4190 
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define EPSILON 1e-4

int main() {
	int tt, t, n, steps, start_idx;
	double start_angle;
	cin >> tt;
	while (tt--) {
		cin >> t >> n >> steps >> start_idx >> start_angle;
		start_idx--;
		vector<pair<double, double>> pts(n);
		int idx;
		for (int i = 0; i < n; i++) {
			cin >> idx;
			idx--;
			cin >> pts[idx].first >> pts[idx].second;
		}
		vector<vector<pair<double, int> > > pts_to_angles(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					double cur_angle = atan2 (pts[j].second - pts[i].second, pts[j].first - pts[i].first);
					if (cur_angle >= PI) {
						cur_angle -= PI;
					}
					else if(cur_angle < 0.0) {
						cur_angle += PI;
					}
					pts_to_angles[i].emplace_back(cur_angle, j);
				}
			}
			sort(pts_to_angles[i].begin(), pts_to_angles[i].end());
		}
		start_angle *= (PI / 180.0);
		cout << t;
		while (steps --) {
			int next_idx = pts_to_angles[start_idx][0].second;
			double next_angle = pts_to_angles[start_idx][0].first;
			for (int i = 0; i < n - 1; i++) {
				if (start_angle <= pts_to_angles[start_idx][i].first) {
					next_idx = pts_to_angles[start_idx][i].second;
					next_angle = pts_to_angles[start_idx][i].first;
					break;
				}
			}
			cout << " " << next_idx + 1;
			start_idx = next_idx;
			start_angle = next_angle + EPSILON;
		}
		cout << endl;
	}
	return 0;
}
