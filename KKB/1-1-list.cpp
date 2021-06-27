#include<iostream>

struct Node
{
	Node(int data) : data(data), next(NULL){};
	int data;
	Node *next;
};
//打印链表
void print(Node *head)
{
	if(head == nullptr)
	{
		printf("\n");
		return;
	}
	printf("%d->", head->data);
	print(head->next);
}
//反转链表（倒序打印）递归
void reverse(Node *head)
{
	if(head == nullptr ) return;
	reverse(head->next);
	printf("%d->", head->data);
	return;
}
//反转链表的n个元素 递归
Node *reverseN(Node *head, int n)
{
	if(n == 1) return head;
	Node *tail = head->next, *p = reverseN(head->next, n - 1);
	head->next = tail->next;
	tail->next = head;
	return p;
}
//反转链表第m和第n个元素之间的元素
Node *reverseBetween(Node *head, int m, int n)
{
	Node *ret = new Node(0);
	ret->next = head;
	int count = n - m + 1;
	while(--m) ret = ret->next;
	ret->next = reverseN(ret->next, count);
	return head;
}
//判断剩余元素是否足够反转一组
Node *ifcanreverseG(Node *head, int n)
{
	Node *p = head;
	int count = n;
	while((p = p->next) && --count);
	if(p == nullptr) return head;
	return reverseN(head, n);
}
//按组反转链表，组内反转，不足一组不做变化
Node *reverseG(Node *head, int k)
{
	Node *per = new Node(0), *q = per->next = head, *newhead = head;
	int n = 1;
	while((per->next = ifcanreverseG(q, k)) != q)
	{
		if(n--) newhead = per->next;
		per = q;  
		q = per->next;
	}
	return newhead;
}
//旋转链表（右移K个节点）
Node *rotateList(Node *head, int k)
{
	if(head == nullptr) return nullptr;
	int n = 1;
	Node *p = head;
	while(p->next) p = p->next, n++;
	p->next = head;
	k %= n;
	k = n - k;
	while(k--) p = p->next;
	head = p->next;
	p->next = nullptr;
	return head;
}
//删除倒数第n个节点
void removeNthFromEnd(Node *head, int n)
{
	Node *p =head, *q = head;
	n += 1;
	while(n--) q = q->next;
	while(q) p = p->next, q = q->next;
	p->next = p->next->next; 
}
//删除链表重复多余的节点（有序）
Node *deleteDuplicate(Node *head)
{
	if(head == nullptr) return nullptr;
	Node *p = head;
	while(p->next)
	{
		if(p->data == p->next->data)
			p->next = p->next->next;
		else
			p = p->next;
	}
	return head;
}
//删除链表重复的所有节点（有序）
Node *deleteDuplicates(Node *head)
{
	Node *p = new Node(0), *q, *h = p;
	p->next =head;
	while(p->next->next)
	{
		if(p->next->data == p->next->next->data)
		{
			q = p->next->next;
			while(q && q->data == q->next->data) q = q->next;
			p->next = q->next;
		}
		else
			p = p->next;
	}
	return h->next;
}
//判断链表是否有环
bool hasCycle(Node *head)
{
	if(head == NULL)
		return false;
	Node *p = head, *q = head->next;
	while(p != q && q && q->next)
	{
		p = p->next;
		q = q->next->next;
	}
	return q && q->next;
}
//计算各位数的平方和
int squareSum(int i)
{
	int sum = 0, j = i;
	do{
		sum += (j%10) * (j%10);
		if(j < 10)
			break;
	}while(j /= 10);
	return sum;
}
int main()
{
	Node *head = new Node(1);
	head->next = new Node(1);
	head->next->next = new Node(2);
	head->next->next->next = new Node(3);
	head->next->next->next->next = new Node(4);
	head->next->next->next->next->next = new Node(4);
	head->next->next->next->next->next->next = new Node(5);
	
	//head = reverseN(head, 2);
	
	//reverseBetween(head, 2, 4);

	//head = reverseG(head, 3);
	
	//head = rotateList(head,2);
	
	//removeNthFromEnd(head, 2);
	
	//deleteDuplicates(head);

	//head = deleteDuplicates(head);
	
	//print(head);
	
	/*
	bool val = hasCycle(head);
	if(val == true)
		printf("有环\n");
	else
		printf("无环\n");
	*/

	//彩蛋作业：十万以内快乐数总和
	//非快乐数最后会进入4->16->37->58->89->145->42->20->4的循环
	int S = 0;
	for(int i = 1; i <= 100000; i++)
	{
		int j = i;
		int sum = squareSum(j);
		while(sum != 1 && sum != 4)
			sum = squareSum(sum);
		if(sum == 1)
			S += j;
	}
	printf("%d\n", S);

	return 0;
}
