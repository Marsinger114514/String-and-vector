//vector.h
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <fstream>
using namespace std;
template <typename T>
class Vector
{
	public:
		Vector():data(nullptr),size(0),capacity(4096)														//���캯��
		{
			data = new T[capacity];
		};  													
		Vector(const int s): data(nullptr),size(0),capacity(s) {											//���캯��
			data = new T[capacity];
		};
		Vector(const Vector<T>& vec) : size(vec.size), capacity(vec.capacity) {								//������캯��
			data = new T[capacity];
			for (int i = 0; i < size; i++) {
				data[i] = vec.data[i];
			}
		}
		~Vector()
		{
			delete[] data;
		};
		Vector <T>& operator=(const Vector<T>& v); 														//���ظ�ֵ�����
		T& operator[](int pos) throw(int);     															//����[]��������±�Խ���׳��쳣
		const T& operator[](int pos) const throw(int) ;
		Vector<T>& operator+(const Vector<T>& v)throw(int);  											//����+�������ʵ�������������λ��Ԫ����Ӻ�ϲ�Ϊһ������,����ͬ��С����֮�䲻����ӣ�����С��ͬ���׳��쳣
		Vector<T>& operator+=(const Vector<T>& v)throw(int);
		template <typename U>
		friend std::ostream& operator<<(std::ostream& out, const Vector<U>& v);								//������������������չʾ����Ļ�ϣ�����������ļ���
		void resize();  																				//�ռ䲻���Զ���չ
		void reverse(); 																				//��������
		void input();																					//���ļ��ڶ�ȡ���ݵ�����
		void output(const string& filename);																					//������������ݵ��ļ�
		void push_back(const T val);																	//β������һ��Ԫ��
		void push_front(const T val);																	//ͷ������һ��Ԫ��
		void insert(const T val, int pos);																//��posλ�ú����һ��Ԫ�أ���0��ʼ��
		void insert(const T val, int pos, int n);														//���أ���posλ�ú����n��Ԫ��val���أ���posλ�ú����n��Ԫ��val
		void pop_back();																				//������ĩβɾ��һ��Ԫ��
		void pop_front();																				//������ͷ��ɾ��һ��Ԫ��
		void erease(const int pos) throw (int);															//ɾ��posλ�õ�һ��Ԫ��,�±�Խ���׳��쳣!
		void erease(const int lt, const int rt) throw (int);											//ɾ����[left,right]�������ڵ�����Ԫ�أ��±�Խ���׳��쳣
		T& front();																						//��ȡͷ��Ԫ�أ������������ͣ�
		T& back();																						//��ȡβ��Ԫ�أ������������ͣ�
		int getsize() const;																					//����������С
		int space() const;																					//������������
		bool isempty() const;																					//���������Ƿ�Ϊ��
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
		data[i]=v[i];
	}
	return *this;
}

template <typename T>
T& Vector<T>:: operator[](int pos) throw (int)
{
	if(pos<0 || pos >= size) throw -1;                                 //�±�Խ�磬���쳣
	return data[pos];
}

template <typename T>
const T& Vector<T>::operator[](int pos) const throw(int) {
	if (pos < 0 || pos >= size) throw -1; // �±�Խ�磬�׳��쳣
	return data[pos]; // ���� const ���ã������޸�
}

template <typename T>
Vector<T>& Vector<T>:: operator+(const Vector<T>& v) throw(int)
{
	if(this->getsize()!=v.getsize()) throw -1;								//��С��ͬ�����쳣 
	for(int i=0 ;i<this->getsize() ;i++)
	{
		data[i] += v[i];													//ÿ��Ԫ�����
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>:: operator+=(const Vector<T>& v) throw(int)
{
	if(this->getsize() != v.getsize() ) throw -1;
	Vector<T> result(*this);
	for(int i=0 ;i<this->getsize() ;i++)
	{
		result[i] += v[i]; ;
	}
	return result;
}

template <typename T>
std::ostream & operator<<(std::ostream& out, const Vector<T>& v) {
    for (int i = 0; i < v.getsize(); i++) {
        out << v[i] << ' ';
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
		temp = data[i];
		data[i] = data[size - 1 - i]; // ����ǰԪ����Գ�λ�õ�Ԫ�ؽ���
		data[size - 1 - i] = temp;
	}
}

template <typename T>
void Vector<T>:: push_back(const T val)
{
	resize();
	data[size] = val;
	size++;
}

template <typename T>
void Vector<T>:: push_front(const T val)
{
	resize();
	for(int i = size-1 ;i >= 0 ;i--)
	{
		data[i+1] = data[i];													//��ÿһ��Ԫ�ض������һλ
	}
	data[0] = val;
	size++;
}

template <typename T>
void Vector<T>:: insert(const T val, int pos)
{
	resize();
	for(int i=size-1 ;i>=pos-1 ;i--)
	{
		data[i+1]=data[i];
	}
	data[pos-1]=val;
	size++;
}

template <typename T>
void Vector<T>:: insert(const T val, int pos, int n)
{
	for(int i=0 ;i<n ;i++)
	{
		for(int j=size+i-1 ;j>=pos - 1 ;j--)
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
		data[i-1]=data[i];														//�������ǰ�ƶ�һλ
	}
	size--;
}

template <typename T>
void Vector<T>:: erease(const int pos) throw (int)
{
	if(pos<0 || pos>size) throw -1;
	for(int i=pos ;i<size ;i++)
	{
		data[i-1]=data[i];														//pos���Ԫ����ǰ�ƶ�һλ
	}
	size--;
}

template <typename T>
void Vector<T>:: erease(const int lt, const int rt) throw (int)
{
	if(lt<0 || lt>size || rt<0 || rt>size || lt>rt) throw -1;
	int n=rt-lt+1;
	for(int i=lt-1 ;i<size-n ;i++)
	{
		data[i]=data[i+n];														//rt���Ԫ����ǰ�ƶ�nλ
	}
	size-=n;
}

template <typename T>
T& Vector<T>:: front()
{
	return data[0];
}

template <typename T>
T& Vector<T>:: back()
{
	return data[size-1];
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
void Vector<T>::input() {
	ifstream ifs("text.txt");
	if (!ifs) {
		cout << "�޷����ļ�!" << endl;
		return;
	}

	T value;
	while (ifs >> value) {
		push_back(value); // ʹ�� push_back ��ӵ�������
	}
	ifs.close();
}

template <typename T>
void Vector<T>::output(const string& filename) {
	ofstream ofs(filename, ios::out);
	if (!ofs) {
		cerr << "�޷����ļ�: " << filename << endl;
		return;
	}
	for (int i = 0; i < size; ++i) {
		ofs << data[i] << ' ';
	}
	ofs.close();
}



#endif
