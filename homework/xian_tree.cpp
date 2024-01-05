#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

bool isdigit_mine(char c){
    if (c>='a'&&c<='z')
    {
        return true;
    }
    return false;
    
}
TreeNode* buildTree(string prefixExpr, int& index) {
    if (index >= prefixExpr.length()) {
        return nullptr;  // 表达式已经解析完毕
    }

    char c = prefixExpr[index++];

    TreeNode* node = new TreeNode(c);

    if (isdigit_mine(c)) {  // 如果是数字，说明是叶子节点
        return node;
    }

    node->left = buildTree(prefixExpr, index);
    node->right = buildTree(prefixExpr, index);

    return node;
}

void InorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    InorderTraversal(root->left);
       cout << root->val ;
    InorderTraversal(root->right);
 
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val ;
}

int main() {
    string prefixExpr;
    getline(cin, prefixExpr);

    int index = 0;
    TreeNode* root = buildTree(prefixExpr, index);

    cout<<prefixExpr<<endl;
    InorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
    return 0;
}
