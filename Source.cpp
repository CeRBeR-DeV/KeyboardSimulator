#include <iostream>
#include <ctime>
#include <conio.h>

void Start(char GeneratedArray[], char UserArray[], int n);
void Fill_Rand(char arr[], int n);
void Print(char arr[], int n);
void Enter(char user[], char rand[], int n);
void score(char user[], char compuer[], int n);
unsigned int Time = 0;

void main()
{
	setlocale(LC_ALL, "");
	std::cout << "Клавиатурный тренажер\nBackspace не работает\nУбедитесь что включен Caps Lock и английская раскладка клавиатуры\nУдачной тренировки :) :(\n\n";
	srand(time(NULL));
	const int n = 40;
	char GeneratedArray[n];
	char UserArray[n];
	Start(GeneratedArray, UserArray, n);
}
void Start(char GeneratedArray[], char UserArray[], int n)
{
	Fill_Rand(GeneratedArray, n);
	Print(GeneratedArray, n);
	Enter(UserArray, GeneratedArray, n);
	score(UserArray, GeneratedArray, n);
}
void Fill_Rand(char arr[], int n)
{
	for (int i = 0; i < n; i++)i % 5 == 4 ? arr[i] = ' ' : arr[i] = char((rand() % 25) + 65);
}
void Print(char arr[], int n)
{
	for (int i = 0; i < n; i++)std::cout << arr[i];
}
void Enter(char user[], char rand[], int n)
{
	unsigned int start_time = clock();
	std::cout << std::endl << std::endl;
	//
	for (int i = 0; i < n; i++)
	{
		user[i] = _getch();
	    if (user[i] == rand[i])std::cout << "\033[32m\033[1m" << user[i] << "\033[0m";
		else std::cout << "\033[31m\033[1m" << user[i] << "\033[0m";
	}
	//
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	Time = search_time;
}
void score(char user[], char rand[], int n)
{
	int neverno = 0, verno = 0;
	for (int i = 0; i < n; i++)user[i] != rand[i] ? neverno++ : verno++;
	std::cout << "\n\n\nПравильно: " << verno;
	std::cout << "\n\nОшибок: " << neverno;
	int Sec = Time / 1000;
	int MSec = Time - (Sec * 1000);
	std::cout << "\n\nВремя: " << Sec << "," << MSec << " секунд";
}