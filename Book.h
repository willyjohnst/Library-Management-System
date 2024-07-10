#ifndef BOOK_H

#include <string>
#include <iostream>

class Book {
private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string genre;
	int publicationYear;
	std::string checkoutWait = "";
	std::string reserveWait = "";

public:
	Book(std::string isbn, std::string title, std::string author, std::string genre, int publicationYear, std::string checkoutWait, std::string reserveWait); // book as all identifying information
	
	// getters
	std::string GetISBN();
	std::string GetTitle();
	std::string GetAuthor();
	std::string GetGenre();
	int GetPublicationYear();
	std::string GetCheckoutWait();
	std::string GetReserveWait();

	// setters
	void SetISBN(std::string isbn);
	void SetTitle(std::string title);
	void SetAuthor(std::string author);
	void SetGenre(std::string genre);
	void SetPublicationYear(int publicationyear);
	void SetCheckoutWait(int checkoutDays, std::string inputDate);
	void SetReserveWait(int reserveDays, std::string inputDate);

	// prints all info about the book
	void PrintInfo();
};
#endif // !BOOK_H