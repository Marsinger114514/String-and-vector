//vector.h
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
	public:
		Vector():data(NULL),size(0),capacity(4096)														//构造函数
		{
			T arr[capacity];
			data=arr;
		};  													
		Vector(int s): data(NULL),size(s),capacity(4096){}; 											//构造函数
		Vector(Vector<T> &vec):data(vec.data),size(vec.size),capacity(vec.capacity){}; 					//深拷贝构造函数 
		~Vector()
		{
			delete[] data;
		};
		Vector <T>& operator=(const Vector<T>& v); 														//重载赋值运算符
		T& operator[](int pos) throw(int);     															//重载[]运算符，下标越界抛出异常
		Vector<T>& operator+(const Vector<T>& v)throw(int);  											//重载+运算符，实现两个数组各个位置元素相加后合并为一个数组,但不同大小数组之间不能相加，若大小不同，抛出异常
		Vector<T>& operator+=(const Vector<T>& v)throw(int);
		friend ostream & operator << <T> (ostream& ,const Vector<T>& v);								//重载输出运算符（这是展示到屏幕上，不是输出到文件）
		void resize();  																				//空间不足自动扩展
		void reverse(); 																				//逆置向量
		void input();																					//从文件内读取内容到容器
		void output();																					//输出容器内数据到文件
		void push_back(const T val);																	//尾部插入一个元素
		void push_front(const T val);																	//头部插入一个元素
		void insert(const T val, int pos);																//在pos位置后插入一个元素（从0开始）
		void insert(const T val, int pos, int n);														//重载，在pos位置后插入n个元素val重载，在pos位置后插入n个元素val
		void pop_back();																				//在容器末尾删除一个元素
		void pop_front();																				//在容器头部删除一个元素
		void erease(const int pos) throw (int);															//删除pos位置的一个元素,下标越界抛出异常!
		void erease(const int lt, const int rt) throw (int);											//删除从[left,right]闭区间内的所有元素，下标越界抛出异常
		T& front();																						//获取头部元素（返回引用类型）
		T& back();																						//获取尾部元素（返回引用类型）
		int getsize();																					//返回容器大小
		int space();																					//返回容器容量
		bool isempty();																					//返回容器是否为空
	private:
		T *data;
		int size;
		int capacity;
};
