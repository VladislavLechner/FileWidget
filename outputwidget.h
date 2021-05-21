#ifndef OUTPUTWIDGET_H
#define OUTPUTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>

class OutputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OutputWidget(QWidget *parent = nullptr);
    void outputTheResults(std::pair <std::map <char,std::size_t>, int> result, QString filter);

private:
    QLabel      * m_automaticCollection;
    QLabel      * m_filterCollectrion;
    QGridLayout * m_gridLayout;

private:
    void setUpLayout();

};

#endif // OUTPUTWIDGET_H
