/*
	Вывести индексы всех отрицательных чисел. Умножить положительные элементы массива на 3.
	Программа должна предоставить пользователю возможность
	выбора одного из двух способов заполнения массива: с клавиатуры
	или случайными числами из отрезка [A, B], границы которого задаёт
	пользователь. Заполнение массива каждым способом, вывод массива
	на экран и решение задач согласно варианту из списка задач
	для самостоятельного решения необходимо оформить в виде
	отдельных подпрограмм. Массивы и их длины передавать функциям
	с помощью списка аргументов, глобальные данные не использовать.
	Программа должна запросить у пользователя все необходимые
	исходные данные, вывести массив и результат решения задачи
	на экран. Она должна быть отформатирована и снабжена
	комментариями.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define MULTIPLIER	3
#define ARR_INIT	32
int GetArrSize(void);
int WayToWork(void);
void ManualSolution(int arrSize, int* nums);
void RandomSolution(int arrSize, int* nums);
void PrintIndexes(int arrSize, int* nums);
void ChangeArr(int arrSize, int* nums);
void PrintArr(int arrSize, int* nums, int isMulted);

int main(void)
{
	int nums[ARR_INIT];			//Обозначение массива чисел
	int arrSize = GetArrSize(); //Получение размера массива, с которыми мы будем работать

	switch (WayToWork())		//Заполнение массива в соответствии с выбранным способом
	{
	case 1:
		ManualSolution(arrSize, nums);
		break;
	case 2:
		RandomSolution(arrSize, nums);
		break;
	}
	printf("\nВывод:\n\n");

	//Определение, было ли выполнено изменение массива осуществляется...
	//посредством флага, передаваемого функции

	PrintArr(arrSize, nums, 0);	//Выполнение функции вывода до изменения массива
	ChangeArr(arrSize, nums);	//Умножение положительных чисел на 3	
	PrintArr(arrSize, nums, 1);	//Выполнение функции вывода после изменения массива

	return 0;
}

int GetArrSize(void)
{
	int arrSize = ARR_INIT + 1;	//Инициализация количества чисел массива
	do	//Цикл ввода корректного значения
	{
		printf("Введите размер массива чисел (не более %d): ", ARR_INIT);
		scanf("%d", &arrSize);
		if (arrSize > 0 && arrSize < ARR_INIT + 1)
			return arrSize;
		printf("Размер массива должен быть хотя бы 1, но не более %d\n", ARR_INIT);
	} while (1);
}

int WayToWork(void)
{
	int way;
	printf("Выберите способ заполнения массива:\n%s",
		"1 для ручного, 2 - для автозаполнения из диапазона: ");
	scanf("%d", &way);
	if (way > 0 && way <= 2)
		return way;
	printf("Введите правильное значение\n");
	return WayToWork();	//Вывод сообщения об ошибке и повторный ввод
}

void ManualSolution(int arrSize, int* nums)
{
	//Ввод значения в каждую ячейку массива
	for (int i = 0; i < arrSize; ++i)
	{
		printf("%d-я ячейка: ", i + 1);
		scanf("%d", &nums[i]);
	}
}

void RandomSolution(int arrSize, int* nums)
{
	srand(time(NULL));				//Создаёт псевдослучайный сид на основе времени
	int a, b;

	printf("Введите минимальное и максимальное значения для массива: \n");
	scanf("%d %d", &a, &b);
	if (a > b)
	{	//Меняет местами a и b при необходимости для правильной работы программы
		int tmp = b;
		b = a;
		a = tmp;
	}

	//Заполнение каждой ячейки случайным значением
	for (int i = 0; i < arrSize; i++)
		nums[i] = rand() % (b - a + 1) + a;
}

void ChangeArr(int arrSize, int* nums)
{	//Цикл перебирает элементы массива и, если значение в них положительное...
	//значение элемента умножается на множитель
	for (int i = 0; i < arrSize; ++i)
		if (nums[i] > 0)
			nums[i] *= MULTIPLIER;
}

void PrintArr(int arrSize, int* nums, int isMulted)
{	//Определение, было ли выполнено изменение массива осуществляется посредством флага isMulted
	if (isMulted)	//Если массив был модифицирован, выполняется эта часть
	{
		PrintIndexes(arrSize, nums);	//Вывод индексов отрицательных чисел на экран
		printf("\n\nТаблица после изменений:\n");
	}
	else			//Если массив не был модифицирован, выполняется эта часть
		printf("Таблица до изменений:\n");

	printf("%s%s%s%s",
		"╔════════════════════════════╗\n",
		"║           Вывод            ║\n",
		"╟──────────────╥─────────────╢\n",
		"║ Номер ячейки ║ Её значение ║\n");
	for (int i = 0; i < arrSize; ++i)	//Вывод заполненного массива
	{
		printf("╟──────────────╫─────────────╢\n");
		printf("║      %02d      ║ %-11d ║\n", i + 1, nums[i]);
	}
	printf("╚══════════════╩═════════════╝\n");
}

void PrintIndexes(int arrSize, int* nums)
{	//Цикл перебирает элементы массива и, если значение в них отрицательное...
	//выводится индекс этого элемента 
	printf("\nИндексы отрицательных чисел:\n");
	for (int i = 0; i < arrSize; ++i)
		if (nums[i] < 0)
			printf("%d ", i + 1);
}