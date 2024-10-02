//vector.h
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
	public:
		Vector():data(NULL),size(0),capacity(4096)														//���캯��
		{
			T arr[capacity];
			data=arr;
		};  													
		Vector(int s): data(NULL),size(s),capacity(4096){}; 											//���캯��
		Vector(Vector<T> &vec):data(vec.data),size(vec.size),capacity(vec.capacity){}; 					//������캯�� 
		~Vector()
		{
			delete[] data;
		};
		Vector <T>& operator=(const Vector<T>& v); 														//���ظ�ֵ�����
		T& operator[](int pos) throw(int);     															//����[]��������±�Խ���׳��쳣
		Vector<T>& operator+(const Vector<T>& v)throw(int);  											//����+�������ʵ�������������λ��Ԫ����Ӻ�ϲ�Ϊһ������,����ͬ��С����֮�䲻����ӣ�����С��ͬ���׳��쳣
		Vector<T>& operator+=(const Vector<T>& v)throw(int);
		friend ostream & operator << <T> (ostream& ,const Vector<T>& v);								//������������������չʾ����Ļ�ϣ�����������ļ���
		void resize();  																				//�ռ䲻���Զ���չ
		void reverse(); 																				//��������
		void input();																					//���ļ��ڶ�ȡ���ݵ�����
		void output();																					//������������ݵ��ļ�
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
		int getsize();																					//����������С
		int space();																					//������������
		bool isempty();																					//���������Ƿ�Ϊ��
	private:
		T *data;
		int size;
		int capacity;
};
