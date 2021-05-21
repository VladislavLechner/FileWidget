#include "inputwidget.h"

static Widget* m_instance = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    memoryAllocation();
    setUpWidgets();
    setMinimumSize(400,120);
    setMaximumSize(600,120);
    connect(m_startScaning, &QPushButton::clicked,
                this    ,&Widget::startScaningPressed);
}

Widget::~Widget()
{
}

void Widget::startScaningPressed()
{
    try {
        ReadFile readFile;
//        std::thread th(&ReadFile::checkPath, &readFile, m_inputPath->text().toStdString(), m_inputFilter->text().toStdString());
        readFile.checkPath(m_inputPath->text().toStdString(), m_inputFilter->text().toStdString());
        m_outputWidget.show();
        m_outputWidget.outputTheResults(readFile.resultOfWork(), m_inputFilter->text());
//        th.join();
    }  catch (...) {
        std::exception_ptr ex;
        ex = std::current_exception();
        handle_eptr(ex);
        std::cout << "EXCEPTION!!!" << std::endl;
    }
}

void Widget::memoryAllocation()
{
    m_path = new QLabel("Input the path", this);
    m_filter = new QLabel ("Input filter", this);
    m_inputPath = new QLineEdit("/home/maxim/Documents/test", this);
    m_inputFilter = new QLineEdit(this);
    m_startScaning = new QPushButton("Start scaning",this);
    m_gridLayout = new QGridLayout(this);
}

void Widget::setUpWidgets()
{
    m_gridLayout->addWidget(m_path,0,0);
    m_gridLayout->addWidget(m_inputPath, 0,1);
    m_gridLayout->addWidget(m_filter,1,0);
    m_gridLayout->addWidget(m_inputFilter,1,1);
    m_gridLayout->addWidget(m_startScaning, 2,0,1,2);
    setLayout(m_gridLayout);
}

void Widget::handle_eptr(std::exception_ptr eptr)
{
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        QMessageBox::warning(this, "Error", QString::fromStdString(e.what()));
    }
}

void *getInstance()
{
    if(!m_instance)
        m_instance = new (std::nothrow) Widget();
    return m_instance;
}



void releaseInstance(Widget *)
{
    if(m_instance != nullptr)
        {
            delete m_instance;
            m_instance = nullptr;
        }
}

