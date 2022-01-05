//Includes & namespace*************************************************************************************
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
//Functions init *****************************************************************************************
void printLine(string txt);
void printOptions();
void controlLoop();
//Switch options
void addPublication();
//void deletePublication();
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

  string toString(){
    string titleStr;
    string authorStr;
    for(int i = 0; i < strlen(title); i++){
      titleStr.push_back(title[i]);
    }
    for(int i = 0; i < strlen(author); i++){
      authorStr.push_back(author[i]);
    }
    string mess = "Tytul: " + titleStr + " | " + "autor: " + authorStr + " | " + "data wydania: " + to_string(releaseDate) + " | "
        + "kategoria: " + category + " | " + "liczba stron: " + to_string(pagesNumber) + " | "
        + "liczba egzemplarzy: " + to_string(itemsNumber);
/*    string toSave = titleStr + " ; " + authorStr + " ; " + to_string(releaseDate) + " ; " + category + " ; "
        + to_string(itemsNumber) + " ; " + to_string(pagesNumber);*/
    return mess;
  }
};

//Options ---------------------------------------------------------------------------------------------------
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
//Data base **************************************************************************************************
vector<Publication> publications;
//App name ---------------------------------------------------------------------------------------------------
const string appName = "Library System v0.45";
//Main ****************************************************************************************************
int main() {
  printLine(appName);
  controlLoop();  //loop switch with option

  return 0;
}
//Functions ************************************************************************************************
void controlLoop() {
  int choice;
  do{
    printOptions();
    choice = 0; //Overwriting variable
    cin >> choice;
    switch (choice) {
      case ADD_PUBLICATION:
        addPublication();
        break;
      case DELETE_PUBLICATION:
//        deletePublication();
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
//    TODO czyszczenie ekranu po kliknięciu
  }while(choice != EXIT);
}
void printOptions(){
  printLine("Wybierz opcje: ");
  for(auto &ele:optionMap){
    string message = to_string(ele.first) + " - " + ele.second;
    printLine(message);
  }
}

//Add Publication Func. ---------------------------------------------------------------------------------------------
Publication createPublication();
void checkPublication(Publication*);
//***
void addPublication() {
  Publication newPublication = createPublication();
  checkPublication(&newPublication);
  publications.push_back(newPublication);
  printLine("Dodano: " + newPublication.toString());
}
//***
//Create new publication
Publication createPublication(){
  bool dataRight = false;
  char* titleCh;
  string title;
  char* authorCh;
  string author;
  int releaseDate;
  string category;
  int pagesNumber;

  printLine("Podaj tytul: ");
  cin.ignore();
  getline(cin, title);
  titleCh = &title[0];
  printLine("Podaj autora dziela: ");
  getline(cin, author);
  authorCh = &author[0];
  printLine("Podaj date wydania: ");
  cin >> releaseDate;
  do{
    printLine("Podaj kategorie: (ksiazka/czasopismo/rocznik)");
    cin >> category;
    if(category == "ksiazka" || category == "czasopismo" || category == "rocznik"){
      dataRight = true;
    }else{
      printLine("Podana kategoria nie istnieje");
    }
  }while(!dataRight);
  printLine("Podaj liczbe stron: ");
  cin >> pagesNumber;


  Publication newPublication(titleCh, authorCh, releaseDate, category, 0, 0, "",
                             pagesNumber);
  return newPublication;
}
//Checks if the publication exists later
void checkPublication(Publication* newPublic){
  if(publications.size() == 0){
    newPublic->itemsNumber = 1;
    cout << "pierwsza" << endl;
  }else{
    for(Publication pub : publications){
      cout << newPublic->title << endl;
      cout << pub.title << endl;
      cout << (strcmp(newPublic->title,pub.title)) << endl;
      if(strcmp(newPublic->title,pub.title) == 0 && strcmp(newPublic->author,pub.author) == 0 &&
      (newPublic->category == pub.category)){
        newPublic->itemsNumber = pub.itemsNumber+1;
      }else{
        newPublic->itemsNumber = 1;
      }
    }
  }
}

//Delete Publication Func. ---------------------------------------------------------------------------------------------
/*void deletePublication(){
  cout << "ba ba" << endl;
};*/

//Exit Func. ---------------------------------------------------------------------------------------------------
void exitApp(){
  printLine("Koniec programu");
}

//Printer ---------------------------------------------------------------------------------------------------
void printLine(string txt){
  cout << txt << endl;
}
