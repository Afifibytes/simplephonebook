#include <iostream>
#include <cstdlib> 
#include "headers.cpp"

using namespace std;


bool isEmpty = true;

node *head;

void printInstructions(void)
{
    cout << "Enter a to add contact\n";
    cout << "Enter e to edit contact\n";
    cout << "Enter o to add phone to existing contact\n";
    cout << "Enter d to delete contact\n";
    cout << "Enter da to delete the entire contacts\n";
    cout << "Enter v to view all the list\n";
    cout << "Enter c to exit\n";
}

void addContact (void)
{
    cout << "add phone: \n";
    int temp;
    cin >> temp;

    cout << "add name: \n";
    string name;
    cin >> name;

    cout << "add email: \n";
    string email;
    cin >> email;

    insertNode(temp, name, email);
    cout << "The contact added\n \n";
    printInstructions();
}


/**
 * prints the list
 */
void printContacts()
{
    if(isEmpty)
    {
        printf("There are no contacts!\n");
    }
    else
    {
        printf("The Conatcts are:\n");
        node * temp = head;
        while(temp != NULL)
        {
            phone *phonetemp = temp->nextPhone;
            cout << temp->name;
            cout << " " << temp->email;
            cout << " " << temp->number;
            while(phonetemp != NULL)
            {
                cout << " " << phonetemp->phone;
                phonetemp = phonetemp->next;
            }
            temp = temp->next;
            printf("\n");
        }
    }
    
    printf("\n");
    printInstructions();
}

void editContact()
{
    if(isEmpty)
    {
        cout << "No Contacts to edit\n \n";
        printInstructions();
    }
    else
    {
        cout << "Enter the excisting contact phone: ";
        int phone;
        cin >> phone;
        if(phoneIsValid(phone))
        {
            string name, email;
            printf("The new name: ");
            cin >> name;
            printf("The new email: ");
            cin >> email;
            editNode(phone, name, email);
        }
        else
        {
            printf("This phone not excist\n \n");
            printInstructions();
        }
    }
    printf("The edits saved.\n \n");
    printInstructions();
}

void deleteContact()
{
    printf("Enter the number of the contact\n");
    int phone;
    cin >> phone;
    if(phoneIsValid(phone))
    {
        deleteNode(phone);
        printInstructions();
    }
    else
    {
        printf("The contact not found!\n \n");
        printInstructions();
    }
}

void addPhoneToContact()
{
    if(isEmpty)
    {
        printf("No contacts to add!\n \n");            
        printInstructions();
    }
    else
    {
        int excistPhone, newPhone;
        printf("The excisting numbereditContact: ");
        cin >> excistPhone;
        if (phoneIsValid(excistPhone))
        {
            printf("The new number: ");
            cin >> newPhone;
            addPhoneToNode(excistPhone, newPhone);
        }
        else
        {
            printf("this number not excist!\n \n");
            printInstructions();
        }
    }
}

/**
 * checks if a number exists in a list
 */
bool phoneIsValid(int number)
{
    node * temp = head;
    while(temp != NULL)
    {
        if(temp->number == number)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

node * findNode(int number)
{
    node * temp = head;
    while(temp != NULL)
    {
        if(temp->number == number)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


/**
 *  inserts a node to the list
 */
void insertNode(int number, string name, string email)
{
    // allocate memory for new node
    node * temp = new node;

    if(temp == NULL)
    {
        exit(1);
    }

    // insert at the beginning of the list
    temp->number = number;
    temp->name = name;
    temp->email = email;
    temp->next = head;
    head = temp;

    isEmpty = false;
}

void editNode(int number, string name, string email)
{
    node * temp = findNode(number);
    if(temp != NULL)
    {
        temp->name = name;
        temp->email = email;
    }
}

void addPhoneToNode(int exist, int newPhone)
{
    if(phoneIsValid(exist))
    {
        node * tempNode = findNode(exist);
        if(tempNode != NULL)
        {
            if(tempNode->number == exist)
            {
                phone *temp = (phone*) malloc(sizeof(phone));
                if(temp == NULL)
                {
                    exit(1);
                }
                temp->next = tempNode->nextPhone;
                tempNode->nextPhone = temp;
                tempNode->nextPhone->phone = newPhone;
                printf("the number added to the contact\n");
                printInstructions();
            }
        }
    }
}

/**
 * deletes a node from a list
 */
void deleteNode(int number)
{
    node * temp = head;

    if(temp->number == number)
    {
        phone * tempPhone = temp->nextPhone;
        while(tempPhone != NULL)
        {
            free(tempPhone);
            tempPhone = tempPhone->next;
        }
        head = head->next;
        delete temp;
    }

    while(temp->next != NULL)
    {
        if(temp->next->number == number)
        {
            phone * tempPhone = temp->next->nextPhone;
            while(tempPhone != NULL)
            {
                free(tempPhone);
                tempPhone = tempPhone->next;
            }
            delete temp->next;
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
}

void freeList()
{
    while(head != NULL)
    {
        phone * temp = head->nextPhone;
        while(temp != NULL)
        {
            free(temp);
            temp = temp->next;
        }
        delete head;
        head = head->next;
    }
    cout << "All contacts was deleted!\n";

    isEmpty = true;
}