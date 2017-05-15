//
// Created by Dimitar on 6.5.2017 г..
//

#ifndef SVG_RECTANGLE_H
#define SVG_RECTANGLE_H

#include "Shape.h"
#include <fstream>


class Rectangle: public Shape {
public:
    //Голяма 4-ка.
    Rectangle(double xC = 0, double yC = 0, double w = 0, double h = 0, const char* f = "none");
    Rectangle(const Rectangle& rect);
    Rectangle& operator= (const Rectangle& rect);
    virtual ~Rectangle();
    //Гетъри и сетъри.
    double getX() const;
    void setX(double x);

    double getY() const;
    void setY(double y);

    double getWidth() const;
    void setWidth(double width);

    double getHeight() const;
    void setHeight(double height);

    const char* getFill() const;
    void setFill(const char* f);
    //функция която ни позволява да използваме оператора за изход на класа Shape.
    virtual std::ostream& Print(std::ostream& os)const override;

    virtual void WriteFile(std::ofstream& of)const override;

    virtual void Translate(int v, int h) override;

    virtual bool WithinCircle(double cx, double cy, double r) const override;

    virtual bool WithinRectangle(double x, double y, double width, double height) const override;


private:
    double x;
    double y;
    double width;
    double height;
    char* fill;

    void Copy(const Rectangle& rect);
};


#endif //SVG_RECTANGLE_H
