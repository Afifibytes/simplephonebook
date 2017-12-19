#include "phonebook.cpp"
#include <iostream>

int main(void)
{
    cout << "Welcome!\n";
    printInstructions();
    while (true)
    {
        string input;
        cin >> input;

        if (input == "a")
        {
            addContact();
        }
        else if (input == "e")
        {
            editContact();
        }
        else if (input == "d")
        {
            deleteContact();
        } 
        else if (input =="o")
        {
            addPhoneToContact();
        }
        else if (input == "da")
        {
            freeList();
        }
        else if (input == "v")
        {
            printContacts();
        }
        else if (input == "c")
        {
            freeList();
            exit(0);
        }
        else
        {
            printInstructions();
        }
    }
}