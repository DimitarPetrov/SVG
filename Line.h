//
// Created by Dimitar on 6.5.2017 г..
//

#ifndef SVG_LINE_H
#define SVG_LINE_H

#include "Shape.h"
#include <fstream>

class Line:public Shape {
public:
    Line(double x1C = 0, double y1C = 0, double x2C = 0, double y2C = 0);
    //Гетъри и сетъри.
    double getX1() const;
    void setX1(double x1);

    double getY1() const;
    void setY1(double y1);

    double getX2() const;
    void setX2(double x2);

    double getY2() const;
    void setY2(double y2);
    //Функция която ни позволява да използваме оператора за изход на класа Shape.
    virtual std::ostream& Print(std::ostream& os)const override;

    virtual void WriteFile(std::ofstream& of)const override;

    virtual void Translate(int v, int h) override;

    virtual bool WithinCircle(double cx, double cy, double r)const override;

    virtual bool WithinRectangle(double x, double y, double width, double height)const override;

    virtual Shape* Clone() const override;



private:
    double x1;
    double y1;
    double x2;
    double y2;
};


#endif //SVG_LINE_H
