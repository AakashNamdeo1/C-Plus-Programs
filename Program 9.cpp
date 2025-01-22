/*A book shop maintains the inventory of books that are being sold at the shop. The list includes details such 
as author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person 
inputs the title and author and the system searches the list and displays whether it is available or not. If it is 
not, an appropriate message is displayed. If it is, then the system displays the book details and requests for 
the number of copies required. If the requested copies book details and requests for the number of copies 
required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise 
the message “Required copies not in stock” is displayed. 
 Design a system using a class called books with suitable member functions and Constructors. Use new 
operator in constructors to allocate memory space required.*/




#include <iostream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    double price;
    std::string publisher;
    int stockPosition;
    static int successfulTransactions; // Static member to count successful transactions

    // Private member function to update the price
    void updatePrice(double newPrice) {
        price = newPrice;
    }

public:
    // Constructor to initialize the Book object
    Book(const std::string &auth, const std::string &titl, double prc, 
         const std::string &pub, int stock) 
        : author(auth), title(titl), price(prc), publisher(pub), stockPosition(stock) {}

    // Function to check book availability
    bool isAvailable(const std::string &reqTitle, const std::string &reqAuthor) {
        return (title == reqTitle && author == reqAuthor && stockPosition > 0);
    }

    // Function to display book details
    void displayDetails() {
        std::cout << "Title: " << title << "\nAuthor: " << author 
                  << "\nPrice: $" << price << "\nPublisher: " << publisher 
                  << "\nStock Position: " << stockPosition << std::endl;
    }

    // Function to handle purchase request
    void purchaseBook(int requestedCopies) {
        if (requestedCopies <= stockPosition) {
            std::cout << "Total cost for " << requestedCopies << " copies: $"
                      << (requestedCopies * price) << std::endl;
            stockPosition -= requestedCopies; // Update the stock position
            successfulTransactions++; // Increment the transaction count
        } else {
            std::cout << "Required copies not in stock" << std::endl;
        }
    }

    // Public function to allow price updates
    void changePrice(double newPrice) {
        updatePrice(newPrice);
    }

    // Static function to get the number of successful transactions
    static int getSuccessfulTransactions() {
        return successfulTransactions;
    }
};

// Initialize static member
int Book::successfulTransactions = 0;

int main() {
     // Dynamically allocating memory for a new book
    Book *book = new Book("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", 
                          19.99, "Bloomsbury", 50);

    // Simulating a customer request
    if (book->isAvailable("Harry Potter and the Sorcerer's Stone", "J.K. Rowling")) {
        book->displayDetails(); // Display book details
        book->purchaseBook(2); // Request 2 copies
    } else {
        std::cout << "The requested book is not available." << std::endl;
    }

    // Free the allocated memory
    delete book;

    return 0;
}
