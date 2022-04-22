#include "StudentCalculator.h"

StudentCalculator::~StudentCalculator() {
    delete _ageSpinBox;
    delete _calculateButton;

    delete _buttonEditCostsFile;
    delete _buttonEditInstituteFile;
    delete _buttonEditTransportFile;
    delete _buttonEditOtherCostsFile;
}

void StudentCalculator::updateCalculateButton() {
    int count = 0;

    for (int i = 0; i < countCheckedFields; ++i) {
        count += _completeFieldsArr[i];
    }

    if (count == 10) {
        _calculateButton->setEnabled(true);
        _calculateButton->setText("Calculate");
    }
    else {
        _calculateButton->setEnabled(false);
        QString line = QString::number(count);
        _calculateButton->setText(line + "/10");
    }
}


void StudentCalculator::errorDataLoadShow(const std::vector<string>& dataLoudErrors) {
    string lineForWarning;

    for (int i = 0; i < dataLoudErrors.size(); ++i) {
        lineForWarning += dataLoudErrors[i];
        lineForWarning += '\n';
    }

    QMessageBox* errorInput = new QMessageBox(QMessageBox::Warning, "Warning", QString::fromStdString(lineForWarning),
                                              QMessageBox::Ok, this);
    errorInput->show();
}

void StudentCalculator::studentMoneyShow(int sum) {
    QString line = "The " + QString::fromStdString(_name) + " spend " + QString::number(sum) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, "Warning", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}