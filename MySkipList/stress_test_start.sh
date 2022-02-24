###
 # @Date: 2022-02-24 10:09:50
 # @Author: yufeng
 # @GitHub: https://github.com/fzhiy
 # @Email: fzhiy270@163.com
 # @LastEditTime: 2022-02-24 10:09:51
### 
#!/bin/bash
g++ stress-test/stress_test.cpp -o ./bin/stress  --std=c++11 -pthread  
./bin/stress
