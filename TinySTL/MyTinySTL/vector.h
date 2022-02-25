/*** 
 * @Date: 2022-02-25 18:56:57
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-25 22:13:13
 */

#ifndef MYTINYSTL_VECTOR_H_
#define MYTINYSTL_VECTOR_H_

/**
 * @file vector.h
 * @author yufeng (you@domain.com)
 * @brief 此文件包含一个模板类vector
 *      notes:
 *      异常保证：
 *      mystl::vector<T> 满足基本异常保证，部分函数无异常保证，并对以下函数做强异常安全保证：
 *          * emplace
 *          * emplace_back
 *          * push_back
 *      当 std::is_nothrow_move_assignable<T>::value == true 时，以下函数也满足强异常保证：
 *          * reserve
 *          * resize
 *          * insert
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <initializer_list>

#include "iterator.h"
#include "memory.h"
#include "util.h"
#include "exceptdef.h"

namespace mystl {

#ifdef max
#pragma message("#undefing marco max")
#undef max
#endif  // max

// 模板类： vector
// 模板参数 T 代表类型
template <class T>
class vector {
    static_assert(!std::is_same<bool, T>::value, "vector<bool> is abandoned in mystl");
public:
    // vector 的嵌套型别定义
    typedef mystl::allocator<T>                         allocator_type;
    typedef mystl::allocator<T>                         data_allocator;
    
    typedef typename allocator_type::value_type         value_type;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;

    typedef value_type*                                 iterator;
    typedef const value_type*                           const_iterator;
    typedef mystl::reverse_iterator<iterator>           reverse_iterator;
    typedef mystl::reverse_iterator<const_iterator>     const_reverse_iterator;

    allocator_type get_allocator()  { return data_allocator(); }

private:
    iterator begin_;    // 表示目前使用空间的头部
    iterator end_;      // 表示目前使用空间的尾部
    iterator cap_;      // 表示目前储存空间的尾部

public:
    // 构造、复制、移动、析构函数
    vector() noexcept {
        try_init();
    }

    explicit vector(size_type n) {
        fill_init(n, value_type());
    }

    vector(size_type n, const value_type& value) {
        fill_init(n, value);
    }

    template <class Iter, typename std::enable_if<
        mystl::is_input_iterator<Iter>::value, int>::type = 0>
    vector(Iter first, Iter last) {
        MYSTL_DEBUG(!(last < first));
        range_init(first, last);
    }

    vector(const vector& rhs) {
        range_init(rhs.begin_, rhs.end_);
    }

    vector(vector&& rhs) noexcept
        :begin_(rhs.begin_),
        end_(rhs.end_),
        cap_(rhs.cap_) {
            rhs.begin_ = nullptr;
            rhs.end_ = nullptr;
            rhs.cap_ = nullptr;
        }

    vector(srd::initializer_lsit<value_type> ilist) {
        range_init(ilist.begin(), ilist.end());
    }

    vector& operator=(const vector& rhs);
    vector& operator=(vector&& rhs) noexcept;

    vector& operator=(std::initializer_list<value_type>ilist) {
        vector tmp(ilist.begin(), ilist.end());
        swap(tmp);
        return *this;
    }

    ~vector() {
        destroy_and_recover(begin_, end_, cap_ - begin_);
        begin_ = end_ = cap_ = nullptr;
    }

public:

    // 迭代器相关操作
    iterator            begin()           noexcept {
        return begin_;
    }
    const_iterator      begin()     const noexcept {
        return begin_;
    } 
    iterator            end()             noexcept {
        return end_;
    }
    iterator            end()       const noexcept {
        return end_;
    }

    reverse_iterator    rbegin()         noexcept {
        return reverse_iterator(end());
    }
    const_reverse_iterator  rbgin()     const noexcept {
        return const_reverse_iterator(end());
    }
    reverse_iterator    rend()          noexcept {
        return reverse_iterator(begin());
    }
    const_reverse_iterator  rend()      const noexcept {
        return const_reverse_iterator(begin());
    }

    const_iterator      cbegin()        const noexcept {
        return begin();
    }
    const_iterator      cend()          const noexcept {
        return end();
    }
    const_reverse_iterator  crbegin()   const noexcept {
        return rbegin();
    }
    const_reverse_iterator  crend()     const noexcept {
        return rend();
    }

    // 容量相关操作
    bool        empty()   const noexcept {
        return begin_ == end_;
    }
    size_type   size()    const noexcept {
        return static_cast<size_type>(end_ - begin_);
    }
    size_type   max_size() const noexcept {
        return static_cast<size_type>(-1) / sizeof(T);
    }
    
};

    /*****************************************************************************/
    // helper function 
    // try_init 函数，若分配失败 则忽略，不抛出异常
    template <class T>
    void vector<T>::try_init() noexcept {
        try {
            begin_ = data_allocator::allocate(16);
            end_ = begin_;
            cap_ = being_ + 16;
        } catch (...) {
            begin_ = nullptr;
            end_ = nullptr;
            cap_ = nullptr;
        }
    }

    // init_space函数
    template<class T>
    void vector<T>::init_space(size_type size, size_type cap) {
        try {
            begin_ = data_allocator::allocate(cap);
            end_ = begin_ + size;
            cap_ = begin_ + cap;
        } catch (...) {
            begin_ = nullptr; 
            end_ = nullptr;
            cap_ = nullptr;
            throw;
        }
    } 

    // fill_init 函数
    template<class T>
    void vector<T>::fill_init(size_type n, const value_type& value) {
        const size_type init_size = mystl::max(static_cast<size_type>(16), n);
        init_size(n, init_size);
        mystl::uninitialized_fill_n(begin_, n, value);
    }

    // range_init 函数
    template <class T>
    template <class Iter>
    void vector<T>::
    range_init(Iter first, Iter last) {
        const size_type init_size = mystl::max(static_cast<size_type>(last - first),
                                            static_cast<size_type>(16));
        init_space(static_cast<size_type>(last - first), init_size);
        mystl::uninitialized_copy(first, last, begin_);
    }

    // destroy_and_recover函数
    template <class T>
    void vector<T>::
    destroy_and_recover(iterator first, iterator last, size_type n) {
        data_allocator::destroy(first, last);
        data_allocator::deallocate(first, n);
    }

    // get_new_cap 函数
    template <class T>
    typename vector<T>::size_type
    vector<T>::get_new_cap(size_type add_size) {
        const auto old_size = capacity();
        THROW_LENGTH_ERROR_IF(old_size > max_size() - add_size, "vector<T>'s size too big");
        if (old_size > max_size() - old_size / 2) {
            return old_size + add_size > max_size() - 16 ?
                old_size + add_size : old_size + add_size + 16;
        }
        const size_type new_size = old_size == 0  
            ? mystl::max(add_size, static_cast<size_type>(16))
            : mystl::max(old_size + old_size / 2, old_size + add_size);
        return new_size;
    }

    // fill_assign 函数
    template <class T>
    void vector<T>::
    fill_assign(size_type n, const value_type& value) {
        if (n > capacity()) {
            vector tmp(n, value);
            swap(tmp);
        } else if (n > size()) {
            mystl::fill(begin(), end(), value);
            end_ = mystl::uninitialized_fill_n(end_, n - size(), value);
        } else {
            erase(mystl::fill_n(begin_, n, value), end_);
        }
    }

    // copy_assign 函数
    template <class T>
    template <class IIter>
    void vector<T>::
    copy_assign(IIter first, IIter last, input_iterator_tag) {
        auto cur = begin_;
        for (; first != last && cur != end_; ++first, ++cur) {
            *cur = *first;
        }
        if (first == last) {
            erase(cur, end_);
        } else {
            insert(end_, first, last);
        }
    }


}   // namespace mystl


#endif // !MYTINYSTL_VECTOR_H_