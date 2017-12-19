#include <string>
using namespace std;

typedef struct phone
{
    int phone;
    struct phone * next;
}phone;

typedef struct node
{
    int number;
    phone * nextPhone;
    string name;
    string email;
    struct node * next;
}node;

void printInstructions();

void printContacts();
void addContact();
void addPhoneToContact();
void editContact();
void deleteContact();

bool phoneIsValid(int phone);

void insertNode(int phone, string name, string email);
void deleteNode(int phone);
void editNode(int phone, string name, string email);
void addPhoneToNode(int exist, int newPhone);

node * findNode(int phone);

void freeList();
