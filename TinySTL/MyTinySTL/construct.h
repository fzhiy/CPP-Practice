/*** 
 * @Date: 2022-02-25 13:29:22
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-26 14:03:21
 */

#ifndef MYTINYSTL_CONSTRUCT_H_
#define MYTINYSTL_CONSTRUCT_H_

/**
 * @file construct.h
 * @author yufeng (you@domain.com)
 * @brief 此文件包含两个函数 construct, destroy
 *          construct   负责对象的构造
 *          destroy     复制对象的析构
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <new>

#include "type_traits.h"
#include "iterator.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4100)     // unused parameter
#endif  // _MSC_VER

namespace mystl {

    // construct 构造对象

    template <class Tp>
    void construct(Tp* ptr) {
        ::new ((void*)ptr) Tp();
    }

    template <class Tp1, class Tp2>
    void construct(Tp1* ptr, const Tp2& value) {
        ::new ((void*)ptr) Tp1(value);
    }

    template <class Tp, class... Args>
    void construct(Tp* ptr, Args&&... args) {
        ::new ((void*)ptr) Tp(mystl::forward<Args>(args)...);
    }

    // destroy 将对象析构

    template <class Tp>
    void destroy_one(Tp*, std::true_type) {}

    template <class Tp>
    void destroy_one(Tp* pointer, std::false_type) {
        if (pointer != nullptr) {
            pointer->~Tp();
        }
    }

    template <class ForwardIter>
    void destroy_cat(ForwardIter, ForwardIter, std::true_type) {}

    template <class ForwardIter>
    void destroy_cat(ForwardIter first, ForwardIter last, std::false_type) {
        for (; first != last; ++first) {
            destroy(&*first);       // TODO: &*  ???
        }
    }

    template <class Tp>
    void destroy(Tp* pointer) {
        destroy_one(pointer, std::is_trivially_destructible<Tp>{}); //TODO: ???
    }

    template <class ForwardIter>
    void destroy(ForwardIter first, ForwardIter last) {
        destroy_cat(first, last, std::is_trivially_destructible<
                    typename iterator_traits<ForwardIter>::value_type>{});
    }
}   // namespace mystl

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif  // !MYTINYSTL_CONSTRUCT_H_