#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include "Solution.h"
#include "ListNode.h"

static void create_list(ListNode* node, int values[], int len);
static bool validate_list_equivalence(ListNode* a, ListNode* b);

int main()
{
    std::vector<int> numArr = { 2, 7, 11, 15 };
    int target = 9;

    Solution sol = Solution();
    std::vector<int> idx = sol.efficient_two_sum(numArr, target);

    assert(numArr[idx[0]] + numArr[idx[1]] == target);

    assert(sol.is_palindrome(23) == false);
    assert(sol.is_palindrome(121) == true);

    assert(sol.romanToInt("III") == 3);
    assert(sol.romanToInt("LVIII") == 58);

    std::vector<std::string> strs = std::vector<std::string> { "flower", "flow", "flight" };
    std::vector<std::string> strs2 = std::vector<std::string>{ "dog","racecar","car" };

    assert(sol.longestCommonPrefix(strs) == "fl");
    assert(sol.longestCommonPrefix(strs2) == "");

    assert(sol.lcp_optimized(strs) == "fl");
    assert(sol.lcp_optimized(strs2) == "");

    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    ListNode* ans = new ListNode();

    int val1[] = { 1, 2, 4 };
    int val2[] = { 1, 3, 4 };
    int val3[] = { 1, 1, 2, 3, 4, 4 };

    create_list(list1, val1, 3);
    create_list(list2, val2, 3);
    create_list(ans, val3, 6);

    assert(validate_list_equivalence(sol.mergeTwoLists(list1, list2), ans));

    delete list1;
    delete list2;

    return 0;
}

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