#include <iostream>
#include <string>
#include <vector>
using namespace std;

void libVersion(string s, vector<string>& v) {
    int start = 0;
    int end = s.find('.');
    while (end != string::npos) {
        v.push_back(s.substr(start, end - start));
        start = end + 1;
        end = s.find('.', start);
    }
    v.push_back(s.substr(start));
}

int main() {
    string s, t;
    cin >> s >> t;
    if (s.empty() || t.empty())
        cout << max(s, t) << endl;
    else {
        vector<string> l1;
        vector<string> l2;
        libVersion(s, l1);
        libVersion(t, l2);

        bool done = false;
        int i = 0, j = 0;
        int n = l1.size(), m = l2.size();
        while (i < n && j < m) {
            if (l1[i] == l2[j]) {
                i++;
                j++;
            } else {
                done = true;
                l1[i] > l2[j] ? cout << s << endl : cout << t << endl;
                break;
            }
        }
        if (!done)
            j == m ? cout << s << endl : cout << t << endl;
    }
    return 0;
}