#pragma once
#include <stack>
#include <string>
#include <stdexcept>

class RPNCalculator {
public:
    RPNCalculator() = default;

    /* 压栈 */
    void push(double value);

    /* 弹出并返回栈顶 */
    double pop();

    /* 返回栈顶但不弹出 */
    double peek() const;

    /* 清空栈 */
    void clear();

    /* 当前栈大小 */
    std::size_t size() const { return stk.size(); }

    /* 是否为空 */
    bool empty() const { return stk.empty(); }

    /* 执行一个操作符，操作数从栈顶取 */
    void calculate(const std::string& op);

    /* 把当前栈内容转成字符串，方便打印 */
    std::string stack_string() const;

private:
    std::stack<double> stk;

    /* 工具：弹出一个操作数，若栈空抛异常 */
    double fetch();
};
