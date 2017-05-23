//
// Created by Dimitar on 6.5.2017 г..
//

#include "ShapeArr.h"
#include <iostream>

ShapeArr::ShapeArr() {
    arr = new Shape* [10];
    capacity = 10;
    current = 0;
}

ShapeArr::ShapeArr(const ShapeArr &a) {
    Copy(a);
}

void ShapeArr::Copy(const ShapeArr &a) {
    capacity = a.capacity;
    current = a.current;
    arr = new Shape* [a.capacity];
    for(int i = 0; i<current; ++i){
        arr[i] = a.arr[i]->Clone();
    }
}

ShapeArr &ShapeArr::operator=(const ShapeArr &a) {
    if(this == &a){
        return *this;
    }
    Erase();
    Copy(a);
    return *this;
}

ShapeArr::~ShapeArr() {
    Erase();
}

void ShapeArr::add(Shape *a) {
    if(capacity == current){
        resize();
    }
    arr[current] = a->Clone();
    ++current;
}

void ShapeArr::resize() {
    Shape** tmp = arr;
    arr = new Shape* [capacity*2];
    capacity *= 2;
    for(int i = 0; i< capacity/2; ++i){
        arr[i] = tmp[i];
    }
}

bool ShapeArr::remove(int indx) {
    if(indx < 0 || indx >= current){
        std::cout<<"There is no figure number "<< indx+1 << "." <<std::endl;
        return 0;
    }
    --current;
    for(int i = indx; i<current; ++i){
        Shape* tmp;
        tmp = arr[i];
        arr[i] = arr[i+1]->Clone();
        delete tmp;
    }
    return 1;
}

std::ostream& operator<<(std::ostream& out, const ShapeArr& a){
    for(int i = 0; i<a.current; ++i){
        out<<(i+1)<<". "<<*a.arr[i]<<"\n";
    }
    return out;
}

void ShapeArr::WriteFile(std::ofstream& of)const {
    for(int i = 0; i < current; ++i){
        arr[i]->WriteFile(of);
    }
}

void ShapeArr::Translate(int indx, int v, int h) {
    if(indx < 0 || indx >= current){
        for(int i = 0; i<current; ++i){
            arr[i]->Translate(v,h);
        }
        std::cout<<"Translated all figures."<<std::endl;
    }
    else{
        arr[indx]->Translate(v,h);
        std::cout<< "Translated figure " << indx+1 << "." <<std::endl;
    }
}

void ShapeArr::erase() {
    for(int i = current-1; i>=0; --i){
        remove(i);
    }
}

void ShapeArr::WithinCircle(double cx, double cy, double r) const {
    bool flag = false;
    for(int i = 0; i<current; ++i){
        if(arr[i]->WithinCircle(cx,cy,r)){
            flag = true;
        }
    }
    if(flag == false){
        std::cout<<"No figures are located within circle "<< cx << " " << cy << " " << r << "." <<std::endl;
    }
}

void ShapeArr::WithinRectangle(double x, double y, double width, double height) const {
    bool flag = false;
    for(int i = 0; i<current; ++i){
        if(arr[i]->WithinRectangle(x,y,width,height)){
            flag = true;
        }
    }
    if(flag == false){
        std::cout<<"No figures are located within rectangle "<< x << " " << y << " " << width << " " << height << "." <<std::endl;
    }
}

void ShapeArr::Erase() {
    for(int i = 0; i<current; ++i){
        delete arr[i];
    }
    delete[]arr;
}

