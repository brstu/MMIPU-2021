# Laboratory work No.3              
              MINISTRY OF EDUCATION OF THE REPUBLIC OF BELARUS
                          EDUCATIONAL INSTITUTION 
                    «BREST STATE TECHNICAL UNIVERSITY»        
                            Department of IIT


                           Laboratory work No.3 


	                                	Completed by the 3rd year student of 
                                            Faculty of Electronic Information Systems
	                                	the group AC-55 Chernetsky N.A.
                                 		Checked by Ivanuk D.S.


                                 Brest 2021

## Задание 
## Работа с контроллером **AXC F 2152** ##

1. Изучить [руководство](https://github.com/savushkin-r-d/PLCnext_howto/tree/master/HowTo%20install%20Linux%20(Ubuntu)%20tools%20for%20C%2B%2B%20programming%20with%20Eclipse%20IDE) и согласно ему подготовить образ Ubuntu 18.04 LTS. Общая информация о контроллере **AXC F 2152** находится [здесь](https://www.plcnext-community.net/index.php?option=com_wrapper&view=wrapper&Itemid=374&lang=en).

2. В среде **Eclipse** создать тестовый проект *"Hello world!"*, собрать его и продемонстрировать работоспособность на тестовом контроллере.

### Ход работы:
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/1.png">
</p>
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/2.png">
</p>
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/3.png">
</p>
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/4.png">
</p>
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/5.png">
</p>

### Исходный код:
```C++
//============================================================================
// Name        : plcnext_lab3.cpp
// Author      : Nikita Chernetsky
// Version     :
// Copyright   : Completed by Nikita Chernetsky, the group AS-55, FEIS 2021.
// Description : 
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Performed by Nikita Chernetsky AS-55" << endl;
	return 0;
}
```

### Результат:
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/6.png">
</p>
<p align="center">
  <img src ="https://github.com/pumpezny/plcnext_screenshots/blob/main/7.png">
</p>
