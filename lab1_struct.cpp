#include "stdafx.h"
#include <iostream>

#include <fstream>

using namespace std;

struct Date

{

	int year, month, day;

	void Show()

	{

		cout << endl << "Now: " << day << "." << month << "." << year << endl;

	}

	//перевод на след день

	void Next_date()

	{

		day++; //+ день



	}

	//перевод надень назад

	void Prev_date()

	{

		day--; //день назад


		if (day == 0)

		{

			

			 if ((month - 1 == 3) || (month - 1 == 5) || (month - 1 == 7) || (month - 1 == 8) || (month - 1 == 10) || (month - 1 == 0))

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

	ifstream file("data.txt");

	if (!file.is_open())

		cout << "File is not open!" << endl;

	Date temp;

	int n = 0;

	while (!file.eof())

	{

		file >> temp.day >> temp.month >> temp.year;

		n++;

	}

	file.close();

	//создание массива по кол-во дат 

	Date* DT;

	DT = new Date[n];

	file.open("data.txt");

	int i = 0;

	while (!file.eof())

	{

		//счтывание дат в отдельный элемент массива каждая дата

		file >> DT[i].day >> DT[i].month >> DT[i].year;

		i++;

	}

	//вивод

	cout << " Recording from file" << endl;

	for (int i = 0; i < n; i++)

	{

		cout << endl << i + 1 << " - current date: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;


		DT[i].Prev_date();

		cout << " | previous: " << DT[i].day << "." << DT[i].month << "." << DT[i].year;

		DT[i].Next_date();

		cout << endl;

	}

	//вариант 8 задание

	cout << endl << endl << "Variant 8" << endl;

	for (int i = 0; i < n; i++)

		if ((DT[i].day == 1) && (DT[i].month == 1))

		{
		
			break;

		}

		else

		{
			
			
			cout << i + 1 << ":" << DT[i].day << "." << DT[i].month << "." << DT[i].year << "-";

			DT[i].Prev_date();

			cout << DT[i].day << "." << DT[i].month << "." << DT[i].year << endl;

			DT[i].Prev_date();

		}

	return 0;

}