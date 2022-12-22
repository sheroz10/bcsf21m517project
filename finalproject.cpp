#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int name_size=50;
struct fac
{
    char name[50];
    char post[50];
};
struct inventory
{
    char name[name_size];
    int item_no;
    char category[name_size];
    int item_count;
    fac allocated_to[20];
    // suppose the total member are 20 of the facilty
};
void add_inventory(inventory s);
void view_inventory(inventory s);
void search_inventory(inventory s);
void edit_inventory(inventory s);
void delete_inventory(inventory s);
void assign_inventory(inventory s);
void reterive_inventory(inventory s);
void search_assigned(inventory s);
int main()
{
    inventory c;
    int choose;
    char ch;
    do
    {
        cout << "                       WHAT WE CAN DO FOR YOU?          " << endl;
        cout << "        PRESS THE FOLLOWING TO GET YOUR DESIRE TASK         " << endl;
        cout << "1.ADD INVENTORY\n2.VIEW ALL INVENTORY\n3.SEARCH INVENTORY ITEM\n4.EDIT INVENTORY\n5.DELETE INVENTORY" << endl;
        cout << "6.ASSIGN INVENTORY\n7.RETERIVE INVENTORY\n8.SHOW ASSIGNED PERSON\n9.EXIT" << endl;
        cin >> choose;

        if (choose == 1)
            add_inventory(c);
        else if (choose == 2)
            view_inventory(c);
        else if (choose == 3)
            search_inventory(c);
        else if (choose == 4)
            edit_inventory(c);
        else if (choose == 5)
            delete_inventory(c);
        else if (choose == 6)
            assign_inventory(c);
        else if (choose == 7)
            reterive_inventory(c);
        else if (choose == 8)
            search_assigned(c);
        else
        {
            cout << "thanks for your precious time" << endl;
            return 0;
        }

        cout << "DO YOU WANT TO RUN THE PROGRAM AGAIN\npress Y for again" << endl;
        cin >> ch;
        cin.ignore();
    }
    while (ch == 'y' || ch == 'Y');


    return 0;
}
// entering inventory here
void add_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tADDING THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    char c = 'n';
    fstream file;
    file.open("project.txt", ios::out | ios::binary);
    do
    {
        cin.ignore();
        cout << "Enter the name of product?" << endl;
        cin.getline(s.name,name_size);
        cout << "Enter the product id?" << endl;
        cin >> s.item_no;
        cin.ignore();
        cout << "Enter the product category?" << endl;
        cin.getline(s.category,name_size);
        cout << "Enter the no of item you have?" << endl;
        cin >> s.item_count;
        while(s.item_count<=0)
        {
            cout<<"the enteries are invalid"<<endl;
            cout<<"please re-enter the value"<<endl;

            cin >> s.item_count;
        }
        file.write(reinterpret_cast<char *>(&s), sizeof(s));
        cout << "Do you want to enter another inventory item?\nif yes press y\nif no press n" << endl;
        cin >> c;
    }
    while (c == 'y' || c == 'Y');
    file.close();
}
void view_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tVIEWING THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    fstream file;
    file.open("project.txt", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(&s), sizeof(s));
    while (!file.eof())
    {
        cout << "The name of product?" << endl;
        cout << s.name << endl;
        cout << "The product id?" << endl;
        cout << s.item_no << endl;
        cout << "The product category?" << endl;
        cout << s.category << endl;
        cout << "The no of item you have?" << endl;
        cout << s.item_count << endl;
        file.read(reinterpret_cast<char *>(&s), sizeof(s));
    }
    file.close();
}
void search_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tSEARCHING WITHIN THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    fstream file;
    bool status = 0;
    char c;
    char name[50];
    int id;
    cout << "You can search an item either by its name and item id\n1.press 1 for search by name\n2.press 2 for search using item id " << endl;
    cin >> c;
    switch (c)
    {
    case '1':
        cin.ignore();
        cout << "Enter the name of the Item you want to search?" << endl;
        cin.getline(name,name_size);
        file.open("project.txt", ios::in | ios::binary);
        file.read(reinterpret_cast<char *>(&s), sizeof(s));
        while (!file.eof())
        {
            if (strcmp(s.name, name) == 0)
            {
                cout << "The name of product=";
                cout << s.name << endl;
                cout << "The product id=";
                cout << s.item_no << endl;
                cout << "The product category=";
                cout << s.category << endl;
                cout << "The no of item you have=";
                cout << s.item_count << endl;
                status = 0;
                break;
            }
            else
                status = 1;

            file.read(reinterpret_cast<char *>(&s), sizeof(s));
        }
        if (status)
            cout << "!!!THE RECORD IS NOT AVAILABLE!!!" << endl;
        break;
    case '2':
        cout << "Enter the id of the Item you want to search?" << endl;
        cin >> id;
        file.open("project.txt", ios::in | ios::binary);
        file.read(reinterpret_cast<char *>(&s), sizeof(s));
        while (!file.eof())
        {
            if (s.item_no == id)
            {
                cout << "The name of product=";
                cout << s.name << endl;
                cout << "The product id=";
                cout << s.item_no << endl;
                cout << "The product category=";
                cout << s.category << endl;
                cout << "The no of item you have=";
                cout << s.item_count << endl;
                break;
            }
            else
                status = 1;

            file.read(reinterpret_cast<char *>(&s), sizeof(s));
        }
        if (status)
            cout << "!!!THE RECORD IS NOT AVAILABLE!!!" << endl;
        break;
    }
    file.close();
}
void edit_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tEDITING THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    int id;
    fstream file;
    cout << "Enter the id of the Item you want to edit?" << endl;
    cin >> id;
    file.open("project.txt", ios::in | ios::out | ios::binary);
    while (!file.eof())
    {

        file.read(reinterpret_cast<char *>(&s), sizeof(s));

        if (s.item_no == id)
        {

        cin.ingnore();
            cout << "Enter the name of product?" << endl;
            cin.getline(s.name,name_size) ;
            cout << "Enter the product id?" << endl;
            cin >> s.item_no;
            cin.ignore();
            cout << "Enter the product category?" << endl;
            cin.getline(s.category,name_size) ;
            cout << "Enter the no of item you have?" << endl;
            cin >> s.item_count;
            int x = file.tellp();

            file.seekp(x - sizeof(s), ios::beg);
            file.write(reinterpret_cast<char *>(&s), sizeof(s));
            break;
        }
    }
    file.close();
}
void delete_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tDELETING THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    int id;
    bool status = 0;
    fstream file, file1;
    cout << "Enter the id of the Item you want to delete ?" << endl;
    cin >> id;
    file.open("project.txt", ios::in | ios::binary);
    file1.open("newfile.txt", ios::out | ios::binary | ios::app);

    file.read(reinterpret_cast<char *>(&s), sizeof(s));

    while (!file.eof())
    {

        if (s.item_no != id)
        {

            file1.write(reinterpret_cast<char *>(&s), sizeof(s));
        }
        else
        {
            status = 1;
        }
        file.read(reinterpret_cast<char *>(&s), sizeof(s));
    }
    if (status)
    {
        cout << "Item Deleted!\n";
    }
    else
    {
        cout << "!!!RECORD NOT FOUND!!!" << endl;
        //     remove("newfile.txt");
    }
    file1.close();
    file.close();
    remove("project.txt");
    rename("newfile.txt", "project.txt");
}
void assign_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tASSINGING THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    fstream file;
    char name[50];
    bool status = 0;
    cin.ignore();
    cout << "\t\t\tENTER THE NAME OF THE INVENTORY ITEM YOU WANT TO BORROW?" << endl;
    cin.getline(name,50);
    file.open("project.txt", ios::in | ios::out | ios::binary);
    file.read(reinterpret_cast<char *>(&s), sizeof(s));
    while (!file.eof())
    {
        if (strcmp(s.name, name) == 0)
        {
            status = 1;
            break;
        }

        file.read(reinterpret_cast<char *>(&s), sizeof(s));
    }
    if (status)
    {
        cin.ignore();
        // file.seekp(-sizeof(s), ios::cur);
        cout << "ENTER YOUR NAME?" << endl;
        cin.getline(s.allocated_to->name,50);
        cin.ignore();
        cout << "ENTER YOUR POST?" << endl;
        cin.getline(s.allocated_to->post,50);
        s.item_count--;
        int x = file.tellp();
        file.seekp(x - sizeof(s), ios::beg);
        file.write(reinterpret_cast<char *>(&s), sizeof(s));
    }
}

