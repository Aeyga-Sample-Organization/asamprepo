#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>
#include "ListNode.h"

/// <summary>
/// Contains solutions to various Leetcode problems. Some problems have multiple solutions.
/// </summary>
static class Solution
{
    public:

        /// <summary>
        /// Checks if any two numbers from the provided vector add up to target.
        /// </summary>
        /// <param name="nums">: A vector containing the numbers we want to check.</param>
        /// <param name="target">: The target sum to check for.</param>
        /// <returns>A new vector containing the indices of the two numbers that add up to target.</returns>
        static std::vector<int> two_sum(std::vector<int>& nums, int target);

        /// <summary>
        /// Checks if any two numbers from the provided vector add up to target.
        /// </summary>
        /// <param name="nums">: A vector containing the numbers we want to check.</param>
        /// <param name="target">: The target sum to check for.</param>
        /// <returns>A new vector containing the indices of the two numbers that add up to target.</returns>
        static std::vector<int> efficient_two_sum(std::vector<int>& nums, int target);

        /// <summary>
        /// Checks if the provided number is a palindrome.
        /// </summary>
        /// <param name="x">: The number we want to check.</param>
        /// <returns>true if the given number is a palindrome, false otherwise.</returns>
        static bool is_palindrome(int x);

        /// <summary>
        /// Converts a given string into a roman integer.
        /// </summary>
        /// <param name="s">: The input string to convert into an integer.</param>
        /// <returns>The roman numeral converted to an integer.</returns>
        static int roman_to_int(std::string s);

        /// <summary>
        /// Finds the longest common prefix among a list of strings.
        /// </summary>
        /// <param name="strs">: The input strings.</param>
        /// <returns></returns>
        static std::string longest_common_prefix(std::vector<std::string>& strs);

        /// <summary>
        /// Finds the longest common prefix among a list of strings.
        /// </summary>
        /// <param name="strs">: The input strings.</param>
        /// <returns></returns>
        static std::string lcp_optimized(std::vector<std::string>& strs);

        /// <summary>
        /// Merge two sorted linked lists into a single list.
        /// </summary>
        /// <param name="list1">: A sorted linked list.</param>
        /// <param name="list2">: A sorted linked list.</param>
        /// <returns></returns>
        static ListNode* merge_two_lists(ListNode* list1, ListNode* list2);

        /// <summary>
        /// Finds the first occurence of needle in haystack.
        /// </summary>
        /// <param name="haystack">: The string to search.</param>
        /// <param name="needle">: The target string to search for.</param>
        /// <returns>The index of the first occurence. Returns -1 if it doesn't exist in haystack</returns>
        static int find_needle(std::string haystack, std::string needle);
};
#endif

