#include "Book.h"
#include "Functions.h"

Book::Book(std::string isbn, std::string title, std::string author, std::string genre, int publicationYear, std::string checkoutWait, std::string reserveWait) {
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->genre = genre;
	this->publicationYear = publicationYear;
	this->checkoutWait = checkoutWait;
	this->reserveWait = reserveWait;
}

std::string Book::GetISBN() {
	return isbn;
}
std::string Book::GetTitle() {
	return title;
}
std::string Book::GetAuthor() {
	return author;
}
std::string Book::GetGenre() {
	return genre;
}

int Book::GetPublicationYear() {
	return publicationYear;
}

std::string Book::GetCheckoutWait() {
	return checkoutWait;
}
std::string Book::GetReserveWait() {
	return reserveWait;
}

void Book::SetISBN(std::string isbn) {
	this->isbn = isbn;
}
void Book::SetTitle(std::string title) {
	this->title = title;
}
void Book::SetAuthor(std::string author) {
	this->author = author;
}
void Book::SetGenre(std::string genre) {
	this->genre = genre;
}
void Book::SetPublicationYear(int year) {
	this->publicationYear = year;
}
void Book::SetCheckoutWait(int checkoutDays, std::string inputDate) {
	if (!inputDate.empty()) {
		std::string date = Calander(inputDate);
		this->checkoutWait = DateAfterChange(date, checkoutDays);
	}
	else
		this->checkoutWait = "";
}

void Book::SetReserveWait(int reserveDays, std::string inputDate) {
	if (!inputDate.empty()) {
		std::string date = Calander(inputDate);
		this->reserveWait = DateAfterChange(date, reserveDays);
	}
	else
		this->reserveWait = "";
}

void Book::PrintInfo() {
	std::cout << "ISBN: " << isbn;
	std::cout << ", title: " << title;
	std::cout << ", author: " << author;
	std::cout << ", genre: " << genre;
	std::cout << ", publication year: " << publicationYear;
	std::cout << ", checkout wait: " << checkoutWait;
	std::cout << ", reserve wait: " << reserveWait << std::endl;
	return;
}