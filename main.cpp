#include <iostream>
#include "card.hpp"

int main() {
    Card card = Card("QS");
    std::cout << "Hello, World!" << std::endl;
    std::cout << "This is " << card.rank_bm() << ", " << card.suit();
    std::cout << ", score:" << card.score() << std::endl;
    return 0;
}