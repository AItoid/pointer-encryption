#include "ptr.h"

struct test_t
{
    int num;
    const char* text;
};

int main()
{
    // Create encrypted pointer.
    test_t* test = g_crypt->enc<test_t*>(new test_t());

    // Print pointer.
    printf("Encrypted: 0x%p\n", test);
    printf("Decrypted: 0x%p\n", g_crypt->dec<test_t*>(test));

    // Set pointer data.
    g_crypt->dec<test_t*>(test)->num = 1337;
    g_crypt->dec<test_t*>(test)->text = "RandomText";

    // Print pointer members.
    printf("Num: %i\n", g_crypt->dec<test_t*>(test)->num);
    printf("Text: %s\n", g_crypt->dec<test_t*>(test)->text);

    std::cin.get();
    return 0;
}
