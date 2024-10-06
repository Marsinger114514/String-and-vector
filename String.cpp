#include "String.h"
#include <stdexcept>
#include <cstring>

// Ĭ�Ϲ��캯������ʼ�� data Ϊ nullptr������ len Ϊ 0
String::String() : data(nullptr), len(0) {}

// ���캯�������� C ����ַ�������������
String::String(const char* str) : data(nullptr), len(0) {
    if (str) {
        copy_data(str);
    }
}

// �������캯������������ String ���������
String::String(const String& other) : data(nullptr), len(0) {
    if (other.data) {
        copy_data(other.data);
    }
}

// �ƶ����캯�����ƶ����� String ���������
String::String(String&& other) noexcept : data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

// �����������ͷŶ�̬������ڴ�
String::~String() {
    delete[] data;
}

// ������ֵ�����
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

// �ƶ���ֵ�����
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

// �������ݵ���̬������ڴ�
void String::copy_data(const char* str) {
    len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
}

// �����ַ�������
size_t String::length() const {
    return len;
}

// ���� C ����ַ���
const char* String::c_str() const {
    return data;
}

// �±�����������ؿ��޸��ַ�
char& String::operator[](size_t index) {
    if (index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// �±�����������ز����޸��ַ�
const char& String::operator[](size_t index) const {
    if (index >= len) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

// �ַ���������������������ַ���
String String::operator+(const String& other) const {
    size_t new_len = len + other.len;
    char* new_data = new char[new_len + 1];
    std::strcpy(new_data, data);
    std::strcat(new_data, other.data);
    String new_str(new_data);
    delete[] new_data;
    return new_str;
}

// �ַ���׷�������
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

//���ظ����Ƚ������
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

// ����ַ�������
void String::clear() {
    delete[] data;
    data = nullptr;
    len = 0;
}

// �����ַ����ĸ���
String String::copy() const {
    return String(data);
}

// �����ַ����Ĵ�С
unsigned int String::size() const {
    return static_cast<unsigned int>(len);
}

// �ж��ַ����Ƿ�Ϊ��
bool String::empty() const {
    return len == 0;
}

// ��ת�ַ���
String& String::reverse() {
    for (size_t i = 0; i < len / 2; ++i) {
        std::swap(data[i], data[len - i - 1]);
    }
    return *this;
}

// ׷���ַ���
String& String::append(const String& str) {
    *this += str;
    return *this;
}

// ����ָ��λ�õ��Ӵ�
String& String::erase(const unsigned int& index, const unsigned int& len) {
    if (index >= this->len || index + len > this->len) {
        throw std::out_of_range("Index out of range");
    }
    std::memmove(data + index, data + index + len, this->len - index - len + 1);
    this->len -= len;
    data[this->len] = '\0';
    return *this;
}
