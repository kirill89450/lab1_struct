#include <iostream>

#include <fstream>

using namespace std;

struct Date

{
	int year,month,day;
	void Show()

	{
		cout << endl << "Сейчас: " << day << "." << month << "." << year <<  endl;
	}

	//перевод на след день

	void Next_date()

	{	
		day++;

		if ((month == 2) && (year % 4 == 0) && (day==30))

		{
			day = 1;
			month =3;
			

		}
		else if ((month == 2) && (year % 4!= 0) && (day == 29))

		{
			day = 1;
			month = 3;


		}
		if ((day == 32) && ((month  == 3) || (month  == 5) || (month  == 7) || (month  == 8) || (month  == 10) || (month  == 1)))
		{
			day = 1;
			month += 1;

		}
		if ((day == 31) && ((month == 4) || (month == 6) || (month == 9) || (month == 11)))
		{

			day = 1;
			month += 1;
		}
		else if ((day == 32) && (month == 12))
		{
			day = 1;
			month = 1;
			year += 1;
		}
	}

	//перевод надень назад

	void Prev_date()

	{
		day--; //день назад

		if (day == 0)

		{
			if ((month == 3) && (year % 4 != 0))

			{
				day = 28;

				month--;
			}

			else if ((month == 3) && (year % 4 == 0))

			{

				day = 29;

				month--;

			}

			else if ((month - 1 == 3) || (month - 1 == 5) || (month - 1 == 7) || (month - 1 == 8) || (month - 1 == 10) || (month - 1 == 0))

			{

				day = 31;

				month--;

				if (month == 0)

				{

					month = 12;

					year--;

				}

			}

			else

			{

				day = 30;

				month--;

			}

		}

	}

};

int main()

{

	setlocale(LC_ALL, "ru");

	ifstream fin("data.txt");

	if (!fin.is_open())

		cout << "Файл не был отрыт!" << endl;

	Date temp;

	int n = 0;

	while (!fin.eof())

	{

		fin >> temp.day >> temp.month >> temp.year ;

		n++;

	}

	fin.close();

	//создание массива по кол-во дат 

	Date* DT;

	DT = new Date[n];

	fin.open("data.txt");

	int i = 0;

	while (!fin.eof())

	{

		//счтывание дат в отдельный элемент массива каждая дата

		fin >> DT[i].day >> DT[i].month >> DT[i].year ;

		i++;

	}

	//вивод

	cout << "Запись из файла" << endl;

	for (int i = 0; i < n; i++)

	{

		cout << endl << i + 1 << " - Нынешняя дата: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;
		

		DT[i].Prev_date();

		cout << " | Предыдущая: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;

		DT[i].Next_date();
		

		cout << endl;

	}

	//вариант 8 задание

	cout << endl << endl << "Вариативное задание 8" << endl;

	for (int i = 0; i < n; i++)

		if ((DT[i].day == 1) && (DT[i].month == 01))

		

			continue;

		

		else

		{

			cout << i + 1 << ":" << DT[i].day << "." << DT[i].month << "." << DT[i].year << "-";

			DT[i].Prev_date(); 
			

			cout << DT[i].day << "." << DT[i].month << "." << DT[i].year << endl;

			DT[i].Prev_date();

		}

	return 0;

}