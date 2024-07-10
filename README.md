Library Management System

This project uses C++ to create a system which is to be used by Librarians to manage various library functions.
Some examples are to manage book inventorie, track book checkouts and returns, handle late returns, reservations and reservation cancellations.

The base class is Book, which through composition is used by the Inventory class, which itself is used by the Library class.

Book

(-) ISBN: String

(-) title: String

(-)	author: String

(-)	genre: String

(-)	publicationYear: int

(-)	checkoutWait: String

(-) reserveWait: String 

(+) PrintInfo: void


Inventory
(-)	inventory: vector<Book*>

(+) AddBook(in ISBN: String, in title: String, in author: String, in genre: String, in publicationYear: int, in checkoutWait: String, in reserveWait: String): void

(+) RemoveBook(in ISBN: String): void

(+) FindBook(in title: String, in author: String): Book*

(+) FindBook(in count: int): Book*

(+) AvailableLibBooks: vector<Book*>

(+) PrintInventory: void

(+) LibraryBookCount: int

(+) LibraryInventory: vector<Book*>



Library
-	thisLibrary: Inventory
+ CheckoutBook(in ISBN: string, in title: String, in currentDate: string): String
+ ReturnBook(in ISBN: string, in title: String, in currentDate: string): String
+ ReserveBook(in title: string, in author: String, in format: string): String
+ CancelReservation(in title: string, in author: String, in currentDate: string): string
+ RenewBook(in title: string, in author: string, in currentDate: string): string
+ ReturnOverdueBook (in book: Book*): String
+ AddBookToLibrary(in ISBN: String, in title: String, in author: String, in genre: String, in publicationYear: int, in checkoutWait: String, in reserveWait: String): void
+ RemoveBookFromLibrary(in ISBN: string): void
+ ListLibraryBooks: void
+ ListOverdueBooks(in currentDate: string): void
+ ListAvailableBooks(in CurrentDate: string): void
+ FindBook(in title: String, in author: String): Book*


The Library management system is divided into 8 files:
Main.cpp is which contains the UI code, and main function.

Library.cpp and Library.h are where the inventory of the library’s books is declared along with various functions which manipulate this inventory and the books’ private variables in order to do things like checkout and return books, add and remove books from the inventory, and other such basic library functions.
Inventory.cpp and Inventory.h are where the vector of Book pointers is declared. The vector (inventory) is the method used to hold each book’s values inside the library’s inventory. Also, in the Inventory files, basic functions necessary to manipulate the inventory are declared, such as functions to add and remove books, find books, and functions to print all or some of the books in the library.
Book.cpp and Inventory.h are the base class Book is declared. Book has private values of all the attributes of a book relevant to a library system made to manage their inventories. It contains Getters and Setters for each attribute, as well as a class to print out all of the attributes.
I decided to code it this way, with 3 classes each using compositions of its parent class, in order to help organize the different levels of functions to make coding it, and understanding it easier. The Book class has the attributes to manipulate the values of an individual book, the Inventory class has the attributes to manipulate whole books in an inventory, and finally, the Library class has the attributes to do library level functions, such as checkout or return books. 
I made the specific variables which make up the Book class private, in order to protect them from potentially being compromised by more complex code on the Inventory and Library level. I did the same for Inventory’s vector of Book pointers called inventory, and Library’s inventory called thisLibrary, for the same reason. 

I made liberal use of Book pointers throughout the project, as getting the specific values of a book for certain functions in the two higher level classes were crucial, and book pointers were an easy way to solve this problem. Inventory was a vector of Book pointers, as each Book was its own object with its values liable to being changed, so using pointers here made the most sense to me. 

This project performs input and output through the iostream library. In the main file, the system prompts the user whether they want to checkout, renew, return, or reserve a book. The system then prompts them for book details, and lets them know the status of their inquiry.
Testing occurred throughout the coding process, testing each bit of code after I was finished writing it. The final testing occurred towards the end of the process, editing code at each level of class, I would approach the code as a user trying to use it, and when errors occurred I would fix them until I believe I have fixed most of them.
The biggest challenges I had on this process was coding a project of this scale, when I am mostly use to coding small homework and lab problems, I found it hard to organize the project as a whole, while keeping the code consistent and avoiding spaghetti code. I also had a lot of difficulty with using multiple files. When errors occurred in this, I did not know what the problems even were, where they were occurring or least of all why. It took me several hours to figure out these issues, which many times were single line omissions, which I didn’t know I needed to include, such as not including return() in the main function.
