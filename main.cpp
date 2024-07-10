#include "Library.h"

int main() {

	// initalising variables
	std::string userInput;
	std::string userTitle;
	std::string userAuthor;
	std::string userISBN;
	std::string currentDate = "5/6/24"; // date as of coding this, update the date in the Administrator menu
	Library thisLibrary;


	while (true) {
		// Gives menu options to user
		std::cout << "Press 1: BOOK ISSUE" << std::endl;
		std::cout << "Press 2: BOOK RENEWAL" << std::endl;
		std::cout << "Press 3: BOOK RESERVATION" << std::endl;
		std::cout << "Press 4: CANCEL RESERVATION" << std::endl;
		std::cout << "Press 5: BOOK RETURN" << std::endl;
		std::cout << "Press 6: EXIT" << std::endl;
		std::cout << "Press 7: ADMINISTRATOR MENU" << std::endl;

		std::cout << "PLEASE SELECT YOUR OPTION(1-7): ";
		std::cin >> userInput;
		std::cout << std::endl;

		// issues the inputted book
		if (userInput == "1") {
			std::cout << std::endl << "Please enter the Book TITLE: "; // getting the book's title
			std::cin >> userTitle;

			std::cout << std::endl << "Please enter the AUTHOR'S name: "; // getting the auhtor's name
			std::cin >> userAuthor;

			Book* checkoutBook;
			checkoutBook = thisLibrary.FindBook(userTitle, userAuthor); // returns a pointer to the book, or 0 if the book isnt found

			if (checkoutBook == 0) {
				std::cout << "This book is not currently found in this library." << std::endl << std::endl;
			}
			else {
				std::string checkedOut; // used to check whether this book is already checked out
				userISBN = checkoutBook->GetISBN();

				checkedOut = thisLibrary.CheckoutBook(userAuthor, userTitle, currentDate);

				if (checkedOut == "0") {
					std::cout << std::endl << "This book is already checked out" << std::endl << std::endl;
				}
				else {
					std::cout << "You have checked out " << userTitle << " by " << userAuthor << " until " << checkoutBook->GetCheckoutWait() << std::endl;
				}
			}

		}

		// renews the inputted book
		else if (userInput == "2") {
			std::cout << std::endl << "Please enter the Book TITLE: "; // getting the book's title
			std::cin >> userTitle;

			std::cout << std::endl << "Please enter the AUTHOR'S name: "; // getting the auhtor's name
			std::cin >> userAuthor;

			Book* renewalBook;
			renewalBook = thisLibrary.FindBook(userTitle, userAuthor); // returns a pointer to the book, or 0 if the book isnt found
			
			if (renewalBook == 0) {
				std::cout << "This book is not currently found in this library." << std::endl << std::endl;
			}
			else {
				if (renewalBook->GetCheckoutWait() == "") {
					std::cout << "This book is not currently checked out" << std::endl;
				}
				else if (renewalBook->GetReserveWait() != "") {
					std::cout << "This book is currently reserved, so it cannot be renewed." << std::endl;
					std::cout << "Your return date is " << renewalBook->GetCheckoutWait() << std::endl;
				}
				else {
					std::cout << "Renewed " << userTitle << " until " << thisLibrary.RenewBook(userTitle, userAuthor, currentDate) << std::endl;
				}
			}
		}

		// reserving books
		else if (userInput == "3") {
			if (currentDate == "") {
				std::cout << "Current Date is not set. Please set date in the ADMINISTRATOR MENU" << std::endl;
			}
			else {
				std::cout << std::endl << "Please enter the Book TITLE: "; // getting the book's title
				std::cin >> userTitle;

				std::cout << std::endl << "Please enter the AUTHOR'S name: "; // getting the auhtor's name
				std::cin >> userAuthor;

				Book* reserveBook;
				reserveBook = thisLibrary.FindBook(userTitle, userAuthor); // returns a pointer to the book, or 0 if the book isnt found

				if (reserveBook == 0) {
					std::cout << "This book is not currently found in this library." << std::endl << std::endl;
				}
				else {
					if (reserveBook->GetCheckoutWait() == "") {
						std::cout << userTitle << " is not currently checked out." << std::endl;
					}
					else if (reserveBook->GetReserveWait() == "") {
						reserveBook->SetReserveWait(0, reserveBook->GetCheckoutWait());
						std::cout << userTitle << " reserved for " << reserveBook->GetReserveWait() << std::endl;
					}
					else {
						reserveBook->SetReserveWait(14, reserveBook->GetReserveWait());
						std::cout << userTitle << " reserved for " << reserveBook->GetReserveWait() << std::endl;
					}
				}
			}
		}

		else if (userInput == "4") {
				std::cout << std::endl << "Please enter the Book TITLE: "; // getting the book's title
				std::cin >> userTitle;

				std::cout << std::endl << "Please enter the AUTHOR'S name: "; // getting the auhtor's name
				std::cin >> userAuthor;

				Book* cancelReservationBook;
				cancelReservationBook = thisLibrary.FindBook(userTitle, userAuthor); // returns a pointer to the book, or 0 if the book isnt found

				if (cancelReservationBook == 0) {
					std::cout << "This book is not currently found in this library." << std::endl << std::endl;
				}
				else {
					if (cancelReservationBook->GetReserveWait() == "") {
						std::cout << userTitle << " is not currently reserved." << std::endl;
					}
					else {
						cancelReservationBook->SetReserveWait(-14, cancelReservationBook->GetReserveWait());
						std::cout << "Cancelled reservation for " << userTitle << std::endl;
					}
				}
		}
		
		// returning books
		else if (userInput == "5") {
			if (currentDate == "") {
				std::cout << "Current Date is not set. Please set date in the ADMINISTRATOR MENU" << std::endl;
			}
			else {
				std::cout << std::endl << "Please enter the Book TITLE: "; // getting the book's title
				std::cin >> userTitle;

				std::cout << std::endl << "Please enter the AUTHOR'S name: "; // getting the auhtor's name
				std::cin >> userAuthor;

				Book* returnBook;
				returnBook = thisLibrary.FindBook(userTitle, userAuthor); // returns a pointer to the book, or 0 if the book isnt found

				if (returnBook == 0) {
					std::cout << "This book is not currently found in this library." << std::endl << std::endl;
				}
				else {
					std::string checkoutDate; // used if there is a fine
					userISBN = returnBook->GetISBN();

					checkoutDate = thisLibrary.ReturnBook(userTitle, userAuthor, currentDate); // if it returns $30 fine is issued, otherwise = 0
					if (checkoutDate.empty()) {
						std::cout << userTitle << "'s due date was " << checkoutDate << " please pay a $30 late fee" << std::endl;
					}
					else {
						std::cout << userTitle << " was returned successfully." << std::endl;
					}
				}
			}
		}

		// exits the code
		else if (userInput == "6") {
			return 0;
		}

		// admin settings
		else if (userInput == "7") {
			while (userInput != "6") {
				std::cout << "Press 1: ADD BOOK" << std::endl;
				std::cout << "Press 2: DELETE BOOK" << std::endl;
				std::cout << "Press 3: LIST ALL BOOKS" << std::endl;
				std::cout << "Press 4: LIST OVERDUE BOOKS" << std::endl;
				std::cout << "Press 5: LIST AVAILABLE BOOKS" << std::endl;
				std::cout << "Press 6: EXIT" << std::endl;
				std::cout << "Press 7: UPDATE DATE" << std::endl;
				std::cout << "PLEASE SELECT YOUR OPTION(1-7): ";

				std::cin >> userInput;
				std::cout << std::endl;


				// add book
				if (userInput == "1") {
					std::string genre;
					int publicationYear;

					std::cout << "Input ISBN: ";
					std::cin >> userISBN;
					std::cout << std::endl;

					std::cout << "Input title: ";
					std::cin >> userTitle;
					std::cout << std::endl;

					std::cout << "Input author: ";
					std::cin >> userAuthor;
					std::cout << std::endl;

					std::cout << "Input genre: ";
					std::cin >> genre;
					std::cout << std::endl;

					std::cout << "Input publication year: ";
					std::cin >> publicationYear;
					std::cout << std::endl;

					thisLibrary.AddBookToLibrary(userISBN, userTitle, userAuthor, genre, publicationYear, "", "");

					thisLibrary.FindBook(userTitle, userAuthor)->PrintInfo();
				}

				// delete book
				else if (userInput == "2") {
					std::cout << std::endl << "Please enter the Book TITLE: "; // getting the book's title
					std::cin >> userTitle;

					std::cout << std::endl << "Please enter the AUTHOR'S name: "; // getting the auhtor's name
					std::cin >> userAuthor;

					Book* deleteBook;
					deleteBook = thisLibrary.FindBook(userTitle, userAuthor); // returns a pointer to the book, or 0 if the book isnt found

					if (deleteBook == 0) {
						std::cout << "This book is not currently found in this library." << std::endl << std::endl;
					}
					else {
						thisLibrary.RemoveBookFromLibrary(deleteBook->GetISBN());
						std::cout << "Book has been removed from the library" << std::endl;
					}
				}
				// list all books
				else if (userInput == "3") {
					thisLibrary.ListLibraryBooks();
				}
				// list overdue books
				else if (userInput == "4") {
					thisLibrary.ListOverdueBooks(currentDate);
				}
				// list available books
				else if (userInput == "5") {
					thisLibrary.ListAvailableBooks(currentDate);
				}
				else if (userInput == "7") {
					std::cout << "Please input the current date, format MM/DD/YY: ";
					std::cin >> currentDate;
					std::cout << std::endl << "Date updated to " << currentDate << std::endl;
				}
				else if (userInput != "6") {
					std::cout << "Please input a NUMBER between 1-6" << std::endl;
				}

			}
		}
		// Input number wasnt (1-4)
		else {
			std::cout << "Please input a NUMBER between 1-7" << std::endl;
		}
	}
	return 69;
}