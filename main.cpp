//
// Created by 18101 on 24-10-4.
//
#include "Vector.h"
#include <iostream>
#include <conio.h>
int Pos(char ch, const char *str)			// ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
    int i;
    for(i=0; str[i]!='\0'; i++)
        if(ch==str[i])
            return i;
    return -1;
}

int Choice(const char *prompt, const char *options="");	// ��������
int Choice(const char *prompt, const char *options)		// �������塣�����ʾ��Ϣprompt������ѡ����ַ������ء�
{
    int key;
    cout << prompt << "{";
    for(int i=0; options[i]!='\0'; i++)
    {
        if(' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// ѡ��options�еĿɴ�ӡ�ַ�
            cout << options[i] << ' ';
        else														// ѡ��options�еĲ��ֿ����ַ�
        {
            switch(options[i])
            {
                case '\t':   cout << "[Tab] ";   break;					// ѡ���е�Tab�ַ�'\t'����ASCII����9��
                case '\x1b': cout << "[Esc] ";   break;					// ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
                case ' ':    cout << "[Space] "; break;					// ѡ���еĿո��ַ�' '����ASCII����32��
            }
        }
    }
    cout << "\b}: ";					// '\b'�˸�����һ��������һ�����
    do
    {
        key = getch();
    }while(options[0]!='\0' && Pos(key, options)<0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
    cout << endl;
    return key;
}

int main() {
    void testStringClass(), testVectorString(), testVectorint();
    int key;
    while(true)
    {
        cout << "C-�ַ�����������ģ�����" << endl;
        cout << "1 --- C-�ַ�������" << endl;
        cout << "2 --- �ַ���������ģ�����" << endl;
        cout << "3 --- ����������ģ�����" << endl;
        key = Choice("\n��ѡ��", "123\x1b");
        cout << "\n\n";
        if(key==27)		// '\x1b'����27��ָESC��
            break;
        switch(key)
        {
            case '1':	testStringClass();			break;
            case '2':	testVectorString();	        break;
            case '3':	testVectorint();			break;
        }
    }
    return 0;
}


