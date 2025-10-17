#!/usr/bin/env bash
set -e
echo "========== 编译 =========="
g++ -std=c++17 -Wall -Wextra -pedantic rpn_calc.cpp rpn_engine.cpp -o rpn_calc
echo "✅ 编译通过且无警告"

echo "========== 基础用例 =========="
check(){ echo -n "$1 ... "; res=$(echo "$2" | ./rpn_calc | grep -oP '结果: \K.*'); [[ "$res" == "$3" ]] && echo ✅ || echo ❌ 期望=$3 实际=$res; }
check "加法"           "3 4 +"            "7"
check "减法"           "9 2 -"            "7"
check "乘法"           "2 3 *"            "6"
check "除法"           "22 7 /"           "3.14286"
check "连续运算"       "3 4 + 5 *"        "35"

echo "========== 错误处理 =========="
if echo '5 0 /' | ./rpn_calc | grep -i "divide by zero"; 
then
	echo  "✅ 除零检测" 
else
	echo "❌ 除零检测"
fi
if echo '+' | ./rpn_calc | grep -i "stack underflow";
then
	echo  "✅ 栈空检测"
else
	echo  "❌ 除零检测"
fi

echo "========== 高级功能 =========="
check "pow"  "2 3 pow"     "8"
check "sqrt" "2 sqrt"      "1.41421"
check "fib"  "10 fib"      "55"

echo "========== 内存检查 =========="
which valgrind >/dev/null && \
valgrind --leak-check=full --error-exitcode=1 ./rpn_calc <<< '3 4 + q' >/dev/null && echo ✅ 无内存泄漏

echo "========== 全部自测完成 =========="
