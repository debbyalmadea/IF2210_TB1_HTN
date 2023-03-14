#include "exceptionFile.hpp"

string ExceptionFile::message[] = {
    "Tidak ditemukan file : ",
    "Konfigurasi file salah : Format kartu salah",
    "Konfigurasi file salah : Jumlah kartu tidak 52",
};

ExceptionFile::ExceptionFile(int ID, string fileName) : Exception(ID),
                                                        fileName(fileName){};

ExceptionFile::ExceptionFile(const ExceptionFile &other) : Exception(other), fileName(other.fileName){};

void ExceptionFile::print() const
{
    cout << message[this->getID()];
    if (this->getID() == 0)
    {
        cout << fileName;
    }
    cout << endl;
};

string ExceptionFile::getFileName() const { return fileName; }