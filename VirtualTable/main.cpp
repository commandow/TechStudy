#include "stdio.h"
#include <iostream>

using namespace std;

class Base
{
public:
	virtual void a();
	virtual void b();
	virtual void c();
};

void Base::a()
{
	cout << "base::a" << endl;
}

void Base::b()
{
	cout << "base::b" << endl;
}

void Base::c()
{
	cout << "base::c" << endl;
}

class Derived : public Base
{
public:
	void a();
};

void Derived::a()
{
	cout << "derived::a" << endl;
}

typedef void (*func)();

int main(int argc, char **argv)
{
	// �ȿ��̳���ĵ�ַ�ռ�
	Derived derive;
	printf("derive::vptr %p\n", *(int *)&derive);

	// ��ȡ�麯����ĵ�ַ
	int *v_ptr = (int *)(*(int *)&derive);

	printf("derive::vptr->a %p\n", *v_ptr);
	printf("derive::vptr->b %p\n", *(v_ptr+1));
	printf("derive::vptr->c %p\n", *(v_ptr+2));

	((func)*v_ptr)();
	((func)*(v_ptr + 1))();
	((func)*(v_ptr + 2))();

	// ����Base�ĵ�ַ�ռ�
	Base base1;
	printf("base1::vptr %p\n", *(int *)&base1);

	// ��ȡ�麯����ĵ�ַ
	v_ptr = (int *)(*(int *)&base1);

	printf("base1::vptr->a %p\n", *v_ptr);
	printf("base1::vptr->b %p\n", *(v_ptr + 1));
	printf("base1::vptr->c %p\n", *(v_ptr + 2));

	((func)*v_ptr)();
	((func)*(v_ptr + 1))();
	((func)*(v_ptr + 2))();

	// ����Base�ĵ�ַ�ռ�
	Base base2;
	printf("base2::vptr %p\n", *(int *)&base2);

	// ��ȡ�麯����ĵ�ַ
	v_ptr = (int *)(*(int *)&base2);

	printf("base2::vptr->a %p\n", *v_ptr);
	printf("base2::vptr->b %p\n", *(v_ptr + 1));
	printf("base2::vptr->c %p\n", *(v_ptr + 2));

	((func)*v_ptr)();
	((func)*(v_ptr + 1))();
	((func)*(v_ptr + 2))();

	int test;
	cin >> test;

	return 0;
}