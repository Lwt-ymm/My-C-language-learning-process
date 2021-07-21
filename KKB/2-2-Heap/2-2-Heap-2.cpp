#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<fstream>
using namespace std;

template<typename T>
class Heap : public vector<T> {
public:
    template<typename Fun_T>
    Heap(Fun_T cmp) : cmp(cmp) {}

    void push(const T val) {
        this->push_back(val);
        push_heap(this->begin(), this->end(), cmp);
        return;
    }

    void pop() {
        pop_heap(this->begin(), this->end(), cmp);
        this->pop_back();
        return;
    }

    T top() {
        return this->at(0);
    }
private:
    function<bool(T, T)> cmp;
};
//---------------------------------------------------------------------------
//作业：
vector<int> sixSmallestNumbers(string filename, int k) {
    ifstream ifs(filename, ios::in);
    if(!ifs.is_open()) {
        cout << "文件打开失败！" << endl;
        return vector<int>();
    }
    Heap<int> nums{less<int>()};
    string temp;
    while(ifs >> temp) {
        nums.push(atoi(temp.c_str()));
    }
    int a, b;
    while(nums.size() >= k) {
        a = nums.top(); nums.pop();
        b = nums.top(); nums.pop();
        if(a == b) continue;
        else nums.push(a - b);
    }
    sort(nums.begin(), nums.end(), less<int>());
    ifs.close();
    return nums;
}

int main() {
    vector<int> ans = sixSmallestNumbers("【第六周】堆与优先队列-彩蛋数据.txt", 6);
    for(auto x : ans) cout << x << ' ';
    cout << endl;
    return 0;
}

// int main() {
//     ifstream ifs("【第六周】堆与优先队列-彩蛋数据.txt", ios::in);
//     if(!ifs.is_open()) {
//         cout << "文件打开失败！" << endl;
//         return 0;
//     }
//     string v;
//     int i = 0;
//     while(ifs >> v) {
//         cout << i++ << " &&&&  " << v << endl;
//     }
//     cout << v << endl;
//     ifs.close();
// }

//---------------------------------------------------------------------------
//积压订单的总数
/*struct CMP1 {
    bool operator()(vector<int> a, vector<int> b) {return a[0] < b[0];}
};

struct CMP2 {
    bool operator()(vector<int> a, vector<int> b) {return a[0] > b[0];}
};

int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    Heap<vector<int>> buy{CMP1()}, sell{CMP2()};
    for(auto x : orders) {
        if(x[2] == 0) {
            while(x[1] != 0 && sell.size() && sell[0][0] <= x[0]) {
                int cnt = min(x[1], sell[0][1]);
                x[1] -= cnt; sell[0][1] -= cnt;
                if(sell[0][1] == 0) sell.pop();
            }
            if(x[1] != 0) buy.push(x);
        }else {
            while(x[1] != 0 && buy.size() && buy[0][0] <= x[0]) {
                int cnt = min(x[1], buy[0][1]);
                x[1] -= cnt; buy[0][1] -= cnt;
                if(buy[0][1] == 0) buy.pop();
            }
            if(x[1] != 0) sell.push(x);
        }
    }
    int sum = 0;
    for(auto x : buy) sum += x[1];
    for(auto x : sell) sum += x[1];
    return sum;
}
int main() {
    vector<vector<int>> orders = {{10, 5, 0}, {15, 2, 1}, {25, 1, 1}, {30, 4, 0}};
    cout << getNumberOfBacklogOrders(orders) << endl;
    return 0;
}*/
//---------------------------------------------------------------------------
//超级丑数
/*int nthSuperUglyNumber(vector<int> &v, int n) {
    vector<int> p(v.size());
    vector<int> data = {1};
    int ans = 1;
    while(data.size() != n) {
        ans = v[0] * data[p[0]];
        for(int i = 0; i < v.size(); i++) ans = min(ans, v[i] * data[p[i]]);
        for(int i = 0; i < v.size(); i++) if(v[i] * data[p[i]] == ans) p[i]++;
        data.push_back(ans);
    }
    return ans;
}

int main() {
    vector<int> primes = {2, 7, 13, 19};
    cout << nthSuperUglyNumber(primes, 12) << endl;
    return 0;
}*/
//---------------------------------------------------------------------------
//数据流中的中位数
/*class MedianFinder{
public:
    MedianFinder() : h1{less<int>()}, h2{greater<int>()} {}

    void addNum(int num) {
        if(h1.size() == 0 || num > h1.top()) h1.push(num);
        else h2.push(num);
        if(h1.size() < h2.size()) {
            h1.push(h2.top());
            h2.pop();
        }
        if(h1.size() == h2.size() + 2) {
            h2.push(h1.top());
            h1.pop();
        }
        return;
    }

    double findMedian() {
        if(h1.size() == h2.size()) return (h1.top() + h2.top()) / 2.0;
        else return h1.top();
    }
private:
    Heap<int> h1, h2;
};

int main() {
    MedianFinder nums;
    int op;
    while(cin >> op) {
        switch (op)
        {
        case 0:
            int num;
            cin >> num;
            nums.addNum(num);
            break;
        case 1:
            cout << nums.findMedian() << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}*/
//---------------------------------------------------------------------------
/*vector<string> topKFrequent(vector<string> v, int k) {
    map<string, int> freq;
    for(auto x : v) freq[x] += 1;
    auto cmp = [&freq](string a, string b){
        if(freq[a] != freq[b]) return freq[a] > freq[b];
        return a < b;
    };
    Heap<string> ans(cmp);
    for(auto x : freq) {
        if(ans.size() < k || freq[ans.top()] < x.second) ans.push(x.first);
        if(ans.size() > k) ans.pop();
    }
    return ans;
}

int main() {
    vector<string> v = {"i", "love", "leetcode", "i", "love", "coding"};
    for(auto x : topKFrequent(v, 2)) {
        cout << "\"" << x << "\"" << ' ';
    }
    cout << endl;
    return 0;
}*/