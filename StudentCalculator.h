#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include <QtWidgets>
#include "Database.h"
#include "Student.h"

#include <string>
using std::string;

class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    StudentCalculator(QWidget* parent = nullptr);

private slots:
    void calculateButtonClicked();

    void ageEdited(const QString& age);
    void monthEdited(const QString& month);
    void cityEdited(const QString& city);
    void addressEdited(const QString& address);
    void instituteEdited(const QString& institute);
    void cinemaEdited(const QString& cinema);
    void caffeEdited(const QString& caffe);

    void costsFileEdited(const QString& costsFile);
    void instituteFileEdited(const QString& instituteFile);
    void transportFileEdited(const QString& transportFile);
    void caffeCinemaFileEdited(const QString& caffeCinemaFile);
    
private:
    QWidget* fileChoiceWidget();
    QWidget* studentInfoWidget();
    QWidget* tabWidget();
    QWidget* calculateButton();

    void errorAgeMonthShow();
    void errorFileShow();
    void errorInputShow();
    void studentMoneyShow(size_t count);

    void startCalculate();
    bool inputInspection();

    QWidget* _messagePosition;

    string _age;
    string _month;
    string _city;
    string _address;
    string _institute;
    string _cinema;
    string _caffe;

    size_t _ageI;
    size_t _monthI;

    string _costsFile;
    string _instituteFile;
    string _transportFile;
    string _caffeCinemaFile;
};


#endif //STUDENTCALCULATOR_H
