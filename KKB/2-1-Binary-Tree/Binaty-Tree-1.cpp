#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

//-------------------------------------------------------------------
//N叉树的前序遍历
/*class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int val) : val(val) {}
    Node(int val, vector<Node*> children) : val(val), children(children) {}
};

vector<int> preorder(Node* root) {
    vector<int> ans;
    if(root == nullptr) return ans;
    ans.push_back(root->val);
    //for(auto a : b) {} b为一个容器，效果是利用a遍历获得b中的每个值，但a无法影响到b容器中的元素；
    //for(auto &a : b) {} 多了一个引用符号，a可以改变b容器中的元素
    for(auto x : root->children) preorder(x);
    return ans;
}*/
//-------------------------------------------------------------------
//随即生成n个节点的二叉树
struct Node {
    Node(int key) : key(key),lchild(nullptr),rchild(nullptr) {}
    int key;
    Node *lchild, *rchild;
};

Node* getNewNode(int key) {
    Node *p = new Node(key);
    return p;
}

Node* random_insert(Node *root, int key) {
    if(root == nullptr) return getNewNode(key);
    if(rand() % 2) root->lchild = random_insert(root->lchild, key);
    else root->rchild = random_insert(root->rchild, key);
    return root;
}

void preorder(Node *root) {
    if(root == nullptr) return;
    cout << root->key << ' ';
    preorder(root->lchild);
    preorder(root->rchild);
    return;
}

void inorder(Node *root) {
    if(root == nullptr) return;
    cout << root->key << ' ';
    inorder(root->lchild);
    inorder(root->rchild);
    return;
}

//-------------------------------------------------------------------
//从上到下打印二叉树
vector<vector<int>> levelOrder(Node* root, int k, vector<vector<int>> ans) {
    if(root == nullptr) return ans;
    if(k == ans.size()) ans.push_back(vector<int> ());
    ans[k].push_back(root->key);
    levelOrder(root->lchild, k + 1, ans);
    levelOrder(root->rchild, k + 1, ans);
    return ans;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if(argc != 2) return 0;
    int max = atoi(argv[1]);
    Node *root = nullptr;
    for(int i = 1; i <= max; i++) {
        root = random_insert(root, i);
    }
    preorder(root); cout << endl;
    inorder(root); cout << endl;

    vector<vector<int>> ans = levelOrder(root, 0, ans);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << '[' << ans[i][j] << ", ";
        }
        cout << ']' <<endl;
    }
    return 0;
}
//-------------------------------------------------------------------
//1-3彩蛋，螺旋矩阵
/*vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans;
    int n = matrix.size(), m = matrix[0].size();
    int K = n * m;
    for(int i = 0, j = 0, k = 0, l = 0; k < K; l++) {
        while(k < K) {
            ans.push_back(matrix[i][j]); k++;
            if(j == m -1 - l) {
                i++;
                break;
            }
            j++;
        }
        while(k < K) {
            ans.push_back(matrix[i][j]); k++;
            if(i == n -1 - l) {
                j--;   
                break;
            }
            i++;
        }
        while(k < K) {
            ans.push_back(matrix[i][j]); k++;
            if(j == l) {
                i--;
                break;
            }    
            j--;
        }
        while(k < K) {
            ans.push_back(matrix[i][j]); k++;
            if(i == l + 1) {
                j++;   
                break;
            }
            i--;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    vector<int> ans = spiralOrder(matrix);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ", "; 
    }
    cout << endl;
    return 0;
}*/