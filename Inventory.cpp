#include "Inventory.h"
#include "Functions.h"

Inventory::Inventory()
{
}

void Inventory::AddBook(std::string isbn, std::string title, std::string author, std::string genre, int publicationYear, std::string checkoutWait, std::string reserveWait)
{
	inventory.push_back(new Book(isbn, title, author, genre, publicationYear, checkoutWait, reserveWait));
}
void Inventory::RemoveBook(std::string isbn)
{
	//TODO, use a better algorithim to search for the removed-book (now is O(N))
	for (int i = 0; i < inventory.size(); i++) // goes through the whole inventory
	{
		if (inventory.at(i)->GetISBN() == isbn) // true if current book's isbn is the same as the isbn we have to remove
		{
			inventory.erase(inventory.begin() + i); // removes that book from the inventory
			return;
		}
	}
}

Book* Inventory::FindBook(std::string inputTitle, std::string inputAuthor)
{
	// goes through inventory to look for it O(N)
	// will update if I sort library
	for (int i = 0; i < inventory.size(); i++) {
		std::string librarydetail = inventory.at(i)->GetTitle();
		if (librarydetail == inputTitle) { // true if the input title is the same as the inventory title
			librarydetail = inventory.at(i)->GetAuthor();
			if (librarydetail == inputAuthor) { // true if the input author is the same as the inventory author
				return inventory.at(i);
			}
		}
	}
	return nullptr;
}

Book* Inventory::FindBook(int count)
{
	return this->inventory.at(count); // returns a pointer to the book at index count within the inventory
}

std::vector<Book*> Inventory::AvailableLibBooks()
{
	// goes through inventory to find all books that are available and outputs them
	// will update if I sort library
	std::vector<Book*> availableBooks;
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory.at(i)->GetCheckoutWait() != "") {
			availableBooks.push_back(inventory.at(i)); // creates a vector of Book pointers to all available books
		}
	}
	return availableBooks;
}


// prints the entire inventory out
void Inventory::PrintInventory()
{
	for (int i = 0; i < inventory.size(); i++) {
		inventory.at(i)->PrintInfo();
	}
}

int Inventory::LibraryBookCount()
{
	return static_cast<int>(inventory.size());
}

std::vector<Book*> Inventory::LibraryInventory() {
	// goes through inventory to find all books that are available and outputs them
	// will update if I sort library
	std::vector<Book*> availableBooks;
	for (int i = 0; i < inventory.size(); i++) {
		availableBooks.push_back(inventory.at(i)); // creates a vector of Book pointers to all available books
	}
	return availableBooks;
}