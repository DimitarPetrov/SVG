//
// Created by Dimitar on 6.5.2017 г..
//

#ifndef SVG_SHAPEARR_H
#define SVG_SHAPEARR_H

#include "Shape.h"
#include <fstream>
//Клас който представлява масив от указатели към обекти от класове наследили Shape.
class ShapeArr{
public:
    //Голяма 4-ка.
    ShapeArr();
    ShapeArr(const ShapeArr& a);
    ShapeArr& operator=(const ShapeArr& a);
    ~ShapeArr();
    //Функция добавяща елемнт в масива.
    void add(Shape* a);
    //Функция премахваща елемнт от масива по зададен индекс.
    bool remove(int indx);
    //Функция изчистваща масива;
    void erase();
    //Записва елементите на масвиа във файл.
    void WriteFile(std::ofstream& of) const;
    //Транслира елементите на масива.
    void Translate(int indx, int v, int h);
    //Търси кои елемнти на масива се съдържат изцяло в зададен кръг.
    void WithinCircle(double cx, double cy, double r) const;
    //Търси кои елементи на масива се съдържат изцяло в зададен правоъгълник.
    void WithinRectangle(double x, double y, double width, double height) const;
    //Извежда масива на екрана.
    friend std::ostream& operator<<(std::ostream& out, const ShapeArr& a);

private:
    Shape** arr;
    int capacity;
    int current;

    void Copy(const ShapeArr& a);
    void Erase();
    void resize();
};


#endif //SVG_SHAPEARR_H