void reterive_inventory(inventory s)
{
    system("cls");
    cout<<"\t\t\tRETERIVING THE INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    fstream file;
    char pname[50];
    char name[50];
    bool status = 0;
    cin.ignore();
    cout << "\t\t\tENTER THE NAME OF THE INVENTORY ITEM YOU WANT TO RETURN?" << endl;
    cin.getline(name,50);
    file.open("project.txt", ios::in | ios::out | ios::binary);
    file.read(reinterpret_cast<char *>(&s), sizeof(s));
    while (!file.eof())
    {
        if (strcmp(s.name, name) == 0)
        {
            status = 1;
            break;
        }

        file.read(reinterpret_cast<char *>(&s), sizeof(s));
    }
    file.close();
    file.open("project.txt", ios::in | ios::out | ios::binary);

    if (status)
    {
        cin.ignore();
        cout << "!!!yes this is our product!!!" << endl;
        cout << "enter your name" << endl;
        cin.getline(pname,50);

        file.read(reinterpret_cast<char *>(&s), sizeof(s));
        while (!file.eof())
        {
            if (strcmp(pname,s.allocated_to->name) == 0)
            {


                strcpy(s.allocated_to->name, "");
                strcpy(s.allocated_to->post, "");

                s.item_count++;
                int x = file.tellp();
                file.seekp(x - sizeof(s), ios::beg);
                file.write(reinterpret_cast<char *>(&s), sizeof(s));
            }
            file.read(reinterpret_cast<char *>(&s), sizeof(s));
        }
    }
    else
        cout<<"Sorry!!not found"<<endl;
}
void search_assigned(inventory s)
{
    system("cls");
    cout<<"\t\t\tVIEWING THE ASSIGNED INVENTORY"<<endl;
    cout<<endl;
    cout<<endl;
    fstream file;
    file.open("project.txt", ios::in | ios::binary);
    file.read(reinterpret_cast<char *>(&s), sizeof(s));
    while (!file.eof())
    {

        cout << "the assigned person who has currently borrow the book is" << endl;
        cout << s.allocated_to->name << endl;
        cout << s.allocated_to->post << endl;
        cout << "---------------------------------------------------------" << endl;

        file.read(reinterpret_cast<char *>(&s), sizeof(s));
    }
}

