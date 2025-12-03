#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DatabaseManager.h"
#include "RecordsModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int userId, DatabaseManager *db, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_exportButton_clicked();

private:
    Ui::MainWindow *ui;
    int m_userId;
    DatabaseManager *m_db;
    RecordsModel *m_model;
};

#endif // MAINWINDOW_H
