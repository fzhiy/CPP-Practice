# LeetCode_tag

> 分类参考：https://github.com/resumejob/Leetcode-retag
>
> 重新分类 Leetcode 高频题 2021 版
>
> - 题目按照面试频率降序排列
> - 增加难度分类，适合从简单开始学习
> - 增加细分类别，例如单调栈，前缀树等，一道题目可能会有多个类别

# 目录



## 链表

| 题目                                                         | 难度 | 题解文件                                                     | 方法                                    |
| ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | --------------------------------------- |
| [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/) | 简单 | [简单-206.反转链表.md](链表/单链表/简单-206.反转链表.md)     | 迭代/递归                               |
| [141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/) | 简单 | [简单-141. 环形链表.md](链表/单链表/简单-141. 环形链表.md)   | 快慢指针                                |
| [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) | 简单 | [简单-83. 删除排序链表中的重复元素.md](链表/单链表/简单-83. 删除排序链表中的重复元素.md) |                                         |
| [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/) | 简单 | [简单-234. 回文链表.md](链表/单链表/简单-234. 回文链表.md)   | 快慢指针+反转链表                       |
| [203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/) | 简单 | [简单-203. 移除链表元素.md](链表/单链表/简单-203. 移除链表元素.md) |                                         |
| [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/) | 简单 | [简单-237. 删除链表中的节点.md](链表/单链表/简单-237. 删除链表中的节点.md) |                                         |
| [876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/) | 简单 | [简单-876. 链表的中间结点.md](链表/单链表/简单-876. 链表的中间结点.md) | 快慢指针                                |
| [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) | 中等 | [中等-92. 反转链表 II.md](链表/单链表/中等-92. 反转链表 II.md) | 头插法                                  |
| [143. 重排链表](https://leetcode-cn.com/problems/reorder-list/) | 中等 | [中等-143. 重排链表.md](链表/单链表/中等-143. 重排链表.md)   | 快慢指针+反转链表+合并链表              |
| [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/) | 中等 | [中等-82. 删除排序链表中的重复元素 II.md](链表/单链表/中等-82. 删除排序链表中的重复元素 II.md) | 删除节点（2种方法）                     |
| [148. 排序链表](https://leetcode-cn.com/problems/sort-list/) | 中等 | [中等-148. 排序链表.md](链表/单链表/中等-148. 排序链表.md)   | 归并排序（迭代（**切割链表**） + 递归） |
| [86. 分隔链表](https://leetcode-cn.com/problems/partition-list/) | 中等 | [中等-86. 分隔链表.md](链表/单链表/中等-86. 分隔链表.md)     | 合并链表                                |
| [61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/) | 中等 | [中等-61. 旋转链表.md](链表/单链表/中等-61. 旋转链表.md)     | 切割链表                                |
| [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/) | 中等 | [中等-142. 环形链表 II.md](链表/单链表/中等-142. 环形链表 II.md) | 快慢指针                                |
| [147. 对链表进行插入排序](https://leetcode-cn.com/problems/insertion-sort-list/) | 中等 | [中等-147. 对链表进行插入排序.md](链表/单链表/中等-147. 对链表进行插入排序.md) | 头插法                                  |
| [138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/) | 中等 | [中等-138. 复制带随机指针的链表.md](链表/单链表/中等-138. 复制带随机指针的链表.md) |                                         |
| [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/) | 中等 | [中等-24. 两两交换链表中的节点.md](链表/单链表/中等-24. 两两交换链表中的节点.md) | 三指针                                  |
| [328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/) | 中等 | [中等-328. 奇偶链表.md](链表/单链表/中等-328. 奇偶链表.md)   | 双指针                                  |
| [707. 设计链表](https://leetcode-cn.com/problems/design-linked-list/) | 中等 | [中等-707. 设计链表.md](链表/单链表/中等-707. 设计链表.md)   | 建立链表                                |
| [109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/) | 中等 | [中等-109. 有序链表转换二叉搜索树.md](链表/单链表/中等-109. 有序链表转换二叉搜索树.md) | 分治法（中序遍历）                      |
| [430. 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/) | 中等 | [中等-430. 扁平化多级双向链表.md](链表/单链表/中等-430. 扁平化多级双向链表.md) |                                         |
| [725. 分隔链表](https://leetcode-cn.com/problems/split-linked-list-in-parts/) | 中等 | [中等-725. 分隔链表.md](链表/单链表/中等-725. 分隔链表.md)   |                                         |
|                                                              |      |                                                              |                                         |
|                                                              |      |                                                              |                                         |
|                                                              |      |                                                              |                                         |



## 树



## 动态规划

| 题目                                                         | 难度 | 题解文件                                                     | 方法              |
| ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | ----------------- |
| [70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/) | 简单 | [70. 爬楼梯.md](动态规划\一维\70. 爬楼梯.md)                 |                   |
| [53. 最大子数组和](https://leetcode-cn.com/problems/maximum-subarray/) | 简单 | [53. 最大子数组和.md](动态规划\一维\53. 最大子数组和.md)     | DP, 分治法        |
| [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) | 简单 | [121. 买卖股票的最佳时机.md](动态规划\一维\121. 买卖股票的最佳时机.md) | DP                |
| [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) | 简单 | [746. 使用最小花费爬楼梯.md](动态规划\一维\746. 使用最小花费爬楼梯.md) | DP                |
| [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/) | 中等 | [337. 打家劫舍 III.md](动态规划\一维\337. 打家劫舍 III.md)   | DP(dfs)           |
| [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) | 中等 | [322. 零钱兑换.md](动态规划\一维\322. 零钱兑换.md)           | 完全背包          |
| [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) | 中等 | [300. 最长递增子序列.md](动态规划\一维\300. 最长递增子序列.md) | DP / DP+二分      |
| [139. 单词拆分](https://leetcode-cn.com/problems/word-break/) | 中等 | [139. 单词拆分.md](动态规划\一维\139. 单词拆分.md)           | DP                |
|                                                              |      |                                                              |                   |
| [5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/) | 中等 | [5. 最长回文子串.md](动态规划\二维\5. 最长回文子串.md)       | DP/中心扩展法     |
| [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/) | 中等 | [1143. 最长公共子序列.md](动态规划\二维\1143. 最长公共子序列.md) | 经典二维DP        |
| [131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/) | 中等 | [131. 分割回文串.md](动态规划\二维\131. 分割回文串.md)       |                   |
| [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/) | 中等 | [62. 不同路径.md](动态规划\二维\62. 不同路径.md)             | 二维DP / 滚动数组 |
| [63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/) | 中等 | [63. 不同路径 II.md](动态规划\二维\63. 不同路径 II.md)       | 二维DP            |
| [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/) | 中等 | [64. 最小路径和.md](动态规划\二维\64. 最小路径和.md)         | 二维DP / 滚动数组 |
| [718. 最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/) | 中等 | [718. 最长重复子数组.md](动态规划\二维\718. 最长重复子数组.md) | 二维DP / 滚动数组 |
| [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/) | 中等 | [221. 最大正方形.md](动态规划\二维\221. 最大正方形.md)       | 二维DP            |
| [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum/) | 中等 | [416. 分割等和子集.md](动态规划\二维\416. 分割等和子集.md)   | 二维DP => 一维    |
| [494. 目标和](https://leetcode.cn/problems/target-sum/)      | 中等 | [494. 目标和.md](动态规划\二维\494. 目标和.md)               | 递归 / DP         |
|                                                              |      |                                                              |                   |
| [72. 编辑距离](https://leetcode.cn/problems/edit-distance/)  | 困难 | [72. 编辑距离.md](动态规划\二维\72. 编辑距离.md)             | DP                |
|                                                              |      |                                                              |                   |



## 堆



## 二分查找



## 位运算

| 题目                                                         | 难度 | 题解文件                                                     | 方法             |
| ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | ---------------- |
| [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/) | 简单 | [136. 只出现一次的数字.md](位运算/136. 只出现一次的数字.md)  | 位异或           |
| [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/) | 简单 | [191. 位1的个数.md](位运算/191. 位1的个数.md)                | 位运算           |
| [169. 多数元素](https://leetcode-cn.com/problems/majority-element/) | 简单 | [169. 多数元素.md](位运算/169. 多数元素.md)                  | Boyer-Moore 算法 |
| [231. 2 的幂](https://leetcode-cn.com/problems/power-of-two/) | 简单 | [231. 2 的幂.md](位运算/231. 2 的幂.md)                      | 位运算           |
| [389. 找不同](https://leetcode-cn.com/problems/find-the-difference/) | 简单 | [389. 找不同.md](位运算/389. 找不同.md)                      | 位运算，问题转化 |
| [268. 丢失的数字](https://leetcode-cn.com/problems/missing-number/) | 简单 | [268. 丢失的数字.md](位运算/268. 丢失的数字.md)              | 位运算           |
| [190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/) | 简单 | [190. 颠倒二进制位.md](位运算/190. 颠倒二进制位.md)          | 位运算           |
| [461. 汉明距离](https://leetcode-cn.com/problems/hamming-distance/) | 简单 | [461. 汉明距离.md](位运算/461. 汉明距离.md)                  | 位运算           |
| [405. 数字转换为十六进制数](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/) | 简单 | [405. 数字转换为十六进制数.md](位运算/405. 数字转换为十六进制数.md) | 位运算           |
|                                                              |      |                                                              |                  |



## 双指针与滑动窗口

| 题目                                                         | 难度 | 题解文件                                                     | 方法           |
| ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | -------------- |
| [387. 字符串中的第一个唯一字符](https://leetcode-cn.com/problems/first-unique-character-in-a-string/) | 简单 | [387. 字符串中的第一个唯一字符.md](双指针与滑动窗口/387. 字符串中的第一个唯一字符.md) | 计数           |
| [349. 两个数组的交集](https://leetcode-cn.com/problems/intersection-of-two-arrays/) | 简单 | [349. 两个数组的交集.md](双指针与滑动窗口/349. 两个数组的交集.md) | 哈希表         |
| [409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/) | 简单 | [409. 最长回文串.md](双指针与滑动窗口/409. 最长回文串.md)    | （哈希表）计数 |
| [217. 存在重复元素](https://leetcode-cn.com/problems/contains-duplicate/) | 简单 | [217. 存在重复元素.md](双指针与滑动窗口/217. 存在重复元素.md) | 哈希表         |
| [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/) | 简单 | [88. 合并两个有序数组.md](双指针与滑动窗口/88. 合并两个有序数组.md) | 逆双指针       |
| [283. 移动零](https://leetcode-cn.com/problems/move-zeroes/) | 简单 | [283. 移动零.md](双指针与滑动窗口/283. 移动零.md)            | 双指针         |
| [125. 验证回文串](https://leetcode-cn.com/problems/valid-palindrome/) | 简单 | [125. 验证回文串.md](双指针与滑动窗口/125. 验证回文串.md)    | 双指针         |
| [344. 反转字符串](https://leetcode-cn.com/problems/reverse-string/) | 简单 | [344. 反转字符串.md](双指针与滑动窗口/344. 反转字符串.md)    | 双指针         |
| [27. 移除元素](https://leetcode-cn.com/problems/remove-element/) | 简单 | [27. 移除元素.md](双指针与滑动窗口/27. 移除元素.md)          | 双指针         |
| [977. 有序数组的平方](https://leetcode-cn.com/problems/squares-of-a-sorted-array/) | 简单 | [977. 有序数组的平方.md](双指针与滑动窗口/977. 有序数组的平方.md) | 双指针         |
| [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) | 中等 | [3. 无重复字符的最长子串.md](双指针与滑动窗口/3. 无重复字符的最长子串.md) | 滑动窗口       |
| [781. 森林中的兔子](https://leetcode-cn.com/problems/rabbits-in-forest/) | 中等 | [781. 森林中的兔子.md](双指针与滑动窗口/781. 森林中的兔子.md) | 哈希表         |
| [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/) | 中等 | [49. 字母异位词分组.md](双指针与滑动窗口/49. 字母异位词分组.md) |                |
| [18. 四数之和](https://leetcode-cn.com/problems/4sum/)       | 中等 | [18. 四数之和.md](双指针与滑动窗口/18. 四数之和.md)          | 排序+双指针    |
| [11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) | 中等 | [11. 盛最多水的容器.md](双指针与滑动窗口/11. 盛最多水的容器.md) | 双指针         |
| [16. 最接近的三数之和](https://leetcode.cn/problems/3sum-closest/) | 中等 | [16. 最接近的三数之和.md](双指针与滑动窗口/16. 最接近的三数之和.md) | 排序+双指针    |
| [424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/) | 中等 | [424. 替换后的最长重复字符.md](双指针与滑动窗口\424. 替换后的最长重复字符.md) | 双指针         |
| [713. 乘积小于 K 的子数组](https://leetcode.cn/problems/subarray-product-less-than-k/) | 中等 | [713. 乘积小于 K 的子数组.md](双指针与滑动窗口\713. 乘积小于 K 的子数组.md) | 双指针         |
| [992. K 个不同整数的子数组](https://leetcode.cn/problems/subarrays-with-k-different-integers/) | 困难 | [992. K 个不同整数的子数组.md](双指针与滑动窗口\992. K 个不同整数的子数组.md) | 双指针         |
| [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) | 困难 |                                                              |                |

## 二叉搜索树



## 图论



## 并查集

| 题目                                                         | 难度 | 题解文件                                            | 方法                 |
| ------------------------------------------------------------ | ---- | --------------------------------------------------- | -------------------- |
| [200. 岛屿数量](https://leetcode-cn.com/problems/number-of-islands/) | 中等 | [中等-200.岛屿数量.md](并查集/中等-200.岛屿数量.md) | 并查集；DFS；（BFS） |
|                                                              |      |                                                     |                      |
|                                                              |      |                                                     |                      |
|                                                              |      |                                                     |                      |

