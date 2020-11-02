// TestRPGConsoleGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include "Description.h" // пользовательский класс общей описательной начинки
#include "GameField.h"
#include "Point.h"

//общая свободная функция для объединения интро
void introDesc(const Description& desc)
{
    desc.outputGreeting();
    desc.outputBuffer();
    desc.outputHeadDescription();
    desc.outputBuffer();
    desc.outputGeneralHint();
   // desc.outputBuffer();
   // desc.outputValediction();
}

/*::ostream& operator<< (std::ostream& out, const Point& point)
{
    out << "\nТочка " << point.getPointRow() << ',' << point.getPointColumn() << " имеет статус " << point.getPointStatus() << " для поля с размером стороны " << \
        point.getFieldSize();
    return out;
}*/



int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0)));
    rand();
    Description desc;
   // introDesc(desc);

    GameField field(20);
    StatusVector pointStatusVec(0);         // статус точки относительно поля (угол, на границе, или внутри поля)
    StatusVector cellStatusVec(1);          // статус клетки (проходимая или стена, для отрисовки поля)

    //field.printGameField();

    unsigned fieldSize = field.getSize();

   /* for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            Point pnt(i, j, fieldSize, pointStatusVec);
            if (field.currentFieldCell(pnt))
            {
                std::cout << "\nТочка (" << pnt.getPointRow() << " , " << pnt.getPointColumn() << ") находится в " << pnt.getPointStatus() << " связанного поля";
            }
            else
            {
                std::cout << "\nТочка (" << pnt.getPointRow() << " , " << pnt.getPointColumn() << ") находится вне поля";
            }
        }
    }*/
    
   /* for (unsigned short i = 0; i < fieldSize; i++)
    {
        for (unsigned short j = 0; j < fieldSize; j++)
        {
            std::cout << "\n Дистанция от нулевой до текущей точки: "<< Point(i, j, fieldSize, pointStatusVec).distanceTo(Point(fieldSize, pointStatusVec));
        }
    }*/
    //field.printKeyPoints();
    std::string answer("");
    do
    {
        std::cout << "\nПожалуйста, подождите, идет генерация поля...";
        field.redrawFieldWithDE(pointStatusVec);
        field.printGameField();
        field.printKeyPoints();
        do
        {
            std::cout << "\nПовторить генерацию?(да/нет):";
            std::cin >> answer;
        } while (answer != "да" && answer != "нет");
    } while (answer != "нет");

    std::cout << "\nСпасибо за уделенное время!";
    
/*    std::list<Point> pList;
    auto countTypes = field.getPointSomeCells(pList, 5);
    std::cout << countTypes;
    for (auto element : pList)
    {
        std::cout << element;
    }

    field.removeDeadEnds(0);
    field.printGameField();

    countTypes = field.getPointSomeCells(pList, 5);
    std::cout << countTypes;
    for (auto element : pList)
    {
        std::cout << element;
    }*/

   // std::cout << field.getFreePointNum(); 
   /* Point p1(0, 0, field.getSize(), pointStatusVec);
    std::cout << p1 << p1.upperToPoint() << p1.rightToPoint() << p1.downToPoint() << p1.leftToPoint();*/

   /* std::vector<Point> adjacentAccessiblePoint;
    for (unsigned short i = 0; i < fieldSize; i++)
    {
        for (unsigned short j = 0; j < fieldSize; j++)
        {
            Point pnt(i, j, field.getSize());
            std::cout << pnt << " имеет " << field.CanToPoint(pnt, adjacentAccessiblePoint) << " точек, доступнух для перехода: ";
            for (auto element : adjacentAccessiblePoint)
                std::cout << element;
        }
    }*/
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
