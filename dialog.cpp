#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    connect(ui->addHomeG, SIGNAL(clicked()), this, SLOT(addHome()));
    connect(ui->addHomew, SIGNAL(clicked()), this, SLOT(addHomework()));
    connect(ui->addPartG, SIGNAL(clicked()), this, SLOT(addPart()));
    connect(ui->addTestG, SIGNAL(clicked()), this, SLOT(addTest()));
    connect(ui->addProjG, SIGNAL(clicked()), this, SLOT(addProject()));
    connect(ui->addFinalG, SIGNAL(clicked()), this, SLOT(addFinal()));
    connect(ui->loadButt, SIGNAL(clicked()), this, SLOT(load()));
    connect(ui->saveButt, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->selectAll, SIGNAL(clicked()), this, SLOT(selectAll()));
    connect(ui->dSelect, SIGNAL(clicked()), this, SLOT(dSelectAll()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addHome()
{
    double sum = 0, tempNum, tempNumPer;
    QString temp, tempPer, letter;

    for (int i = 0; i < 5; i++)
    {
       if (i == 0)
       {
          temp = ui->lineEdit_54->text();
          tempPer = ui->doubleSpinBox->text();
       }
       else if (i == 1)
       {
          temp = ui->lineEdit_55->text();
          tempPer = ui->doubleSpinBox_2->text();
       }
       else if (i == 2)
       {
          temp = ui->lineEdit_56->text();
          tempPer = ui->doubleSpinBox_3->text();
       }
       else if (i == 3)
       {
          temp = ui->lineEdit_57->text();
          tempPer = ui->doubleSpinBox_4->text();
       }
       else
       {
          temp = ui->lineEdit_58->text();
          tempPer = ui->doubleSpinBox_5->text();
       }

       if (temp.isEmpty() || tempPer.isEmpty())
       {
          tempNum = 0;
          tempNumPer = 0;
       }
       else
       {
          tempNum = temp.split(" ")[0].toDouble();
          tempNumPer = tempPer.split(" ")[0].toDouble();
       }

       sum += tempNum * (tempNumPer / 100.0);
    }

    if (sum > 89.5)
       letter = "A";
    else if (sum < 90 && sum > 79.5)
       letter = "B";
    else if (sum < 80 && sum > 69.5)
       letter = "C";
    else if (sum < 70 && sum > 59.5)
       letter = "D";
    else
       letter = "F";

    if (sum >= 69.5)
    {
       ui->textEdit_12->setText(tr("You did good my son!"));
       ui->textEdit_12->append(tr("\nYou did it! You passed! I knew you had it in ya"));
       ui->textEdit_12->append(tr("\nGood luck next semester, or maybe you are done, who cares you passed!"));
    }
    else
    {
       ui->textEdit_12->setText(tr("You failed me boy..."));
       ui->textEdit_12->append(tr("\nI dont even know what to say, because I didnt think you would get here..."));
       ui->textEdit_12->append(tr("\nWell I guess you will see this class next year"));
    }


    QString charSum = QString::number(sum);
    ui->lineEdit_59->setText(tr("%1 %").arg(charSum));
    ui->lineEdit_60->setText(letter);
}

void Dialog::addHomework()
{
    double temp(calcGrade(1));
    (void)temp;
}

void Dialog::addPart()
{
    double temp(calcGrade(2)), temp1(ui->numAtten->text().split(" ")[0].toInt()), temp2(ui->inclassAvg->text().split(" ")[0].toDouble());
    if (temp >= 70)
       ui->textEdit_4->setText(tr("You did good my son on those quizzes!"));
    else
       ui->textEdit_4->setText(tr("Dang man you need to do better on those quizzes..."));

    if (temp1 >= 22)
       ui->textEdit_4->append(tr("Nice, there isn't a grade for attending cause I am sure they'll give you full credit!"));
    else
       ui->textEdit_4->append(tr("Get yo butt to class!"));

    if (temp2 >= 70)
       ui->textEdit_4->append(tr("Well it looks like you are not totally useless in class!"));
    else
       ui->textEdit_4->append(tr("You still done messed up in class A Aron!"));
}

void Dialog::addTest()
{
    double temp(calcGrade(3));
    if (temp >= 69.5)
    {
       ui->textEdit_6->setText(tr("You did good my son!"));
       ui->textEdit_6->append(tr("\nPhew! You made it, no more sleepless nights for now!"));
       ui->textEdit_6->append(tr("\nGood luck next semester, hahahahaha!"));
    }
    else if (temp < 69.5 && temp > 0)
    {
       ui->textEdit_6->setText(tr("You done messed up A Aron! Take yo a** down to OshackHennesy's office right now!"));
       ui->textEdit_6->append(tr("\nYOU SHALL NOT PASS!"));
       ui->textEdit_6->append(tr("\nYou are the weakest link, Goodbye!"));
    }
    else if (temp == 0)
        ui->textEdit_6->setText(tr("NA"));
}

void Dialog::addProject()
{
    double temp(calcGrade(4));
    (void)temp;
}

void Dialog::addFinal()
{
    double temp(calcGrade(5));
    if (temp >= 69.5)
    {
       ui->textEdit_11->setText(tr("You did good my son!"));
       ui->textEdit_11->append(tr("\nNow go check the home tab to see if you passed!"));
       ui->textEdit_11->append(tr("\nGood luck next semester, hahahahaha if you passed..."));
    }
    else if (temp < 69.5 && temp > 0)
    {
       ui->textEdit_11->setText(tr("You done messed up A Aron! Take yo a** down to the home tab right now!"));
       ui->textEdit_11->append(tr("\nThere is still a chance you might have passed!"));
       ui->textEdit_11->append(tr("\nBut you still failed that final tho, Goodbye..."));
    }
    else if (temp == 0)
        ui->textEdit_11->setText(tr("NA"));
}

void Dialog::selectAll()
{
    foreach(QCheckBox *checkIt, findChildren<QCheckBox *>())
        checkIt->setChecked(true);
}

void Dialog::dSelectAll()
{
    foreach(QCheckBox *checkIt, findChildren<QCheckBox *>())
        checkIt->setChecked(false);
}

void Dialog::load()
{

}

void Dialog::save()
{

}

double Dialog::calcGrade(int code)
{
    QList<QLineEdit*> label;
    foreach (QLineEdit *boom, findChildren<QLineEdit *>())
    {
        label.push_back(boom);
    }
    double sum = 0, count = 0, tempNum;
    QString temp, letter;

    if (code == 1)
    {
        for (int i = 57; i < 68; i++)
        {
            temp = label[i]->text();

            if (temp.isEmpty())
                sum += 0;
            else
            {
                tempNum = temp.split(" ")[0].toDouble();
                if (tempNum < 0)
                    sum += 0;
                else
                    sum += tempNum;
                count++;
            }
        }
        if (count == 0)
        {
           ui->homewAvg->setText(tr("NA"));
           ui->numHw->setText(tr("NA"));
           ui->letterGrade->setText(tr("NA"));
        }
        else
        {
           sum = sum / count;

           if (sum >= 89.5)
              letter = "A";
           else if (sum < 89.5 && sum >= 79.5)
              letter = "B";
           else if (sum < 79.5 && sum >= 69.5)
              letter = "C";
           else if (sum < 70.5 && sum >= 59.5)
              letter = "D";
           else
              letter = "F";

           QString charSum = QString::number(sum);
           QString charCount = QString::number(count);

           ui->homewAvg->setText(tr("%1 %").arg(charSum));
           ui->numHw->setText(charCount);
           ui->letterGrade->setText(letter);
        }
    }
    else if (code == 2)
    {
        int count1 = 0, count2 = 0;
        double tempNum2, sum2 = 0;
        QString temp2;
        foreach(QCheckBox *check, findChildren<QCheckBox *>())
            if (check->isChecked())
                count1++;
        QString charNum = QString::number(count1);
        ui->numAtten->setText(charNum);

        for (int i = 43; i < 58; i++)
        {
            temp = label[i]->text();

            if (temp.isEmpty())
                sum += 0;
            else
            {
                tempNum = temp.split(" ")[0].toDouble();
                if (tempNum < 0)
                    sum += 0;
                else
                    sum += tempNum;
                count++;
            }
        }

        for (int i = 58; i < 68; i++)
        {
            temp2 = label[i]->text();

            if (temp2.isEmpty())
                sum2 += 0;
            else
            {
                tempNum2 = temp2.split(" ")[0].toDouble();
                if (tempNum2 < 0)
                    sum2 += 0;
                else
                    sum2 += tempNum2;
                count2++;
            }
        }

        if (count != 0)
            sum = sum / count;
        if (count2 != 0)
            sum2 = sum2 / count2;

        QString charSum = QString::number(sum);
        QString charSum2 = QString::number(sum2);

        ui->quizAvg->setText(charSum);
        ui->inclassAvg->setText(charSum2);
    }
    else if (code == 3)
    {
        for (int i = 64; i < 68; i++)
        {
            temp = label[i]->text();

            if (temp.isEmpty())
                sum += 0;
            else
            {
                tempNum = temp.split(" ")[0].toDouble();
                if (tempNum < 0)
                    sum += 0;
                else
                    sum += tempNum;
                count++;
            }
        }
        if (count == 0)
        {
           ui->testAvg->setText(tr("NA"));
           ui->numTest->setText(tr("NA"));
           ui->letterGradeT->setText(tr("NA"));
        }
        else
        {
           sum = sum / count;

           if (sum >= 89.5)
              letter = "A";
           else if (sum < 89.5 && sum >= 79.5)
              letter = "B";
           else if (sum < 79.5 && sum >= 69.5)
              letter = "C";
           else if (sum < 70.5 && sum >= 59.5)
              letter = "D";
           else
              letter = "F";

           QString charSum = QString::number(sum);
           QString charCount = QString::number(count);

           ui->testAvg->setText(tr("%1 %").arg(charSum));
           ui->numTest->setText(charCount);
           ui->letterGradeT->setText(letter);
        }
    }
    else if (code == 4)
    {
            for (int i = 64; i < 66; i++)
            {
                temp = label[i]->text();

                if (temp.isEmpty())
                    sum += 0;
                else
                {
                    tempNum = temp.split(" ")[0].toInt();
                    if (tempNum < 0)
                        sum += 0;
                    else
                        sum += tempNum;
                    count++;
                }
            }
            if (count == 0)
            {
               ui->projAvg->setText(tr("NA"));
               ui->numProj->setText(tr("NA"));
               ui->letterGradePr->setText(tr("NA"));
            }
            else
            {
               sum = sum / count;

               if (sum >= 89.5)
                  letter = "A";
               else if (sum < 89.5 && sum >= 79.5)
                  letter = "B";
               else if (sum < 79.5 && sum >= 69.5)
                  letter = "C";
               else if (sum < 70.5 && sum >= 59.5)
                  letter = "D";
               else
                  letter = "F";

               QString charSum = QString::number(sum);
               QString charCount = QString::number(count);

               ui->projAvg->setText(tr("%1 %").arg(charSum));
               ui->numProj->setText(charCount);
               ui->letterGradePr->setText(letter);
            }
    }
    else
    {
        if (ui->lineEdit_51->text().isEmpty())
        {
            ui->finalAvg->setText(tr("NA"));
            ui->letterGradeF->setText(tr("NA"));
        }
        else
        {
            temp = ui->lineEdit_51->text();
            ui->finalAvg->setText(tr("%1 %").arg(temp));

            tempNum = temp.split(" ")[0].toInt();

            if (tempNum >= 89.5)
                letter = "A";
            else if (tempNum < 89.5 && tempNum >= 79.5)
                letter = "B";
            else if (tempNum < 79.5 && tempNum >= 69.5)
                letter = "C";
            else if (tempNum < 70.5 && tempNum >= 59.5)
                letter = "D";
            else
                letter = "F";

            ui->letterGradeF->setText(letter);
        }
    }
    return sum;
}
