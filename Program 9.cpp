/* Improve the system design in exercise 8 to incorporate the following features:
(a) The price of the books should be updated as and when required. Use a private meneber function to 
implement this.
(b) The stock value of each book should be automatically updated as soon as a transaction is completed.
(c) The number of successful transactions should be recorded for the purpose of statistical analysis. Use 
static data members to keep count of transaction.*/




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
