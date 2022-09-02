#include <iostream>
#include "Book.hpp"

int main(int argc, char* argv[])
{
    Book promotion_book;

    promotion_book.author = "Lewis Carroll";
    promotion_book.title = "Alice's adventures in Wonderland";
    promotion_book.publisher = "Macmillan";
    promotion_book.price = 199;
    promotion_book.format = "hardback";
    promotion_book.SetYearOfPublication(1978);

    std::cout << "Year of publication of "
              << promotion_book.title << " is "
              << promotion_book.GetYearOfPublication() << "\n";
}