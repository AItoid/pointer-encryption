#include "Includes.h"

struct ExampleStruct
{
    int someNumber;
    const char* someText;
};

int main()
{
    // Create encrypted pointer.
    ExampleStruct* exampleStruct = reinterpret_cast<ExampleStruct*>(g_ptr->Encrypt(new ExampleStruct()));

    // Print pointer.
    printf("Encrypted: 0x%p\n", exampleStruct);
    printf("Decrypted: 0x%p\n", reinterpret_cast<ExampleStruct*>(g_ptr->Decrypt(exampleStruct)));

    // Set pointer data.
    reinterpret_cast<ExampleStruct*>(g_ptr->Decrypt(exampleStruct))->someNumber = 100;
    reinterpret_cast<ExampleStruct*>(g_ptr->Decrypt(exampleStruct))->someText = "RandomText";

    // Print pointer members.
    printf("Num: %i\n", reinterpret_cast<ExampleStruct*>(g_ptr->Decrypt(exampleStruct))->someNumber);
    printf("Text: %s\n", reinterpret_cast<ExampleStruct*>(g_ptr->Decrypt(exampleStruct))->someText);

    std::cin.get();
    return 0;
}