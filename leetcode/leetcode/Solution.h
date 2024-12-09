#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>
#include "ListNode.h"

/// <summary>
/// Contains solutions to various Leetcode problems. Some problems have multiple solutions.
/// </summary>
class Solution
{
    public:

        /// <summary>
        /// Checks if any two numbers from the provided vector add up to target.
        /// </summary>
        /// <param name="nums">: A vector containing the numbers we want to check.</param>
        /// <param name="target">: The target sum to check for.</param>
        /// <returns>A new vector containing the indices of the two numbers that add up to target.</returns>
        std::vector<int> two_sum(std::vector<int>& nums, int target);

        /// <summary>
        /// Checks if any two numbers from the provided vector add up to target.
        /// </summary>
        /// <param name="nums">: A vector containing the numbers we want to check.</param>
        /// <param name="target">: The target sum to check for.</param>
        /// <returns>A new vector containing the indices of the two numbers that add up to target.</returns>
        std::vector<int> efficient_two_sum(std::vector<int>& nums, int target);

        /// <summary>
        /// Checks if the provided number is a palindrome.
        /// </summary>
        /// <param name="x">: The number we want to check.</param>
        /// <returns>true if the given number is a palindrome, false otherwise.</returns>
        bool is_palindrome(int x);

        /// <summary>
        /// Converts a given string into a roman integer.
        /// </summary>
        /// <param name="s">: The input string to convert into an integer.</param>
        /// <returns>The roman numeral converted to an integer.</returns>
        int romanToInt(std::string s);

        /// <summary>
        /// Finds the longest common prefix among a list of strings.
        /// </summary>
        /// <param name="strs">: The input strings.</param>
        /// <returns></returns>
        std::string longestCommonPrefix(std::vector<std::string>& strs);

        /// <summary>
        /// Finds the longest common prefix among a list of strings.
        /// </summary>
        /// <param name="strs">: The input strings.</param>
        /// <returns></returns>
        std::string lcp_optimized(std::vector<std::string>& strs);

        /// <summary>
        /// Merge two sorted linked lists into a single list.
        /// </summary>
        /// <param name="list1">: A sorted linked list.</param>
        /// <param name="list2">: A sorted linked list.</param>
        /// <returns></returns>
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};
#endif

