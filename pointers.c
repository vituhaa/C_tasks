// # 9 указатели
int main() {
	setlocale(LC_ALL, "Russian");
	// пример 1 //
	int x = 10;
	int* p; // объявление указателя
	p = &x; // получение адреса
	printf("// пример 1 // \n");
	printf("Значение x = %d, значение адреса x = %p\n", x, p); // значение p при каждом запуске разное -> 10, адрес
	printf("Получение значения через разыменование: %d\n", *p); // -> 10
	printf("\n");

	// пример 2 //
	int y = *p;
	printf("// пример 2 // \n");
	printf("Значение y = %d \n", y); // разыменовние и присвоение другой переменной -> 10
	printf("\n");

	// пример 3 //
	char ch = 'A';
	int d = 20;
	short s = 2;

	char* cp = &ch;
	int* dp = &d;
	short* sp = &s;
	printf("// пример 3 // \n");
	printf("Значение char c = %c, Адрес char c = %p\n", *cp, cp); // -> разыменование (из адреса получаем число), адрес
	printf("Значение int d = %d, Адрес int d = %p\n", *dp, dp);
	printf("Значение short s = %hd, Адрес short s = %p\n", *sp, sp);
	printf("\n");

	// пример 4 //
	return 0;
}


// # 10 операции с указателями
int main() {
	setlocale(LC_ALL, "Russian");
	// ПРИСВАИВАНИЕ //
	int a = 10;
	int b = 20;
	int* pa = &a;
	int* pb = &b;
	printf("// Присваивание // \n");
	printf("Число a = %d, число b = %d\n", *pa, *pb);
	printf("Адрес числа a = %p, адрес числа b = %p\n", pa, pb);
	printf("Значение числа a через разыменование = %d, адрес числа a = %p\n", *pa, pa);
	pa = pb;
	printf("Результат операции присвоения адреса b адресу a: число = %d, адрес = %p\n", *pa, pa);
	printf("\n");

	// РАЗЫМЕНОВАНИЕ //
	int c = 10;
	int* pc = &c;
	int* pd = pc;
	printf("// Разыменование // \n");
	printf("Адрес в указателе pc: %p \n", pc);
	printf("Адрес в указателе pd: %p \n", pd); 

	*pc = 25;

	// pc — это значение указателя, то есть адрес 0x7ffee4a3c9a4.
	// * pc — это разыменование : «возьми то, что лежит по адресу, хранящемуся в pc».
	// * pc = 25 — «положи 25 по адресу, который хранится в pc».
	// То есть мы не меняем pc.Мы идём по адресу, который в нём записан, и меняем то, что там лежит — то есть переменную c:
	//pc: [0x7ffee4a3c9a4] ← pc НЕ изменился, тот же адрес
	//pd : [0x7ffee4a3c9a4] ← pd тоже не изменился
	//c : [25] ← а вот ЗНАЧЕНИЕ по этому адресу изменилось

	printf("Адрес в указателе pc после присвоения 25: %p \n", pc);
	printf("Значение в указателе pc: %d \n", *pc);  // 25
	printf("Значение в указателе pd: %d \n", *pd);  // 25
	printf("Значение числа c: %d \n", c);    // 25
	printf("\n");

	// УКАЗАТЕЛЬ НА VOID //
	int x = 123;
	int* xp = &x;
	void* vp = xp;

	printf("Значение в указателе xp = %d, адрес в указателе xp = %p\n", *xp, (void*)xp); // также можно просто написать xp
	printf("Значение в указателе vp = %d, адрес в указателе vp = %p\n", *((int*)vp), vp);
	printf("\n");


	// АДРЕС УКАЗАТЕЛЯ //
	printf("Адрес указателя xp = %p\n", (void*)&xp);
	printf("Адрес В указателе xp = %p\n", (void*)xp);
	printf("\n");

	// ПРИВЕДЕНИЕ ТИПОВ //
	char ch = 'N';
	char* p_ch = &ch;
	int* pd_ch = (int*)p_ch;
	printf("Адрес в p_ch = %p\n", p_ch);
	printf("Адрес в pd_ch = %p\n", pd_ch);

	return 0;
}


