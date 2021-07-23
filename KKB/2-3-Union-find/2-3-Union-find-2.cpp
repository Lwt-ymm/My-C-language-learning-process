#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

//---------------------------------------------------------------------------
//帐户合并
class UnionSet {
public:
    UnionSet(int n) : n(n) {
        root = new int[n];
        for(int i = 0; i < n; i++) root[i] = i;
    }

    int get(int x) {
        if(root[x] == x) return x;
        return root[x] = get(root[x]);
    }

    void merge(int a, int b) {
        int ra = get(a), rb = get(b);
        if(ra == rb) return;
        root[ra] = rb;
        return;
    }
private:
    int *root;
    int n;
};


vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    UnionSet u(accounts.size());
    unordered_map<string, int> email_id;
    for(int i = 0; i < accounts.size(); i++) {
        vector<string> x = accounts[i];
        for(int j = 1; j < x.size(); j++) {
            if(email_id.find(x[j]) != email_id.end() && u.get(i) != u.get(email_id[x[j]])) {
                u.merge(i, email_id[x[j]]);
            }
            email_id[x[j]] = i;
        }
    }
    vector<vector<string>> ans;
    unordered_map<int, vector<string>> id_emails;
    for(auto x : email_id) {
        id_emails[u.get(x.second)].push_back(x.first); 

    }
    for(auto x : id_emails) {
        vector<string> temp = {accounts[x.first][0]};
        sort(x.second.begin(), x.second.end());
        temp.insert(temp.end(), x.second.begin(), x.second.end());
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    vector<vector<string>> accounts = {{"John", "johnnybravo@mail.com"}, 
    {"John", "johnsmith@mail.com", "john00@mail.com"}, 
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
    {"Mary", "mary@mail.com"}};
    for(auto x : accountsMerge(accounts)) {
        for(int i = 0; i < x.size(); i++) {
            cout << x[i] << ", ";
        }
        cout << endl;
    }
    return 0;   
}
//---------------------------------------------------------------------------
//交换字符串中的元素
// class UnionSet {
// public:
//     UnionSet(int n) : n(n) {
//         root = new int[n];
//         for(int i = 0; i < n; i++) root[i] = i;
//     }

//     int get(int x) {
//         if(root[x] == x) return x;
//         return root[x] = get(root[x]);
//     }

//     void merge(int a, int b) {
//         int ra = get(a), rb = get(b);
//         if(ra == rb) return;
//         root[ra] = rb;
//         return;
//     }
// private:
//     int *root;
//     int n;
// };

// string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
//     UnionSet u(s.size());
//     priority_queue<char, vector<char>, greater<char>> h[s.size()];
//     for(auto x : pairs) {
//         int a = x[0], b = x[1];
//         u.merge(a, b);
//     }
//     for(int i = 0; i < s.size(); i++) {
//         h[u.get(i)].push(s[i]); 
//     }
//     string ans;
//     for(int i = 0; i < s.size(); i++) {
//         ans += h[u.get(i)].top();
//         h[u.get(i)].pop();
//     }
//     return ans;
// }

// int main() {
//     string s = "dcab";
//     vector<vector<int>> pairs = {{0, 3}, {1, 2}, {0, 2}};
//     cout << smallestStringWithSwaps(s, pairs) << endl;
//     return 0;
// }
//---------------------------------------------------------------------------
//移除最多同行同列石头
// class UnionSet {
// public:
//     UnionSet(int n) : n(n) {
//         root = new int[n];
//         for(int i = 0; i < n; i++) root[i] = i;
//     }

//     int get(int x) {
//         if(root[x] == x) return x;
//         return root[x] = get(root[x]);
//     }

//     void merge(int a, int b) {
//         int ra = get(a), rb = get(b);
//         if(ra == rb) return;
//         root[ra] = rb;
//         return;
//     }
// private:
//     int *root, n;
// };

// int removeStones(vector<vector<int>> &stones) {
//     UnionSet u(stones.size());
//     unordered_map<int, int> indx, indy;
//     int ans = 0;
//     for(int i = 0; i < stones.size(); i++) {
//         int x = stones[i][0], y = stones[i][1];
//         if(indx.find(x) != indx.end()) u.merge(i, indx[x]);
//         if(indx.find(y) != indx.end()) u.merge(i, indy[y]);
//         indx[x] = i, indy[y] = i;
//     }
//     for(int i = 0; i < stones.size(); i++) {
//         if(u.get(i) == i) ans++;
//     }
//     return stones.size() - ans;
// }

// int main() {
//     vector<vector<int>> stones = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
//     cout << removeStones(stones) << endl;
//     return 0;
// }