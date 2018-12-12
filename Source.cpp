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
	cout << "������� ���������� ������: ";
	cin >> q;
	while (q)
	{
		cout << "������� �������: (CHANGE_CAPITAL-��������� ������� ������ ��� ���������� ������ ���� ������ �� �� ����" << endl;
		cout << "RENAME - �������������� ������" << endl;
		cout << "ABOUT - ����� ������� ������" << endl;
		cout << "DUMP - ����� ������ ���� �����" << endl;
		cin >> command;
		if (command == "DUMP")
		{
			if (catalog.size())
			{
				for (const auto& s : catalog)
					cout << s.first << "/" << s.second << " ";
			}
			else
				cout << "����� ������ ���";
			cout << "\n";
		}
		else
		{
			string country;
			cout << "������� ������: ";
			cin >> country;
			auto iter_country = catalog.find(country);
			auto end_of_catalog = catalog.end();
			if (command == "ABOUT")
			{
				if (iter_country != end_of_catalog)
				{
					cout << "������: " << country << " �������: " << iter_country->second;
				}
				else
					cout << "������: " << country << " �� ����������";
				cout << "\n";
			}
			else
			{
				string capital;
				cout << "������� �������(������): ";
				cin >> capital;
				if (command == "RENAME")
				{
					auto iter_new_country = catalog.find(capital);
					if (capital == country ||
						iter_country == end_of_catalog ||
						iter_new_country != end_of_catalog)
						cout << "������������ ��������������" << endl;
					else
					{
						cout << "������: " << country << " ������� " << catalog[country] << " �������������: " << capital << endl;
						catalog[capital] = catalog[country];
						catalog.erase(country);
					}
				}
				else if (command == "CHANGE_CAPITAL")
				{
					if (catalog[country] == capital)
						cout << "������: " << country << " �� �������� �������" << endl;
					else
					{
						if (iter_country == end_of_catalog)
							cout << "����� ����� ������: " << country << " �������: " << capital << endl;
						else if (catalog[country] != capital)
							cout << "������: " << country << " �������� ������� " << catalog[country] << " � " << capital << endl;
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