// BookcaseApp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BookShelf.h"
#include <iostream>

using namespace std;

// добавление книги
void addBook(BookShelf &bookShelf)
{
	// ввод данных
	int idShelf;
	int idSlot;
	string name;
	int countPages;
	cout << "Input id shelf: ";
	cin >> idShelf;
	cout << "Input id slot: ";
	cin >> idSlot;
	cin.get();
	cout << "Input book name: ";
	getline(cin, name);
	cout << "Input count pages of book: ";
	cin >> countPages;

	bookShelf.addBook(idShelf, idSlot, PrintBook(name, countPages)); // добавляем
}

// вернуть книгу
PrintBook getBook(BookShelf &bookShelf)
{
	int idShelf;
	int idSlot;
	
	cout << "Input id shelf: ";
	cin >> idShelf;
	cout << "Input id slot: ";
	cin >> idSlot;

	return bookShelf.getBook(idShelf, idSlot);
}


int main()
{
	int countShelfs;
	int countSLots;
	
	// вводим кол-во полок и ячеек на них
	cout << "Create bookshelf:\n" << endl;
	cout << "Input count shelfs: ";
	cin >> countShelfs;
	cout << "Input count slots: ";
	cin >> countSLots;

	BookShelf bookShelf(countShelfs, countSLots); // создаем шкаф

	int command = -1;
	while (command != 0) { // пока не выход из меню
		system("cls"); // очистка экрана

		cout << "1. Add book" << endl;  // меню
		cout << "2. Get book" << endl;
		cout << "0. Exit" << endl;

		cout << "\nInput command: ";
		cin >> command;

		system("cls");
		switch (command)
		{
		case 1:
			addBook(bookShelf);
			cin.get(); cin.get();
			break;
		case 2:
		{
			getBook(bookShelf).print();
			cin.get(); cin.get();
			break;
		}
		default:
			break;
		}
	}

    return 0;
}

