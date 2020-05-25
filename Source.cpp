#include <iostream>
#include <conio.h>
#include <ctime>

void Start(char GeneratedArray[], char UserArray[], int n);
void Fill_Rand(char arr[], int n);
void Print(char arr[], int n);
void Enter(char user[], char compuer[], int n);
void score(char user[], char compuer[], int n);
unsigned int Time = 0;

void main()
{
	setlocale(LC_ALL, "");
	std::cout << "Клавиатурный тренажер\nУбедитесь что включен Caps Lock и английская раскладка клавиатуры\nУдачной тренировки :)\n";
	srand(time(NULL));
	const int n = 49;
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
void Enter(char user[], char compuer[], int n)
{
	unsigned int start_time = clock();
	std::cout << std::endl << std::endl;
	//
	for (int i = 0; i < n; i++)
	{
		user[i] = _getch();
	    if (user[i] == compuer[i])std::cout << "\033[32m\033[1m" << user[i] << "\033[0m";
		else std::cout << "\033[31m\033[1m" << user[i] << "\033[0m";
	}
	//
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	Time = search_time;
}
void score(char user[], char compuer[], int n)
{
	int incorrect = 0, correct = 0;
	for (int i = 0; i < n; i++)user[i] != compuer[i] ? incorrect++ : correct++;
	std::cout << "\n\n\nПравильно: " << correct;
	std::cout << "\n\nОшибок: " << incorrect;
	int Sec = Time / 1000;
	int MSec = Time - (Sec * 1000);
	std::cout << "\n\nВремя: " << Sec << "," << MSec << " секунд";
}