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
    explicit MainWindow(int userId, DatabaseManager* db, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_exportButton_clicked();

private:
    Ui::MainWindow *ui;
    RecordsModel* m_model;
    DatabaseManager* m_db;
    int m_userId;
};

#endif // MAINWINDOW_H
