#ifndef LIBRARY

#include "Inventory.h"

class Library {
private:
	Inventory thisLibrary;
	// attach a value to each book, when theyre taken out = how many days till due
public:
	Library();

	// checks out a book, returns when it was checked out to
	// calls find book to make sure book is available and in Library
	// if not available returns 0, if not in the library returns -1
	std::string CheckoutBook(std::string isbn, std::string title, std::string currentDate);
	
	// returns the book, makes it available again. 
	// checks if it was overdue and if so, calls ReturnOverdueBook
	std::string ReturnBook(std::string isbn, std::string title, std::string currentDate);

	std::string ReserveBook(std::string title, std::string author, std::string currentDate);
	void CancelReservation(std::string title, std::string author, std::string currentDate);
	std::string RenewBook(std::string title, std::string author, std::string currentDate);

	std::string ReturnOverdueBook(Book* book); // called by returnBook, calls calculate fine and outputs result to librarian

	void AddBookToLibrary(std::string isbn, std::string title, std::string author, std::string genre, int publicationYear, std::string checkoutWait, std::string reserveWait) {
		thisLibrary.AddBook(isbn, title, author, genre, publicationYear, checkoutWait, reserveWait);
	}
	void RemoveBookFromLibrary(std::string isbn) {
		thisLibrary.RemoveBook(isbn);
	}
	void ListLibraryBooks() // outputs every book in the library 
	{
		thisLibrary.PrintInventory();
	}
	void ListOverdueBooks(std::string currentDate); // outputs every overdue book in the library
	void ListAvailableBooks(std::string currentDate); // outputs every available book in the library

	Book* FindBook(std::string inputTitle, std::string inputAuthor) {
		return thisLibrary.FindBook(inputTitle, inputAuthor);
		
	}
};
#endif // !LIBRARY