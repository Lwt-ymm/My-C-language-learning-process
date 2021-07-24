#include<iostream>
#include<vector>
using namespace std;
//---------------------------------------------------------------------
//作业：朋友圈
class UnionSet {
public:
    UnionSet(int n) : root(vector<int>(n)) {
        for(int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    int find(int i) {
        if(root[i] == i) return i;
        return root[i] = find(root[i]);
    }

    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if(fa == fb) return;
        root[fa] = fb;
        return;
    }
private:
    vector<int> root;
};

int main() {
    int a, b, c;
    cin >> a >> b;
    UnionSet u(a);
    int sum = b;
    while(cin >> a >> b >> c) {
        if(a == 1) {
            u.merge(b, c);
        }else {
            if(u.find(b) == u.find(c)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        if(--sum == 0) break; 
    }
    return 0;
}
//---------------------------------------------------------------------
//冗余连接II
// class UnionSet {
// public:
//     UnionSet(int n) : root(vector<int>(n)) {
//         for(int i = 0; i < n; i++) {
//             root[i] = i;
//         }
//     }
    
//     int find(int i) {
//         if(root[i] == i) return i;
//         return root[i] = find(root[i]);
//     }

//     void merge(int a, int b) {
//         int fa = find(a), fb = find(b);
//         if(fa == fb) return;
//         root[fb] = fa;
//         return;
//     }
// private:
//     vector<int> root;
// };

// vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
//     UnionSet u(edges.size());
//     vector<int> ans;
//     for(auto x : edges) {
//         int a = x[0], b = x[1];
//         if(u.find(a) != u.find(b)) u.merge(a, b);
//         else ans = x;
//     }
//     return ans;
// }

// int main() {
//     vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}},
//     edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1,5}};
//     vector<int> temp1 = findRedundantDirectedConnection(edges1);
//     vector<int> temp2 = findRedundantDirectedConnection(edges2);
//     printf("[%d, %d]\n", temp1[0], temp1[1]);
//     printf("[%d, %d]\n", temp2[0], temp2[1]);
//     return 0;
// }
//---------------------------------------------------------------------
//情侣牵手
// class UnionSet {
// public:
//     UnionSet(int n) : root(vector<int>(n)) {
//         for(int i = 0; i < root.size(); i++) {
//             if(i % 2 == 1) root[i] = i - 1;
//             else root[i] = i;
//         }
//     }

//     int find(int i) {
//         if(root[i] == i) return i;
//         return i - 1;
//     }

// private:
//     vector<int> root;
// };

// int minSwapsCouples(vector<int> &row) {
//     UnionSet u(row.size());
//     int ans = 0;
//     for(int i = 0; i < row.size() - 1; i += 2) {
//         int a = row[i], b = row[i + 1];
//         if(u.find(a) != u.find(b)) {
//             for(int j = i + 2; j < row.size(); j++) {
//                 if(u.find(a) == u.find(row[j])) {
//                     swap(row[i + 1], row[j]);
//                     ans++;
//                     break;
//                 }
//             }
//         }
//     }
//     return ans;
// }

// int main() {
//     vector<int> row = {0, 2, 1, 3};
//     cout << minSwapsCouples(row) << endl;
//     return 0;
// }