//vector.h
#ifndef VECTOR_H
#define VECTOR_H
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
	public:
		Vector():data(nullptr),size(0),capacity(4096)														//构造函数
		{
			data = new T[capacity];
		};  													
		Vector(const int s): data(nullptr),size(0),capacity(s) {											//构造函数
			data = new T[capacity];
		};
		Vector(const Vector<T>&vec):data(vec.data),size(vec.size),capacity(vec.capacity){}; 					//深拷贝构造函数
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
		int getsize() const;																					//返回容器大小
		int space() const;																					//返回容器容量
		bool isempty() const;																					//返回容器是否为空
	private:
		T *data;
		int size;
		int capacity;
};




template <typename T>
Vector<T>& Vector<T>:: operator=(const Vector<T>& v)
{
	if(this==&v) return *this;
	for(int i=0 ;i<v.getsize() ;i++)
	{
		*(this+i)=v[i];
	}
	return *this;
}

template <typename T>
T& Vector<T>:: operator[](int pos) throw (int)
{
	if(pos<0 || pos>this->space()) throw -1;                                 //下标越界，抛异常 
	return *(this+pos);
}

template <typename T>
Vector<T>& Vector<T>:: operator+(const Vector<T>& v) throw(int)
{
	if(this->getsize()!=v.getsize()) throw -1;								//大小不同，抛异常 
	for(int i=0 ;i<this->getsize() ;i++)
	{
		*(this+i)+=v[i];													//每个元素相加 
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>:: operator+=(const Vector<T>& v) throw(int)
{
	if(this->getsize() != v.getsize() ) throw -1;
	for(int i=0 ;i<this->getsize() ;i++)
	{
		*(this+i)+=v[i];
	}
	return *this;
}

template <typename T>
ostream &operator <<(ostream& out,const Vector<T>& v)
{
	for(int i=0 ;i<v.getsize() ;i++)
	{
		out<<v[i]<<' ';
	}
	return out;
}

template <typename T>
void Vector<T>:: resize()
{
	if(this->getsize()>=this->space() )
	{
		capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i <size; i++) 
		{
       		new_data[i] = data[i];												//把原数组中的每一项都都复制到新数组中 
        }
        delete[] data;
        data = new_data; 
	}
}

template <typename T>
void Vector<T>:: reverse()
{
	T temp;
	for(int i=0 ;i<size/2 ;i++)
	{
		temp=*(this+i);
		*(this+i)=*(this+size-1-i);												//把第一项和最后一项的值交换，然后是第二项和最后一项，直到全部交换完成 
		*(this+size-1-i)=temp;
	}
}

template <typename T>
void Vector<T>:: push_back(const T val)
{
	resize();
	*(this+size)=val;
	size++;
}

template <typename T>
void Vector<T>:: push_front(const T val)
{
	resize();
	for(int i=size-1 ;i>=0 ;i--)
	{
		*(this+i+1)=*(this+i);													//把每一个元素都向后移一位 
	}
	*this=val;
	size++;
}

template <typename T>
void Vector<T>:: insert(const T val, int pos)
{
	resize();
	for(int i=size-1 ;i>=pos-1 ;i--)
	{
		*(this+i+1)=*(this+i);
	}
	*(this+pos-1)=val;
	size++;
}

template <typename T>
void Vector<T>:: insert(const T val, int pos, int n)
{
	for(int i=0 ;i<n ;i++)
	{
		for(int j=size+i-1 ;i>=pos+i-1 ;j--)
		{
			*(this+j+1)=*(this+j);
		}
	}
	for(int i=0 ;i<n ;i++)
	{
		*(this+pos-1+i)=val;
	}
	size+=n;
}

template <typename T>
void Vector<T>:: pop_back()
{
	size--;																			//容器大小-1，让所有操作都检索不到最后一项即可 
}

template <typename T>
void Vector<T>:: pop_front()
{
	for(int i=1 ;i<size ;i++)
	{
		*(this+i-1)=*(this+i);														//所有项都向前移动一位 
	}
	size--;
}

template <typename T>
void Vector<T>:: erease(const int pos) throw (int)
{
	if(pos<0 || pos>this->space()) throw -1;
	for(int i=pos ;i<size ;i++)
	{
		*(this+i-1)=*(this+i);														//pos后的元素向前移动一位 
	}
	size--;
}

template <typename T>
void Vector<T>:: erease(const int lt, const int rt) throw (int)
{
	if(lt<0 || lt>this->space() || rt<0 || rt>this->space() || lt>rt) throw -1;
	int n=rt-lt+1;
	for(int i=lt-1 ;i<size-n ;i++)
	{
		*(this+i)=*(this+i+n);														//rt后的元素向前移动n位
	}
	size-=n;
}

template <typename T>
T& Vector<T>:: front()
{
	return *this;
}

template <typename T>
T& Vector<T>:: back()
{
	return *(this+size-1);
}

template <typename T>
int Vector<T>:: getsize() const
{
	return size;
}

template <typename T>
int Vector<T>:: space() const
{
	return capacity;
}

template <typename T>
bool Vector<T>:: isempty() const
{
	if(size==0) return true;
	return false;
}

template <typename T>
void Vector<T>:: input()
{
	ofstream ofs;
	ofs.open("text.txt",ios::in);                                    					//文件名暂时假定为text，按照所需更改 
	ofs.close();
}

template <typename T>
void Vector<T>:: output()
{
	ofstream ofs;
	ofs.open("text.txt",ios::out);
	ofs.close();
}



#endif
