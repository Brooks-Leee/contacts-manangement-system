#include <iostream>
#include <string>
#include "myheader.h"

void menuDisplay() {
	std::cout << "***************************" << std::endl;
	std::cout << "  * 1.Add contacts     *" << std::endl;
	std::cout << "  * 2.Display contacts *" << std::endl;
	std::cout << "  * 3.Delete contacts  *" << std::endl;
	std::cout << "  * 4.Search contacts  *" << std::endl;
	std::cout << "  * 5.Modify contacts  *" << std::endl;
	std::cout << "  * 6.Clear contacts   *" << std::endl;
	std::cout << "  * 0.Exit system      *" << std::endl;
	std::cout << "***************************" << std::endl;
}

void addContact(addressBook* book1) {
	if (book1->bookSize == MAX)
	{
		std::cout << "The address book has hit the limit. ";
		return;
	}
	else 
	{
		std::cout << "Enter name: ";
		std::string name;
		std::cin >> name;
		book1->contArray[book1->bookSize].name = name;

		std::cout << "Enter gender:  1-male, 2-female";
		int gender;
		std::cin >> gender;
		book1->contArray[book1->bookSize].gender = gender;

		std::cout << "Enter age: ";
		int age;
		std::cin >> age;
		book1->contArray[book1->bookSize].age = age;

		std::cout << "Enter phone number: ";
		std::string phoneNum;
		std::cin >> phoneNum;
		book1->contArray[book1->bookSize].phoneNum = phoneNum;

		std::cout << "Enter address: ";
		std::string address;
		std::cin >> address;
		book1->contArray[book1->bookSize].address = address;

		book1->bookSize++;//通讯录人数更新

		std::cout << "添加成功!";
		system("pause");
		system("cls");
	}
}

void disContact(addressBook* book1) {
	if (book1->bookSize == 0) 
	{
		std::cout << "当前记录为空" << std::endl;
	}
	else
	{
		for (int i = 0; i < book1->bookSize; i++)
		{
		
			std::cout << " name: " << book1->contArray[i].name << " gender: "
				<< (book1->contArray[book1->bookSize].gender == 2 ? "男":"女") << " age: " 
				<< book1->contArray[i].age
				<< " phone number: " << book1->contArray[i].phoneNum
				<< " address: " << book1->contArray[i].address << std::endl;
		}
	}
	system("pause");
	system("cls");
}

int ifExist(addressBook* book1) {
	std::string name;
	std::cin >> name;
	for (int i = 0; i < book1->bookSize; i++)
	{
		if (name == book1->contArray[i].name)
		{
			return i;
		}
	}
	return -1;
	
}

void delContact(addressBook* book1) {
	std::cout << "enter the contact that you want to delete: " << std::endl;
	int ret = ifExist(book1);
	if(ret == -1)
	{
		std::cout << "查无此人" << std::endl;
	}
	else
	{
		for (int i = ret; i < book1->bookSize; i++)
		{
			book1->contArray[i] = book1->contArray[i + 1];
		}
		book1->bookSize--; //更新人数
		std::cout << "删除成功！" << std::endl;
		system("pause");
		system("cls");
	}
}

void searchContact(addressBook* book1) {
	std::cout << "enter the contact that you want to search: ";
	int ret = ifExist(book1);
	if (ret != -1) 
	{
		std::cout << " name: " << book1->contArray[ret].name << " gender: "
			<< (book1->contArray[book1->bookSize].gender == 2 ? "男" : "女") << " age: "
			<< book1->contArray[ret].age
			<< " phone number: " << book1->contArray[ret].phoneNum
			<< " address: " << book1->contArray[ret].address << std::endl;
	}
	else
	{
		std::cout << "查无此人" << std::endl;
	}
	system("pause");
	system("cls");
}

void modifyContact(addressBook* book1) {
	std::cout << "enter the contact that you want to modify: ";
	int ret = ifExist(book1);
	if (ret != -1)
	{
		std::cout << "Enter name: ";
		std::string name;
		std::cin >> name;
		book1->contArray[book1->bookSize].name = name;

		std::cout << "Enter gender:  1-male, 2-female";
		int gender;
		while (true)
		{
			std::cin >> gender;
			if (gender == 1 || gender == 2) {
				book1->contArray[book1->bookSize].gender = gender;
				break;
			}
			else
			{
				std::cout << "输入错误，请重新输入";
			}
		}

		std::cout << "Enter age: ";
		int age;
		std::cin >> age;
		book1->contArray[book1->bookSize].age = age;

		std::cout << "Enter phone number: ";
		std::string phoneNum;
		std::cin >> phoneNum;
		book1->contArray[book1->bookSize].phoneNum = phoneNum;

		std::cout << "Enter address: ";
		std::string address;
		std::cin >> address;
		book1->contArray[book1->bookSize].address = address;
		std::cout << "修改完成" << std::endl;
	}
	else
	{
		std::cout << "查无此人" << std::endl;
	}
	system("pause");
	system("cls");
}

void clearContact(addressBook* book1) {
	std::cout << "Are you sure you want to clear the addressbook?" << std::endl;
	std::cout << "1-yes   2-no" << std::endl;
	int ifclear;
	std::cin >> ifclear;
	if (ifclear == 1)
	{
		book1->bookSize = 0;
		std::cout << "All clear" << std::endl;
	}
	else
	{
		std::cout << "Cancel clear" << std::endl;
	}
	system("pause");
	system("cls");
}