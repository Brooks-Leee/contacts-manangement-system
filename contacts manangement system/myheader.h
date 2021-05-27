#pragma once
#define MAX 1000

struct contact {
	std::string name;
	int gender;//1-male 2-female
	int age;
	std::string phoneNum;
	std::string address;
};

struct addressBook {
	contact contArray[MAX];
	int bookSize;
};


void menuDisplay();
void addContact(addressBook* book1);
void disContact(addressBook* book1);
int ifExist(addressBook* book1);
void delContact(addressBook* book1);
void searchContact(addressBook* book1);
void modifyContact(addressBook* book1);
void clearContact(addressBook* book1);