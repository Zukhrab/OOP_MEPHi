	
		Из входного потока вводится прямоугольная сильно разреженная матрица целых чисел [aij], i = 1, …, m, j
	= 1, …, n. Значения m и n заранее не известны и вводятся из входного потока.
	Сформировать вектор {bi}, i = 1, …, m, i-ый элемент которого равен максимальному количеству
	одинаковых элементов в i-ой строке матрицы.
	Исходную матрицу и полученный вектор вывести в выходной поток с необходимыми комментариями.

		
		Требования:

	1) Выбранная структура матрицы должна учитывать специфику разреженной матрицы (оптимальность)

	2) Проверка корректности ввода (работа через потоки C++) (обязательно)
	
	3) Статический анализ кода
	
	4) Не "кривой", не избыточный, поддерживаемый и расширяемый код (разумная декомпозиция, DRY)
	
	5) Использование ООП
	
	6) Стандарт языка C++17 (рекомендуется), С++20 (при наличии). Допустим C++11 или С++14.
