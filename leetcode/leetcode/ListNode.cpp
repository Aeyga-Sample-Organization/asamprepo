#include "ListNode.h"

ListNode::ListNode()
{
	this->val = 0;
	this->next = nullptr;
}

ListNode::ListNode(int val)
{
	this->val = val;
	this->next = nullptr;
}

ListNode::ListNode(int val, ListNode* node)
{
	this->val = val;
	this->next = node;
}