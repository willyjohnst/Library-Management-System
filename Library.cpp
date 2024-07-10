#include "Library.h"
#include "Functions.h"

Library::Library() {
	//Add inital books, otherwise its complete
}

std::string Library::CheckoutBook(std::string title, std::string author, std::string currentDate) {
	Book* thisBook = thisLibrary.FindBook(title, author);
	if (thisBook->GetISBN() == "") { //book is not present in library
		return "- 1";
	}
	
	if ((thisBook->GetCheckoutWait() == "") && (thisBook->GetReserveWait() == "")) {
		thisBook->SetCheckoutWait(14, currentDate); // if the book isnt reserved or checked out, checks it out
		return thisBook->GetCheckoutWait();
	}
	else {
		return "0";
	}
}

// returns the book, makes it available again. 
// checks if it was overdue and if so, calls ReturnOverdueBook
std::string Library::ReturnBook(std::string title, std::string author, std::string currentDate) {
	int currentDateValue = DateToInt(Calander(currentDate)); // gets value for input date 
	Book* checkedoutBook = thisLibrary.FindBook(title, author);
	int checkedDateValue = DateToInt(Calander(checkedoutBook->GetCheckoutWait()));

	// if the due date has not passed
	if (checkedDateValue <= currentDateValue) {
		checkedoutBook->SetCheckoutWait(0, "");
		return "";
	}
	else {
		return ReturnOverdueBook(checkedoutBook);
	}
}

// adds 14 days to the reserve time for this customer
std::string Library::ReserveBook(std::string title, std::string author, std::string currentDate) {
	Book* thisbook = thisLibrary.FindBook(title, author);
	thisbook->SetReserveWait(14, currentDate);
	return thisbook->GetReserveWait();
}

void Library::CancelReservation(std::string title, std::string author, std::string currentDate) {
	Book* book = thisLibrary.FindBook(title, author);
	book->SetReserveWait(-14, currentDate);
}

// checks out the book for another two weeks
std::string Library::RenewBook(std::string title, std::string author, std::string currentDate) {
	Book* thisBook = thisLibrary.FindBook(title, author);
	thisBook->SetCheckoutWait(14, thisBook->GetCheckoutWait());
	return thisBook->GetCheckoutWait();
}


// on further research most librarys do a flat fee for their fine
std::string Library::ReturnOverdueBook(Book* book)
{
	std::string checkoutDate;
	checkoutDate = book->GetCheckoutWait();
	book->SetCheckoutWait(0, "");
	return checkoutDate;
}

void Library::ListOverdueBooks(std::string currentDate) {
	
	int currentDateInt = DateToInt(currentDate);
	std::vector<Book*> availableBooks;
	
	for (int i = 0; i < thisLibrary.LibraryBookCount(); i++) {
		int bookDateInt = DateToInt(thisLibrary.FindBook(i)->GetCheckoutWait());
		if (bookDateInt < currentDateInt) { // if the book is overdue prints it
			thisLibrary.FindBook(i)->PrintInfo();
		}
	}
}

void Library::ListAvailableBooks(std::string currentDate) {

	int currentDateInt = DateToInt(currentDate);

	for (int i = 0; i < thisLibrary.LibraryBookCount(); i++) {
		int bookDateInt = DateToInt(thisLibrary.FindBook(i)->GetCheckoutWait());
		if (bookDateInt > currentDateInt) { // if the book is available prints it
			thisLibrary.FindBook(i)->PrintInfo();
		}
	}
}