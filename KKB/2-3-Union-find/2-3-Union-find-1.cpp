#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//---------------------------------------------------------
//最长连续序列
class UnionSet {
public:
    int *root, *size, n;

    UnionSet(int n) : n(n) {
        root = new int[n + 1]; size = new int[n + 1];
        for(int i = 0; i <= n; i++) root[i] = i, size[i] = 1;
    }

    int get(int x) {return root[x] = (root[x] == x ? x : get(root[x]));}

    void merge(int a, int b) {
        int fa = get(a), fb = get(b);
        if(fa == fb) return;
        size[fb] += size[fa];
        root[fa] = fb;
        //cout << a << ' ' << b << endl;
        return;
    }
};

int longestConsecutive(vector<int> &nums) {
    int ans = 0;
    unordered_map<int, int> ind;
    UnionSet u(nums.size());
    for(int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        if(ind.find(x) != ind.end()) continue;
        if(ind.find(x - 1) != ind.end()) u.merge(i, ind[x - 1]);
        if(ind.find(x + 1) != ind.end()) u.merge(i, ind[x + 1]);
        ind[x] = i;
    }
    for(int i = 0; i < nums.size(); i++) {
        if(u.get(i) == i && u.size[i] > ans) ans = u.size[i];
    }
    return ans;
}

int main() {
    vector<int> v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(v) << endl;
    return 0;
}
//---------------------------------------------------------
//带路径压缩的并查集模板
// class UnionSet {
//     int *root, n;

//     UnionSet(int n) : n(n) {
//         root = new int[n + 1];
//         for(int i = 0; i <= n; i++) root[i] = i;
//     }

//     int get(int i) {return root[i] = (root[i] == i ? i : get(root[i]));}

//     void merge(int a, int b) {root[get(a)] = get(b);}
// };
//---------------------------------------------------------
//并查集Weighted-Quick-Union-Pathcompression算法
// class UnionSet {
// public:
//     int *boss, *size, n;

//     UnionSet(int n) : n(n) {
//         boss = new int[n + 1];
//         size = new int[n + 1];
//         for(int i = 0; i <= n; i++) boss[i] = i, size[i] = i;
//     } 

//     int find(int i) {
//         if(boss[i] == i) return i;
//         int root = find(boss[i]);
//         boss[i] = root;
//         return root;
//     }

//     void merge(int a, int b) {
//         int fa = find(a), fb = find(b);
//         if(fa == fb) return;
//         if(size[fa] > size[fb]) {
//             boss[fb] = fa;
//             size[fa] += size[fb];
//         }else{
//             boss[fa] = fb;
//             size[fb] += size[fa];
//         }
//     }
// };
//---------------------------------------------------------
//并查集Weighted-Quick-Union算法
// class UnionSet {
// public:
//     int *boss, *size, n;

//     UnionSet(int n) : n(n) {
//         boss = new int[n + 1];
//         size = new int[n + 1];
//         for(int i = 0; i <= n; i++) boss[i] = i, size[i] = i; 
//     }

//     int find(int i) {
//         if(boss[i] == i) return i;
//         return find(boss[i]);
//     }

//     void merge(int a, int b) {
//         int fa = find(a), fb = find(b);
//         if(fa == fb) return;
//         if(size[fa] > size[fb]) {
//             boss[fb] = fa;
//             size[fa] += size[fb];
//         }else {
//             boss[fa] = fb;
//             size[fb] += size[fa];
//         }
//         return;
//     }
// };
//---------------------------------------------------------
//并查集Quick-Union算法
// class UnionSet {
// public:
//     int *boss, n;

//     UnionSet(int n) : n(n) {
//         boss = new int[n + 1];
//         for(int i = 0; i <= n; i++) boss[i] = i;
//     }

//     int find(int i) {
//         if(boss[i] == i) return boss[i];
//         return find(boss[i]);
//     }

//     void merge(int a, int b) {
//         int fa = find(a), fb = find(b);
//         if(fa == fb) return;
//         boss[fa] = fb;
//         return;
//     }
// };
//---------------------------------------------------------
//并查集Quick-Find算法
// class UnionSet {
// public:
//     int *color, n;

//     UnionSet(int n) : n(n) {
//         color = new int[n + 1];
//         for(int i = 0; i <= n; i++) color[i] = i;
//     }

//     int find(int i) {
//         return color[i];
//     }

//     void merge(int a, int b) {
//         int cb = color[b];
//         for(int i = 0; i <= n; i++) {
//             if(color[i] == cb) color[i] = color[a];
//         }
//         return;
//     }
// };
