#include "readthread.h"

readThread::readThread()
{

}
void readThread::receiveFileNames(QStringList fileList)
{

    Tfile_list=fileList;

 }
void readThread::run()
{


    for (int i=0;i<Tfile_list.length();i++)
    {

         QFile filename(Tfile_list.at(i));
         QByteArray line;
         QStringList AK;
         if (filename.open(QFile::ReadOnly | QIODevice::Truncate))
         {

             while(!filename.atEnd())
             {
                 line = filename.readLine();
                 QString str(line);
                 AK.append(str.split(",").at(0).split(" ").at(1)+"\t");
                 //qDebug()<<str.split(",").at(1).split("\n").at(0);
                 AK.append(str.split(",").at(1).split("\n").at(0));
             }
         }


          QFile saveFileName(Tfile_list.at(i)+"Change.txt");
          QTextStream stream(&saveFileName);
          saveFileName.open(QIODevice::WriteOnly | QIODevice::Text);
          for(int i=0;i<AK.length()-1; i+=2)
          {
                stream<< AK[i]<<AK[i+1]<<"\t\n";
          }

                emit sendChangeFile2M(Tfile_list.at(i)+"Change.txt");



    }
}
