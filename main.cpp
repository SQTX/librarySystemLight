//Includes & namespace*************************************************************************************
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
//Functions init *****************************************************************************************
void printLine(string txt);
void printOptions();
void controlLoop();

void exitApp();

//Variables **********************************************************************************************
struct Publication{
  char title[256];
  char author[50];
  int releaseDate;
  string category;  //TODO types (book, magazine, yearbook)
  int itemsNumber;
  int borrowersNumber;
  string lastReturnDate;
  int pagesNumber;

  Publication(char *title, char *author, int releaseDate, const string &category, int itemsNumber, int borrowersNumber,
              const string &lastReturnDate, int pagesNumber) {
    strcpy(this->title, title);
    strcpy(this->author, author);
    this->releaseDate = releaseDate;
    this->category = category;
    this->itemsNumber = itemsNumber;
    this->borrowersNumber = borrowersNumber;
    this->lastReturnDate = lastReturnDate;
    this->pagesNumber = pagesNumber;
  }
};

//Options -----------
enum options{
  EXIT = 0,
  ADD_PUBLICATION,
  DELETE_PUBLICATION,
  EDIT_PUBLICATION,
  BORROW_PUBLICATION,
  RETURN_PUBLICATION,
  FIND_PUBLICATION,
};

map<const int, string> optionMap{
    {EXIT, "wyjscie z aplikacji"},
    {ADD_PUBLICATION, "dodaj publikacje"},
    {DELETE_PUBLICATION, "usun publikacje"},
    {EDIT_PUBLICATION, "edytuj publikacje"},
    {BORROW_PUBLICATION, "dokonaj wyporzyczenia"},
    {BORROW_PUBLICATION, "dokonaj zwrotu"},
    {FIND_PUBLICATION, "znajdz konkretna oublikacje"},
};
//App name --------------
const string appName = "Library System v0.2";
//Main ****************************************************************************************************
int main() {
  printLine(appName);
  controlLoop();  //loop switch with option

  return 0;
}
//Functions ************************************************************************************************

void controlLoop() {
  printOptions();
  int choice;
  do{
    choice = 0; //Overwriting variable
    cin >> choice;
    switch (choice) {
      case ADD_PUBLICATION:
//        addBook();
        break;
      case DELETE_PUBLICATION:
//        deleteBook();
        break;
      case EDIT_PUBLICATION:
//        editBook();
        break;
      case BORROW_PUBLICATION:
//        borrowBook();
        break;
      case RETURN_PUBLICATION:
//        retrnBook();
        break;
      case FIND_PUBLICATION:
//        findBook();
        break;
      case EXIT:
        exitApp();
        break;
    }
  }while(choice != EXIT);
}
void printOptions(){
  printLine("Wybierz opcje: ");
  for(auto &ele:optionMap){
    string message = to_string(ele.first) + " - " + ele.second;
    printLine(message);
  }
}

//Exit Func.----------
void exitApp(){
  printLine("Koniec programu");
}

//Printer----------
void printLine(string txt){
  cout << txt << endl;
}
