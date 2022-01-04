#include <iostream>
using namespace std;
//Includes & namespace*************************************************************************************
void controlLoop();
//Variables **********************************************************************************************
struct Publication{
  char[256] title;
  char[50] author;
  int releaseDate;
  string category;  //TODO jedne z typów (book, magazine, yearbook)
  int itemsNumber;
  int borrowersNumber;
  string lastReturnDate;
  int pagesNumber;
};

enum options{
  EXIT = 0,
  ADD_BOOK,
  DELETE_BOOK,
  EDIT_BOOK,
  BORROW_BOOK,
  RETURN_BOOK,
  FIND_BOOK,
};
const string appName = "Library System v0.2";
//Main ****************************************************************************************************
int main() {
  cout << appName << endl;
  controlLoop();  //loop switch with option


  return 0;
}
//Functions ************************************************************************************************

void controlLoop() {
  int choice;
  cin >> choice;
  do{
    switch (choice) {
      case ADD_BOOK:
        addBook();
        break;
      case DELETE_BOOK:
        deleteBook();
        break;
      case EDIT_BOOK:
        editBook();
        break;
      case BORROW_BOOK:
        borrowBook();
        break;
      case RETURN_BOOK:
        retrnBook();
        break;
      case FIND_BOOK:
        findBook();
        break;
      case EXIT:
        exitApp();
        break;

    }
  }while(choice != EXIT)
};
