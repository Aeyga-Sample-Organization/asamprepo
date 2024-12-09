#include "Solution.h"
#include "ListNode.h"
#include <unordered_map>
#include <string>

std::vector<int> Solution::two_sum(std::vector<int>& nums, int target)
{
    for (size_t i = 0; i < nums.size(); i++)
    {
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (j == i)
            {
                continue;
            }

            if (nums[i] + nums[j] == target)
            {
                return std::vector<int> { (int)i, (int)j };
            }
        }
    }

    return std::vector<int> { 0, 0};
}

std::vector<int> Solution::efficient_two_sum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> idxMap = std::unordered_map<int, int>();

    for (int i = 0; i < nums.size(); i++)
    {
        // Check target - nums[i] is in the map. If not, add it. If so, return both indices.
        if (idxMap.count(target - nums[i]) > 0)
        {
            // We found the missing number.
            return std::vector<int> { i, idxMap[target - nums[i]]};
        }
        else
        {
            // Add the current element to the table.
            idxMap.emplace(nums[i], i);
        }
    }
    return std::vector<int> { 0, 0 };
}

bool Solution::is_palindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    unsigned int rev = 0;
    int n = x;

    while (n != 0)
    {
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }

    if (rev == x)
    {
        return true;
    }

    return false;
}

int Solution::romanToInt(std::string s)
{
    if (s.empty())
    {
        return 0;
    }

    int retVal = 0;

    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
            case 'I':
                if (i < s.size() - 1 && s[i + 1] == 'V')
                {
                    retVal += 4;
                    i++;
                }
                else if (i < s.size() - 1 && s[i + 1] == 'X')
                {
                    retVal += 9;
                    i++;
                }
                else
                {
                    retVal += 1;
                }
                break;
            case 'V':
                retVal += 5;
                break;
            case 'X':
                if (i < s.size() - 1 && s[i + 1] == 'L')
                {
                    retVal += 40;
                    i++;
                }
                else if (i < s.size() - 1 && s[i + 1] == 'C')
                {
                    retVal += 90;
                    i++;
                }
                else
                {
                    retVal += 10;
                }
                break;
            case 'L':
                retVal += 50;
                break;
            case 'C':
                if (i < s.size() - 1 && s[i + 1] == 'D')
                {
                    retVal += 400;
                    i++;
                }
                else if (i < s.size() - 1 && s[i + 1] == 'M')
                {
                    retVal += 900;
                    i++;
                }
                else
                {
                    retVal += 100;
                }
                break;
            case 'D':
                retVal += 500;
                break;
            case 'M':
                retVal += 1000;
                break;
        }
    }

    return retVal;
}

std::string Solution::longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string result = "";

    if (strs.empty())
    {
        return result;
    }

    // Determine the smallest string in the list.
    int minStrLen = strs[0].size();
    // Index of the smallest string.
    int idx = 0;

    for (int i = 1; i < strs.size(); i++)
    {
        if (strs[i].size() < minStrLen)
        {
            minStrLen = strs[i].size();
            idx = i;
        }
    }

    // Now that we have the size of the smallest string, check the list of strings.
    for (int i = 0; i < minStrLen; i++)
    {
        for (std::string s : strs)
        {
            if (s[i] != strs[idx][i])
            {
                return result;
            }
        }

        result += strs[idx][i];
    }

    return result;
}

std::string Solution::lcp_optimized(std::vector<std::string>& strs)
{
    std::string result = "";

    if (strs.empty())
    {
        return result;
    }

    // Find the smallest string.
    // Index of the smallest string.
    int idx = 0;
    // Length of the smallest string.
    int minStrLen = strs[0].size();

    // Iterate through the list to find the index and length of the smallest string.
    for (int i = 0; i < strs.size(); i++)
    {
        // If the current string is smaller than the previous smallest, update the length and index.
        if (minStrLen > strs[i].size())
        {
            minStrLen = strs[i].size();
            idx = i;
        }
    }

    // Found the smallest string, now start searching for the smallest common prefix.
    result = strs[idx];

    // Iterate over all strings in the list.
    for (int i = 0; i < strs.size(); i++)
    {
        int j = 0;

        // Iterate over all letters of all strings. Update the index only if:
        //      1.  'j' is within bounds of the default prefix length.
        //      2.  'j' is within bounds of the other string's length.
        //      3.  The letter at position 'j' is the same as the letter at the current position in the other strings.
        while (j < result.size() && j < strs[i].size() && result[j] == strs[i][j])
        {
            j++;
        }

        // Get the substring from 0 - j (j could have changed).
        result = result.substr(0, j);

        // The result could be empty after the last step, which means there isn't a common substring. Return it.
        if (result.empty())
        {
            return "";
        }
    }

    return result;
}

ListNode* Solution::mergeTwoLists(ListNode* list1, ListNode* list2)
{
    // Validate inputs.
    if (!list1 && !list2)
    {
        return nullptr;
    }
    else if (!list1 && list2)
    {
        return list2;
    }
    else if (list1 && !list2)
    {
        return list1;
    }

    ListNode* ret = new ListNode();
    ListNode* head = ret;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            ret->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            ret->next = new ListNode(list2->val);
            list2 = list2->next;
        }

        ret = ret->next;
    }

    if (list1 && !list2)
    {
        ret->next = list1;
    }
    else if (list2 && !list1)
    {
        ret->next = list2;
    }

    return head->next;
}