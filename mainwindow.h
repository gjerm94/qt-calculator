#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void expressionGroup_clicked(QAbstractButton*);

    void calculateResult();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
