//
// Created by Dimitar on 6.5.2017 г..
//

#ifndef SVG_SHAPE_H
#define SVG_SHAPE_H


#include <ostream>
#include <fstream>

class Shape {
public:
    //оператор за изход.
    friend std::ostream& operator<<(std::ostream &os, const Shape &shape);
    //виртуална функция, която ни помага да използваме оператора за изход и в наследените класове.
    virtual std::ostream&  Print(std::ostream& os) const;
    //виртуална функция, която ни помага да записваме във файл обекти и от наследените класове.
    virtual void WriteFile(std::ofstream& of) const = 0;
    //виртуална функция, която ни помага да транслираме обекти от какъвто и да е онаследен клас.
    virtual void Translate(int v, int h) = 0;
    //виртуална функция, която ни помага да търсим обект от какъвто и да е онаследен клас в зададен кръг.
    virtual bool WithinCircle(double cx, double cy, double r) const = 0;
    //виртуална функция, която ни помага да търсим обект от какъвто и да е онаследен клас в зададен правоъгълник.
    virtual bool WithinRectangle(double x, double y, double width, double height) const = 0;

    virtual Shape* Clone() const = 0;

    virtual ~Shape();

};


#endif //SVG_SHAPE_H
