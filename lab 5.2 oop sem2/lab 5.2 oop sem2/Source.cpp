#include <iostream>
#include<string>
using namespace std;

class Colection
{
public:
	Colection();
	Colection(string name = "", int disk_size = 0, string type = "", string data_of_recording = "")
	{
		this->name = name;
		this->disk_size = disk_size;
		this->type = type;
		this->data_of_recording = data_of_recording;
	}
	void show()
	{
		cout << "__________" << endl << "name: " << name << endl << "disk size minute : " << disk_size << endl << "type: " << type << endl << "data of recording: " << data_of_recording << endl;
	}
	void delete_data()
	{
		this->name = "";
		this->disk_size = 0;
		this->type = "";
		this->data_of_recording = "";
	}
	void edit_data(string name = "", int disk_size = 0, string type = "", string data_of_recording = "")
	{
		this->name = name;
		this->disk_size = disk_size;
		this->type = type;
		this->data_of_recording = data_of_recording;
	}
protected:
	string name;
	int disk_size;
	string type;
	string data_of_recording;
};
class Colectionplus : public Colection
{
public:
	Colectionplus(string perfomers = "", string production = "", string name = "", int disk_size = 0, string type = "", string data_of_recording = "") :Colection(name, disk_size, type, data_of_recording)
	{
		this->performers = perfomers;
		this->production = production;
	}
	void edit_data(string perfomers = "", string production = "", string name = "", int disk_size = 0, string type = "", string data_of_recording = "")
	{
		Colection::edit_data(name, disk_size, type, data_of_recording);
		this->performers = perfomers;
		this->production = production;
	}
	void show()
	{
		cout << "__________" << endl << "performers: " << performers << endl << "production: " << production << endl << "name: " << name << endl << "disk size minute : " << disk_size << endl << "type: " << type << endl << "data of recording: " << data_of_recording << endl;
	}
	void delete_data()
	{
		Colection::delete_data();
		performers = "";
		production = "";
	}
private:
	string performers;
	string production;
};
int main()
{
	Colection disk("The Dark Side of the Moon", 42, "Progressive rock", "17.03.1973");
	disk.show();
	disk.delete_data();
	disk.show();
	disk.edit_data("The Dark Side of the Moon", 42, "Progressive rock", "17.03.1973");
	disk.show();
	Colectionplus diskplus("Roger Waters", "Pink Floyd ³ Alan Parsons", "The Dark Side of the Moon", 42, "Progressive rock", "17.03.1973");
	diskplus.show();
	diskplus.edit_data();
	diskplus.show();
	diskplus.edit_data("Roger Waters", "Pink Floyd ³ Alan Parsons", "The Dark Side of the Moon", 42, "Progressive rock", "17.03.1973");
	diskplus.show();
	diskplus.delete_data();
	diskplus.show();
}