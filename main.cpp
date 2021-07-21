#include "mainwindow.h"

#include <QApplication>
#include <config.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon(":/Images/Images/logo.png");
    w.setWindowIcon(icon);
    w.setStyleSheet(
                //正常状态样式
                "QPushButton{"
                "background-color:rgba(7,200,249,100);"//背景色（也可以设置图片）
                "border-style:outset;"                  //边框样式（inset/outset）
                "border-width:1px;"                     //边框宽度像素
                "border-radius:5px;"                   //边框圆角半径像素
                "border-color:rgba(255,255,255,30);"    //边框颜色
                "font:normal 10px;"                       //字体，字体大小
                "color:rgba(0,0,0,200);"                //字体颜色
                "padding:3px;"                          //填衬
                "}"
                //鼠标按下样式
                "QPushButton:pressed{"
                "background-color:rgba(10, 133, 237,200);"
                "border-color:rgba(255,255,255,30);"
                "border-style:inset;"
                "color:rgba(0,0,0,100);"
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:rgba(13, 65, 225,100);"
                "border-color:rgba(255,255,255,200);"
                "color:rgba(0,0,0,200);"
                "}");
    w.show();
    return a.exec();
}
