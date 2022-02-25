/*** 
 * @Date: 2022-02-25 13:24:19
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-25 16:49:45
 */

#ifndef MYTINYSTL_MEMORY_H_
#define MYTINYSTL_MEMORY_H_

/**
 * @file memory.h
 * @author yufeng (you@domain.com)
 * @brief 此文件负责更高级的动态内存管理
 *          包含一些基本函数、空间配置器、未初始化的储存空间管理、
 *          以及一个模板类auto_ptr
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cstddef>
#include <cstdlib>
#include <climits>

#include "algobase.h"
#include "allocator.h"
#include "construct.h"
#include "unintialized.h"

namespace mystl {
    // 获取对象地址
    template <class Tp>
    constexpr Tp* address_of(Tp& value) noexcept {
        return &value;
    }

    // 获取 / 释放 临时缓存区

    template <class T>
    pair<T*, ptrdiff_t> get_buffer_helper(ptrdiff_t len, T*) {
        if (len > static_cast<ptrdiff_t>(INT_MAX / sizeof(T))) {
            len = INT_MAX / sizeof(T);
        } 
        while (len > 0) {
            T* tmp = static_cast<T*>(malloc(static_cast<size_t>(len) * sizeof(T)));
            if (tmp) {
                return pair<T*, ptrdiff_t>(tmp, len);
            }
            len /= 2;   // 申请失败时减少len的大小
        }
        return pair<T*, ptrdiff_t>(nullptr, 0);
    }

    template <class T>
    pair<T*, ptrdiff_t> get_temporary_buffer(ptrdiff_t len) {
        return get_buffer_helper(len, static_cast<T*>(0));
    }

    template <class T>
    pair<T*, ptrdiff_t> get_temporary_buffer(ptrdiff_t len, T*) {
        return get_buffer_helper(len, static_cast<T*>(0));
    }

    template <class T>
    void release_temporary_buffer(T* ptr) {
        free(ptr);
    }

    // =================================================================================
    // 类模板： temporary_buffer
    // 进行临时缓冲区的申请与释放
    template<class ForwardIterator, class T>
    class temporary_buffer {
    private:
        ptrdiff_t original_len;     // 缓冲区申请的大小
        ptrdiff_t len;              // 缓冲区实际的大小
        T*        buffer;           // 指向缓冲区的指针
    
    public:
        // 构造、析构函数
        temporary_buffer(ForwardIterator first, ForwardIterator last);

        ~temporary_buffer() {
            mystl::destroy(buffer, buffer + len);
            free(buffer);
        }

    public:
        ptrdiff_t size()            const noexcept { return len;}
        ptrdiff_t requested_size()  const noexcept { return original_len; }
        T*        begin()                 noexcept { return buffer;}
        T*        end()                   noexcept { return buffer + len;}
    };

}   // namespace mystl


#endif // MYTINYSTL_MEMORY_H_
