#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // Create and open a text file
  ofstream MyFile("filename.txt");

  // Write to the file
  MyFile << "Files can be tricky, but it is fun enough!";

  // Close the file
  MyFile.close();
}

// Create a text string, which is used to output the text file
string myText;

// Read from the text file
ifstream MyReadFile("filename.txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
  cout << myText;
}

// Close the file
MyReadFile.close();



#include <fstream> 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    // Open the file 
    ifstream file("example.txt"); 
  
    // Check if the file was opened successfully 
    if (!file) { 
        cout << "Unable to open file"; 
        return 1; 
    } 
  
    // Read the file character by character 
    char ch; 
    while (file.get(ch)) { 
        cout << ch << " "; 
    } 
    cout << endl; 
  
    // Close the file 
    file.close(); 
  
    return 0; 
}