//	������� ��������� �������������
// ���������� ���������
//�������� ������
//��������
//����
//������� ������������
//���� �����
//  ����������� ���� �������
//����� �� ��������
//����� �� �����
//����� �� ��������
//����� ���������� ����� � �����
//����� ���� �������
//����������
//

#include <iostream>
using namespace std;

struct film
{
	char title[20];//�������� ������
	char director[20];//�������
	char genre[20];//����
	double rating;//�������
	double price;//���� ����
};
//������� ���������� ������ �������
film create()
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
	return temp;
}

void ShowList(film* a, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i].title<< endl;
		cout << a[i].director << endl;
		cout << a[i].genre << endl;
		cout << a[i].rating<< endl;
		cout << a[i].price << endl;
	}
	cout << endl;
}


int main()
{
	int sizelist = 2;
	film* ListFilm = new film[sizelist];
	ListFilm[0] = create();
	cout << endl;
	ListFilm[1] = create();
	cout << endl;
	ShowList(ListFilm, sizelist);

	return 0;
}