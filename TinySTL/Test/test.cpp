/*** 
 * @Date: 2022-02-24 15:28:04
 * @Author: yufeng
 * @GitHub: https://github.com/fzhiy
 * @Email: fzhiy270@163.com
 * @LastEditTime: 2022-02-26 13:52:36
 */

#ifdef _MSC_VER
#define _SCL_SECURE_NO_WARNINGS
#endif  // _MSC_VER

#if defined(_MSC_VER) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif  // check memory leaks

#include "vector_test.h"

int main() {
    using namespace mystl::test;

    std::cout.sync_with_stdio(false);

    RUN_ALL_TESTS();
    vector_test::vector_test();

#if defined(_MSC_VER) && defined(_DEBUG)
    _CrtDumpMemoryLeaks()
#endif  // check memory leaks
}