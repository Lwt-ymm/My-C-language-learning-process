#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<string>
using namespace std;
//作业:
struct Node {
public:
    Node(int val, Node *lchild, Node *rchild) : val(val), lchild(lchild), rchild(rchild) {};
    int val;
    Node *lchild;
    Node *rchild;
};

void inputData(string &s_pre, string &s_in, string filename) {
    ifstream ifs(filename, ios::in);
    if(!ifs.is_open()) {
        cout << "文件打开失败!" << endl;
        return;
    }
    while(getline(ifs, s_pre)) {
        while(getline(ifs, s_in)) break;
        break;
    }
    ifs.close();
    return;
}

void transform(string s, vector<int> &v) {
    string tmp;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            v.push_back(atoi(tmp.c_str()));
            tmp = "";
            continue;
        }
        tmp += s[i];
    }
}

Node *buildTree(vector<int> pre, vector<int> in) {
    if(pre.size() == 0) return nullptr;
    int pos = 0;
    vector<int> l_pre, l_in, r_pre, r_in;
    while(pre[0] != in[pos]) pos++;
    for(int i = 0; i < pos; i++) {
        l_pre.push_back(pre[i + 1]);
        l_in.push_back(in[i]);
    }
    for(int i = pos + 1; i < pre.size(); i++) {
        r_pre.push_back(pre[i]);
        r_in.push_back(in[i]);
    }
    Node *root = new Node(pre[0], buildTree(l_pre, l_in), buildTree(r_pre, r_in)); 
    return root;
}

vector<int> postorder(Node *root, vector<int> &post) {
    if(root == nullptr) return post;
    postorder(root->lchild, post);
    postorder(root->rchild, post);
    post.push_back(root->val);
    return post;
}
string getResult(vector<int> post) {
    int ans = 0;
    int mm = 0, m = 0; 
    for(int i = 1; i <= post.size(); i++) {
        ans += post[i - 1] * i;
        if(ans > 10000) {
            m += ans / 10000;
            ans = ans % 10000;
        }
        if(m > 10000) {
            mm += m / 10000;
            m = m % 10000;
        }
    }
    return to_string(mm) + "亿" + to_string(m) + "万" +to_string(ans);
}

int main() {
    string s_pre, s_in;
    vector<int> v_pre, v_in, v_post;
    inputData(s_pre, s_in, "【第五课】二叉树与经典问题-彩蛋数据_16.txt");
    transform(s_pre, v_pre); transform(s_in, v_in);
    Node *root = buildTree(v_pre, v_in);
    v_post = postorder(root, v_post);
    cout << getResult(v_post) << endl;
    return 0;
}