#include "exceptionFile.hpp"

string ExceptionFile::message[] = {
    "Tidak ditemukan file",
    "Konfigurasi file salah",
    "Konfigurasi file salah : Jumlah kartu kurang"};

ExceptionFile::ExceptionFile(int id, string fileName) : Exception(id),
                                                        fileName(fileName){};

ExceptionFile::ExceptionFile(const ExceptionFile &other) : Exception(other), fileName(other.fileName){};

void ExceptionFile::print() const
{
    cout << message[this->getID()];
    if (this->getID() == 0)
    {
        cout << " : " << fileName;
    }
    cout << endl;
};

string ExceptionFile::getFileName() const { return fileName; }