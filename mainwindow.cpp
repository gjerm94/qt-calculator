#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QString>
#include <string>
#include <exprtk.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->expressionGroup,SIGNAL(buttonClicked(QAbstractButton*)),
            this, SLOT(expressionGroup_clicked(QAbstractButton*)));

    connect(ui->m_buttonEquals, SIGNAL (clicked()),
            this, SLOT(calculateResult()));

    connect(ui->m_buttonC, SIGNAL (clicked()),
            ui->m_labelOutput, SLOT(clear()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Called when a number button (0-9), an operator button (+, -, *, /) or a decimal separator button (.) is clicked
// Appends the text of the clicked button to the output label
void MainWindow::expressionGroup_clicked(QAbstractButton* button)
{
      QString output = ui->m_labelOutput->text();

      ui->m_labelOutput->setText(output + button->text());
}

// Calculates and displays the answer in the output label
// Uses exprtk library to calculate the result based on the expression string from the output label
void MainWindow::calculateResult()
{
    std::string expression_string = ui->m_labelOutput->text().toStdString();
    exprtk::parser<double> parser;
    exprtk::expression<double> expression;
    parser.compile(expression_string, expression);

    ui->m_labelOutput->setText(QString::number(expression.value()));
}
