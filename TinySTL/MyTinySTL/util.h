/*** 
 * @Date: 2022-02-24 13:07:30
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-24 16:10:23
 */

#ifndef MYTINYSTL_UTIL_H_
#define MYTINYSTL_UTIL_H_

/**
 * @file util.h
 * @author yufeng (you@domain.com)
 * @brief 此文件包含一些通用工具，如 move，forward，swap等函数，以及pair等
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstddef>

#include "type_traits.h"

namespace mystl {

    /** https://zhuanlan.zhihu.com/p/55856487
     * 问题：临时变量copy开销太大
     * 引入：rvalue, lvalue, rvalue reference概念
     * 方法：rvalue reference传临时变量，move语义避免copy
     * 优化：forward同时能处理rvalue/lvalue reference和const reference
     */

    // std::remove_reference<T>::type&& 用于移除类型的引用，返回原始类型
    // static_cast 可用于任何隐式转换，包括标准转换和用户定义的转换
    // noexcept 在C++11引入，告诉编译器函数中不会发生异常，这有利于编译器对程序做更多优化;
    // 在1)移动构造函数；2）移动分配函数；3）析构函数；4）叶子函数；这几种情况下鼓励使用noexcept
    /** move
     * @brief  Convert a value to an rvalue
     * 
     * @tparam T 
     * @param arg 
     * @return std::remove_reference<T>::type&& 
     */
    template <class T>
    typename std::remove_reference<T>::type&& move(T&& arg) noexcept {
        return static_cast<typename std::remove_reference<T>::type&&>(arg); // 将T&&类型的arg转换为T类型
    }

    /** forward
     * @brief Forward a lvalue and get a rvalue(anonymous variable)
     *     std::remove_reference<T>::type& 的原始类型是_Tp, forward(...) 将_Tp
     * @tparam T 
     * @param arg 
     * @return T&& 
     */
    template <class T>
    T&& forward(typename std::remove_reference<T>::type& arg) noexcept {
        return static_cast<T&&>(arg);   
    }

    template<class T>
    T&& forward(typename std::remove_reference<T>::type&& arg) noexcept {
        static_assert(!std::is_lvalue_reference<T>::value, "bad forward");
        return static_cast<T&&>(arg);
    }

    /** swap 
     * @brief swap lhs and rhs
     * 
     * @tparam Tp 
     * @param lhs 
     * @param rhs 
     */
    template<class Tp>
    void swap(Tp& lhs, Tp& rhs) {
        auto tmp(mystl::move(lhs));
        lhs = mystl::move(rhs);
        rhs = mystl:move(tmp);
    }

    template<class ForwardIter1, class ForwardIter2>
    ForwardIter2 swap_range(ForwardIter1 first1, ForwardIter1 last1, ForwardIter2 first2) {
        for (; first != last1; ++first1, (void) ++first2) {
            mystl::swap(*first, *first2);
        }
        return first2;
    } 

    template <class Tp, size_t N>
    void swap(Tp(&a)[N], Tp(&b)[N]) {
        mystl:swap_range(a, a + N, b);
    }


    // =============================================================================================
    // pair

    /** 结构体模板：pair
     * @brief 两个模板参数分别表示两个数据的类型，用first和second 分别取出第一个数据和第二个数据
     * 
     */
    template<class Tp1, class Tp2>
    struct pair {
        typedef Tp1 first_type;
        typedef Tp2 second_type;

        first_type first;   // 保存第一个数据
        second_type second; // 保存第二个数据

        // 默认构造方法
        template<class Other1 = Tp1, class Other2 = Tp2, 
            typename = typename std::enable_if<
            std::is_default_constructible<Other1>::value &&
            std::is_default_constructible<Other2>::value, void>::type>
            constexpr pair() : first(), second() {}

        // implicit constructiable for this type
        template <class U1 = Tp1, class U2 = Tp2, typename std::enable_if<
            std::is_copy_constructible<U1>::value &&
            std::is_copy_constructible<U2>::value &&
            std::is_convertible<const U1&, Tp1>::value &&
            std::is_convertible<const U2&, Tp2>::value, int>::type = 0>
            constexpr pair(const Tp1& a, const Tp2& b) : first(a), second(b) {}

        // explicit constructible for this type
        template <class U1 = Tp1, class U2 = Tp2,
            typename std::enable_if<
            std::is_copy_constructible<U1>::value &&
            std::is_copy_constructible<U2>::value &&
            (!std::is_convertible<const U1&, Tp1>::value ||
            !std::is_convertible<const U2&, Tp2>::value), int>::type = 0>
            explicit constexpr pair(const Tp1& a, const Tp2& b) : first(a), second(b) {}
        
        pair(const pair& rhs) = default;
        pair(pair&& rhs) = default;

        // implicit constructible for other type 
        
    };


}




#endif // !MYTINYSTL_UTIL_H_