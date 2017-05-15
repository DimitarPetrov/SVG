//
// Created by Dimitar on 6.5.2017 г..
//

#include "Circle.h"
#include <cstring>
#include <cmath>
#include <iostream>

Circle::Circle(double cxC, double cyC, double radius, const char* f):cx(cxC), cy(cyC), r(radius){
    fill = new char[strlen(f) + 1];
    strcpy(fill, f);
}

Circle::Circle(const Circle& circle):Shape(circle){
    Copy(circle);
}

Circle& Circle::operator=(const Circle& circle){
    if(this == &circle){
        return *this;
    }
    Shape::operator=(circle);
    delete[] fill;
    Copy(circle);
    return *this;
}
Circle::~Circle(){
    delete[] fill;
}

double Circle::getCx() const {
    return cx;
}

double Circle::getCy() const {
    return cy;
}

double Circle::getR() const {
    return r;
}

const char* Circle::getFill() const {
    return fill;
}

void Circle::setFill(const char *f) {
    delete[] fill;
    fill = new char[strlen(f) + 1];
    strcpy(fill, f);
}

void Circle::setR(double r) {
    this->r = r;
}

void Circle::setCy(double cy) {
    this->cy = cy;
}

void Circle::setCx(double cx) {
    this->cx = cx;
}

std::ostream& Circle::Print(std::ostream& os)const{
    Shape::Print(os);
    os<<"circle "<< cx << " " << cy << " " << r << " " << fill;
    return os;
}

void Circle::Copy(const Circle &circle) {
    cx = circle.cx;
    cy = circle.cy;
    r = circle.r;
    fill = new char[strlen(circle.fill) + 1];
    strcpy(fill, circle.fill);
}

void Circle::WriteFile(std::ofstream &of) const {
    of<< "  " << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r <<"\" fill=\"" << fill
      << "\" />" << std::endl;
}

void Circle::Translate(int v, int h) {
    cx += h;
    cy += v;
}

bool Circle::WithinCircle(double cx, double cy, double r) const {
    double d = sqrt((this->cx - cx)*(this->cx - cx) + (this->cy - cy)*(this->cy - cy));
    if(r > (d + this->r)){
        std::cout<<*this<< " is inside circle "<< cx << " " << cy << " " << r <<"." <<std::endl;
        return 1;
    }
    return 0;
}

bool Circle::WithinRectangle(double x, double y, double width, double height) const {
    if(((cx > x && cx < x + width) && (cy > y && cy < y + height)) && ((cx +r > x && cx + r < x + width) && (cy > y && cy < y + height))
    && ((cx - r > x && cx - r < x + width) && (cy > y && cy < y + height))
    && ((cx > x && cx < x + width) && (cy + r > y && cy + r < y + height))
    && ((cx > x && cx < x + width) && (cy - r > y && cy - r < y + height))){
        std::cout<<*this<< " is inside rectangle "<< x << " " << y << " " << width << " " << height <<"." <<std::endl;
        return 1;
    }
    return 0;
}
