#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void addHome();
    void addHomework();
    void addPart();
    void addTest();
    void addProject();
    void addFinal();
    void selectAll();
    void dSelectAll();
    void load();
    void save();
    double calcGrade(int code);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
