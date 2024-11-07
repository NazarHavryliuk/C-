#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <windows.h>

using namespace std;
string file_autoo = "auto.txt";

int const max_autoo = 100;



struct autoo {
    string producer;
    string model;
    int price;
    int power;
    int year;
};


void menu_start();
void menu_adm_autoo();
void menu_adm_autoo_print();
void read_file_autoo(autoo* autoo_arr, int& autoo_num);
void show_autoo(autoo* autoo_arr, int& autoo_num);
void print_info();
void add_autoo(autoo* autoo_arr, int& autoo_num);
void write_file_autoo(autoo* autoo_arr, int& autoo_num);
void edit_autoo(autoo* autoo_arr, int& autoo_num);
void delete_autoo(autoo* autoo_arr, int& autoo_num);
void sort_producer(autoo* autoo_arr, int& autoo_num);
void sort_model(autoo* autoo_arr, int& autoo_num);
void sort_price(autoo* autoo_arr, int& autoo_num);
void sort_power(autoo* autoo_arr, int& autoo_num);
void sort_year(autoo* autoo_arr, int& autoo_num);
void search_producer(autoo* autoo_arr, int& autoo_num);
void search_model(autoo* autoo_arr, int& autoo_num);
void search_price(autoo* autoo_arr, int& autoo_num);
void search_power(autoo* autoo_arr, int& autoo_num);
void search_year(autoo* autoo_arr, int& autoo_num);


int main()
{
    setlocale(LC_CTYPE, "ukr");
    menu_start();
    return 0;
}


void menu_start_print() {
    cout << "\n\tMenu\n" << endl;
    cout <<
        "1. Work with data\n"
        "0. Exit\n";
}

void menu_start() {
    bool flag = true;

    menu_start_print();

    while (flag) {
        cout << "Enter a number: ";
        int k;
        cin >> k;
        switch (k) {

        case 1:
            menu_adm_autoo();
            menu_start_print();
            break;

        case 0:
            exit(0);
            break;
        default:
            cout << "Wrong number" << endl;
            break;
        }
    }
}

void menu_adm_autoo_print() {
    cout << "\n\tMenu for working with data\n" << endl;
    cout <<
        "1. List of auto\n"
        "2. Add a record\n"
        "3. Change a record\n"
        "4. Delete a record\n"
        "5. Sort by producer\n"
        "6. Sort by model\n"
        "7. Sort by price\n"
        "8. Sort by power\n"
        "9. Sort by year\n"
        "10. Search by producer\n"
        "11. Search by model\n"
        "12. Search by price\n"
        "13. Search by power\n"
        "14. Search by year\n"
        "15. Back\n"
        "0. Exit\n" << endl;
}

