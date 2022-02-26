/*** 
 * @Date: 2022-02-26 14:17:44
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-26 14:21:00
 */

#ifndef MYTINYSTL_ALGO_H_
#define MYTINYSTL_ALGO_H_

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#endif

/**
 * @file algo.h
 * @author yufeng (you@domain.com)
 * @brief 此文件包含 mystl 的一系列算法
 * @version 0.1
 * @date 2022-02-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstddef>


#include "algobase.h"
#include "memory.h"

namespace mystl {


    /*****************************************************************************************/
    // reverse
    // 将[first, last)区间内的元素反转
    /*****************************************************************************************/
    // reverse_dispatch 的 bidirectional_iterator_tag 版本
    template <class BidirectionalIter>
    void reverse_dispatch(BidirectionalIter first, BidirectionalIter last,
                        bidirectional_iterator_tag)
    {
        while (true)
        {
            if (first == last || first == --last)
            return;
            mystl::iter_swap(first++, last);
        }
    }

    // reverse_dispatch 的 random_access_iterator_tag 版本
    template <class RandomIter>
    void reverse_dispatch(RandomIter first, RandomIter last,
                        random_access_iterator_tag)
    {
        while (first < last)
            mystl::iter_swap(first++, --last);
    }

    template <class BidirectionalIter>
    void reverse(BidirectionalIter first, BidirectionalIter last)
    {
        mystl::reverse_dispatch(first, last, iterator_category(first));
    }

}

#endif  // !MYTINYSTL_ALGO_H_