// # 11 - тоже указатели
int main() {
	setlocale(LC_ALL, "Russian");

	// ИНКРЕМЕНТ И ДЕКРЕМЕНТ //
	int n = 10;
	int* pn = &n;
	printf("// ИНКРЕМЕНТ И ДЕКРЕМЕНТ //\n");
	printf("Адрес в pn = %p, значение в pn = %d\n", pn, *pn);

	pn++;
	printf("Адрес в pn после инкремента = %p, значение в pn = %d\n", pn, *pn);

	pn--;
	printf("Адрес в pn после декремента = %p, значение в pn = %d\n", pn, *pn);
	printf("\n");


	// ВЫЧИТАНИЕ УКАЗАТЕЛЕЙ //
	int a = 10;
	int b = 23;
	int* pa = &a;
	int* pb = &b;
	ptrdiff_t c = pb - pa;

	printf("// ВЫЧИТАНИЕ УКАЗАТЕЛЕЙ //\n");
	printf("Адрес в pa = %p\n", pa);
	printf("Адрес в pb = %p\n", pb);
	printf("Расстояние между указателями = %lld\n", c);
	printf("sizeof(int) = %zu байт\n", sizeof(int));
	printf("\n");

	// РАЗНИЦА МЕЖДУ ЭЛЕМЕНТАМИ МАССИВА //
	int arr[64];
	int* p_one = &arr[10];
	int* p_two = &arr[40];
	ptrdiff_t dist = p_two - p_one;
	printf("// РАЗНИЦА МЕЖДУ ЭЛЕМЕНТАМИ МАССИВА //\n");
	printf("dist = %lld\n", dist);
	printf("\n");

	// ПРИОРИТЕТ ОПЕРАЦИЙ //
	int d = 10;
	int* pd = &d;
	printf("// ПРИОРИТЕТ ОПЕРАЦИЙ //\n");
	printf("Адрес в pd = %p, значение в pd = %d\n", pd, *pd);
	//int res_1 = *pd++;
	int res_1 = (*pd)++;
	//int res_1 = ++ * pd;
	//int res_1 = *++pd;

	printf("Значение в res_1 = %d\n", res_1);
	printf("Адрес в pd после res_1 = %p, значение в pd = %d\n", pd, *pd);
	printf("\n");


	// УКАЗАТЕЛЬ VOID //
	int num_1 = 10;
	int num_2 = 11;
	int num_3 = 12;
	int num_4 = 13;

	void* n_p = &num_1;

	void* n_p2 = &num_2;
	void* n_p3 = &num_3;
	void* n_p4 = &num_4;
	printf("Адрес в num_1 = %p\n", n_p);
	printf("Адрес в num_2 = %p\n", n_p2);
	printf("Адрес в num_3 = %p\n", n_p3);
	printf("Адрес в num_4 = %p\n", n_p4);
	printf("Значение в указателе n_p = %d, адрес в указателе n_p = %p\n", *(((int*)n_p) + 16), (int*)n_p + 16);
}


// # 12 - константы и указатели
int main() {
	setlocale(LC_ALL, "Russian");

	// ИЗМЕНЕНИЕ КОНСТАНТЫ ПО УКАЗАТЕЛЮ //
	const int c = 10;
	*(int*)&c = 20; // адрес константы преобразуем в int, потом разыменовываем, кладём 20 вовнутрь
	printf("// ИЗМЕНЕНИЕ КОНСТАНТЫ ПО УКАЗАТЕЛЮ //\n");
	printf("Значение константы c = %d\n", c);
	printf("\n");


	// УКАЗАТЕЛИ НА КОНСТАНТЫ //
	const int a = 10;
	const int* pa = &a;
	//*pa = 34; // -> ошибка
	printf("// УКАЗАТЕЛИ НА КОНСТАНТЫ //\n");
	printf("address=%p \t value=%d \n", pa, *pa);
	printf("\n");


	// ИЗМЕНЕНИЕ КОНСТАНТЫ ПО УКАЗАТЕЛЮ 2 //
	int b = 10;
	const int* b_p = &b;
	printf("// ИЗМЕНЕНИЕ КОНСТАНТЫ ПО УКАЗАТЕЛЮ 2 //\n");
	printf("value=%d \n", *b_p);
	b = 22;
	printf("value=%d \n", *b_p);
	printf("\n");


	// КОНСТАНТНЫЙ УКАЗАТЕЛЬ //
	int d = 10;
	int* const pd = &d;
	*pd = 22;
	printf("%d\n", *pd);
	printf("// КОНСТАНТНЫЙ УКАЗАТЕЛЬ //\n");
	printf("\n");


	// КОНСТАНТНЫЙ УКАЗАТЕЛЬ НА КОНСТАНТУ //
	int e = 10;
	const int* const ep = &e;
	// ни адрес ни значение менять нельзя
	return 0;
}


// # 13 - массивы и указатели
int main() {
	setlocale(LC_ALL, "Russian");

	// МАССИВ И УКАЗАТЕЛЬ //
	printf("// МАССИВ И УКАЗАТЕЛЬ //\n");
	int numbers[] = {1, 2, 3, 4};
	for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
		printf("numbers[%d]: %p\n", i, numbers + i);
	}

	printf("%p %d", numbers + 1, *(numbers + 1)); // -> адрес второго элемента, 
												  // 2 (тк берём адрес 1 эл-та, двигаем на 1, потом берём число, т.е. 2)
	printf("\n\n");


	// ПЕРЕБОР МАССИВА С УКАЗАТЕЛЯМИ //
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;
	printf("// ПЕРЕБОР МАССИВА С УКАЗАТЕЛЯМИ //\n");
	for (int* ptr = arr; ptr <= &arr[4]; ptr++) {
		printf("Address = %p, value = %d\n", ptr, *ptr);
	}
	printf("\n\n");


	// ПЕРЕБОР ДВУМЕРНОГО МАССИВА С УКАЗАТЕЛЯМИ //
	printf("// ПЕРЕБОР ДВУМЕРНОГО МАССИВА С УКАЗАТЕЛЯМИ //\n");
	int num[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int rows = sizeof(num) / sizeof(num[0]); 
	int cols = sizeof(num[0]) / sizeof(num[0][0]);
	for (int* ptr = num[0], i = 0; i < rows * cols;) {
		printf("%d \t", *ptr++);
		if (++i % cols == 0) {
			printf("\n");
		}
	}

	return 0;
}