void menu_adm_autoo() {
    autoo autoo_arr[max_autoo];
    int autoo_num = 0;

    menu_adm_autoo_print();

    int k;
    bool flag = true;
    while (flag) {
        cout << "Enter a number: ";
        cin >> k;
        switch (k) {
        case 1:
            read_file_autoo(autoo_arr, autoo_num);
            show_autoo(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 2:
            add_autoo(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 3:
            edit_autoo(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 4:
            delete_autoo(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 5:
            sort_producer(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 6:
            sort_model(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 7:
            sort_price(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 8:
            sort_power(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 9:
            sort_year(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 10:
            search_producer(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 11:
            search_model(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 12:
            search_price(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 13:
            search_power(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 14:
            search_year(autoo_arr, autoo_num);
            menu_adm_autoo_print();
            break;
        case 0:
            exit(0);
            break;

        default:
            cout << "\nWrong number!" << endl;
            break;
        }
    }
}
void read_file_autoo(autoo* autoo_arr, int& autoo_num)
{
    ifstream in_file(file_autoo, ios::in);
    if (!in_file.is_open())
    {
        cout << "This file does not exist!\n" << endl;
    }
    else
    {
        int i = 0;
        while (in_file >> autoo_arr[i].producer >> autoo_arr[i].model >> autoo_arr[i].price >> autoo_arr[i].power >> autoo_arr[i].year) {
            i++;
        }
        autoo_num = i;
    }
    in_file.close();
}
void show_autoo(autoo* autoo_arr, int& autoo_num)
{
    print_info();

    for (int i = 0; i < autoo_num; i++) {
        cout << "| " <<
            setw(2) << left << i + 1 << "| " <<

            setw(13) << left << autoo_arr[i].producer << "| " <<
            setw(16) << left << autoo_arr[i].model << "| " <<
            setw(16) << left << autoo_arr[i].price << "| " <<
            setw(16) << left << autoo_arr[i].power << "| " <<
            setw(7) << left << autoo_arr[i].year << "| " << endl;

    }
    cout << "___________________________________________________________________________________\n" << endl;
}
void print_info()
{
    cout << "___________________________________________________________________________________" << endl;
    cout << "| # |" <<

        setw(14) << left << "Producer" << "| " <<
        setw(16) << left << "Model" << "| " <<
        setw(16) << left << "Price" << "| " <<
        setw(16) << left << "Power" << "| " <<
        setw(7) << left << "Year" << "| " << endl;

    cout << "___________________________________________________________________________________" << endl;
}
void add_autoo(autoo* autoo_arr, int& autoo_num)
{
    cout << "\n\tAdd data" << endl;
    read_file_autoo(autoo_arr, autoo_num);
    autoo_num++;
    int id = autoo_num - 1;
    string s;
    cout << "Auto producer: ";
    cin >> s;
    autoo_arr[id].producer = s;

    cout << "Auto Model: ";
    cin >> s;
    autoo_arr[id].model = s;


    int c;
    cout << "Auto Price: ";
    cin >> c;
    autoo_arr[id].price = c;

    cout << "Auto Power: ";
    cin >> c;
    autoo_arr[id].power = c;

    cout << "Auto Year: ";
    cin >> c;
    autoo_arr[id].year = c;

    cout << "New entry added.\n" << endl;
    write_file_autoo(autoo_arr, autoo_num);
}
void write_file_autoo(autoo* autoo_arr, int& autoo_num)
{
    ofstream fout(file_autoo, ios::out);
    for (int i = 0; i < autoo_num; i++)
    {
        fout<<
            autoo_arr[i].producer << "\t" <<







            autoo_arr[i].model << "\t" <<
            autoo_arr[i].price << "\t" <<
            autoo_arr[i].power << "\t" <<
            autoo_arr[i].year;
        if (i < autoo_num - 1)
        {
            fout << endl;
        }
    }
    fout.close();
}
void edit_autoo(autoo* autoo_arr, int& autoo_num)
{
    int id;
    cout << "\nRecord variable\n" << endl;
    read_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
    cout << "enter # record:";
    cin >> id;
    id--;
    if (id < 0 && id >= autoo_num)
    {
        cout << "invalid entry entered\n" << endl;
    }
    else
    {
        string s;
        cout << "Auto producer: ";
        cin >> s;
        autoo_arr[id].producer = s;

        cout << "Auto Model: ";
        cin >> s;
        autoo_arr[id].model = s;


        int c;

        cout << "Auto Price: ";
        cin >> c;
        autoo_arr[id].price = c;

        cout << "Auto Power: ";
        cin >> c;
        autoo_arr[id].power = c;

        cout << "Auto Year: ";
        cin >> c;
        autoo_arr[id].year = c;

        cout << "The replacement was successful\n" << endl;
        write_file_autoo(autoo_arr, autoo_num);
    }
}
void delete_autoo(autoo* autoo_arr, int& autoo_num)
{
    int id = 0;
    bool flag = true;
    int k;
    cout << "\nDelete a record" << endl;
    read_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
    cout << "Enter # record:";
    cin >> id;
    id--;
    if (id >= 0 && id < autoo_num)
    {
        cout << "Confirm your attempt:" << endl;
        while (flag)
        {
            cout << "Enter a number ( 1-yes, 0-no) : ";
            cin >> k;
            if (k == 1)
            {
                for (int i = id; i < autoo_num - 1; i++)
                {
                    autoo_arr[i] = autoo_arr[i + 1];
                }
                autoo_num--;
                cout << "Record delete.\n" << endl;
                write_file_autoo(autoo_arr, autoo_num);
                flag = false;
                if (autoo_num == 0) {
                    remove("auto.txt");
                }
            }

            else if (k == 0)
            {
                menu_adm_autoo();
                flag = false;
            }
        }
    }
    else
    {
        cout << "Error!" << endl;
    }
}
void sort_producer(autoo* autoo_arr, int& autoo_num)
{
    autoo temp;
    read_file_autoo(autoo_arr, autoo_num);
    cout << "Sort by producer" << endl;
    for (int i = 0; i < autoo_num - 1; i++)
    {
        for (int j = 0; j < autoo_num - 1; j++)
        {
            if (autoo_arr[j].producer > autoo_arr[j + 1].producer)
            {
                temp = autoo_arr[j];
                autoo_arr[j] = autoo_arr[j + 1];
                autoo_arr[j + 1] = temp;
            }
        }
    }
    write_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
}
void sort_model(autoo* autoo_arr, int& autoo_num)
{
    autoo temp;
    read_file_autoo(autoo_arr, autoo_num);
    cout << "Sort by model" << endl;
    for (int i = 0; i < autoo_num - 1; i++)
    {
        for (int j = 0; j < autoo_num - 1; j++)
        {
            if (autoo_arr[j].model > autoo_arr[j + 1].model)
            {
                temp = autoo_arr[j];
                autoo_arr[j] = autoo_arr[j + 1];
                autoo_arr[j + 1] = temp;
            }
        }
    }
    write_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
}
void sort_price(autoo* autoo_arr, int& autoo_num)
{
    autoo temp;
    read_file_autoo(autoo_arr, autoo_num);
    cout << "Sort by price" << endl;
    for (int i = 0; i < autoo_num - 1; i++)
    {
        for (int j = 0; j < autoo_num - 1; j++)
        {
            if (autoo_arr[j].price > autoo_arr[j + 1].price)
            {
                temp = autoo_arr[j];
                autoo_arr[j] = autoo_arr[j + 1];
                autoo_arr[j + 1] = temp;
            }
        }
    }
    write_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
}
void sort_power(autoo* autoo_arr, int& autoo_num)
{
    autoo temp;
    read_file_autoo(autoo_arr, autoo_num);
    cout << "Sort by power" << endl;
    for (int i = 0; i < autoo_num - 1; i++)
    {
        for (int j = 0; j < autoo_num - 1; j++)
        {
            if (autoo_arr[j].power > autoo_arr[j + 1].power)
            {
                temp = autoo_arr[j];
                autoo_arr[j] = autoo_arr[j + 1];
                autoo_arr[j + 1] = temp;
            }
        }
    }
    write_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
}
void sort_year(autoo* autoo_arr, int& autoo_num)
{
    autoo temp;
    read_file_autoo(autoo_arr, autoo_num);
    cout << "Sort by year" << endl;
    for (int i = 0; i < autoo_num - 1; i++)
    {
        for (int j = 0; j < autoo_num - 1; j++)
        {
            if (autoo_arr[j].year > autoo_arr[j + 1].year)
            {
                temp = autoo_arr[j];
                autoo_arr[j] = autoo_arr[j + 1];
                autoo_arr[j + 1] = temp;
            }
        }
    }
    write_file_autoo(autoo_arr, autoo_num);
    show_autoo(autoo_arr, autoo_num);
}
void search_producer(autoo* autoo_arr, int& autoo_num)
{
    cout << "\n\tSearch for auto by producer\n" << endl;
    read_file_autoo(autoo_arr, autoo_num);

    string Name;
    string s;
    int k = 0;
    cout << "Enter the producer ";
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    print_info();
    for (int i = 0; i < autoo_num; i++)
    {
        string name = autoo_arr[i].producer;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (s == name)
        {
            cout << "| " <<
                setw(2) << left << i + 1 << "| " <<
                setw(13) << left << autoo_arr[i].producer << "| " <<
                setw(16) << left << autoo_arr[i].model << "| " <<
                setw(16) << left << autoo_arr[i].price << "| " <<
                setw(16) << left << autoo_arr[i].power << "| " <<
                setw(7) << left << autoo_arr[i].year << "| " << endl;
            k++;
            Name = autoo_arr[i].producer;
        }
    }

    if (k == 0)
    {
        cout << "No data" << endl;
    }
    else
    {
        cout << "The number of producers with a name " << Name << " is " << k << endl;
    }
    cout << "___________________________________________________________________________________" << endl;
}
void search_model(autoo* autoo_arr, int& autoo_num)
{
    cout << "\n\tSearch for auto by model\n" << endl;
    read_file_autoo(autoo_arr, autoo_num);

    string Name;
    string s;
    int k = 0;
    cout << "Enter the model ";
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    print_info();
    for (int i = 0; i < autoo_num; i++)
    {
        string name = autoo_arr[i].model;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (s == name)
        {
            cout << "| " <<
                setw(2) << left << i + 1 << "| " <<
                setw(13) << left << autoo_arr[i].producer << "| " <<
                setw(16) << left << autoo_arr[i].model << "| " <<
                setw(16) << left << autoo_arr[i].price << "| " <<
                setw(16) << left << autoo_arr[i].power << "| " <<
                setw(7) << left << autoo_arr[i].year << "| " << endl;
            k++;
            Name = autoo_arr[i].model;
        }
    }

    if (k == 0)
    {
        cout << "No data" << endl;
    }
    else
    {
        cout << "The number of models with a name " << Name << " is " << k << endl;
    }
    cout << "___________________________________________________________________________________" << endl;
}
void search_price(autoo* autoo_arr, int& autoo_num)
{
    cout << "\n\tSearch for auto by price\n" << endl;
    read_file_autoo(autoo_arr, autoo_num);

    int Name;
    int s;
    int k = 0;
    cout << "Enter the price ";
    cin >> s;

    print_info();
    for (int i = 0; i < autoo_num; i++)
    {
        int name = autoo_arr[i].price;
        if (s == name)
        {
            cout << "| " <<
                setw(2) << left << i + 1 << "| " <<
                setw(13) << left << autoo_arr[i].producer << "| " <<
                setw(16) << left << autoo_arr[i].model << "| " <<
                setw(16) << left << autoo_arr[i].price << "| " <<
                setw(16) << left << autoo_arr[i].power << "| " <<
                setw(7) << left << autoo_arr[i].year << "| " << endl;
            k++;
            Name = autoo_arr[i].price;
        }
    }

    if (k == 0)
    {
        cout << "No data" << endl;
    }
    else
    {
        cout << "The number of price with a figure " << Name << " is " << k << endl;
    }
    cout << "___________________________________________________________________________________" << endl;
}
void search_power(autoo* autoo_arr, int& autoo_num)
{
    cout << "\n\tSearch for auto by power\n" << endl;
    read_file_autoo(autoo_arr, autoo_num);

    int Name;
    int s;
    int k = 0;
    cout << "Enter the power ";
    cin >> s;

    print_info();
    for (int i = 0; i < autoo_num; i++)
    {
        int name = autoo_arr[i].power;
        if (s == name)
        {
            cout << "| " <<
                setw(2) << left << i + 1 << "| " <<
                setw(13) << left << autoo_arr[i].producer << "| " <<
                setw(16) << left << autoo_arr[i].model << "| " <<
                setw(16) << left << autoo_arr[i].price << "| " <<
                setw(16) << left << autoo_arr[i].power << "| " <<
                setw(7) << left << autoo_arr[i].year << "| " << endl;
            k++;
            Name = autoo_arr[i].power;
        }
    }

    if (k == 0)
    {
        cout << "No data" << endl;
    }
    else
    {
        cout << "The number of power with a figure " << Name << " is " << k << endl;
    }
    cout << "___________________________________________________________________________________" << endl;
}
void search_year(autoo* autoo_arr, int& autoo_num)
{
    cout << "\n\tSearch for auto by year\n" << endl;
    read_file_autoo(autoo_arr, autoo_num);

    int Name;
    int s;
    int k = 0;
    cout << "Enter the year ";
    cin >> s;

    print_info();
    for (int i = 0; i < autoo_num; i++)
    {
        int name = autoo_arr[i].year;
        if (s == name)
        {
            cout << "| " <<
                setw(2) << left << i + 1 << "| " <<
                setw(13) << left << autoo_arr[i].producer << "| " <<
                setw(16) << left << autoo_arr[i].model << "| " <<
                setw(16) << left << autoo_arr[i].price << "| " <<
                setw(16) << left << autoo_arr[i].power << "| " <<
                setw(7) << left << autoo_arr[i].year << "| " << endl;
            k++;
            Name = autoo_arr[i].year;
        }
    }

    if (k == 0)
    {
        cout << "No data" << endl;
    }
    else
    {
        cout << "The number of year with a figure " << Name << " is " << k << endl;
    }
    cout << "___________________________________________________________________________________" << endl;
}