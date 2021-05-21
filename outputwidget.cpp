#include "outputwidget.h"

OutputWidget::OutputWidget(QWidget *parent)
    : QWidget(parent)
{
    setUpLayout();
}

void OutputWidget::setUpLayout()
{
     m_automaticCollection = new QLabel("Автоматически собранная информация\n",this);
     m_filterCollectrion = new QLabel("Информация, полученная от пользователя\n",this);
     m_gridLayout = new QGridLayout(this);

     m_gridLayout->addWidget(m_automaticCollection,0,0);
     m_gridLayout->addWidget( m_filterCollectrion,0,1);
}

void OutputWidget::outputTheResults(std::pair<std::map<char, std::size_t>, int> result, QString filter)
{
    for (auto& x:result.first)
    {
         m_automaticCollection->setText(m_automaticCollection->text() + "Символ '" + x.first + "' встречается ровно " + QString::number(x.second) + " раз\n");
    }

    m_filterCollectrion->setText(m_filterCollectrion->text() + "Введенный пользователем фильтр '" + filter + "' повторяется ровно " + QString::number(result.second) + " раз\n");
}
