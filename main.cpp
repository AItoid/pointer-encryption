#include "ptr.h"

struct test_t
{
	int num;
};

int main()
{
	test_t* prot = reinterpret_cast<test_t*>(g_ptr->process<test_t*>(new test_t()));
	printf("Encrypted: 0x%p\n", prot);
	printf("Decrypted: 0x%p\n", g_ptr->process<test_t*>(prot));

	for (int i = 0; i < 100; i++)
	{
		g_ptr->process<test_t*>(prot)->num++;
		printf("%i\n", g_ptr->process<test_t*>(prot)->num);
		Sleep(500);
	}

	std::cin.get();
	return 0;
}
