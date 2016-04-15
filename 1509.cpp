#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int first;
        cin >> first;
        while (first != 0) {
            int num[1000];
            stack<int> s;
            num[0] = first;
            for (int i = 1; i < n; i++) {
                cin >> num[i];
            }
            for (int j = 0, i = 1; j < n && i <= n + 1;) {
                if (s.empty() || s.top() != num[j]) {
                    s.push(i);
                    i++;
                } else {
                    s.pop();
                    j++;
                }
            }
            if (s.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
            cin >> first;
        }
        cout << endl;
    }
    return 0;
}
