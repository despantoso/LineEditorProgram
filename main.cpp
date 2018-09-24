#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

int main() {

string line;                                                                            //String variable used for the line that user is inserting
string userInput;                                                                       //String variable used for user input in quotations
LinkedList linkedList;                                                                  //Creation of an object from the LinkedList class


while((getline(cin,line))) {                                                            //While the program is receiving commands through cin, select which function to call

    if (line.find("insertEnd") == 0) {                                                  //If the user types insertEnd at the beginning of the line

        int firstIndex = line.find("\"");                                               //Int variable called firstIndex that finds the index of the first quotations
        int secondIndex = line.length()-2;                                              //Int variable called secondIndex that finds the index of the last letter in the line


        userInput = line.substr(firstIndex + 1, (secondIndex - firstIndex));            //UserInput is equal to the substring from the first letter after the first quotation to the difference between the last letter and the first letter that gets the user's text value
        linkedList.insertEnd(userInput);                                                //Call the insertEnd method
        continue;
    }

    if (line.find("insert") == 0) {                                                     //If the user types insert at the beginning of the line

        int firstIndex = line.find("\"");                                               //Int variable called firstIndex that finds index of the first quotations
        int secondIndex = line.length()-2;                                              //Int variable called secondIndex that finds the index of the last letter in the line
        int index = stoi(line.substr(7));                                               //Int variable called index that is equal to the number of the line where the user wants to insert. Stoi() casts a string to an int in C++

        userInput = line.substr(firstIndex + 1, (secondIndex - firstIndex));            //UserInput is equal to the substring from the first letter after the first quotation to the difference between the last letter and the first letter that gets the user's text value
        linkedList.insertAtIndex(userInput,index);                                      //Call the insertAtIndex method
        continue;
    }

    if(line.find("delete") == 0){                                                       //If the user types delete at the beginning of the line

        int index = stoi(line.substr(7));                                               //Int variable called index that is equal to the number of the line where the user wants to delete. Stoi() casts a string to an int in C++
        linkedList.deleteAtIndex(index);                                                //Call the deleteAtIndex method
        continue;

    }

    if(line.find("edit") == 0){                                                         //If the user types edit at the beginning of the line

        int firstIndex = line.find("\"");                                               //Int variable called firstIndex that finds the index of the first quotations
        int secondIndex = line.length()-2;                                              //Int variable called secondIndex that finds the index of the last letter in the line
        int index = stoi(line.substr(5));                                               //Int variable called index that is equal to the number of the line where the user wants to edit. Stoi() casts a string to an int in C++

        userInput = line.substr(firstIndex + 1, (secondIndex - firstIndex));            //UserInput is equal to the substring from the first letter after the first quotation to the difference between the last letter and the first letter that gets the user's text value
        linkedList.editAtIndex(userInput,index);                                        //Call the editAtIndex method
        continue;
    }

    if(line.find("search") == 0){                                                       //If the user types search at the beginning of the line

        int firstIndex = line.find("\"");                                               //Int variable called firstIndex that finds the index of the first quotations
        int secondIndex = line.length()-2;                                              //Int variable called secondIndex that finds the index of the last letter in the line

        userInput = line.substr(firstIndex + 1, (secondIndex - firstIndex));            //UserInput is equal to the substring from the first letter after the first quotation to the difference between the last letter and the first letter that gets the user's text value
        linkedList.searchText(line,userInput);                                          //Call the searchText method
        continue;
    }

    if (line.find("print") == 0) {                                                      //If the user types print at the beginning of the line
        linkedList.printList();                                                         //Call the printList method
        continue;
    }

    if (line.find("quit") == 0) {                                                       //If the user types quit, then quit the program
        break;
    }

}

    return 0;
}