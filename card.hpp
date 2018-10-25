#include <iostream>
#include <string>
#include <map>
#include <vector>

class Card {
    int rank_value_bm_p;
    char rank_char_p;

    int suit_idx_p; // CDSH
    char suit_char_p;
    std::string card_string;

    static std::map<char, int> rank_to_bm;
    static std::map<char, int> suit_to_idx;
public:
    Card(std::string);

    int rank_bm();
    char suit();
    int suit_idx();
    virtual int score(bool expose_ah=false);
};

class Cards {
    std::vector<int> bitmap_p = {0, 0, 0, 0}; //CDSH
    std::vector<Card> cards_p;
public:
    Cards ();

    Cards (std::vector<Card>);

    bool in(Card);
    bool in(std::vector<Card>);
    bool greater(Card);
    bool less(Card);
};
