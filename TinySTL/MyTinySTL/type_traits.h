/*** 
 * @Date: 2022-02-24 13:07:23
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-24 15:03:38
 */

#ifndef MYTINY_TYPE_TRAITS_H_
#define MYTINY_TYPE_TRAITS_H_

/**
 * @file type_traits.h
 * @author yufeng (you@domain.com)
 * @brief 此文件用于提取类型信息
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * type_traits是C++11提供的模板元基础库
 *              可实现在编译期的计算、判断、转换、查询等功能
 *              提供了编译期的true和false
 */
#include <type_traits>

namespace mystl {

    // helper struct
    template <class T, T v>
    struct m_integral_constant {
        static constexpr T value = v;   // C++11引入constexpr 编译期常量
    };

    template <bool b>
    using m_bool_constant = m_integral_constant<bool, b>;   
    // using a = b; 指定别名用法，a是b的别名；
    // using有三种用法：1）引入命名空间；2）指定别名；3）在子类中引用基类的成员
    // https://blog.csdn.net/chaipp0607/article/details/100128842

    typedef m_bool_constant<true> m_true_type;      // m_true_type是别名， true type
    typedef m_bool_constant<false> m_false_type;    // false type

    /***************************************************************************/
    // type traits
    // is_pair

    // --- forward declaration begin
    template <class T1, class T2>
    struct pair;
    // --- forward declaration end

    template <class T>
    struct is_pair : mystl::m_false_type {};

    template <class T1, class T2>
    struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};
}   // namespace mystl

#endif // !MYTINY_TYPE_TRAITS_H_