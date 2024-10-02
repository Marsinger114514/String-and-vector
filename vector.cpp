//vector.cpp
#include <bits/stdc++.h>
#include "vector.h"
using namespace std;

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
	if(pos<0 || pos>this->space()) throw -1;                                 //�±�Խ�磬���쳣 
	return *(this+pos);
}

template <typename T>
Vector<T>& Vector<T>:: operator+(const Vector<T>& v) throw(int)
{
	if(this->getsize()!=v.getsize()) throw -1;								//��С��ͬ�����쳣 
	for(int i=0 ;i<this->getsize() ;i++)
	{
		*(this+i)+=v[i];													//ÿ��Ԫ����� 
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
	if(this->getsize()==this->space() )
	{
		capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i <size; i++) 
		{
       		new_data[i] = data[i];												//��ԭ�����е�ÿһ������Ƶ��������� 
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
		*(this+i)=*(this+size-1-i);												//�ѵ�һ������һ���ֵ������Ȼ���ǵڶ�������һ�ֱ��ȫ��������� 
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
		*(this+i+1)=*(this+i);													//��ÿһ��Ԫ�ض������һλ 
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
	size--;																			//������С-1�������в����������������һ��� 
}

template <typename T>
void Vector<T>:: pop_front()
{
	for(int i=1 ;i<size ;i++)
	{
		*(this+i-1)=*(this+i);														//�������ǰ�ƶ�һλ 
	}
	size--;
}

template <typename T>
void Vector<T>:: erease(const int pos) throw (int)
{
	if(pos<0 || pos>this->space()) throw -1;
	for(int i=pos ;i<size ;i++)
	{
		*(this+i-1)=*(this+i);														//pos���Ԫ����ǰ�ƶ�һλ 
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
		*(this+i)=*(this+i+n);														//rt���Ԫ����ǰ�ƶ�nλ
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
int Vector<T>:: getsize()
{
	return size;
}

template <typename T>
int Vector<T>:: space()
{
	return capacity;
}

template <typename T>
bool Vector<T>:: isempty()
{
	if(size==0) return true;
	return false;
}

template <typename T>
void Vector<T>:: input()
{
	ofstream ofs;
	ofs.open("text.txt",ios::in);                                    					//�ļ�����ʱ�ٶ�Ϊtext������������� 
	ofs.close();
}

template <typename T>
void Vector<T>:: output()
{
	ofstream ofs;
	ofs.open("text.txt",ios::out);
	ofs.close();
}
