#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> al(n, vector<int>(m));
    vector<vector<int>> mx(n, vector<int>(m));
    vector<vector<int>> nd(n, vector<int>(m));

    vector<int> av(m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> al[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mx[i][j];
        }
    }

    for (int j = 0; j < m; j++){
        cin >> av[j];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            nd[i][j] = mx[i][j] - al[i][j];
        }
    }

    vector<int> work = av;
    vector<int> vis(n, 0);
    vector<int> seq;

    int cnt = 0;

    while (cnt < n){
        bool found = false;

        for (int i = 0; i < n; i++){
            if (vis[i])continue;

            bool can = true;

            for (int j = 0; j < m; j++){
                if (nd[i][j] > work[j]) {
                    can = false;
                    break;
                }
            }

            if (can){
                for (int j = 0; j < m; j++)
                {
                    work[j] += al[i][j];
                }

                vis[i] = 1;
                seq.push_back(i);
                cnt++;

                found = true;
            }
        }

        if (!found){
            cout << "UNSAFE\n";
            return 0;
        }
    }

    cout << "SAFE\n";
    cout << "Safe Sequence:\n";

    for (int i = 0; i < seq.size(); i++){
        cout << "P" << seq[i];

        if (i + 1 < seq.size()){
            cout << " -> ";
        }
    }

    cout << endl;

    return 0;
}