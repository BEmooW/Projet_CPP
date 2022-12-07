#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <espace.h>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Espace E;
    QByteArray data;
};

#endif // MAINWINDOW_H