// # 14 - функция и указатель
void sum_digits(int* ptr_x)
{
   int sum = 0;
   while (*ptr_x != 0) {
       sum += *ptr_x % 10;
       *ptr_x /= 10;
   }
   *ptr_x = sum;
   printf("%d", *ptr_x);
}

int main() {
   int a;
   scanf_s("%d", &a);
   int* p_a = &a;
   sum_digits(p_a);
	return 0;
}


// # 15 - строка и указатель
int main() {
	setlocale(LC_ALL, "Russian");

	// КЛАССИЧЕСКОЕ ОБЪЯВЛЕНИЕ ЧЕРЕЗ СТРОКУ //
	printf("// КЛАССИЧЕСКОЕ ОБЪЯВЛЕНИЕ ЧЕРЕЗ СТРОКУ //\n");
	const char* hello = "Hello, world!";
	printf("%s\n", hello);
	printf("\n\n");


	// УКАЗАТЕЛЬ НА СТРОКУ НАПРЯМУЮ //
	const char* s_1 = "Hello, world";
	const char (*s_2)[] = (const char (*)[]) & "Hello, world";
	printf("s_1 = %p \n", &s_1[0]);
	printf("s_2 = %p \n", s_2);
	return 0;
}


// # 16 - массив указателей, указатель на массив
int main() {
	setlocale(LC_ALL, "Russian");

	// МАССИВ УКАЗАТЕЛЕЙ //
	// три способа задать массив указателей:
	int array[] = { 1, 2, 3, 4 };
	int* p1[3]; // 1 способ
	int* p2[] = { &array[1], &array[2], &array[0] }; // 2 способ
	int* p3[3] = { &array[1], &array[2], &array[0] }; // 3 способ

	printf("// МАССИВ УКАЗАТЕЛЕЙ //\n");
	for (int i = 0; i < 3; i++) {
		//printf("Значение в индексе %d массива p1 = %d ", i, *p1[i]);
		//printf("Значение в индексе %d массива p2 = %d \n", i, *p2[i]);
		//printf("Значение в индексе %d массива p3 = %d \n", i, *p3[i]);
		printf("Значение в индексе %d массива p3 = %d \n", i, **(p3 + i));
	}
	printf("\n\n");

	// УКАЗАТЕЛЬ НА МАССИВ // 
	int(*pa)[4] = &array;
	printf("Первый элемент - %d\n",(*pa)[0]);
	printf("\n\n");

	// ПОДМАССИВЫ МНОГОМЕРНЫХ МАССИВОВ //
	int array_1[3][2] = { {1, 2}, {3, 4}, {5, 6} };
	printf("%p\n", array_1);
	printf("%p\n", &array_1[0][0]); // адрес первого элемента и адрес массива - одни и те же

	int(*pa_1)[2] = array_1 + 1; // указатель на 2 подмассив
	printf("// ПОДМАССИВЫ МНОГОМЕРНЫХ МАССИВОВ //\n");
	for (size_t i = 0; i < sizeof(*pa_1) / sizeof(*pa_1[0]); i++) {
		printf("%d ", (*pa_1)[i]);
	}
	printf("\n\n");


	// УКАЗАТЕЛЬ И МАССИВ СТРОК //
	printf("// УКАЗАТЕЛЬ И МАССИВ СТРОК //\n");
	const char* fruit[] = { "apricot", "apple", "banana", "lemon", "orange" };
	for (int i = 0; i < 5; i++)
	{
		printf("%s \n", *(fruit + i)); // или fruit[i]
	}
	printf("\n\n");


	// МНОГОУРОВНЕВАЯ АДРЕСАЦИЯ, УКЗААТЕЛЬ НА УКАЗАТЕЛЬ //
	int  x = 22;
	int* px = &x;       // указатель px хранит адрес переменной x
	int** ppx = &px;    // указатель ppx хранит адрес указателя px
	printf("// МНОГОУРОВНЕВАЯ АДРЕСАЦИЯ, УКЗААТЕЛЬ НА УКАЗАТЕЛЬ //\n");
	printf("Address of px: %p \n", (void*)ppx);
	printf("Address of x: %p \n", (void*)*ppx);
	printf("Value of x: %d \n", **ppx);
	printf("\n\n");
}
