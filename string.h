#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
public:
    String(); // 默认构造函数
    String(const char* str); // 参数为C字符串的构造函数
    String(const String& other); // 拷贝构造函数
    String(String&& other) noexcept; // 移动构造函数
    ~String(); // 析构函数

    String& operator=(const String& other); // 拷贝赋值运算符
    String& operator=(String&& other) noexcept; // 移动赋值运算符

    size_t length() const; // 获取字符串长度
    const char* c_str() const; // 获取C字符串
    char& operator[](size_t index); // 重载[]运算符（可修改）
    const char& operator[](size_t index) const; // 重载[]运算符（只读）

    String operator+(const String& other) const; // 重载+运算符
    String& operator+=(const String& other); // 重载+=运算符

    bool operator<(const String& other) const; // 重载<运算符
    bool operator<=(const String& other) const; // 重载<=运算符
    bool operator>(const String& other) const; // 重载>运算符
    bool operator>=(const String& other) const; // 重载>=运算符
    bool operator==(const String& other) const; // 重载==运算符
    bool operator!=(const String& other) const; // 重载!=运算符

    friend std::ostream& operator<<(std::ostream& os, const String& str); // 重载<<运算符
    friend std::istream& operator>>(std::istream& is, String& str); // 重载>>运算符

private:
    char* data;
    size_t len;

    void copy_data(const char* str); // 辅助函数，用于复制字符串
};

#endif // STRING_H