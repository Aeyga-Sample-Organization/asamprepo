#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include "Solution.h"
#include "ListNode.h"
#include "GlobalFunctions.h"

int main()
{
    std::vector<int> numArr = { 2, 7, 11, 15 };
    int target = 9;

    std::vector<int> numIndices = Solution::efficient_two_sum(numArr, target);

    assert(numArr[numIndices[0]] + numArr[numIndices[1]] == target);

    assert(Solution::is_palindrome(23) == false);
    assert(Solution::is_palindrome(121) == true);

    assert(Solution::roman_to_int("III") == 3);
    assert(Solution::roman_to_int("LVIII") == 58);

    std::vector<std::string> strs = std::vector<std::string> { "flower", "flow", "flight" };
    std::vector<std::string> strs2 = std::vector<std::string>{ "dog","racecar","car" };

    assert(Solution::longest_common_prefix(strs) == "fl");
    assert(Solution::longest_common_prefix(strs2) == "");

    assert(Solution::lcp_optimized(strs) == "fl");
    assert(Solution::lcp_optimized(strs2) == "");

    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    ListNode* ans = new ListNode();

    int val1[] = { 1, 2, 4 };
    int val2[] = { 1, 3, 4 };
    int val3[] = { 1, 1, 2, 3, 4, 4 };

    GlobalFunctions::create_list(list1, val1, 3);
    GlobalFunctions::create_list(list2, val2, 3);
    GlobalFunctions::create_list(ans, val3, 6);

    assert(GlobalFunctions::validate_list_equivalence(Solution::merge_two_lists(list1, list2), ans));

    GlobalFunctions::destroy_list(list1);
    GlobalFunctions::destroy_list(list2);
    GlobalFunctions::destroy_list(ans);

    assert(Solution::find_needle("sadbutsad", "sad") == 0);
    assert(Solution::find_needle("leetcode", "leeto") == -1);
    assert(Solution::find_needle("hello", "ll") == 2);

    std::vector<int> nums = {0 ,0, 1, 1, 1, 2, 2, 3, 3, 4};
    assert(Solution::remove_duplicates(nums) == 5);

    // nums = { 0, 1, 2, 2, 3, 0, 4, 2};
    // assert(Solution::remove_element(nums, 2) == 5);

    nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    std::vector<int> numsResult = Solution::sliding_window_max(nums, 3);
    std::vector<int> maxSlidingWindowAnswer = { 3, 3, 5, 5, 6, 7 };
    assert(GlobalFunctions::validate_vector_equivalence(numsResult, maxSlidingWindowAnswer));

    return 0;
}