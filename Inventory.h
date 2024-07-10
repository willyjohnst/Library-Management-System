#ifndef INVENTORY_H

#include "book.h"
#include <vector>

class Inventory {
private:
	std::vector<Book*> inventory;

public:
	
	Inventory();
	void AddBook(std::string isbn, std::string title, std::string author, std::string genre, int publicationYear, std::string checkoutWait, std::string reserveWait); // adds book to the inventory
	void RemoveBook(std::string isbn); // removes book from the inventory
	
	Book* FindBook(std::string inputTitle, std::string inputAuthor); // finds a book in the inventory, returns a pointer to it
	Book* FindBook(int count); //finds the book at index count

	std::vector<Book*> AvailableLibBooks(); // returns a vector pointer to all the available books


	void PrintInventory(); // outputs all books in the inventory

	int LibraryBookCount(); // returns the number of books in the library currently

	std::vector<Book*> LibraryInventory(); // returns a vector pointer to every book in the library
	
};
#endif  // !INVENTORY_H