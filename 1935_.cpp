/*思路：1.先序遍历的第一个节点是根节点，根据这个信息，在中序遍历中找到左右子树。
*2.根据获得的左右子树在先序遍历中找到对应的左右部分，然后找出左右子树的根，不断重复，直到先后序遍历的大小都为0.
*问题：总是WA，问题在于build_tree判断何时返回出了问题。应该先判断先序序列和中序序列是否为空，才能进一步将pre[0]赋给root->c。但命令行的输出没有问题，导致这
*个问题被忽略。这个问题是在输出到文件时产生乱码后发现的。以后使用递归应明确返回的位置。
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct node{
    node(char data) {
        left = right = NULL;
        c = data;
    }
    node* left;
    node* right;
    char c;
};
void print(string s) {
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
    }
    cout << endl;
}
void build_tree(node* &root, string pre, string in) {
    //cout << "pre: " << pre << " " << "in: " << in << endl;
    string left_in, right_in, left_pre, right_pre;
    int i, j;
    if (pre.length() == 0 && in.length() == 0) return;
    root = new node(pre[0]);
    for (i = 0; i < in.length(); ++i) {
        if (in[i] != pre[0]) {
            left_in.push_back(in[i]);
        }
        else break;
    }
    //cout << "leftin: ";
    //print(left_in);
    //cout << "here" << endl;
    for (i = i + 1; i < in.length(); ++i) {
        right_in.push_back(in[i]);
    }
    //cout << "rightin: ";
    //print(right_in);
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
    //cout << "leftpre: ";
    //print(left_pre);
    for (j; j < pre.length(); ++j) {
        right_pre.push_back(pre[j]);
    }
    //cout << "rightpre: ";
    //print(right_pre);
    if (right_in.length() == 0 && left_in.length() == 0 && right_pre.length() == 0 && left_pre.length() == 0) {
        return;
   }
    build_tree(root->left, left_pre, left_in);
    build_tree(root->right, right_pre, right_in);
}

void BFS(node* root) {
    queue<node*> q;
    if (root == NULL) return;
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
    string pre_order, in_order;
    int n;
    cin >> n;
    while (n--) {
        node* tree = NULL;
        cin >> pre_order >> in_order;
        build_tree(tree, pre_order, in_order);
        BFS(tree);
    }
    return 0;
}                                 
