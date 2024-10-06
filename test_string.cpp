#include <iostream>
#include "String.h"

void testStringClass() {
    try {
        // Ĭ�Ϲ��캯��
        String str1;
        std::cout << "Default constructed string: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // C ����ַ������캯��
        String str2("Hello");
        std::cout << "C-string constructed string: '" << str2 << "' (length: " << str2.length() << ")" << std::endl;

        // �������캯��
        String str3(str2);
        std::cout << "Copy constructed string: '" << str3 << "' (length: " << str3.length() << ")" << std::endl;

        // �ƶ����캯��
        String str4(std::move(str3));
        std::cout << "Move constructed string: '" << str4 << "' (length: " << str4.length() << ")" << std::endl;
        std::cout << "Original string after move: '" << str3 << "' (length: " << str3.length() << ")" << std::endl;

        // ������ֵ�����
        str1 = str2;
        std::cout << "After copy assignment, str1: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // �ƶ���ֵ�����
        str1 = std::move(str4);
        std::cout << "After move assignment, str1: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;
        std::cout << "Original string after move assignment: '" << str4 << "' (length: " << str4.length() << ")" << std::endl;

        // �±������
        std::cout << "Character at index 1: " << str1[1] << std::endl;
        try {
            std::cout << "Character at index 100: " << str1[100] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // �ַ������������
        String str5 = str1 + str2;
        std::cout << "Concatenated string: '" << str5 << "' (length: " << str5.length() << ")" << std::endl;

        // �ַ���׷�������
        str1 += str2;
        std::cout << "Appended string: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // �Ƚ������
        std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
        std::cout << "str1 != str2: " << (str1 != str2) << std::endl;
        std::cout << "str1 < str2: " << (str1 < str2) << std::endl;
        std::cout << "str1 <= str2: " << (str1 <= str2) << std::endl;
        std::cout << "str1 > str2: " << (str1 > str2) << std::endl;
        std::cout << "str1 >= str2: " << (str1 >= str2) << std::endl;

        // �������
        std::cout << "Enter a string: ";
        String str6;
        std::cin >> str6;
        std::cout << "You entered: " << str6 << std::endl;

        // ����ַ�������
        str6.clear();
        std::cout << "After clear, str6: '" << str6 << "' (length: " << str6.length() << ", empty: " << std::boolalpha << str6.empty() << ")" << std::endl;

        // �����ַ����ĸ���
        String str7 = str1.copy();
        std::cout << "Copied string: '" << str7 << "' (length: " << str7.length() << ")" << std::endl;

        // �����ַ����Ĵ�С
        std::cout << "Size of str1: " << str1.size() << std::endl;

        // �ж��ַ����Ƿ�Ϊ��
        std::cout << "Is str1 empty? " << std::boolalpha << str1.empty() << std::endl;

        // ��ת�ַ���
        str1.reverse();
        std::cout << "Reversed string: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;
        str1.reverse(); // Reverse back to original for further tests

        // ׷���ַ���
        str1.append(" World");
        std::cout << "Appended ' World': '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // ����ָ��λ�õ��Ӵ�
        str1.erase(5, 5); // Erase " World"
        std::cout << "After erase ' Hello': '" << str1 << "' (length: " << str1.length() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}


