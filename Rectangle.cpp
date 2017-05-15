//
// Created by Dimitar on 6.5.2017 г..
//

#include "Rectangle.h"
#include <cstring>
#include <iostream>


Rectangle::Rectangle(double xC, double yC, double w, double h, const char* f):x(xC), y(yC), width(w), height(h) {
    fill = new char[strlen(f) + 1];
    strcpy(fill, f);
}

Rectangle::Rectangle(const Rectangle& rect): Shape(rect){
    Copy(rect);
}

Rectangle& Rectangle::operator= (const Rectangle& rect){
    if(this == &rect){
        return *this;
    }
    Shape::operator=(rect);
    delete[] fill;
    Copy(rect);
    return *this;
}

Rectangle::~Rectangle(){
    delete[] fill;
}

double Rectangle::getX() const {
    return x;
}

void Rectangle::setX(double x) {
    this->x = x;
}

double Rectangle::getY() const {
    return y;
}

void Rectangle::setY(double y) {
    this->y = y;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

const char* Rectangle::getFill() const {
    return fill;
}

void Rectangle::setFill(const char* f) {
    delete[] fill;
    fill = new char[strlen(f) + 1];
    strcpy(fill, f);
}

void Rectangle::setHeight(double height) {
    this->height = height;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

std::ostream& Rectangle::Print(std::ostream& os)const{
    Shape::Print(os);
    os<<"rectangle "<< x << " " << y << " " << width << " " << height << " " << fill;
    return os;
}


void Rectangle::Copy(const Rectangle &rect) {
    x = rect.x;
    y = rect.y;
    width = rect.width;
    height = rect.height;
    fill = new char[strlen(rect.fill) + 1];
    strcpy(fill, rect.fill);
}

void Rectangle::WriteFile(std::ofstream &of) const {
    of<< "  " << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << fill
      << "\" />" << std::endl;
}

void Rectangle::Translate(int v, int h) {
    x += h;
    y += v;
}

bool Rectangle::WithinCircle(double cx, double cy, double r) const {
    if(((x - cx)*(x - cx) + (y - cy)*(y - cy) < r*r) && (((x + width)  - cx)*((x + width)  - cx) + ((y + height) - cy)*((y + height) - cy) < r*r)){
        std::cout<<*this<< " is inside circle "<< cx << " " << cy << " " << r <<"." <<std::endl;
        return 1;
    }
    return 0;
}

bool Rectangle::WithinRectangle(double x, double y, double width, double height) const {
    if(((this->x + this->width) < (x + width)) && (this-> x > x) && (this-> y > y) && ((this-> y + this-> height) < (y + height))){
        std::cout<<*this<< " is inside rectangle "<< x << " " << y << " " << width << " " << height <<"." <<std::endl;
        return 1;
    }
    return 0;
}
