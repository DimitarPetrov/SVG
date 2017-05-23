//
// Created by Dimitar on 6.5.2017 г..
//

#ifndef SVG_CIRCLE_H
#define SVG_CIRCLE_H

#include "Shape.h"
#include <fstream>

class Circle: public Shape {
public:
    //Голяма 4-ка.
    Circle(double cxC = 0, double cyC = 0, double radius = 0, const char* f = "none" );
    Circle(const Circle& circle);
    Circle& operator=(const Circle& circle);
    virtual ~Circle();
    //Гетъра и сетъри.
    double getCx() const;
    void setCx(double cx);

    double getCy() const;
    void setCy(double cy);

    double getR() const;
    void setR(double r);

    const char* getFill() const;
    void setFill(const char* f);
    //Функция която ни позволява да използваме оператора за изход на класа Shape.
    virtual std::ostream& Print(std::ostream& os)const override;

    virtual  void WriteFile(std::ofstream& of)const override;

    virtual void Translate(int v, int h) override;

    virtual bool WithinCircle(double cx, double cy, double r)const override;

    virtual bool WithinRectangle(double x, double y, double width, double height) const override;

    virtual Shape* Clone() const override;



private:
    double cx;
    double cy;
    double r;
    char* fill;

    void Copy(const Circle& circle);
};


#endif //SVG_CIRCLE_H
