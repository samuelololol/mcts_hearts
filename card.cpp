#include "card.hpp"

Card::Card (std::string card) :
   card_string(card),
   rank_char_p(card[0]),
   suit_char_p(card[1]),
   rank_value_bm_p(rank_to_bm[card[0]]),
   suit_idx_p(suit_to_idx[card[1]])
{}

int Card::rank_bm() { return this->rank_value_bm_p; }

char Card::suit() { return this->suit_char_p; }

int Card::suit_idx() { return this->suit_idx_p; }

int Card::score(bool expose_ah)
{
    if (3 == suit_idx_p)
        if (expose_ah)
            return 2;
        else
            return 1;
    if ((2 == suit_idx_p)  && (this->rank_value_bm_p & 1024))  //QS
        return 13;
    return 0;
}

std::map<char, int> Card::rank_to_bm = {
    {'2', 1}, {'3', 2}, {'4', 4}, {'5', 8}, {'6', 16}, {'7', 32} , {'8', 64},
    {'9', 128}, {'T', 256}, {'J', 512}, {'Q', 1024}, {'K', 2048}, {'A', 4096}
};

std::map<char, int> Card::suit_to_idx = {
    {'C', 0}, {'D', 1}, {'S', 2}, {'H', 3}
};


bool Cards::in(Card card) {
    return this->bitmap_p[card.suit_idx()] & card.rank_bm();
}

bool Cards::in(std::vector<Card>) {
    return false;
}

bool Cards::greater(Card) {
    return false;
}

bool Cards::less(Card) {
    return false;
}

Cards::Cards() { }

Cards::Cards(std::vector<Card> cards) {
    for (auto card: cards) {
        this->cards_p.push_back(card);
        this->bitmap_p[card.suit_idx()] |= card.rank_bm();
    }
}
