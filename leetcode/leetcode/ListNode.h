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

		/// <summary>
		/// Create a linked list with default values.
		/// </summary>
		ListNode();

		/// <summary>
		/// Create a linked list and assign it with a value.
		/// </summary>
		/// <param name="val">The value to assign the node.</param>
		ListNode(int val);

		/// <summary>
		/// Create a linked list and assign it with a value and a next pointer.
		/// </summary>
		/// <param name="val">The value to assign the node.</param>
		/// <param name="node">A node to point to for the next element.</param>
		ListNode(int val, ListNode* node);
};
#endif