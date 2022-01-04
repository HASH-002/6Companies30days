#include <iostream>
#include <vector>
#include <queue>
#define MAX_ENTRIES 10000000
using namespace std;

int main() {

    int a[MAX_ENTRIES];
    int k = 10;  // Number of max entries we need
    priority_queue<int, vector<int>, greater<int>> p;  // storing 10 max entries

    for (int i = 0; i < MAX_ENTRIES; i++) 
        cin >> a[i];

    for (int i = 0; i < MAX_ENTRIES; i++) {
        p.push(a[i]);
        if (p.size() > k) 
            p.pop();
    }

    while(!p.empty()){
        cout << p.top() << endl;
        p.pop();
    }
    return 0;
}