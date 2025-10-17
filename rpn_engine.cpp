#include "rpn_engine.hpp"
#include <cmath>
#include <sstream>
#include <vector>

void RPNCalculator::push(double value) { stk.push(value); }

double RPNCalculator::pop() {
    if (stk.empty()) throw std::runtime_error("stack underflow");
    double v = stk.top();
    stk.pop();
    return v;
}

double RPNCalculator::peek() const {
    if (stk.empty()) throw std::runtime_error("stack empty");
    return stk.top();
}

void RPNCalculator::clear() { while (!stk.empty()) stk.pop(); }

double RPNCalculator::fetch() {
    if (stk.empty()) throw std::runtime_error("stack underflow");
    double v = stk.top();
    stk.pop();
    return v;
}

void RPNCalculator::calculate(const std::string& op) {
    if (op == "+" || op == "-" || op == "*" || op == "/") {
        double b = fetch();
        double a = fetch();
        if (op == "+") { push(a + b); return; }
        if (op == "-") { push(a - b); return; }
        if (op == "*") { push(a * b); return; }
        if (op == "/") {
            if (b == 0) throw std::runtime_error("divide by zero");
            push(a / b);
            return;
        }
    }
    /* --- 高级功能：斐波那契 --- */
    if (op == "fib") {
        int n = static_cast<int>(fetch());
        if (n < 0) throw std::runtime_error("fib index must >= 0");
        long long a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            long long t = a + b;
            a = b; b = t;
        }
        push(static_cast<double>(a));
        return;
    }
    /* --- 高级功能：幂运算 --- */
    if (op == "pow") {
        double y = fetch();
        double x = fetch();
        push(std::pow(x, y));
        return;
    }
    /* --- 高级功能：平方根 --- */
    if (op == "sqrt") {
        double x = fetch();
        if (x < 0) throw std::runtime_error("sqrt of negative");
        push(std::sqrt(x));
        return;
    }
    throw std::runtime_error("unknown operator: " + op);
}

std::string RPNCalculator::stack_string() const {
    if (stk.empty()) return "[空栈]";
    std::stack<double> tmp(stk);
    std::vector<double> v;
    while (!tmp.empty()) { v.push_back(tmp.top()); tmp.pop(); }
    std::ostringstream os;
    os << "[栈底] ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) os << *it << ' ';
    os << "[栈顶]";
    return os.str();
}
