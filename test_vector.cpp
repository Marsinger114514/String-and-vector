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
    // 创建一个整型 Vector
    Vector<int> test_vector;

    // 尾部添加元素
    test_vector.push_back(1);
    test_vector.push_back(2);
    test_vector.push_back(3);
    cout << "添加元素 1, 2, 3 后: " << test_vector << endl;

    // 头部添加元素
    test_vector.push_front(0);
    cout << "添加元素 0 到头部后: " << test_vector << endl;

    // 在特定位置插入元素
    test_vector.insert(1, 2);  // 在索引 2 插入元素 1
    cout << "在索引 2 插入 1 后: " << test_vector << endl;

    // 删除最后一个元素
    test_vector.pop_back();
    cout << "删除最后一个元素后: " << test_vector << endl;

    // 删除第一个元素
    test_vector.pop_front();
    cout << "删除第一个元素后: " << test_vector << endl;

    // 删除特定位置的元素
    test_vector.erease(2); // 删除索引 2 的元素
    cout << "删除索引 2 的元素后: " << test_vector << endl;

    // 删除一段范围内的元素
    test_vector.erease(1, 2); // 删除索引 1 到 2 的元素
    cout << "删除索引 1 到 2 的元素后: " << test_vector << endl;

    // 反转向量
    test_vector.push_back(4);
    test_vector.push_back(5);
    test_vector.reverse();
    cout << "添加元素4，5反转后: " << test_vector <<endl;

    // 显示头部和尾部元素
    cout << "头部元素: " << test_vector.front() << endl;
    cout << "尾部元素: " << test_vector.back() << endl;

    // 检查大小和容量
    cout << "大小: " << test_vector.getsize() << ", 容量: " << test_vector.space() << endl;

    // 检查向量是否为空
    cout << "是否为空: " << (test_vector.isempty() ? "是" : "否") << endl;
}