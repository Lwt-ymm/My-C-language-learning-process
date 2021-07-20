#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
//--------------------------------------------------------------------
//查找和最小的K对数字
template<typename T>
class Heap : public vector<T> {
public:
    template<typename Func_T>
    Heap(Func_T cmp) : cmp(cmp) {}

    void push(const T val) {
        this->push_back(val);
        push_heap(this->begin(), this->end(), cmp);
        return;
    }

    void pop() {
        this->pop_back();
        pop_heap(this->begin(), this->end(), cmp);
        return;
    }

    T top() {
        return this->at(0);
    }

private:
    function<bool(T, T)> cmp;
};

struct CMP{
    bool operator()(vector<int> a, vector<int> b) {
        return a[0] + a[1] < b[0] + b[1];
    }
}less_than;

vector<vector<int>> kSmallestPairs(vector<int> &a, vector<int> &b, int k) {
    vector<int> temp(2);
    Heap<vector<int>> h {less_than};
    for(auto x : a) {
        for(auto y : b) {
            temp[0] = x, temp[1] = y;
            if(h.size() < k || less_than(temp, h.top())) {
                h.push(temp);
                if(h.size() > k) h.pop();
            }else break;
        }
    }
    return h;
}

int main() {
    vector<int> nums1, nums2;
    nums1 = {1, 7, 11}; nums2 = {2, 4, 6};
    vector<vector<int>> ans = kSmallestPairs(nums1, nums2, 3);
    for(auto x : ans) {
        cout << '[' << x[0] << ", " << x[1] << ']';
    }
    cout << endl;
    return 0;
}
//--------------------------------------------------------------------
//堆的实现2
/*template<typename T>
class Heap : public vector<T> {
public:
    template<typename Func_T>
    Heap(Func_T cmp) : cmp(cmp) {}

    void push(const T a) {
        this->push_back(a);
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

int main() {
    Heap<int> h1 = Heap<int>(less<int>());
    Heap<int> h2 = Heap<int>(greater<int>());
    h1.push(1); h1.push(2); h1.push(3); h1.push(4);
    h2.push(1); h2.push(2); h2.push(3); h2.push(4);
    while(h1.size()) {
        cout << h1.top() << ' ';
        h1.pop();
    }
    cout << endl;
    while(h2.size()) {
        cout << h2.top() << ' ';
        h2.pop();
    }
    cout << endl;
    return 0;
}*/
//--------------------------------------------------------------------
//堆的实现
/*int heap[1000], cnt = 0;

int top() {
    return heap[0];
}

int size() {
    return cnt;
}

void output(int n) {
    cout << "heap : ";
    for(int i = 0; i < n; i++) {
        cout << heap[i] << ' ';
    }
    cout << endl;
}
 
void shiftup(int ind) {
    while(ind && heap[(ind - 1) / 2] < heap[ind]) {
        swap(heap[(ind - 1) / 2], heap[ind]);
        ind = (ind - 1) / 2;
    }
    return;
}

void shiftdown(int ind) {
    int n = cnt - 1;
    while(ind * 2 + 1 <= n) {
        int temp = ind;
        if(heap[temp] < heap[ind * 2 + 1]) temp = ind * 2 + 1;
        if(ind * 2 + 2 <= n && heap[temp] < heap[ind * 2 + 2]) temp = ind * 2 + 2;
        if(temp ==  ind) break;
        swap(heap[temp], heap[ind]);
        ind = temp;
    }
    return;
}

void push(int data) {
    heap[cnt++] = data;
    shiftup(cnt - 1);
    return;
}

void pop() {
    if(size() == 0) return;
    swap(heap[0], heap[cnt - 1]);
    cnt -= 1;
    shiftdown(0);
    return;
}

int main() {
    int max_n = 0, op, val;
    while(cin >> op) {
        switch(op) {
            case 0:
                cin >> val;
                printf("push %d to heap", val);
                push(val);
                break;
            case 1:
                pop();
                printf("pop %d from heap", top());
                break;
            case 2:
                output(max_n);
                break;
        }
        output(cnt);
        max_n = max(max_n, cnt);
    }
    return 0;
}*/