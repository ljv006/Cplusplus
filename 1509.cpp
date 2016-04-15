/*思路：使用栈去解决。给定一个N明确数串的范围，1-N。然后给了若干个数串，问能否通过将原数串调顺序达到其他数串的顺序。关键是理解火车到站的意义。进站相当如入
*栈，而出站相当于出栈。将1-N依次尝试入栈，判断栈顶元素与目标串元素是否匹配，匹配则将栈顶元素出栈，否则降1-N串继续入栈。最后如果栈为空，证明能够通过一系列操
*作是两个串匹配，否则不能匹配。
*/
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
