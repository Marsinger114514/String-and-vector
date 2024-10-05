#include "String.h"
#include <stdexcept>
#include <cstring>

// 默认构造函数，初始化 data 为 nullptr，长度 len 为 0
String::String() : data(nullptr), len(0) {}

// 构造函数，接收 C 风格字符串并复制数据
String::String(const char* str) : data(nullptr), len(0) {
    if (str) {
        copy_data(str);
    }
}

// 拷贝构造函数，复制其他 String 对象的数据
String::String(const String& other) : data(nullptr), len(0) {
    if (other.data) {
        copy_data(other.data);
    }
}

// 移动构造函数，移动其他 String 对象的数据
String::String(String&& other) noexcept : data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

// 析构函数，释放动态分配的内存
String::~String() {
    delete[] data;
}

// 拷贝赋值运算符
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        data = nullptr;
        len = 0;
        if (other.data) {
            copy_data(other.data);
        }
    }
    return *this;
}

// 移动赋值运算符
String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }
    return *this;
}

// 复制数据到动态分配的内存
void String::copy_data(const char* str) {
    len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
}

// 返回字符串长度
size_t String::length() const {
    return len;
}

// 返回 C 风格字符串
const char* String::c_str() const {
    return data;
}

// 下标运算符，返回可修改字符
char& String::operator[](size_t index) {
    if (index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// 下标运算符，返回不可修改字符
const char& String::operator[](size_t index) const {
    if (index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// 字符串连接运算符，返回新字符串
String String::operator+(const String& other) const {
    size_t new_len = len + other.len;
    char* new_data = new char[new_len + 1];
    std::strcpy(new_data, data);
    std::strcat(new_data, other.data);
    String new_str(new_data);
    delete[] new_data;
    return new_str;
}

// 字符串追加运算符
String& String::operator+=(const String& other) {
    size_t new_len = len + other.len;
    char* new_data = new char[new_len + 1];
    std::strcpy(new_data, data);
    std::strcat(new_data, other.data);
    delete[] data;
    data = new_data;
    len = new_len;
    return *this;
}

//重载各个比较运算符
bool String::operator<(const String& other) const {
    return std::strcmp(data, other.data) < 0;
}

bool String::operator<=(const String& other) const {
    return std::strcmp(data, other.data) <= 0;
}

bool String::operator>(const String& other) const {
    return std::strcmp(data, other.data) > 0;
}

bool String::operator>=(const String& other) const {
    return std::strcmp(data, other.data) >= 0;
}

bool String::operator==(const String& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const {
    return std::strcmp(data, other.data) != 0;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    if (str.data) {
        os << str.data;
    }
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    char buffer[1024];
    is >> buffer;
    str = String(buffer);
    return is;
}

// 清空字符串数据
void String::clear() {
    delete[] data;
    data = nullptr;
    len = 0;
}

// 返回字符串的副本
String String::copy() const {
    return String(data);
}

// 返回字符串的大小
unsigned int String::size() const {
    return static_cast<unsigned int>(len);
}

// 判断字符串是否为空
bool String::empty() const {
    return len == 0;
}

// 逆转字符串
String& String::reverse() {
    for (size_t i = 0; i < len / 2; ++i) {
        std::swap(data[i], data[len - i - 1]);
    }
    return *this;
}

// 追加字符串
String& String::append(const String& str) {
    *this += str;
    return *this;
}

// 擦除指定位置的子串
String& String::erase(const unsigned int& index, const unsigned int& len) {
    if (index >= this->len || index + len > this->len) {
        throw std::out_of_range("Index out of range");
    }
    std::memmove(data + index, data + index + len, this->len - index - len + 1);
    this->len -= len;
    data[this->len] = '\0';
    return *this;
}
