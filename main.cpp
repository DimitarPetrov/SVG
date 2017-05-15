#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "FileCommands.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "ShapeArr.h"
using namespace std;
//Функция прочитаща всички поддържани елементи и сторираща ги в обек от класа ShapeArr
void ReadFile(ifstream& inf, ShapeArr& shapes){
    char fig[10];
    for(int i = 0; i < 4; ++i) {
        inf.ignore(10000, '\n');
    }
    while(inf){
        inf>>fig;
        if(!strcmp(fig, "<rect")){
            char x[32];
            char y[32];
            char width[32];
            char height[32];
            char fill[32];
            for(int i = 0; i<4; ++i){
                inf.get();
            }
            inf>>x;
            for(int i = 0; i<4; ++i){
                inf.get();
            }
            inf>>y;
            for(int i = 0; i<8; ++i){
                inf.get();
            }
            inf>>width;
            for(int i = 0; i<9; ++i){
                inf.get();
            }
            inf>>height;
            for(int i = 0; i<7; ++i){
                inf.get();
            }
            inf>>fill;
            fill[strlen(fill)-1] = 0;
            Rectangle* rect = new Rectangle(atof(x), atof(y), atof(width), atof(height), fill);
            shapes.add(rect);
        }
        if(!strcmp(fig, "<circle")){
            char x[32];
            char y[32];
            char r[32];
            char fill[32];
            for(int i = 0; i<5; ++i){
                inf.get();
            }
            inf>>x;
            for(int i = 0; i<5; ++i){
                inf.get();
            }
            inf>>y;
            for(int i = 0; i<4; ++i){
                inf.get();
            }
            inf>>r;
            for(int i = 0; i<7; ++i){
                inf.get();
            }
            inf>>fill;
            fill[strlen(fill)-1] = 0;
            Circle* circle = new Circle(atof(x), atof(y), atof(r), fill);
            shapes.add(circle);
        }
        if(!strcmp(fig, "<line")){
            char x1[32];
            char y1[32];
            char x2[32];
            char y2[32];
            for(int i = 0; i<5; ++i){
                inf.get();
            }
            inf>>x1;
            for(int i = 0; i<5; ++i){
                inf.get();
            }
            inf>>y1;
            for(int i = 0; i<5; ++i){
                inf.get();
            }
            inf>>x2;
            for(int i = 0; i<5; ++i){
                inf.get();
            }
            inf>>y2;
            Line* line = new Line(atof(x1), atof(y1), atof(x2), atof(y2));
            shapes.add(line);
        }

        inf.ignore(10000, '\n');
    }
}

void CreateRectangle(ShapeArr& shapes){
    double x,y,width,height;
    char fill[16];
    cin>>x>>y>>width>>height>>fill;
    Rectangle* rect = new Rectangle(x,y,width,height,fill);
    shapes.add(rect);
}

void CreateCircle(ShapeArr& shapes){
    double cx,cy,r;
    char fill[16];
    cin>>cx>>cy>>r>>fill;
    Circle* circle = new Circle(cx,cy,r,fill);
    shapes.add(circle);
}

void CreateLine(ShapeArr& shapes){
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Line* line = new Line(x1,y1,x2,y2);
    shapes.add(line);
}
//Функция занимаваща се с отварянето на файлове и организацията на командния лог.
void FileCommands(ShapeArr& shapes){
    bool ready = false;
    FileCommand a;
    char CurrentPath[256];
    while(!ready){
        cin>>a;
        if(a == FileCommand("exit")){
            cout<<"Exiting program..."<<endl;
            break;
        }
        if(a == FileCommand("open")){
            ifstream inf(a.getPath());
            if(!(inf.is_open())){
                ofstream tmp(a.getPath());
                tmp.close();
                ifstream inf(a.getPath());
                if(!inf.is_open()){
                    cerr<<"Can't open file for reading..."<<endl;
                    continue;
                }
                else{
                    cout << "File successfully opened." << endl;
                }
            }
            else{
                cout << "File successfully opened." << endl;
            }
            //Прехвърлям данните от файла в паметта
            ReadFile(inf, shapes);
            inf.close();
            //използваме флаг за да обозначим, че сме успели да прехвърлим данните от файла в паметта и можем да използваме
            //последващите команди.
            ready = true;
            strcpy(CurrentPath,a.getPath());
            while(ready){
                cin>>a;
                if(a == FileCommand("close")){
                    ready = false;
                    cout<<"File successfully closed."<<endl;
                    shapes.erase();
                    break;
                }
                if(a == FileCommand("save")){
                    ofstream of(CurrentPath);
                    of<<"<?xml version=\"1.0\" standalone=\"no\"?>" << "\n"
                      <<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" <<"\n"
                      << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" <<"\n"
                      << "<svg>" <<"\n";
                    //записваме данните обратно в същия файл.
                    shapes.WriteFile(of);
                    of<<"</svg>";
                    of.close();
                    cout<<"File successfully saved."<<endl;
                }
                if(a == FileCommand("saveas")){
                    ofstream of(a.getPath());
                    of<<"<?xml version=\"1.0\" standalone=\"no\"?>" << "\n"
                      <<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" <<"\n"
                      << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" <<"\n"
                      << "<svg>" <<"\n";
                    //записваме данните в нов .svg файл.
                    shapes.WriteFile(of);
                    of<<"</svg>";
                    of.close();
                    cout<<"File successfully saved as "<<a.getPath()<<endl;
                }
                if(a == FileCommand("exit")){
                    cout<<"Exiting program..."<<endl;
                    break;
                }
                if(a == FileCommand("print")){
                    cout<<shapes;
                }
                if(a == FileCommand("create")){
                    char shape[16];
                    cin>>shape;
                    if(!strcmp(shape, "rectangle")){
                        CreateRectangle(shapes);
                        cout<<"Rectangle successfully created."<<endl;
                    }
                    if(!strcmp(shape, "circle")){
                        CreateCircle(shapes);
                        cout<<"Cirlce successfully created."<<endl;
                    }
                    if(!strcmp(shape, "line")){
                        CreateLine(shapes);
                        cout<<"Line successfully created."<<endl;
                    }
                }
                if(a == FileCommand("erase")){
                    int id;
                    cin>>id;
                    if(shapes.remove(id-1)) {
                        cout << "Erased figure " << id << "." << endl;
                    }
                }
                if(a == FileCommand("translate")){
                    int h, v, id = 0;
                    cin>>v>>h>>id;
                    shapes.Translate(id-1,v,h);
                }
                if(a == FileCommand("within")){
                    char figure[10];
                    cin>>figure;
                    if(!strcmp(figure, "circle")){
                        double cx,cy,r;
                        cin>>cx>>cy>>r;
                        shapes.WithinCircle(cx,cy,r);
                    }
                    if(!strcmp(figure, "rectangle")){
                        double x,y,width,height;
                        cin>>x>>y>>width>>height;
                        shapes.WithinRectangle(x,y,width,height);
                    }
                }

            }
        }
    }
}

int main(){
    ShapeArr shapes;
    FileCommands(shapes);
    return 0;
}
