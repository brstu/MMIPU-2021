## Общее задание ##

1. Написать отчет по выполненной лабораторной работе №1 в .md формате (readme.md) и с помощью **pull request** разместить его в следующем каталоге: **trunk\as000xxyy\task_01\doc**.
2. Исходный код написанной программы разместить в каталоге: **trunk\as000xxyy\task_01\src**.

## Task 1. Modeling controlled object

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

<p align="center">
<img src="images/main_eq.png">
</p>

where τ – time (discrete moments 1,2,3…n); y*τ – input temperature; f*τ – input warm; Y_0 – room temperature; C,RC – some constants.

After transformation we get these linear and nonlinear models:

<p align="center">
<img src="images/sub_eq.png">
</p>

Task is to write program (C++), which simulates this object temperature.
