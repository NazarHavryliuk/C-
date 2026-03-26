#include<iostream>
#include<fstream>
#include<string>

using namespace std;
string file_name = "file_input.txt";
string file_name2 = "file_output.txt.";


int main()
{
    string str1="", q,str2="",str3="";
    int min_lenght = 100;
    ifstream in_file(file_name, ios::in);
    if (!in_file.is_open())
    {
        cout << "This file does not exist!\n" << endl;
    }
    else
    {
        
        while (in_file >> q)
        {
            str1 =str1+q+" ";
            char w = q[0];
            int a = (int)w;
            if (!((a > 96) && (a < 123)))
            {
                str2 = str2 + q + " ";
            }
            if (q.size() < min_lenght)
            {
                min_lenght = q.size();
            }
        }
    }
    in_file.clear();
    in_file.seekg(0, std::ios::beg);
    if (!in_file.is_open())
    {
        cout << "This file does not exist!\n" << endl;
    }
    else
    {
        while (in_file >> q)
        {
            if (q.length() == min_lenght)
            {
                str3 = str3 + q + " ";
            }
        }
    }
    in_file.close();
    int number_of_capital_letters = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (((str1[i] > 64) && (str1[i] < 91)))
        {
            number_of_capital_letters++;
        }
    }
    ofstream fout(file_name2, ios::out);
    if (!fout.is_open())
    {
        cout << "This file does not exist!\n" << endl;
    }
    else
    {
        fout << "Text: " << str1 << endl <<
            "The number of capital letters in the text: " << number_of_capital_letters << endl <<
            "Words with the least number of letters: " << str3 << endl <<
            "Text without words starting with a lowercase letter: " << str2;
    }
    fout.close();
    return 0;
}
