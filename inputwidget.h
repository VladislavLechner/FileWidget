#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <boost/filesystem.hpp>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QMessageBox>

#include <iostream>
#include <exception>
#include <thread>

#include "readfile.h"
#include "outputwidget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void startScaningPressed();

private:
    QLineEdit   * m_inputPath;
    QLineEdit   * m_inputFilter;
    QLabel      * m_path;
    QLabel      * m_filter;
    QPushButton * m_startScaning;
    QGridLayout * m_gridLayout;
    OutputWidget  m_outputWidget;

private:
    void memoryAllocation();
    void setUpWidgets();
    void handle_eptr(std::exception_ptr eptr);

};

extern "C" void *getInstance();
extern "C" void  releaseInstance(Widget*);

#endif // INPUTWIDGET_H
