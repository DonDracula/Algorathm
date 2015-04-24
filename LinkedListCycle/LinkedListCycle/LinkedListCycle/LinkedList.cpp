#include<stdio.h>

//This program is to determine if a given linked list has a cycle in it
//then calculate the cycle's length if it does
//and return the node where the cycle begins,if there is no cycle, return NULL
typedef struct  Node
{
	int val;
	 Node  *next;
}Node,*ListNode;

//check if there is a cycle
/*
 当fast与slow相遇时，show肯定没有走完链表，而fast已经在环里走了n（n>= 1）圈。设slow走了s步，那么fast走了2s步。fast的步数还等于s走的加上环里转的n圈，
 所以：2s = s + nr。因此，s = nr。
*/
bool hasCycle(ListNode lHead)
{
	ListNode fast= lHead;
	ListNode slow =lHead;
	//if the cycle doesn't exist, the "fast" will come to the end earier
	//if the length is odd, "fast->next" will be a NULL
	//if it is even number,the "fast" will be null
	while (fast !=NULL &&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow =slow->next;
		//it ther is a cycle ,"fast" will run over a lap than "slow"
		if(fast =slow)
			break;
	}

	if(fast==NULL||fast->next ==NULL)
		return false;
	else 
		return true;
}
//calculate the length
int calCycleLength(ListNode lHead)
{
	if(hasCycle(lHead) == false)
		return 0;
	ListNode fast = lHead;
	ListNode slow =lHead;
	int length =0;
	bool begin =false;
	bool twice = false;
	while (fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow =slow->next;
		//after over two laps,break
		if(fast == slow && twice ==true)
			break;
		//at the first over lap time, start counting
		if(fast==slow &&twice == false)
		{
		begin =true;
		twice =true;
		}

		if(begin ==true)
			++length;
	}
}
// find the entrance of the cycle
/*
设整个链表长为L，入口据相遇点X，起点到入口的距离为a。因为slow指针并没有走完一圈，所以：
a + x = s，带入第一步的结果，有：a + x = nr = (n-1)r + r = (n-1)r + L - a；即：
a = (n-1)r + L -a -x;
这说明：从头结点到入口的距离，等于转了(n-1)圈以后，相遇点到入口的距离。因此，我们可以在链表头、相遇点各设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
*/
Node* findCycleEntrance(ListNode lHead)
{
	ListNode fast = lHead;
	ListNode slow = lHead;

	while(fast!=NULL&&fast->next!=NULL)
	{
		fast =fast->next->next;
		slow=slow->next;
		//if cycle exist, "fast" will run over a lap than "slow"
		if(fast == slow )
			break;
	}
	if(fast!=NULL&&fast->next!=NULL)
		return NULL;
	slow =lHead;
	while (slow !=fast)
	{
		slow =slow->next;
		fast =fast->next;
	}

	return slow;
}
