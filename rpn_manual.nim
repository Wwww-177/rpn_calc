import nimib

nbInit()
nbText: "## RPN 计算器使用说明书"
nbText: "本程序为命令行逆波兰（RPN）计算器，支持整数、浮点数、四则运算及扩展数学函数。"
nbText: "所有输入按「空格」分隔；一行即一次求值，回车得结果。"

nbText: "### 1. 安装与编译666"
nbCode:
  echo """
  git clone https://github.com/yourname/rpn_calc.git
  cd rpn_calc
  g++ -std=c++17 rpn_calc.cpp rpn_engine.cpp -o rpn_calc
  """

nbText: "### 2. 启动"
nbCode:
  echo """
  ./rpn_calc
  === C++ RPN 计算器 ===
  支持操作: +  -  *  /  pow  sqrt  fib
  输入表达式（如 3 4 +），或 q 退出
  >
  """

nbText: "### 3. 基础示例"
nbText: "加法"
nbCode: echo "> 3 4 +\n结果: 7"

nbText: "乘法结合"
nbCode: echo "> 2 3 4 * +\n结果: 14"

nbText: "浮点除法"
nbCode: echo "> 22 7 /\n结果: 3.14286"

nbText: "### 4. 扩展运算"
nbText: "幂运算"
nbCode: echo "> 2 3 pow\n结果: 8"

nbText: "平方根"
nbCode: echo "> 2 sqrt\n结果: 1.41421"

nbText: "斐波那契（第 n 项）"
nbCode: echo "> 10 fib\n结果: 55"

nbText: "### 5. 栈操作与调试"
nbText: "- 连续运算自动复用栈内剩余数据  \n- 输入非法字符或栈空时会提示错误，但程序不崩溃  \n- 随时按 q 或 quit 退出"

nbText: "### 6. 错误提示对照表"
nbText: "| 错误信息 | 含义 |"
nbText: "|---|---|"
nbText: "| stack underflow | 运算符需要的操作数不足 |"
nbText: "| divide by zero | 除零 |"
nbText: "| sqrt of negative | 对负数开方 |"
nbText: "| fib index must >= 0 | 斐波那契下标为负 |"

nbText: "### 7. 批量模式（重定向）"
nbText: "支持管道一次计算多行："
nbCode: echo "echo -e \"3 4 +\\n2 pow\" | ./rpn_calc"

nbText: "### 8. 常见问题"
nbText: "- **Q：必须空格分隔？** A：是的，Tab/多个空格也可。  \n"
nbText: "- **Q：支持负数？** A：支持，如 `-5 2 +` 得 -3。  \n"
nbText: "- **Q：括号怎么打？** A：RPN 无需括号，靠顺序即隐含优先级。"

nbText: "### 9. 源码与更新"
nbText: "开源地址：[https://github.com/Wwww-177/rpn_calc](https://github.com/yourname/rpn_calc)  \n"
nbText: "提交 Issue 欢迎反馈 bug 或新功能需求。"

nbSave()
