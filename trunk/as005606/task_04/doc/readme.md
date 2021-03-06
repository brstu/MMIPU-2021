				
                                  МИНИСТЕРСТВО ОБРАЗОВАНИЯ РЕСПУБЛИКИ БЕЛАРУСЬ
                                            УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ 
                              «БРЕСТСКИЙ ГОСУДАРСТВЕННЫЙ ТЕХНИЧЕСКИЙ УНИВЕРСИТЕТ»
                                                КАФЕДРА ИИТ




                                            Лабораторная работа № 4
           По дисциплине: «Математические модели информационных процессов и управления»
                                              За 5 семестр
                             Тема: «Построение эквивалентной передаточной функции»







                                                                            Выполнил:
                                                                            студент 3-го курса
                                                                            группы АС-56
                                                                            Железко В. Д.

                                                                            Проверил:
                                                                            Пролиско Е. Е.






                                              Брест 2021



	Цель: 
		1) Изучить способы построения эквивалентных моделей, используя средства MATLAB;
		2) построить эквивалентную модель и исследовать её с помощью LTI-viewer, 
		результат сравнить с исходной моделью.

	Задание 1.
Выполним структурную схему, сверяясь с методологическими указаниями.
Структурная схема:

![model1](images/model1.png)

Передаточные функции блоков:

![funcModel1](images/funcModel1.png)

где А = номер дня рождения / 100; В = номер месяца рождения / 100 .
На осциллографе (Scope) получим переходную функцию системы:

![model1Scope](images/model1Scope.png)

Характеристики системы:

![functions1](images/functions1.png)

	Задание 2. 
Построим эквивалентную схему:

![EcvModel2](images/EcvModel2.png)

На осциллографе (Scope) получим переходную функцию системы:

![model2Scope](images/model2Scope.png)

Характеристики системы:

![functions2](images/functions2.png)

Из характеристик обоих систем, видим, что они практически совпадают,
значит преобразование блоков выполнено верно.

	Вывод:
Мы изучили основные операции используемые при исследовании моделей Simulink с помощью 
LTI-viewer (построение передаточных функции и другие);
построили модель и исследовали её с с помощью LTI-viewer, получив необходимые графики.
Сравнили полученный результат с исходной моделью и установили, что преобразования выполнены верно.
