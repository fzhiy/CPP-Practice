/*** 
 * @Date: 2022-02-25 13:24:31
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-26 13:55:26
 */

#ifndef MYTINYSTL_EXCEPTDEF_H_
#define MYTINYSTL_EXCEPTDEF_H_

#include <stdexcept>
#include <cassert>

namespace mystl {
#define MYSTL_DEBUG(expr) \
    assert(expr)

#define THROW_LENGTH_ERROR_IF(expr, what) \
    if ((expr)) throw std::length_error(what)

#define THROW_OUT_OF_RANGE_IF(expr, what) \
    if ((expr)) throw std::out_of_range(what)

#define THROW_RUNTIME_ERROR_IF(expr, what) \
    if ((expr)) throw std::runtime_error(what)

}   // namespace mystl

#endif // !MYTINYSTL_EXCEPTDEF_H_