#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int q;
	map<string, string> catalog;
	string command;
	cout << "Введите количество команд: ";
	cin >> q;
	while (q)
	{
		cout << "Введите команду: (CHANGE_CAPITAL-Изменение столицы страны или добавление страны если раньше ее не было" << endl;
		cout << "RENAME - Переименование страны" << endl;
		cout << "ABOUT - Вывод столицы страны" << endl;
		cout << "DUMP - Вывод столиц всех стран" << endl;
		cin >> command;
		if (command == "DUMP")
		{
			if (catalog.size())
			{
				for (const auto& s : catalog)
					cout << s.first << "/" << s.second << " ";
			}
			else
				cout << "Такой страны нет";
			cout << "\n";
		}
		else
		{
			string country;
			cout << "Введите страну: ";
			cin >> country;
			auto iter_country = catalog.find(country);
			auto end_of_catalog = catalog.end();
			if (command == "ABOUT")
			{
				if (iter_country != end_of_catalog)
				{
					cout << "Страна: " << country << " Столица: " << iter_country->second;
				}
				else
					cout << "Страна: " << country << " Не существует";
				cout << "\n";
			}
			else
			{
				string capital;
				cout << "Введите столицу(страну): ";
				cin >> capital;
				if (command == "RENAME")
				{
					auto iter_new_country = catalog.find(capital);
					if (capital == country ||
						iter_country == end_of_catalog ||
						iter_new_country != end_of_catalog)
						cout << "Неправильное переименование" << endl;
					else
					{
						cout << "Страна: " << country << " Столица " << catalog[country] << " Переименовано: " << capital << endl;
						catalog[capital] = catalog[country];
						catalog.erase(country);
					}
				}
				else if (command == "CHANGE_CAPITAL")
				{
					if (catalog[country] == capital)
						cout << "Страна: " << country << " Не изменила столицу" << endl;
					else
					{
						if (iter_country == end_of_catalog)
							cout << "Ввели новую страну: " << country << " столица: " << capital << endl;
						else if (catalog[country] != capital)
							cout << "Страна: " << country << " Изменила столицу " << catalog[country] << " в " << capital << endl;
						catalog[country] = capital;
					}
				}
			}
		}
		--q;
	}
	system("pause");
	return 0;
}