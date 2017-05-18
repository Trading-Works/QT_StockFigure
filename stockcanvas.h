#ifndef STOCKCANVAS_H
#define STOCKCANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <qmydata.h>





#define BORDER_SIZE         10              //边框
#define COORDINATE_X1       80              //网格距左边距离
#define COORDINATE_Y1       20              //网格距上边距离
#define COORDINATE_X2       80              //网格距右边距离
#define COORDINATE_Y2       20              //网格距下边距离
#define TEXT_LENGTH         50              //股票价格字符长度



//const int iBorder = 10;                 //边框
//const int igridInterval = 20;           //网格每一个高度
//const int iCoordinate_left_x   = 80;    //网格距左边距离
//const int iCoordinate_right_x  = 80;    //网格距右边距离
//const int iCoordinate_top_y    = 40;    //网格距上边距离
//const int iCoordinate_bottom_y = 20;    //网格距下边距离


class StockCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit StockCanvas(QWidget *parent = 0);


private:
    void virtual paintEvent(QPaintEvent* event);
    void virtual resizeEvent(QResizeEvent * event);
    void virtual mouseMoveEvent(QMouseEvent* event);
    void DrawBK();
    void DrawMouseLine();
    void DrawFSJL(char* SecID,char* szDate);
    void setLSpace( QString& str, int n );
    void DrawTips();
    void DrawBorder();

private:
    int m_windowWidth;
    int m_windowHeight;


    //fen shi line area
    float m_xGridMin;
    float m_xGridMax;
    float m_yGridMin;
    float m_yGridMax;

    float m_MaxPrice;
    float m_minPrice;

    float xInterval;    //x方向每一个大格间隔
    float yInterval;    //y方向每一个大格间隔


    //int iTipsLength;


    QPoint mousePoint;
    float pervalue;
    float price_start;
    QMyData m_fsjl;
signals:

public slots:
};

#endif // STOCKCANVAS_H
