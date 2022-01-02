string encode(string s) {
    int c = 1, i = 0, n = s.length();
    string ans = "";

    while (i < n) {
        ans.push_back(s[i++]);
        while (i < n && s[i] == s[i - 1]) {
            c++;
            i++;
        }
        ans.push_back(c + '0');
        c = 1;
    }
    return ans;
}