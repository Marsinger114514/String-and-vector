#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class String {
public:
    String(); // Ĭ�Ϲ��캯��
    String(const char* str); // ����ΪC�ַ����Ĺ��캯��
    String(const String& other); // �������캯��
    String(String&& other) noexcept; // �ƶ����캯��
    ~String(); // ��������

    String& operator=(const String& other); // ������ֵ�����
    String& operator=(String&& other) noexcept; // �ƶ���ֵ�����

    size_t length() const; // ��ȡ�ַ�������
    const char* c_str() const; // ��ȡC�ַ���
    char& operator[](size_t index); // ����[]����������޸ģ�
    const char& operator[](size_t index) const; // ����[]�������ֻ����

    String operator+(const String& other) const; // ����+�����
    String& operator+=(const String& other); // ����+=�����

    bool operator<(const String& other) const; // ����<�����
    bool operator<=(const String& other) const; // ����<=�����
    bool operator>(const String& other) const; // ����>�����
    bool operator>=(const String& other) const; // ����>=�����
    bool operator==(const String& other) const; // ����==�����
    bool operator!=(const String& other) const; // ����!=�����

    friend std::ostream& operator<<(std::ostream& os, const String& str); // ����<<�����
    friend std::istream& operator>>(std::istream& is, String& str); // ����>>�����

    void clear(); // ����ַ�������
    String copy() const; // �����ַ����ĸ���
    unsigned int size() const; // �����ַ����Ĵ�С
    bool empty() const; // �ж��ַ����Ƿ�Ϊ��
    String& reverse(); // ��ת�ַ���
    String& append(const String& str); // ׷���ַ���
    String& erase(const unsigned int& index, const unsigned int& len); // ����ָ��λ�õ��Ӵ�

private:
    char* data;
    size_t len;
    void copy_data(const char* str); // �������������ڸ����ַ���
};

#endif // STRING_H
