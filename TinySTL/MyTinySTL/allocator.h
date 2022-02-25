/*** 
 * @Date: 2022-02-25 13:29:31
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-25 15:42:20
 */

#ifndef MYTINYSTL_ALLOCATOR_H_
#define MYTINYSTL_ALLOCATOR_H_

/**
 * @file allocator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "construct.h"
#include "util.h"

namespace mystl {
    // 模板类: allocator
    // 模板函数代表数据类型
    template <class T>
    class allocator {
    public:
        typedef T           value_type;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;

    public:
        static T*   allocate();
        static T*   allocate(size_type n);

        static void deallocate(T* ptr);
        static void deallocate(T* ptr, size_type n);

        static void construct(T* ptr);
        static void construct(T* ptr, const T& value);
        static void construct(T* ptr, T&& value);

        template <class... Args>
        static void construct(T* ptr, Args&& ...args);

        static void destroy(T* ptr);
        static void destroy(T* first, T* last);
    };

    template <class T>
    T* allocate<T>::allocate() {
        return static_cast<T*>(::operator new(sizeof(T)));
    }

    template <class T>
    T* allocate<T>::allocate(size_type n) {
        if (n == 0) {
            return nullptr;
        }
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    template <class T>
    void allocator<T>::deallocate(T* ptr) {
        if (ptr == nullptr) {
            return;
        }
        ::operator delete(ptr);
    }

    template <class T>
    void allocator<T>::deallocate(T* ptr, size_type /*size*/) {
        if (ptr == nullptr) {
            return;
        }
        ::operator delete(ptr);
    }

    template <class T>
    void allocator<T>::construct(T* ptr) {
        mystl::construct(ptr);
    }

    template <class T>
    void allocator<T>::construct(T* ptr, const T& value) {
        mystl::construct(ptr, value);
    }

    template <class T>
    void allocator<T>::construct(T* ptr, T&& value) {
        mystl::construct(ptr, mystl::move(value));
    }

    template <class T>
    template <class ...Args>    // TODO: 2个template？
    void allocator<T>::construct(T* ptr, Args&& ...args) {
        mystl::construct(ptr, mystl::forward<Args>(args)...);
    }

    template <class T>
    void allocator<T>::destroy(T* ptr) {
        mystl::destroy(ptr);
    }

    template <class T>
    void allocator<T>::destroy(T* first, T* last) {
        mystl::destroy(first, last);
    }
}   // namespace mystl

#endif // !MYTINYSTL_ALLOCATOR_H_