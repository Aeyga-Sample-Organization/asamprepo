#pragma once
#include "ListNode.h"

/// <summary>
/// Contains functions that can be used to perform miscellaneous tasks.
/// </summary>
class GlobalFunctions
{
    public:
        /// <summary>
        /// Create a new linked list using values from the given array.
        /// </summary>
        /// <param name="node">: The head of the linked list.</param>
        /// <param name="values">: The values to assign to each node in the new list.</param>
        /// <param name="len">: The number of elements in the array.</param>
        static void create_list(ListNode* node, int values[], int len)
        {
            for (int i = 0; i < len; i++)
            {
                node->val = values[i];

                if (i != len - 1)
                {
                    node->next = new ListNode();
                }

                node = node->next;
            }
        }

        /// <summary>
        /// Delete all nodes in a given linked list.
        /// </summary>
        /// <param name="node">: The head of a linked list.</param>
        static void destroy_list(ListNode* node)
        {
            if (!node)
            {
                return;
            }

            while (node)
            {
                ListNode* temp = node->next;
                delete node;
                node = temp;
            }
        }

        /// <summary>
        /// Check if each node in list a has the same values as each node in list b.
        /// </summary>
        /// <param name="a">: The first list to compare.</param>
        /// <param name="b">: The second list to compare.</param>
        /// <returns>Returns true if both lists have equal values for all nodes. False otherwise.</returns>
        static bool validate_list_equivalence(ListNode* a, ListNode* b)
        {
            if (!a || !b)
            {
                return false;
            }

            while (a && b)
            {
                if (a->val != b->val)
                {
                    return false;
                }
                a = a->next;
                b = b->next;
            }

            return true;
        }
};