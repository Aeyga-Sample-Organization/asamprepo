#include "Solution.h"
#include "ListNode.h"
#include <algorithm>
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

int Solution::roman_to_int(std::string s)
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

std::string Solution::longest_common_prefix(std::vector<std::string> &strs)
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

ListNode* Solution::merge_two_lists(ListNode* list1, ListNode* list2)
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
    
    ListNode* a = list1;
    ListNode* b = list2;
    ListNode* ret = new ListNode();
    ListNode* tmp = ret;

    while (a && b)
    {
        if (a->val <= b->val)
        {
            ret->next = new ListNode(a->val);
            a = a->next;
        }
        else
        {
            ret->next = new ListNode(b->val);
            b = b->next;
        }

        ret = ret->next;
    }

    if (a && !b)
    {
        ret->next = a;
    }
    else
    {
        ret->next = b;
    }
    
    ListNode* head = tmp->next;
    delete tmp;

    return head;
}

int Solution::find_needle(std::string haystack, std::string needle)
{
    // If either string is null or empty, return.
    if (haystack.empty() || needle.empty())
    {
        return -1;
    }

    int hlen = haystack.size();
    int nlen = needle.size();

    for (int i = 0; i < hlen; i++)
    {
        // If we ever find a match with the first character of needle, keep checking for matching letters.
        if (haystack[i] == needle[0])
        {
            // Check i + 1 since we already verified the ith character.
            int j = i + 1;

            while (haystack[j] == needle[j - i] && (j - i) < nlen && j < hlen)
            {
                // So long as we keep seeing matching letters and we haven't reached the end of needle, keep incrementing.
                j++;
            }

            // If j ever equals the size of needle, it means all characters match. Return i: the index of the first occurence of needle.
            if ((j - i) == nlen)
            {
                return i;
            }
            else
            {
                // Continue iterating. j will reset next iteration.
                continue;
            }
        }
    }

    return -1;
}

int Solution::remove_duplicates(std::vector<int>& nums)
{
    if (nums.empty())
    {
        return -1;
    }

    if (nums.size() == 1)
    {
        return 1;
    }

    int r = 0;
    int l = 1;

    for (l; l < nums.size(); l++)
    {
        if (nums[r] != nums[l])
        {
            r++;
            nums[r] = nums[l];
            continue;
        }
    }

    return r + 1;
}

int Solution::remove_element(std::vector<int>& nums, const int val)
{
    if (nums.empty())
    {
        return -1;
    }

    if (nums.size() == 1)
    {
        return 1;
    }

    int r = 0;
    int l = 0;

    for (r; r < nums.size(); r++)
    {
        if (nums[r] == val)
        {
            for (l = r + 1; l < nums.size(); l++)
            {
                if (nums[l] != val)
                {
                    nums[l] = nums[r];
                    break;
                }

                if (l == nums.size() - 1)
                {
                    return r + 1;
                }
            }
        }
    }

    return r + 1;
}

std::vector<int> Solution::sliding_window_max(std::vector<int>& nums, int k)
{
    std::vector<int> maximumValues = std::vector<int>();
    
    for (int i = 0; i < nums.size(); i++)
    {
        if ((k + i) > nums.size())
        {
            break;
        }
        
        int maximumVal = 0;
        
        for (int j = i; j < (k + i); j++)
        {
            maximumVal = std::max(nums[j], maximumVal);
        }

        maximumValues.push_back(maximumVal);
    }

    return maximumValues;
}
