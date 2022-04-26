#include "StudentCalculator.h"

void StudentCalculator::startCalculate() {
    Student student(_student._age, _student._city, _student._address, _student._institute, _student._cafe, _student._cinema);
    // TODO make Student a field of StudentCalculator.h

    _expenses = StudentExpenses(student, _database[0], _database[1], _database[2], _database[3]);
    StudentExpenses& exp = _expenses;

    if ( !exp.errors.empty() ) {
        errorDataLoadShow(exp.errors);
    }

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int workdays[] = {16, 19, 22, 21, 18, 21, 21, 23, 22, 21, 21, 22};

    int workdaysCost = workdays[_month] * (exp._instituteFoodCost + 2 * exp._transportCost);
    int weekdaysCost = (daysInMonth[_month] - workdays[_month]) * (exp._cinemaCost + exp._cafeCost);

    if ( !exp.errors.empty() ) {
        return;
    }

    if (_calculateAgeFlag) {
        studentMoneyShow(weekdaysCost + workdaysCost + exp._avgFoodCost + exp._otherCost);
    }
    else {
        studentMoneyShow(weekdaysCost + workdaysCost + 15000 + exp._otherCost);
    }

    exp.errors.clear();
}

void StudentCalculator::regulateAgeSpinBox(int mode) {
    _ageSpinBox->setEnabled(mode);
    _calculateAgeFlag = (mode) != 0;
}

void StudentCalculator::ageEdited(int age) {
    _student._age = age;
}

void StudentCalculator::monthEdited(int month) {
    _month = month;
}

void StudentCalculator::nameEdited(const QString& name) {
    _student._name = name.toStdString();
    _completeFieldsArr[0] = !(_student._name.empty());
    updateCalculateButton();
}

void StudentCalculator::cityEdited(const QString& city) {
    _student._city = city.toStdString();
    _completeFieldsArr[1] = !(_student._city.empty());
    updateCalculateButton();
}

void StudentCalculator::addressEdited(const QString& address) {
    _student._address = address.toStdString();
    _completeFieldsArr[2] = !(_student._address.empty());
    updateCalculateButton();
}

void StudentCalculator::instituteEdited(const QString& institute) {
    _student._institute = institute.toStdString();
    _completeFieldsArr[3] = !(_student._institute.empty());
    updateCalculateButton();
}

void StudentCalculator::cinemaEdited(const QString& cinema) {
    _student._cinema = cinema.toStdString();
    _completeFieldsArr[4] = !(_student._cinema.empty());
    updateCalculateButton();
}

void StudentCalculator::caffeEdited(const QString& caffe) {
    _student._cafe = caffe.toStdString();
    _completeFieldsArr[5] = !(_student._cafe.empty());
    updateCalculateButton();
}

void StudentCalculator::costsFileDialog() {
    string costsFilePath = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = costsFilePath.empty() ) {
        return;
    }

    _database.storeFile(costsFilePath, costsFile);

    if (_expenses.costsFileCheck(_database[costsFile])) {
        _buttonEditCostsFile->setEnabled(!flag);
        _completeFieldsArr[6] = true;
        updateCalculateButton();
    }
    else {
        // TODO show error file format
    }
}

void StudentCalculator::instituteFileDialog() {
    string instituteFilePath = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = instituteFilePath.empty() ) {
        return;
    }

    _database.storeFile(instituteFilePath, instituteFile);

    if (_expenses.costsFileCheck(_database[instituteFile])) {
        _buttonEditInstituteFile->setEnabled(!flag);
        _completeFieldsArr[7] = true;
        updateCalculateButton();
    }
    else {
        // TODO show error file format
    }
}

void StudentCalculator::transportFileDialog() {
    string transportFilePath = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = transportFilePath.empty() ) {
        return;
    }

    _database.storeFile(transportFilePath, transportFile);

    if (_expenses.costsFileCheck(_database[transportFile])) {
        _buttonEditTransportFile->setEnabled(!flag);
        _completeFieldsArr[8] = true;
        updateCalculateButton();
    }
    else {
        // TODO show error file format
    }
}

void StudentCalculator::otherCostsFileDialog() {
    string otherCostsFilePath = QFileDialog::getOpenFileName(this, "Weekends File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = otherCostsFilePath.empty() ) {
        return;
    }

    _database.storeFile(otherCostsFilePath, otherCostsFile);

    if (_expenses.costsFileCheck(_database[otherCostsFile])) {
        _buttonEditOtherCostsFile->setEnabled(!flag);
        _completeFieldsArr[9] = true;
        updateCalculateButton();
    }
    else {
        // TODO show error file format
    }
}

void StudentCalculator::editCostsFile() {
    if ( !fileEditWidgetShow(_database[costsFile]) ) {
        return;
    }

    _database.restoreFile(costsFile);
}

void StudentCalculator::editInstituteFile() {
    if ( !fileEditWidgetShow(_database[instituteFile]) ) {
        return;
    }

    _database.restoreFile(instituteFile);
}

void StudentCalculator::editTransportFile() {
    if ( !fileEditWidgetShow(_database[transportFile]) ) {
        return;
    }

    _database.restoreFile(transportFile);
}

void StudentCalculator::editCaffeCinemaFile() {
    if ( !fileEditWidgetShow(_database[otherCostsFile]) ) {
        return;
    }

    _database.restoreFile(otherCostsFile);
}