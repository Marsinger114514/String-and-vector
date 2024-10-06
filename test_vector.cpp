//
// Created by 18101 on 24-10-4.
//
#include "Vector.h"
#include <iostream>
#include "String.h"
void testVectorString() {
    Vector<String> test_String;
    // �����ļ�����
    test_String.input();
    cout << "�ļ���ȡ�ɹ�: " << test_String << endl;

    // β�����Ԫ��
    test_String.push_back("Hello");
    test_String.push_back("World");
    cout << "���Ԫ�� 'Hello', 'World' ��: " << test_String << endl;

    // ͷ�����Ԫ��
    test_String.push_front("Greetings");
    cout << "���Ԫ�� 'Greetings' ��ͷ����: " << test_String << endl;

    // ���ض�λ�ò���Ԫ��
    test_String.insert("C++", 1);
    cout << "������ 1 ���� 'C++' ��: " << test_String << endl;

    // ɾ�����һ��Ԫ��
    test_String.pop_back();
    cout << "ɾ�����һ��Ԫ�غ�: " << test_String << endl;

    // ɾ����һ��Ԫ��
    test_String.pop_front();
    cout << "ɾ����һ��Ԫ�غ�: " << test_String << endl;

    // ɾ���ض�λ�õ�Ԫ��
    test_String.erease(1);
    cout << "ɾ������ 1 ��Ԫ�غ�: " << test_String << endl;

    // ɾ��һ�η�Χ�ڵ�Ԫ��
    test_String.push_back("One");
    test_String.push_back("Two");
    test_String.push_back("Three");
    test_String.erease(1, 2); // ɾ������ 1 �� 2 ��Ԫ��
    cout << "ɾ������ 1 �� 2 ��Ԫ�غ�: " << test_String << endl;

    // ��ת����
    test_String.reverse();
    cout << "��ת��: " << test_String << endl;

    // ��ʾͷ����β��Ԫ��
    cout << "ͷ��Ԫ��: " << test_String.front() << endl;
    cout << "β��Ԫ��: " << test_String.back() << endl;

    // ����С������
    cout << "��С: " << test_String.getsize() << ", ����: " << test_String.space() << endl;

    // ��������Ƿ�Ϊ��
    cout << "�Ƿ�Ϊ��: " << (test_String.isempty() ? "��" : "��") << endl;

    // �ϲ�����
    Vector<String> another_vector;
    another_vector.push_back("Goodbye");
    another_vector.push_back("Everyone");
    try {
        Vector<String> merged_vector = test_String + another_vector;
        cout << "�ϲ���: " << merged_vector << endl;
    }catch (int) {
        cout << "ά����ͬ���޷��ϲ� " << endl;
    }

    Vector<String> other_vector;
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    other_vector.push_back("Goodbye");
    try {
        Vector<String> merged_vector1 = test_String + other_vector;
        cout << "�ϲ���: " << merged_vector1 << endl;
    }catch (int) {
        cout << "ά����ͬ���޷��ϲ� " << endl;
    }

    // ������ļ�
    test_String.output("Output.txt");
    cout << "������������ļ� Output.txt" << endl;

}
void testVectorint() {
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

    // �����쳣���
    try {
        test_vector.erease(100); // ����ɾ��һ�������ڵ�����
    } catch (int ) {
        cout << "�����쳣: ɾ������Խ��" << endl;
    }

    cout << "��������Ϊ0��Ԫ�غ�: " << test_vector[0] << endl;

    try {
        cout << test_vector[2]; // ���Է���һ�������ڵ�Ԫ��
    } catch (int) {
        cout << "�����쳣: �±�Խ��" << endl;
    }

    // �ϲ�����
    Vector<int> another_vector;
    another_vector.push_back(6);
    another_vector.push_back(7);

    // ʹ��+������ϲ�
    Vector<int> merged_vector = test_vector + another_vector;
    cout << "�ϲ���: " << merged_vector << endl;

    Vector<int> other_vector;
    other_vector.push_back(3);
    other_vector.push_back(4);
    other_vector.push_back(5);

    try {
        Vector<int> merged_vector1 = test_vector + other_vector;
    }catch (int) {
        cout<< "ά����ͬ�޷��ϲ�" << endl;
    }


    // �������
    while (!test_vector.isempty()) {
        test_vector.pop_back();
    }
    cout << "��պ��Ƿ�Ϊ��: " << (test_vector.isempty() ? "��" : "��") << endl;

    // �������Ԫ��
    test_vector.push_back(10);
    test_vector.push_back(20);
    cout << "�������Ԫ�� 10 �� 20 ��: " << test_vector << endl;
}