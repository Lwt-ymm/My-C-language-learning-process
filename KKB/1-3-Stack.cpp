#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
//-----------------------------------------------------------------
//

int main() {

    return 0;
}
//-----------------------------------------------------------------
//基本计算器
/*int level(char c) {
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '#': return -1;
    }
    return 0;
}

int calc(int a, char c, int b) {
    switch(c){
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
return 0;
}

int calculate(string s) {
    stack<int> num;
    stack<char> ops;
    s += '#';
    for(int i = 0, n = 0; i < s.size(); i++) {
        if(s[i] == ' ') continue;
        if(level(s[i]) == 0) {
            n = n * 10 + (s[i] - '0');
            continue;
        }
        num.push(n);
        n = 0;
        while(!ops.empty() && level(s[i]) <= level(ops.top())) {
            int a = num.top(); num.pop();
            int b = num.top(); num.pop();
            num.push(calc(a, ops.top(), b));
            ops.pop();
        }
        ops.push(s[i]);
    }
    return num.top();
}

int main() {
    cout << calculate("3 + 2 * 3") << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//验证二叉树的前序序列化
/*ool isValidSerialization(string preorder) {
    vector<string> s;
    for(int i = 0; i < preorder.size(); i += 2) {
        s.push_back(preorder.substr(i, 1));
        while(s.size() >= 3 && s[s.size() - 1] == "#" && s[s.size() - 2] == "#") {
            s[s.size() - 3] = "#";
            s.pop_back();
            s.pop_back();
        }
        if(s.size() == 2 && s[0] == "#" && s[1] == "#") return false;
    }
    return s.size() == 1 && s[0] == "#";
}

int main() {
    string preorder = "#,#,9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << isValidSerialization(preorder) << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//二叉树的后序遍历
/*class Tree{
public:
    Tree(int data, Tree *left, Tree *right) : data(data), right(right), left(left) {}

    int data; 
    Tree *right;
    Tree *left;
};

vector<int> postorderTraversal(Tree *root) {
    if(root == nullptr) return vector<int> ();
    stack<Tree *> s1;
    stack<int> s2;
    vector<int> ret;
    s1.push(root);
    s2.push(1);//0该节点，1左节点，2右节点
    while(!s1.empty()) {
        if(s2.top() == 1) {
            s2.pop();
            s2.push(2);
            if(s1.top() != nullptr) {
                s1.push(s1.top()->left);
                if(s1.top() == nullptr) s2.push(0);
                else s2.push(1);
            }
        }
        else if(s2.top() == 2) {
            s2.pop();
            s2.push(0);
            if(s1.top() != nullptr) {
                s1.push(s1.top()->right);
                if(s1.top() == nullptr) s2.push(0);
                else s2.push(1);
            }
        }
        else if(s2.top() == 0) {
            if(s1.top() != nullptr) ret.push_back(s1.top()->data);
            s1.pop();
            s2.pop();
        }
    }
    return ret;
}

int main() {
    Tree *root = new Tree(1, 
    new Tree(2, new Tree(4, nullptr, nullptr), new Tree(5, nullptr, nullptr)), 
    new Tree(3, nullptr, nullptr));
    vector<int> ret = postorderTraversal(root);
    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ", ";
    }
    cout << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//移除无效括号
/*string minRemoveToMakeValid(string s) {
    vector<int> ss;
    string ret = "";
    int pos = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') ss.push_back(i);
        else if(s[i] == ')') {
            if(ss.size() == pos) {
                ss.push_back(i);
                pos++;
            }
            ss.pop_back();
        }
        
        else continue;
    }
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < ss.size(); j++) if(i == ss[j]) continue;
        ret += s[i];
    }
    return ret;
}

int main() {
    string s = "lee(t(c)o)de)";
    cout << minRemoveToMakeValid(s) << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//删除最外层括号
/*string removeOuterParentheses(string s) {
    string ret;
    for(int i = 0, count = 0, pre = 0; i < s.size(); i++) {
        if(s[i] == '(') count++;
        else count--;
        if(count == 0) {
            ret += s.substr(pre + 1, i - 1 - pre);
            pre = i + 1;
        }
    }
    return ret;
}

int main() {
    string s = "(()())(())";
    cout << removeOuterParentheses(s) << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//有效的括号序列
/*bool isVaild(string s) {
    stack<char> ss;
    map<char, char> m;
    m[')'] = '(';
    m['}'] = '{';
    m[']'] = '[';
    for(int i = 0; i < s.size(); i++) {
        switch(s[i]) {
            case '(':
            case '{':
            case '[': ss.push(s[i]); break;
            //case ')': if(ss.empty() || ss.top() != '(') return false; ss.pop(); break;
            //case '}': if(ss.empty() || ss.top() != '{') return false; ss.pop(); break;
            //case ']': if(ss.empty() || ss.top() != '[') return false; ss.pop(); break;
            case ')':
            case '}':
            case ']': if(ss.empty() || m[s[i]] != ss.top()) return false; ss.pop(); break;
            default : break;
        }
    }
    return ss.empty();
}

int main() {
    string s = "({}[])";
    cout << isVaild(s) << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//验证栈序列
/*bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> s;
    for(int i = 0, j = 0; i < popped.size(); i++) {
        while((s.empty() || popped[i] != s.top()) && j < pushed.size()) {
            s.push(pushed[j]);
            j++;
        }
        if(popped[i] != s.top()) return false;
        s.pop();
    }
    return true;
}

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 5, 3, 2, 1};
    cout << validateStackSequences(pushed, popped) << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//比较含退格的字符串
/*void tranform(string S, stack<char> &s) {
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '#' && !s.empty()) s.pop();
        else if(S[i] != '#') s.push(S[i]);
    }
    return;
}

bool backspaceCompare(string S, string T) {
    stack<char> s;
    stack<char> t;
    tranform(S, s);
    tranform(T, t);
    if(s.size() - t.size()) return false;
    for(int i = 0; i < s.size(); i++) {
        if(s.top() != t.top()) return false;
        s.pop();
        t.pop();
    }
    return true;
}

int main(){
    string S = {"ab#c"};
    string T = {"ad#c"};
    cout << backspaceCompare(S, T) << endl;
    return 0;;
}*/
//-----------------------------------------------------------------
//棒球比赛
/*int calcPoints(vector<string> &ops) {
    stack<int> s;
    for(int i = 0; i < ops.size(); i++) {
        if(ops[i] == "+") {
            int temp1 = s.top();
            s.pop();
            int temp2 = s.top();
            s.push(temp1);
            s.push(temp1 + temp2);
        }else if(ops[i] == "D") {
            s.push(2 * s.top());
        }else if(ops[i] == "C") {
            s.pop(); 
        }else {
            s.push(atoi(ops[i].c_str()));
        }
    }
    int sum = 0;
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }
    return sum;
}

int main() {
    vector<string> ops = {"5", "2", "C", "D", "+"};
    cout << calcPoints(ops) << endl;
    return 0;
}*/
//-----------------------------------------------------------------
//化栈为队
/*class MyQueue{
public:
    MyQueue() {}
    void push(int val) {
        s2.push(val);
        return;
    }
    void pop() {
        if(s1.empty()) transfer();
        s1.pop();
        return;
    }
    void transfer() {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return;
    }
    bool empty() {
        return s1.empty() && s2.empty();
    }
    int peek() {
        if(s1.empty()) transfer();
        return s1.top();
    }
private:
    stack<int> s1, s2;
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl;
    q.pop();
    q.push(3);
    q.push(4);
    q.pop();
    cout << q.peek() << endl;
    q.empty();
    return 0;
}*/
//-----------------------------------------------------------------
//表达式求值
/*int calc(char *s, int a, int b){
    int temp = 0, pri = 10000, cur_pri = 10001, pos = -1;
    for(int i = a; i < b; i++){
        cur_pri = 10001;
        switch (s[i])
        {
        case '+':
        case '-': cur_pri = 1 + temp; break;
        case '*':
        case '/': cur_pri = 2 + temp; break;
        case '(': temp += 100;
        case ')': temp -= 100;
        default: break;
        }
        if(cur_pri < pri){
            pri = cur_pri;
            pos = i;
        }
    }
    if(pos == -1){
        int num = 0;
        for(int i = a; i <= b; i++){
            if(s[i] > '9' || s[i] < '0') continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    int front = calc(s, a, pos - 1);
    int back = calc(s, pos + 1, b);
    switch (s[pos])
    {
    case '+': return front + back;
    case '-': return front - back;
    case '/': return front / back;
    case '*': return front * back;
    default: break;
    }
    return 0;
}

int main(){
    char s[1000];
    while(scanf("%[^\n]", s)){
        getchar();
        printf("%s = %d\n", s, calc(s, 0, strlen(s) - 1));
    }
    return 0;
}*/
//-----------------------------------------------------------------
//栈的实现
/*class Stack{
public:
    Stack(){}
    void push(int val){
        data.push_back(val);
        return;
    }
    void pop(){
        if(isEmpty()) return;
        data.pop_back();
        return;
    }
    bool isEmpty(){
        return data.size() == 0;
    } 
    int size(){
        return data.size();
    }
    void output(){
        cout << "__________" << endl << endl;
        for(int i = data.size() - 1; i >= 0; i--){
            cout << "   " << data[i] << endl;
        }
        cout << "__________" << endl;
        return;
    }
    
private:
    vector<int> data;
};

int main(){
    string op;
    Stack s;
    while(cin >> op){
        if(op == "push"){
            int val = 0;
            cin >> val;
            s.push(val);
        }else if(op == "pop"){
            s.pop();
        }else if(op == "size"){
            cout << s.size() << endl;
        }else if(op == "output"){
            s.output();
        }
    }
    return 0;
}*/