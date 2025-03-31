#include <iostream>
#include <stack>
#include <string>

std::string decimalToBase(int N, int B) {
    if (N < 0) return "请输入非负十进制数";
    if (B < 2 || B > 36) return "无效的进制";
    
    std::stack<char> digits;
    
    while (N > 0) {
        int remainder = N % B;
        char digit;
        
        if (remainder < 10) {
            digit = '0' + remainder;
        } else {
            digit = 'A' + (remainder - 10);
        }
        
        digits.push(digit);
        N /= B;
    }
    
    std::string result = "";
    while (!digits.empty()) {
        result += digits.top();
        digits.pop();
    }
    
    return result;
}

int main() {
    int N, B;
    std::cout << "请输入十进制数N: ";
    std::cin >> N;
    std::cout << "请输入目标进制B: ";
    std::cin >> B;
    std::string result = decimalToBase(N, B);
    std::cout << "转换结果: " << result << std::endl;
    
    return 0;
}