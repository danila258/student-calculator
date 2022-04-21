#include "StudentCalculator.h"

void StudentCalculator::startCalculate() {
    //TODO здесь должны быть использованы твои функции
    Database database = Database(_costsFile, _instituteFile, _transportFile, _otherCostsFile);

    if ( !(database.initDatabase()) ) {
        errorFileShow();
    }
    else {
        if ( !(database.userInputCheck(_age, _city, _address, _institute, _caffe, _cinema)) ) {
            errorInputShow();
        }
        else {
            Student human = Student(_age, _city, _address, _institute, _cinema, _caffe, database);
            studentMoneyShow(human.getCosts(_month));
        }
    }
}

void StudentCalculator::regulateAgeSpinBox(int mode) {
    _ageSpinBox->setEnabled(mode);
    _calculateAgeFlag = (mode) != 0;
}

void StudentCalculator::ageEdited(int age) {
    _age = age;
}

void StudentCalculator::monthEdited(int month) {
    _month = month;
}

void StudentCalculator::nameEdited(const QString& name) {
    _name = name.toStdString();
    _flagName = !(_name.empty());
    updateCalculateButton();
}

void StudentCalculator::cityEdited(const QString& city) {
    _city = city.toStdString();
    _flagCity = !(_city.empty());
    updateCalculateButton();
}

void StudentCalculator::addressEdited(const QString& address) {
    _address = address.toStdString();
    _flagAddress = !(_address.empty());
    updateCalculateButton();
}

void StudentCalculator::instituteEdited(const QString& institute) {
    _institute = institute.toStdString();
    _flagInstitute = !(_institute.empty());
    updateCalculateButton();
}

void StudentCalculator::cinemaEdited(const QString& cinema) {
    _cinema = cinema.toStdString();
    _flagCinema = !(_cinema.empty());
    updateCalculateButton();
}

void StudentCalculator::caffeEdited(const QString& caffe) {
    _caffe = caffe.toStdString();
    _flagCaffe = !(_caffe.empty());
    updateCalculateButton();
}

void StudentCalculator::costsFileDialog() {
    _costsFile = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv").toStdString();
    _flagCostsFile = !(_costsFile.empty());
    updateCalculateButton();

    //TODO скорее всего здесь должна быть отправлена директория в студент дата
}

void StudentCalculator::instituteFileDialog() {
    _instituteFile = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv").toStdString();
    _flagInstituteFile = !(_instituteFile.empty());
    updateCalculateButton();
}

void StudentCalculator::transportFileDialog() {
    _transportFile = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv").toStdString();
    _flagTransportFile = !(_transportFile.empty());
    updateCalculateButton();
}

void StudentCalculator::otherCostsFileDialog() {
    _otherCostsFile = QFileDialog::getOpenFileName(this, "Other Costs File", "", "*.csv").toStdString();
    _flagOtherCostsFile = !(_otherCostsFile.empty());
    updateCalculateButton();
}

void StudentCalculator::EditeCostsFile() {
    QStringList list = {"City", "Age", "Average food cost per month", "Other costs"};
    _sendFile = resetCosts();
    fileEditWidget(_costsData, list);
}

void StudentCalculator::EditeInstituteFile() {
    QStringList list = {"City", "Institute", "Dinner cost"};
    _sendFile = resetInstitute;
    fileEditWidget(_instituteData, list);
}

void StudentCalculator::EditeTransportFile() {
    QStringList list = {"City", "District", "Institute", "Transport cost"};
    _sendFile = resetTransport;
    fileEditWidget(_transportData, list);
}

void StudentCalculator::EditeCaffeCinemaFile() {
    QStringList list = {"City", "Address", "Caffe", "Average caffe cost", "Cinema", "Cinema cost"};
    _sendFile = resetCafeCinema;
    fileEditWidget(_cafeCinemaData, list);
}

void StudentCalculator::deleteRow() {
    _table->removeRow(_table->rowCount() - 1);
}

void StudentCalculator::addRow() {
    _table->insertRow(_table->rowCount());
}

void StudentCalculator::cancelEditFile() {
    close(_fileEditWidget);
}

void StudentCalculator::saveNewFile() {
    _sendFile(file);
    cancelEditFile();
}
