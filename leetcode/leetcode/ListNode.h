#pragma once
#ifndef LISTNODE_H
#define LISTNODE_H

/// <summary>
/// Defines a singly linked list node.
/// </summary>
struct ListNode
{
	public:
		/// <summary>
		/// The value of the node.
		/// </summary>
		int val;

		/// <summary>
		/// Pointer to the next node in the linked list.
		/// </summary>
		ListNode* next;

		ListNode();
		ListNode(int val);
		ListNode(int val, ListNode* node);
};
#endif
