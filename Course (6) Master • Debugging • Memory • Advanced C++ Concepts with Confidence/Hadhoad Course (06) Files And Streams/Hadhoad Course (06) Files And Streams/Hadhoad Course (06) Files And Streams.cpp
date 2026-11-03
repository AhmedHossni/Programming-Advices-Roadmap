#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void FileStream_WriteMode()
{
    fstream fs;
    fs.open("WriteMode_File.txt", ios::out); //fs write Mode
    
    if (fs.is_open())
    {
        fs << "First file stream in write mode\n";
        fs << "file stream write new line\n";

        fs.close();
    }
}
void FileStream_AppendMode()
{
    fstream MyFile;
    MyFile.open("AppendMode_File.txt", ios::out | ios::app);//fs append Mode
    if (MyFile.is_open())
    {
        MyFile << "Hi, this is a new line\n";
        MyFile << "Hi, this is another new line\n";
        MyFile.close();
    }

}
void FileStream_ReadMode()
{
    fstream MyFile;
    MyFile.open("WriteMode_File.txt", ios::in); //fs read Mode

    if (MyFile.is_open())
    {
        string LineFromFile = "";
        while (getline(MyFile, LineFromFile))
        {
            cout << LineFromFile << endl;
        }
    }

}

#pragma region FileStream_With_Vector(Save,Read,update and delete)
void UpdateFileRecord(string fileName, string recordData, string replacedData);

void LoadFileDataToVector(string fileName,vector <string> & destVector)
{
    fstream fs;
    fs.open(fileName, ios::in);

    if (fs.is_open())
    {
        string lineFromFile = "";
        while (getline(fs, lineFromFile))
        {
            destVector.push_back(lineFromFile);
        }
    }
}
void SaveVectorDataToFile(string fileName, vector <string>& sourceVector)
{
    fstream fs;
    fs.open(fileName, ios::out);

    if (fs.is_open())
    {
        string lineFromFile = "";
        for (const string line : sourceVector)
        {
            if(line != "")
                fs << line << endl;
        }
    }
}
void DeleteFileRecord(string fileName,string recordData)
{
    vector <string> bufferVector;

    LoadFileDataToVector(fileName, bufferVector);

    UpdateFileRecord(fileName, recordData, "");
}
void UpdateFileRecord(string fileName, string recordData,string replacedData)
{
    vector <string> bufferVector;
    LoadFileDataToVector(fileName, bufferVector);

    for (string& line : bufferVector)
    {
        if (line == recordData)
            line = replacedData;
    }

    SaveVectorDataToFile(fileName, bufferVector);
}
#pragma endregion



int main()
{
    //FileStream_WriteMode();

    //FileStream_AppendMode();

    //FileStream_ReadMode();

    //vector <string> vectorToReadFileData;
    //LoadFileDataToVector("WriteMode_File.txt", vectorToReadFileData);
    //for (const string &line : vectorToReadFileData)
    //    cout << line << endl;

    //vector <string> vectorToSaveHisDataInFile = {"vector item 1","vector item 2","vector item 3"};
    //SaveVectorDataToFile("DataFromVector.txt", vectorToSaveHisDataInFile);

    //UpdateFileRecord("DataFromVector.txt","vector item 1", "Update Record Method");

    DeleteFileRecord("DataFromVector.txt","vector item 1");

    cin;
}
