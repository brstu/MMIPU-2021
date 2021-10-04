                                         Министерство образования Республики Беларусь
                                                       Учреждение образования
                                           «Брестский государственный технический университет»
                                                         Кафедра ИИТ
                                                     Лабораторная работа № 1
                                                        По дисциплине «ММПиУ»
                                                 Моделирование объекта управления.



                                                                                                                 Выполнила:
                                                                                                                 Студенка. группы. 
                                                                                                                 АС-55
                                                                                                                 Зинькова Д.Г
                                                                                                                 Проверил:
                                                                                                                  Иванюк Д.C.
                                                                                                                                                            
                                                                                                                                                            
                                                                                                                                                            
                                                                                                                                                            
                                                                                                                                                            
                                                             Брест 2021
                                                           
    Цель работы:Написать программу,которая иметирует температуру дпнного объекта.
                                                              Ход работы
                                                          
                                                          

    Код программы:

    #include <iostream>
    using namespace std;
    void linearEquation(float a, float b, float u, float y, int n);
    void nonLinearEquation(float a, float b, float c, float d, float u, float y, int n);
    int main()
    {
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    float y = 0;
    float u = 0;
    int n = 0;
    
    cout << "Input value a:";
    cin >> a;
    cout << "Input value b:";
    cin >> b;
    cout << "Input value c:";
    cin >> c;
    cout << "Input value d:";
    cin >> d;
    cout << "Input value u:";
    cin >> u;
    cout << "Input number of iterations:";
    cin >> n;

    linearEquation(a, b, u, y, n);
    cout << endl;
    nonLinearEquation(a, b, c, d, u, y, n);
    return 0;
    }
    void linearEquation(float a, float b, float u, float y, int n)
    {
    cout << "Linear equation:" << endl;
    for (int i = 0; i <= n; i++)
    {
        y = a * y + b * u;
        cout << i << " - y(t)=" << y << endl;
    }
    }
    void nonLinearEquation(float a, float b, float c, float d, float u, float y, int n)
    {
    cout << "Nonlinear equation:" << endl;
    float y2 = y;
    float y3 = 0;
    for (int i = 0; i <= n; i++)
    {
     y3 = y;
     y = a * y - b * y2 * y2 + c * u + d * sin(u);
     y2 = y3;
     cout << i << " - y(t)=" << y << endl;
    }
    }
   
   
   
   
 
Вывод:Написали программу,которая иметирует температуру данного оъекта.
