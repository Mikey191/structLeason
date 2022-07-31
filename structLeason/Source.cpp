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

void ShowList(film* &a, int &size)//показывает все добавленные фильмы
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Title : " << a[i].title << endl;
		cout << "Director by : " << a[i].director << endl;
		cout << "Genre : " << a[i].genre << endl;
		cout << "Rating : " << a[i].rating << endl;
		cout << "Price : " << a[i].price << endl;
	}
	cout << "\n";
	system("pause");
}

void ShowOneFilm(film a)//показываает один фильм
{
	cout << "Title : " << a.title << endl;
	cout << "Director by : " << a.director << endl;
	cout << "Genre : " << a.genre << endl;
	cout << "Rating : " << a.rating << endl;
	cout << "Price : " << a.price << endl;
}

film addFilm()//функция добавления фильма вручную
{
	film temp;
	cout << "Film title: ";
	cin.getline(temp.title, 20);
	cin.getline(temp.title, 20);
	cout << "Film Director: ";
	cin.getline(temp.director, 20);
	cout << "Film genre: ";
	cin.getline(temp.genre, 20);
	cout << "Film rating: ";
	cin >> temp.rating;
	cout << "Film price: ";
	cin >> temp.price;
	return temp;
}
//
//void pushBackList(film*& arr, int &sizea) //почему эта функция работает некорректно???
//{
//	film* newarr = new film[sizea + 1];
//	for (size_t i = 0; i < sizea; i++) 
//	{
//		newarr[i] = arr[i];
//	}
//	newarr[sizea++] = addFilm();
//
//	delete[] arr;
//	arr = newarr;
//}

void pushBackList(film* &a, int& sizea)//доавление нового фильма вконец списка
{
	film* tmp;
	tmp = a;
	a = new film[sizea + 1];
	for (size_t i = 0; i < sizea; i++)
	{
		a[i] = tmp[i];
	}
	a[sizea++] = addFilm();
	delete[] tmp;
}

void searchTitle(film* &a, int &sizea)
{
	//Функция strcmp() 
	//осуществляет лексикографическую проверку двух строк, 
	//оканчивающихся нулевыми символами, и возвращает целое число со следующим 
	//значением:
	//меньше 0 если str1 < str2
	// 0 если str1 = str2
	//больше 0 если str1 > str2
	//
	cout << "Enter title: " << endl;
	film s;
	cin >> s.title;

	for (size_t i = 0; i < sizea; i++)
	{
		if (strcmp(a[i].title, s.title) == 0)
			ShowOneFilm(a[i]);
	}
	system("pause");
}

void searchGenre(film*& a, int& sizea)
{
	cout << "Enter genre: " << endl;
	film s;
	cin >> s.genre;

	for (size_t i = 0; i < sizea; i++)
	{
		if (strcmp(a[i].genre, s.genre) == 0)
			ShowOneFilm(a[i]);
	}
	system("pause");
}

void searchDirector(film*& a, int& sizea)
{
	cout << "Enter Director: " << endl;
	film s;
	cin >> s.director;

	for (size_t i = 0; i < sizea; i++)
	{
		if (strcmp(a[i].director, s.director) == 0)
			ShowOneFilm(a[i]);
	}
	system("pause");
}

void MostPopFilmGenre(film*& a, int& sizea)
{
	cout << "Enter Genre: ";
	film s;
	cin >> s.genre;
	int b=0, tmp=a[0].rating;
	for (size_t i = 0; i < sizea; i++)
	{
		if (strcmp(a[i].genre, s.genre) == 0)
		{
			if (a[i].rating > tmp)
			{
				tmp = a[i].rating;
				b = i;
			}
		}
	}
	cout << "Most popular film in genre " << a[b].genre << " is " << a[b].title << endl;
	cout << " with rating : " << a[b].rating << endl;
	system("pause");
}

void menu(film* &b, int &sizeb)
{
	cout << "\tHello, world!\n";
	cout << "Add first film" << endl;
	cout << "Skip first add " << endl;
	b[0] = addFilm();

	int choice;
	do
	{
		system("cls");
		cout << "\tMenu\n";
		cout << "Menu: 1 - search by title\n";
		cout << "Menu: 2 - search by genre\n";
		cout << "Menu: 3 - search by director\n";
		cout << "Menu: 4 - most popular movie\n";
		cout << "Menu: 5 - show all\n";
		cout << "Menu: 6 - add film\n";
		cout << "Menu: 0 - exit\n";
		cout << "Your choise: ";
		cin >> choice;
		switch (choice) 
		{
			case 1: 
				searchTitle(b, sizeb);
				break;
			case 2:
				searchGenre(b, sizeb);
				break;
			case 3: 
				searchDirector(b, sizeb);
				break;
			case 4: 
				MostPopFilmGenre(b, sizeb);
				break;
			case 5:
				ShowList(b, sizeb);
				break;
			case 6:
				pushBackList(b, sizeb);
				break;
		}
	} while (choice != 0);
}


int main()
{
	int sizelist = 1;
	film* ListFilm = new film[sizelist];
	
	menu(ListFilm, sizelist);
		
	delete[] ListFilm;

	return 0;
}