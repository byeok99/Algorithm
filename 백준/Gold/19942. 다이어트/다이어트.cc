#include <bits/stdc++.h>
using namespace std;

struct ingredient { 
    int protein;
    int fat; 
    int carbo;
    int vitamin; 
    int cost;
    
    bool isSatisfied(int mp, int mf, int ms, int mv) {
        return protein >= mp && fat >= mf && carbo >= ms && vitamin >= mv;
    }
};

int n, mp, mf, ms, mv, min_cost = INT_MAX;
vector<ingredient> ing;
vector<int> ret, selected; 

void go(int idx, ingredient igdent, vector<int> selected) {
    if (igdent.isSatisfied(mp, mf, ms, mv)) { 
        if (min_cost > igdent.cost) { 
            min_cost = igdent.cost;
            ret = selected;
        }
        return;
    }

    if (idx == n) return;

    selected.push_back(idx+1); 
    go(idx+1, 
        {
            igdent.protein + ing[idx].protein,
            igdent.fat + ing[idx].fat,
            igdent.carbo + ing[idx].carbo,
            igdent.vitamin + ing[idx].vitamin,
            igdent.cost + ing[idx].cost
        }, selected);
    selected.pop_back();
    go(idx+1, igdent, selected);
}

int main() { 
    cin >> n; 
    cin >> mp >> mf >> ms >> mv; 

    for (int i=0; i<n; i++) { 
        int tp, tf, ts, tv, tc; 
        cin >> tp >> tf >> ts >> tv >> tc; 
        ing.push_back({tp, tf, ts, tv, tc}); 
    }

    go(0, {0, 0, 0, 0, 0}, selected); 

    cout << (min_cost == INT_MAX ? -1 : min_cost) << "\n";
    for(auto i : ret) cout << i << " ";
}