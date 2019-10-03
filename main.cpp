#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
char last;

do
 {
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  int number = 0;
  int lineLength = 0;
 
  cout<<"What file do you want to open? ";
  
  getline(cin, fileName);
  
  fileStream.open(fileName.c_str(),ios::in);

  if    (fileStream.is_open())
  {
   cout<<fileName<<" opened.\nFILE CONTENTS:\n";
  
   while (fileStream.is_open() && !fileStream.eof())
   {
            getline(fileStream,line);
            cout<<line<<endl;
            
            if (!line.empty())
            {
                number += 1;          
                lineLength += line.length();
            }
   }
   
   fileStream.close();
  }                                                                             // 3B: display the line, followed by an endline
  //cout<<"METADATA"<< endl << "File: " << fileName << endl << "Lines: "<< number <<endl << "Characters: " << lineLength <<endl;
                                                                                         //STEP 4: close the fileStream
  else
  {
    cout<<fileName<<" could not be opened.\n";
  }
  cout<<"METADATA"<<endl;
  cout<<"File: "<<fileName<<endl;
  cout<<"Lines: "<<number<<endl;
  cout<<"Characters: "<<lineLength<<endl;
  cout<<"Analyze another file (y/n)?"<<endl;
  cin>>last;
  cin.ignore();
}
  while(toupper (last) == 'Y');
  
    
 
  
  
  return 0;
}
