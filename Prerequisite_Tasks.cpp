bool isPossible(int n, vector<pair<int, int>>& a) {
    int in[n] = {0};
    vector<int> g[n];
    for (int i = 0; i < a.size(); i++) {
        in[a[i].second]++;
        g[a[i].first].push_back(a[i].second);
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (in[i] == 0) q.push(i);

    if (q.empty()) 
        return false;

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        in[p] = -1;
        for (int i = 0; i < g[p].size(); i++) {
            in[g[p][i]]--;
            if (in[g[p][i]] == 0) 
                q.push(g[p][i]);
        }
    }

    for (int i = 0; i < n; i++)
        if (in[i] != -1) 
            return false;

    return true;
}