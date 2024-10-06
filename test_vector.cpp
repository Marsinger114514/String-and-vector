//
// Created by 18101 on 24-10-4.
//
#include "Vector.h"
#include <iostream>
#include "String.h"
// void testVectorstringClass() {
//     Vector<String> testString;
//
// }
void testVector() {
    // ����һ������ Vector
    Vector<int> test_vector;

    // β�����Ԫ��
    test_vector.push_back(1);
    test_vector.push_back(2);
    test_vector.push_back(3);
    cout << "���Ԫ�� 1, 2, 3 ��: " << test_vector << endl;

    // ͷ�����Ԫ��
    test_vector.push_front(0);
    cout << "���Ԫ�� 0 ��ͷ����: " << test_vector << endl;

    // ���ض�λ�ò���Ԫ��
    test_vector.insert(1, 2);  // ������ 2 ����Ԫ�� 1
    cout << "������ 2 ���� 1 ��: " << test_vector << endl;

    // ɾ�����һ��Ԫ��
    test_vector.pop_back();
    cout << "ɾ�����һ��Ԫ�غ�: " << test_vector << endl;

    // ɾ����һ��Ԫ��
    test_vector.pop_front();
    cout << "ɾ����һ��Ԫ�غ�: " << test_vector << endl;

    // ɾ���ض�λ�õ�Ԫ��
    test_vector.erease(2); // ɾ������ 2 ��Ԫ��
    cout << "ɾ������ 2 ��Ԫ�غ�: " << test_vector << endl;

    // ɾ��һ�η�Χ�ڵ�Ԫ��
    test_vector.erease(1, 2); // ɾ������ 1 �� 2 ��Ԫ��
    cout << "ɾ������ 1 �� 2 ��Ԫ�غ�: " << test_vector << endl;

    // ��ת����
    test_vector.push_back(4);
    test_vector.push_back(5);
    test_vector.reverse();
    cout << "���Ԫ��4��5��ת��: " << test_vector <<endl;

    // ��ʾͷ����β��Ԫ��
    cout << "ͷ��Ԫ��: " << test_vector.front() << endl;
    cout << "β��Ԫ��: " << test_vector.back() << endl;

    // ����С������
    cout << "��С: " << test_vector.getsize() << ", ����: " << test_vector.space() << endl;

    // ��������Ƿ�Ϊ��
    cout << "�Ƿ�Ϊ��: " << (test_vector.isempty() ? "��" : "��") << endl;
}