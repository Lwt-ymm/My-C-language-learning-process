#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<string>
using namespace std;
struct Node {
public:
    Node(int val, Node* l, Node* r) : val(val), lchild(l), rchild(r) {}
    int val;
    Node* lchild;
    Node* rchild;
};


//------------------------------------------------------------------
//监控二叉树
/*void getDP(Node* root, int dp[2][2]) {
    if(root == nullptr) {
        dp[0][0] = 0;
        dp[0][1] = 10000;
        dp[1][0] = 0;
        dp[1][1] = 10000;
        return;
    }
    if(root->lchild == nullptr && root->rchild == nullptr) {
        dp[0][0] = 10000;
        dp[0][1] = 1;
        dp[1][0] = 0;
        dp[1][1] = 1;
        return;
    }
    int l[2][2], r[2][2];
    getDP(root->lchild, l);
    getDP(root->rchild, r);
    dp[0][0] = min(min(l[0][1] + r[0][0], l[0][0] + r[0][1]), l[0][1] + r[0][1]);
    dp[0][1] = min(min(l[1][0] + r[1][0], l[1][1] + r[1][1]), min(l[1][0] + r[1][1], l[1][1] + r[1][0])) + 1;
    dp[1][0] = min(min(l[0][0] + r[0][0], l[0][1] + r[0][1]),min(l[0][1] + r[0][0], l[0][0] + r[0][1]));
    dp[1][1] = dp[0][1];
    return;
}
int minCameraCover(Node* root) {
    int dp[2][2];
    getDP(root, dp);
    return min(dp[0][0], dp[0][1]);
}*/
//------------------------------------------------------------------
//二叉树最大宽度
/*typedef pair<Node*, int> PNI;
int widthOfBinaryTree(Node* root) {
    int ans = 0;
    queue<PNI> q;
    q.push(PNI(root, 0));
    while(!q.empty()) {
        int j = q.size();
        int l = q.front().second, r = q.front().second;
        for(int i = 0; i < j; i++) {
            Node* n = q.front().first;
            r = q.front().second;
            if(n->lchild) q.push(PNI(n->lchild, (r - l) * 2));
            if(n->rchild) q.push(PNI(n->rchild, (r - l) * 2 + 1));
            q.pop();
        }
        ans = max(ans, l - r - 1);
    }
    return ans;
}*/
//------------------------------------------------------------------
//树的子结构
/*bool isMatch(Node* A, Node* B) {
    if(B == nullptr) return true;
    if(A == nullptr) return false;
    if(A->val != B->val) return false;
    return isMatch(A->lchild, B->lchild) && isMatch(A->rchild, B->rchild);
}
bool isSubStructure(Node* A, Node* B) {
    if(B == nullptr) return true;
    if(A == nullptr) return false;
    if(A->val == B->val && isMatch(A, B)) return true;
    return isSubStructure(A->lchild, B) && isSubStructure(A->rchild, B);
}*/
//------------------------------------------------------------------
//二叉搜索树的第K大节点
/*int getCount(Node* root) {
    if(root == nullptr) return 0;
    return getCount(root->lchild) + getCount(root->rchild) + 1;
}
int kthLargest(Node* root, int k) {
    int cut_r = getCount(root->rchild);
    if(k <= cut_r) return kthLargest(root->rchild, k);
    if(k == cut_r + 1) return root->val;
    return kthLargest(root->lchild, k - cut_r - 1);
}*/
//------------------------------------------------------------------
//完全二叉树的节点数量
/*int countNodes(Node* root) {
    if(root == nullptr) return 0;
    return countNodes(root->lchild) + countNodes(root->rchild) + 1;
}*/
//------------------------------------------------------------------
//根据前序遍历和中序遍历还原二叉树
/*Node* buildTree(vector<int> preorder, vector<int> inorder) {
    if(preorder.size() == 0) return nullptr;
    int pos = 0;
    vector<int> lpre, lin, rpre, rin;
    while(preorder[0] != inorder[pos]) pos++;
    for(int i = 0; i < pos; i++) {
        lpre.push_back(preorder[i + 1]);
        lin.push_back(inorder[i]);
    }
    for(int i = pos + 1; i < preorder.size(); i++) {
        rpre.push_back(preorder[i]);
        rin.push_back(inorder[i]);
    }
    Node* root = new Node(preorder[0], buildTree(lpre, lin), buildTree(rpre, rin));
    return root;
}*/
//------------------------------------------------------------------
//路径总和
/*bool hasPathSum(Node* root, int targetsum) {
    if(root == nullptr) return false;
    if(root->lchild == nullptr && root->rchild == nullptr) return root->val == targetsum;
    if(root->lchild) return hasPathSum(root->lchild, targetsum - root->val);
    if(root->rchild) return hasPathSum(root->rchild, targetsum - root->val);
}*/
//------------------------------------------------------------------
//平衡二叉树
/*int getHeight(Node *root) {
    if(root == nullptr) return 0;
    int l = getHeight(root->lchild);
    int r = getHeight(root->rchild);
    if(l < 0 || r < 0) return -1;
    if(abs(l - r) > 1) return -1;
    return max(l, r) + 1;
}

bool isBalanced(Node* root) {
    return getHeight(root) >= 0;
}*/
//------------------------------------------------------------------
//二叉树的锯齿行层序遍历
/*vector<vector<int>> zigzagLevelOrder(Node* root, int k, vector<vector<int>> &ans) {
    if(root == nullptr) return ans;
    if(k == ans.size()) ans.push_back(vector<int> ());
    ans[k].push_back(root->val);
    zigzagLevelOrder(root->lchild, k + 1, ans);
    zigzagLevelOrder(root->rchild, k + 1, ans);
    if(k == 0) {
        for(int i = 0; i < ans.size(); i++) {
            if(i % 2 == 1) {
                for(int m = 0, n = ans[i].size() - 1; m < n; m++, n--) swap(ans[i][m], ans[i][n]);
            }
        }
    }
    return ans;
}*/
//------------------------------------------------------------------s
//二叉树的层序遍历
/*vector<vector<int>> levelOrderBottom(Node* root, int k, vector<vector<int>> &ans) {
    if(root == nullptr) return ans;
    if(k == ans.size()) ans.push_back(vector<int> ());
    ans[k].push_back(root->val);
    levelOrderBottom(root->lchild, k + 1, ans);
    levelOrderBottom(root->rchild, k + 1, ans);
    if(k == 0) {
        for(int i = 0, j = ans.size() - 1; i < j; i++, j--) swap(ans[i], ans[j]);
    }
    return ans;
}

int main() {
    Node* root = new Node(1, 
    new Node(2, new Node(4, nullptr, nullptr), new Node(5, nullptr, nullptr)),
    new Node(3, new Node(6, nullptr, nullptr), new Node(7, nullptr, nullptr)));
    
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
    vector<vector<int>> ans;
    root = buildTree(preorder, inorder);
    ans = levelOrderBottom(root, 0, ans);
    
    //ans = zigzagLevelOrder(root, 0, ans);
    for(int i = 0; i < ans. size(); i++) {
        cout << '[';
        for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << ", ";
        cout << ']' <<endl;
    }
    //cout << isBalanced(root) << endl;
    //cout << hasPathSum(root, 6) << endl;

    return 0;
}*/