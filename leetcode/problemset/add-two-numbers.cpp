/*
* @Author: krshubham
* @Date:   2018-04-11 17:38:00
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-04-11 17:40:36
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* node1 = l1;
		while(node1->next->next != NULL){
			node1 = node1->next;
		}
		//now node1 points to the second last node of the linked list
		ListNode* node2 = l2;
		while(node2->next != NULL){
			node2 = node2->next;
		}
	}
};