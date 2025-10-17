#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "rpn_engine.hpp"

static void print_banner() {
    std::cout << "=== C++ RPN 计算器 ===\n"
                 "支持操作: +  -  *  /  pow  sqrt  fib\n"
                 "输入表达式（如 3 4 + 5 *），或 q 退出\n";
}

static std::vector<std::string> tokenize(const std::string& line) {
    std::istringstream iss(line);
    std::vector<std::string> out;
    std::string tok;
    while (iss >> tok) out.push_back(tok);
    return out;
}

int main() {
    RPNCalculator calc;
    print_banner();
    std::string line;
    while (std::cout << "> " && std::getline(std::cin, line)) {
        if (line == "q" || line == "quit") break;
        if (line.empty()) continue;
        try {
            auto toks = tokenize(line);
            for (const auto& t : toks) {
                /* 尝试先解析成数字 */
                char* end = nullptr;
                double val = std::strtod(t.c_str(), &end);
                if (*end == '\0') {          // 解析成功
                    calc.push(val);
                } else {                     // 不是数字，当操作符
                    calc.calculate(t);
                }
            }
            /* 输出栈顶作为结果 */
            std::cout << "结果: " << calc.peek() << '\n';
        } catch (const std::exception& ex) {
            std::cerr << "错误: " << ex.what() << '\n';
        }
    }
    std::cout << "再见~\n";
    return 0;
}
