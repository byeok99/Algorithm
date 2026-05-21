#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, L;
int answer;
vector<pair<int, int>> infos; // first: 점수, second: 칼로리

void dfs(int depth, int curr_cal, int curr_value) {
    if (curr_cal > L) return;
	if (depth == N) {
	    answer = max(answer, curr_value);
		return;
	}
	
//    for (int i = depth; i < N; i++) {
//        dfs(
//            i + 1,
//            curr_cal + infos[i].second,
//            curr_value + infos[i].first
//        );
//    }

	dfs(depth+1, curr_cal, curr_value); 
	dfs(depth+1, curr_cal + infos[depth].second, curr_value + infos[depth].first);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> L;

        infos.clear();

        for (int i = 0; i < N; i++) {
            int score, cal;
            cin >> score >> cal;
            infos.push_back({score, cal});
        }

        answer = 0;

        dfs(0, 0, 0);

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}