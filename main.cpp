#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading

  cout<<"What file do you want to open? ";
  getline(cin, fileName);
  
  //STEP 1: open the fileStream for input, using the fileName specified
fileStream.open("fileName",ios::in);



  if(fileStream.in) /*STEP 2: check to see if the fileStream successfully opened*/
  {
    cout<<fileName<<" opened.\nFILE CONTENTS:\n";
    
    //STEP 3: repeat the following until the end-of-file (eof) has been reached...
    while (fileStream.in && !fileStream.eof())// 3A: read a line from fileStream into the variable line
    {
            getline(fileStream,line);
            cout<<line<<endl;
    }

            // 3B: display the line, followed by an endline
  
    //STEP 4: close the fileStream
  fileStream.close();
  }
  else
  {
    cout<<fileName<<" could not be opened.\n";
  }

  return 0;
}
