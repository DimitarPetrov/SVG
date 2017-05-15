//
// Created by Dimitar on 6.5.2017 г..
//

#include "Line.h"
#include <iostream>

Line::Line(double x1C, double y1C, double x2C, double y2C):x1(x1C), y1(y1C), x2(x2C), y2(y2C){
}

double Line::getX1() const {
    return x1;
}

double Line::getY1() const {
    return y1;
}

double Line::getX2() const {
    return x2;
}

double Line::getY2() const {
    return y2;
}

void Line::setY2(double y2) {
    this->y2 = y2;
}

void Line::setX2(double x2) {
    this->x2 = x2;
}

void Line::setY1(double y1) {
    this->y1 = y1;
}

void Line::setX1(double x1) {
    this->x1 = x1;
}

std::ostream& Line::Print(std::ostream& os)const{
    Shape::Print(os);
    os<< "line " << x1 << " " << y1 << " " << x2 << " " << y2;
    return os;
}

void Line::WriteFile(std::ofstream &of) const {
    of<< "  " << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" />" <<std::endl;
}

void Line::Translate(int v, int h) {
    x1 += h;
    x2 += h;
    y1 += v;
    y2 += v;
}

bool Line::WithinCircle(double cx, double cy, double r) const {
    if(((x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) < r*r) && ((x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy) < r*r)){
        std::cout<<*this<< " is inside circle "<< cx << " " << cy << " " << r <<"." <<std::endl;
        return 1;
    }
    return 0;
}

bool Line::WithinRectangle(double x, double y, double width, double height) const {
    if(((x1 > x && x1 < x + width) && (y1 > y && y1 < y + height)) && ((x2 > x && x2 < x + width) && (y2 > y && y2 < y + height))){
        std::cout<<*this<< " is inside rectangle "<< x << " " << y << " " << width << " " << height <<"." <<std::endl;
        return 1;
    }
    return 0;
}
