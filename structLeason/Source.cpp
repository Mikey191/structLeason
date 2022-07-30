//	создвем структуру видеомагазина
// содержание структуры
//Название фильма
//Режессер
//Жанр
//Рейтинг популярности
//Цена диска
//  реализовать след функции
//Поиск по названию
//Поиск по жанру
//Поиск по режесеру
//Самый популярный фильм в жанре
//Показ всех записей
//Добавление
//

#include <iostream>
using namespace std;

struct film
{
	char title[20];//название фильма
	char director[20];//ражесер
	char genre[20];//жанр
	double rating;//рейтинг
	double price;//цена диск
};


void ShowList(film* &a, int &size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i].title << endl;
		cout << a[i].director << endl;
		cout << a[i].genre << endl;
		cout << a[i].rating << endl;
		cout << a[i].price << endl;
	}
	cout << "\n";
}

void ShowOneFilm(film a)
{
	cout << a.title << endl;
	cout << a.director << endl;
	cout << a.genre << endl;
	cout << a.rating << endl;
	cout << a.price << endl;
}

//функция добавления фильма вручную
film addFilm()
{
	film temp;
	cout << "Film title: ";
	cin >> temp.title;
	cout << "Film Director: ";
	cin >> temp.director;
	cout << "Film genre: ";
	cin >> temp.genre;
	cout << "Film rating: ";
	cin >> temp.rating;
	cout << "Film price: ";
	cin >> temp.price;
	//cout << "U add film" << endl;
	//ShowOneFilm(temp);
	return temp;
}

void pushBackList(film*& arr, int &sizea)
{
	film* newarr = new film[sizea + 1];
	for (size_t i = 0; i < sizea; i++) 
	{
		newarr[i] = arr[i];
	}
	newarr[sizea] = addFilm();
	sizea++;

	delete[] arr;
	arr = newarr;
}


void menu(film* b, int &sizeb)
{
	b[0] = addFilm();
	cout << "\tHello\n";
	cout << "Menu: 1 - search by name\n";
	cout << "Menu: 2 - search by genre\n";
	cout << "Menu: 3 - search by director\n";
	cout << "Menu: 4 - most popular movie\n";
	cout << "Menu: 5 - show all\n";
	cout << "Menu: 6 - add film\n";
	cout << "Menu: 0 - exit\n";

	int choice;
	do
	{
		cin >> choice;
		switch (choice) 
		{
			case 1: break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5:
				ShowList(b, sizeb);
				break;
			case 6:
				cout << "sizelist befor = " << sizeb << endl;
				pushBackList(b, sizeb);
				cout << "sizelist after = " << sizeb << endl;
				break;
		}
	} while (choice != 0);
}


int main()
{
	int sizelist = 1;
	film* ListFilm = new film[sizelist];
	
	menu(ListFilm, sizelist);
	cout << "SIZE LIST = " << sizelist << endl;
	
	delete[] ListFilm;

	return 0;
}