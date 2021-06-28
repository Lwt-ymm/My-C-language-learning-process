#include<iostream>
#include<vector>
#include<string>
using namespace std;

//链表复习
//复制链表，该链表具有随即指针元素
struct ListNode{
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
}

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
