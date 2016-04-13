/*思路：1.先序遍历的第一个节点是根节点，根据这个信息，在中序遍历中找到左右子树。
*2.根据获得的左右子树在先序遍历中找到对应的左右部分，然后找出左右子树的根，不断重复，直到先后序遍历的大小都为0.

*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string pre, in;
int pos;
struct node{
    node(char data) {
        left = right = NULL;
        c = data;
    }
    node* left;
    node* right;
    char c;
};

void build_tree(node* &root, int start, int end) {
    //cout << "pre: " << pre << " " << "in: " << in << endl;
    /*
    string left_in, right_in, left_pre, right_pre;
    int i, j;
    root->c = pre[0];
    if (pre.length() == 0 && in.length() == 0) return;
    for (i = 0; i < in.length(); ++i) {
        if (in[i] != pre[0]) {
            left_in.push_back(in[i]);
        }
        else break;
    }
    //cout << "here" << endl;
    for (i = i + 1; i < in.length(); ++i) {
        right_in.push_back(in[i]);
    }
   

    for (j = 1; j < pre.length(); ++j) {
        bool isFound = false;
        for (i = 0; i < left_in.length(); ++i) {
            if (pre[j] == left_in[i]) {
                isFound = true;
                break;
            }
        }
        if (isFound)
            left_pre.push_back(pre[j]);
        else break;
    }
    
    for (j; j < pre.length(); ++j) {
        right_pre.push_back(pre[j]);
    }
    //if (right_in.length() == 0 && left_in.length() == 0 && right_pre.length() == 0 && left_pre.length() == 0) {
    //    return;
    //   }
    */
    if (start > end || pos >= pre.length()) return;
    root = new node(pre[pos]);
    int in_index = in.find(pre[pos++]);
    build_tree(root->left, start, in_index - 1);
    build_tree(root->right, in_index + 1, end);
}

void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* n = q.front();
        cout << n->c;
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        q.pop();
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        node* tree = NULL;
        cin >> pre >> in;
        pos = 0;
        build_tree(tree, 0, pre.length() - 1);
        BFS(tree);
    }
    return 0;
}
