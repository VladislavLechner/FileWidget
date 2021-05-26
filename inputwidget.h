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

class InputFileWidget : public QWidget
{
    Q_OBJECT

public:
    InputFileWidget(QWidget *parent = nullptr);
    ~InputFileWidget();

public slots:
    void startScaningPressed();

private:
    QLineEdit   * m_inputPath;
    QLineEdit   * m_inputFilter;
    QLabel      * m_path;
    QLabel      * m_filter;
    QPushButton * m_startScaning;
    QGridLayout * m_gridLayout;
    OutputFileWidget  m_outputWidget;

private:
    void memoryAllocation();
    void setUpWidgets();
    void handle_eptr(std::exception_ptr eptr);

};

extern "C" void *getWidgetInstance();
extern "C" void  releaseWidgetInstance(InputFileWidget*);
extern "C" std::string *getInfo();

#endif // INPUTWIDGET_H
