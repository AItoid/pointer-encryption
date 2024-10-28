#include "ptr.h"

struct test_t
{
    int num;
    const char* text;
};

int main()
{
    // Create encrypted pointer.
    test_t* test = g_ptr->process<test_t*>(new test_t(), false);

    // Print pointer.
    printf("Encrypted: 0x%p\n", test);
    printf("Decrypted: 0x%p\n", g_ptr->process<test_t*>(test, true));

    // Set pointer data.
    g_ptr->process<test_t*>(test, true)->num = 1;
    g_ptr->process<test_t*>(test, true)->text = "RandomText";

    // Print pointer members.
    printf("Num: %i\n", g_ptr->process<test_t*>(test, true)->num);
    printf("Text: %s\n", g_ptr->process<test_t*>(test, true)->text);

    for (int i = 0; i < 100; i++)
    {
        PROCESS_PTR_AUTO(test, true)->num++;
        printf("%i\n", PROCESS_PTR_AUTO(test, true)->num);
    }

    std::cin.get();
    return 0;
}
