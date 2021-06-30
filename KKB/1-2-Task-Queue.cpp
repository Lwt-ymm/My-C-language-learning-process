#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
//比特位记数
vector<int> countBits(int n){
	vector<int> ans(n + 1);
	ans[0] = 0;
	for(int i = 1; i <= n; i++) ans[i] = ans[i & (i - 1)] + 1;
	return ans;
}

int main(){
	vector<int> ans = countBits(5);
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++) cout << *it << ' ';
	cout << endl;
	return 0;
}
//------------------------------------------------------------------
//任务调度器
/*int leastInterval(vector<char> &tasks, int n){
	int count[26] = {0};
	for(int i = 0; i < tasks.size(); i++) count[tasks[i] - 'A'] += 1;
	sort(count, count + 26);
	int m = 0;
	for(int i = 25; i >= 0 && count[i] == count[25]; i--, m++);
	return max((int)tasks.size(), (count[25] - 1) * (n + 1) + m);
}

int main(){
	vector<char> tasks = {'A', 'A', 'A', 'A', 'A', 'A','B', 'C', 'D', 'E', 'F', 'G'};
	cout << leastInterval(tasks, 2) << endl;
	return 0;
}*/
//------------------------------------------------------------------
//煎饼排序
/*void reverse(vector<int> &arr, int k, vector<int> &index){
	for(int i = 0, j = k - 1; i < j; i++, j--){
		swap(arr[i], arr[j]);
		index[arr[i]] = i;
		index[arr[j]] = j;
	}
}
vector<int> pancakeSort(vector<int> &arr){
	vector<int> index(arr.size() + 1);
	vector<int> ret;
	for(int i = 0; i < arr.size(); i++) index[arr[i]] = i;
	for(int i = arr.size(); i > 0; i--){
		//if(index[i] == i - 1) continue;
		if(index[i] + 1 != 1){
			ret.push_back(index[i] + 1);
			reverse(arr, index[i] + 1, index);	
		}
		if(i != 1){
			ret.push_back(i);
			reverse(arr, i, index);
		}
	}
	return ret;
}

int main(){
	//vector<int> arr = {3, 2, 4, 1};
	vector<int> arr = {9, 8, 4, 1, 3 , 2, 6, 5, 7};
	vector<int> ret = pancakeSort(arr);
	for(int i = 0; i < ret.size(); i++){
		cout << ret[i] << ", ";
	}
	cout << endl;
	return 0;
}*/
//------------------------------------------------------------------
//柠檬水找零
/*bool lemonadeChange(vector<int> arr){
	if(arr[0] != 5) return false;
	int p5 = 0, p10 = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == 5) p5++;
		else if(arr[i] == 10){
			if(p5 > 0) p5--;
			else return false;
			p10++;
		}
		else if(arr[i] == 20){
			if(p10 > 0 && p5 > 0){
				p10--;
				p5--;
			}
			else if(p5 > 2) p5 -= 3;
			else return false;
		}
	}
	return true;
}

int main(){
	vector<int> bills = {5, 5, 10, 10, 20};
	cout << lemonadeChange(bills) << endl;
	return 0;
}*/
//------------------------------------------------------------------
//亲密字符串
/*bool isRepeate(string s1){
	 int cnt[26] = {0};
	 for(int i = 0; i < s1.size(); i++){
		cnt[s1[i] - 'a'] += 1;
		if(cnt[s1[i] - 'a'] == 2) return true;
	}
	return false; 
}

bool buddyStrings(string s1, string s2){
	if(s1.size() != s2.size()) return false;
	if(s1 == s2) return isRepeate(s1);
	int i = 0, j = 0;
	while(s1[i] == s2[i]) i++;
	j = i + 1;
	while(j < s1.size() && s1[j] == s2[j]) j++;
	if(j == s1.size()) return false;
	if(s1[i] != s2[j] || s1[j] != s2[i]) return false;
	for(j = j + 1; j < s1.size(); j++){
		if(s1[j] != s2[j]) return false;
	}
	return true;
} 

int main(){
	string s1 = "aaabcde";
	string s2 = "aaabedf";
	cout << buddyStrings(s1, s2) << endl;;
	return 0;
}*/
//------------------------------------------------------------------
//第K个数
/*int getKthMagicNumber(int k){
	vector<int> arr;
	arr.push_back(1);
	int p3 = 0, p5 = 0, p7 = 0;
	while(arr.size() < k){
		int ans = 3 * arr[p3];
		ans = min(ans, 5 * arr[p5]);
		ans = min(ans, 7 * arr[p7]);
		if(ans == 3 * arr[p3]) p3++;
		if(ans == 5 * arr[p5]) p5++;
		if(ans == 7 * arr[p7]) p7++;
		arr.push_back(ans);
	}
	return arr[k - 1];
}

int main(){
	cout << getKthMagicNumber(5) << endl;
	return 0;
}*/
//------------------------------------------------------------------
//返回最近请求次数
/*class RecentCounter{
public:
	queue<int> q;
	RecentCounter() {}
	int ping(int t){
		q.push(t);
		while(t - q.front() > 3000) q.pop();
		return q.size();  
	}
};

int main(){
	RecentCounter *p = new RecentCounter();
	cout << p->ping(1) << endl;;
	cout << p->ping(2) << endl;
	cout << p->ping(3001) << endl;;
	cout << p->ping(3002) << endl;;
	return 0;
}*/
//------------------------------------------------------------------
//设计前中后队列
/*class ListNode{
public:
	int value;
	ListNode *next, *per;
	ListNode(int value = 0,ListNode *next = nullptr, ListNode *per = nullptr) : value(value), next(next), per(per) {}
	void insertPer(ListNode *p){
		p->per = this->per;
		p->next = this;
		if(this->per) this->per->next = p;
		this->per = p;
		return;
	}
	void insertNext(ListNode *p){
		p->next = this->next;
		p->per = this;
		if(this->next) this->next->per = p;
		this->next = p;
		return;
	}
	void deletePer(){
		if(this->per == nullptr) return;
		ListNode *p = this->per;
		this->per = p->per;
		if(p->per) p->per->next = this;
		delete p;
		return; 
	}
	void deleteNext(){
		if(this->next == nullptr) return;
		ListNode *p = this->next;
		this->next = p->next;
		if(p->next) p->next->per = this;
		delete p;
		return; 
	}
};

class CircularDeque{
public:
	ListNode head, tail;
	int count;
	CircularDeque(){
		count = 0;
		head.per = nullptr;
		head.next = &tail;
		tail.per = &head;
		tail.next = nullptr;
	}
	void pushFront(int val){
		head.insertNext(new ListNode(val));
		count++;
		return;
	}
	void pushBack(int val){
		tail.insertPer(new ListNode(val));
		count++;
		return;
	}
	int popFront(){
		if(isEmpty()) return -1;
		int ret = head.next->value;
		head.deleteNext();
		count--;
		return ret; 
	}
	int popBack(){
		if(isEmpty()) return -1;
		int ret = tail.per->value;
		tail.deletePer();
		count--;
		return ret;
 	}
	bool isEmpty(){
		return count == 0;
	}
	void print(){
		for(ListNode *h = head.next; h != &tail; h = h->next){
			cout << h->value;
			if(h != tail.per) cout << ", "; 
		}
		return;
	}
};

class FrontMiddleBackQueue{
public:
	CircularDeque q1, q2;
	FrontMiddleBackQueue() {}
	void pushFront(int val){
		q1.pushFront(val);
		updata();
		return;
	}
	void pushMiddle(int val){
		if(q1.count > q2.count){
			q2.pushFront(q1.popBack());
		}
		q1.pushBack(val);
		return;
	}
	void pushBack(int val){
		q2.pushBack(val);
		updata();
		return;
	}
	int popFront(){
		if(isEmpty()) return -1;
		int ret = q1.popFront();
		updata();
		return ret;
	}
	int popMiddle(){
		if(isEmpty()) return -1;
		int ret = q1.popBack();
		updata();
		return ret;
	}
	int popBack(){
		if(isEmpty()) return -1;
		int ret;
		if(q2.isEmpty()) ret = q1.popBack();
		else ret = q2.popBack();
		updata();
		return ret;
	}
	bool isEmpty(){
		return q1.count == 0;
	}
	void updata(){
		if(q1.count < q2.count){
			q1.pushBack(q2.head.next->value);
			q2.popFront();
		}
		if(q1.count -1 > q2.count){
			q2.pushFront(q1.tail.next->value);
			q1 .popBack();
		}
		return;
	}
	void print(){
		if(isEmpty()) cout << "[]" <<endl;
		else{
		cout << '[';
		q1.print();
		cout << ", ";
		q2.print();
		cout << ']' <<endl;
		}
		return;
	}
};

int main(){
	FrontMiddleBackQueue *q =new FrontMiddleBackQueue();
	q->pushFront(1);
	q->pushBack(2);
	q->pushMiddle(3);
	q->pushMiddle(4);
	q->print();
	q->popFront();
	q->popMiddle();
	q->popMiddle();
	q->popBack();
	q->popFront();
	q->print();
	return 0;
}*/
//------------------------------------------------------------------
//循环双端队列
/*class MyCircularDeque{
public:	
	int count, head, tail;
	vector<int> arr;
	MyCircularDeque(int k) : arr(k), head(0), tail(0), count(0) {}
	bool insertFront(int value){
		if(isFull()) return false;
		head = (head - 1 + arr.size()) % arr.size();
		arr[head] = value;
		count++;
		return true;
	}
	bool insertLast(int value){
		if(isFull()) return false;
		arr[tail] = value;
		tail = (tail + 1) % arr.size();
		count++;
		return true;
	}
	bool deleteFront(){
		if(isEmpty()) return false;
		head = (head + 1) % arr.size();
		count--;
		return true;
	}
	bool deleteLast(){
		if(isEmpty()) return false;
		tail = (tail - 1 + arr.size()) % arr.size();
		count--;
		return true;
	}
	int getFront(){
		if(isEmpty()) return -1;
		return arr[head];
 	}
	int getRear(){
		if(isEmpty()) return -1;
		return arr[(tail - 1 + arr.size()) % arr.size()];
	}
	bool isFull(){
		return count == arr.size();
	}
	bool isEmpty(){
		return count == 0;
	}
	void print(){
		for(int i = head, j = 0; j < count; j++){
			cout << arr[i] << ' ';
			i = (i + 1) % arr.size();
		}
		cout << endl;
	}
};

int main(){
		MyCircularDeque *q = new MyCircularDeque(3);
	cout << q->isEmpty() << endl;//1
	cout << q->insertFront(1) << endl;//1
	cout << q->insertFront(2) << endl;//1
	q->print();
	cout << q->insertFront(3) << endl;//1
	cout << q->insertFront(4) << endl;//0
	q->print();
	cout << q->getRear() << endl;//1
	cout << q->isFull() << endl;//1
	cout << q->deleteFront() << endl;//1
	cout << q->deleteLast() << endl;//1
	q->print();
	cout << q->insertFront(4) << endl;//1
	q->print();
	cout << q->getFront() << endl;//4
	cout << q->getRear() << endl;//2
	return 0;
}*/
//------------------------------------------------------------------
//实现循环队列
/*class MyCircularQueue{
public:
	MyCircularQueue(int k) : arr(k), head(0), tail(0), count(0) {}
	bool isFull(){
		return count == arr.size();
	}
	bool isEmpty(){
		return count == 0;
	}
	int front(){
		if(isEmpty()) return -1;
		return arr[head];
	}
	int rear(){
		if(isEmpty()) return -1;
		return arr[(tail - 1 + arr.size()) % arr.size()];
	}
	bool enQueue(int value){
		if(isFull()) return false;
		arr[tail] = value;
		tail = (tail + 1) % arr.size();
		count++; 
		return true;
	}
	bool deQueue(){
		if(isEmpty()) return false;
		head = (head + 1) % arr.size();
		count--;
		return true;
	}
private:
	int head, tail, count;
	vector<int> arr;
};

int main(){
	MyCircularQueue *q = new MyCircleQueue(3);
	cout << q->isEmpty() << endl;
	cout << q->enQueue(1) << endl;
	cout << q->enQueue(2) << endl;
	cout << q->enQueue(3) << endl;
	cout << q->enQueue(4) << endl;
	cout << q->rear() << endl;
	cout << q->isFull() << endl;
	cout << q->deQueue() << endl;
	cout << q->enQueue(4) << endl;
	cout << q->front() << endl;
	cout << q->rear() << endl;
	return 0;
}*/
//----------------------------------------------------------------------------------------
//链表复习
//复制链表，该链表具有随即指针元素
/*struct ListNode{
	ListNode(int data) : data(data), next(nullptr), random(nullptr){}
	int data;
	ListNode *next;
	ListNode *random;
};
ListNode *copyRandomList(ListNode *head){
	if(head) return nullptr;
	ListNode *p = head, *q, *new_head;
	while(p){
		q = new ListNode(p->data);
		q->next = p->next;
		p->next =  q;
		q = p->next;	
	}
	p = head->next;
	while(p){
		if(p->random) p->random = p->random->next;
		if(p->next) p = p->next->next;//(p->next) && (p->next);
	}
	new_head = head->next;
	p = head;
	while(p){
		q = p->next;
		p->next = q->next;
		if(p->next) q->next = p->next->next;
		p = p->next; 
	}
	return new_head;
}

ostream &operator<<(ostream &cout, ListNode *l){
	int n = 0;
	if(l == nullptr){
		cout << 0;
	}
	else{
		cout << l->data;
	}
	return cout;
}

int main(){
	ListNode *l0, *l1, *l2, *l3, *l4;
	l0 = new ListNode(1);
	l1 = l0->next = new ListNode(2);
	l2 = l1->next = new ListNode(3);
	l3 = l2->next = new ListNode(4);
	l4 = l3->next = new ListNode(5);
	l0->random = l4;
	l1->random = l3;
	l2->random = l1;
	l3->random = nullptr;
	l4->random = l0;
	ListNode *head = l0;
	while(l0){
		cout << '[' << l0->data << ", " << l0->next << ", " << l0->random << ']';
		l0 = l0->next;
	}
	cout << endl;
	copyRandomList(head);
	while(head){
		cout << '[' << head->data << ", " << head->next << ", " ;
		cout << head->random << ']';
		head = head->next;
	}
	cout << endl;

	return 0;
}*/
//----------------------------------------------------------------------------------------
//按大小分割链表并尽量保持其原位置
/*struct ListNode{
	ListNode(int data) : data(data), next(nullptr){}
	int data;
	ListNode *next;
};

ListNode *partition(ListNode *head, int k){
	ListNode s(0), b(0), *p1 = &s, *p2 = &b, *q = head, *h;
	while(q){
		h = q->next;
		if(q->data < k){
			q->next = nullptr;
			p1->next = q;
			p1 = q;
		}else{
			q->next = nullptr;
			p2->next = q;
			p2 = q;
		}
		q = h;
	}
	p1->next = b.next;
	return s.next;
}

int main(){
	ListNode *head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(5);
	head->next->next->next = new ListNode(6);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(2);
	partition(head, 4);
	while(head){
		cout << head->data << "->";
		head = head->next;
	}
	cout << endl;

	return 0;
}*/
//----------------------------------------------------------------------------------------
/*
class Queue{
public:
	Queue(int n = 10) : arr(n), head(0), tail(0), count(0){}
	void push(int x){//入队
		if(full()){
			cout << "queue is full" << endl;
			return;
		}
		arr[tail] = x;
		if(tail == arr.size()) tail = 0;
		tail += 1;
		count +=1;
	}
	void pop(){//出队
		if(empty()){
			cout << "queue is empty" << endl;
			return;
		}
		if(head == arr.size()) head = 0;
		head += 1;
		count -=1;
	}
	bool full(){//判满
		return count == arr.size();
	}
	bool empty(){//判空
		return count == 0;
	}
	int front(){//查看队首元素
		if(empty()){
			cout << "queue is empty" << endl;
			return 0;
		}
		return arr[head];
	}
	int size(){//输出当前队列大小
		return count;
	}
	void output(){//遍历打印当前队列
		cout << "Queue:";
		if(empty()){
			cout << "queue is empty" << endl;
			return;
		}
		for(int i = 0, j = head; i < count; i++){
			cout << arr[j] << ' ';
			if(j == arr.size()) j = 0;
			j++;
		}
		cout << endl;
	}
private:
	int head, tail, count;
	vector<int> arr;
};

int main(){
	string op;
	int val;
	Queue q(5);
	while(cin >> op){
		if(op == "insert"){
			cin >> val;
			q.push(val);
		}else if(op == "pop"){
			q.pop();
		}else if(op == "front"){
			cout << q.front() << endl;
		}else if(op == "size"){
			cout << q.size(	) << endl;
		}
		q.output();
	}
	return 0;
}
*/
//----------------------------------------------------------------------------------------