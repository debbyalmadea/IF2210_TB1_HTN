#include "exceptionFile.hpp"

ExceptionFile::ExceptionFile(int id, string fileName) : Exception(id), fileName(fileName) {};

ExceptionFile::ExceptionFile (const ExceptionFile& other) : Exception(other), fileName(other.fileName) {};

void ExceptionFile::print() const {
    cout << "Tidak ditemukan file : " << fileName << endl;
};

string ExceptionFile::getFileName() const { return fileName; }