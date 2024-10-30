/*
Defines a Card class suitable for representing a standard playing card, which 
is identified by two components: a rank and a suit. The rank is stored as an 
integer between 1 and 13 in which an ace is a 1, a jack is an 11, a queen is a 
12, and a king is 13. The suit is one of the four constants in the following 
enumeration type:
enum Suit = { CLUBS, DIAMONDS, HEARTS, SPADES };
The Card class should export the following methods:
• A default constructor that creates a card that can later be assigned a value
• A constructor that takes a short string name like "10S" or "JD"
• A constructor that takes separate values for the rank and the suit
• A toString method that returns the short string representation of the card
• The getter methods getRank and getSuit
Write the card.h interface and the card.cpp implementation necessary 
to export the Card class. In addition to the Card class itself, the card.h
interface should export the Suit type, constant names for the ranks that are 
usually named rather than numbered (ACE, JACK, QUEEN, KING), and any other 
definitions you need to run the following main program:
int main() {
 for (Suit suit = CLUBS; suit <= SPADES; suit++) {
 for (int rank = ACE; rank <= KING; rank++) {
 cout << " " << Card(rank, suit);
 }
 cout << endl;
 }
 return 0;
}
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;


enum class Suit{
    CLUBS, 
    DIAMONDS, 
    HEARTS, 
    SPADES,
    UNDEFINED,
};

enum class Rank{
    ACE = 1,
    SKIP_2,SKIP2,SKIP3,SKIP4,
    SKIP_5,SKIP6,SKIP7,SKIP8,
    SKIP9,SKIP10,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
};

Suit& operator++(Suit& s, int){
    switch(s){
        case Suit::CLUBS:
            s = Suit::DIAMONDS;
            break;
        case Suit::DIAMONDS:
            s = Suit::HEARTS;
            break;
        case Suit::HEARTS:
            s = Suit::SPADES;
            break;
        case Suit::SPADES:
            s = Suit::UNDEFINED;
            break;
    }
    return s;
}

class Card{
public:
    Card(){};
    Card(string str){
        string rank_str = str.substr(0, str.length() - 1);
        char suit_str = str.at(str.length() - 1);
        this->_setRank(rank_str);
        this->_setSuit(suit_str);
    }
    Card(int rank, Suit s){
        this->rank = rank;
        suit = s;
    }
    string toString(){
        string rank_str;
        char suit_char;
        switch(rank){
            case 1:
                rank_str = "A";
                break;
            case 11:
                rank_str = "J";
                break;
            case 12:
                rank_str = "Q";
                break;
            case 13:
                rank_str = "K";
                break;
            default:
                rank_str = to_string(rank);
        }

        switch(suit){
            case Suit::CLUBS:
                suit_char = 'C';
                break;
            case Suit::DIAMONDS:
                suit_char = 'D';
                break;
            case Suit::HEARTS:
                suit_char = 'H';
                break;
            case Suit::SPADES:
                suit_char = 'S';
                break;
        }
        return rank_str + string(1, suit_char);

    }
    bool _isAllDigit(string& str){
        for(auto &item : str){
            if(!isdigit(item))
                return false;
        }
        return true;
    }
    void _setRank(string rank_str){
        if(this->_isAllDigit(rank_str)){
            rank = stoi(rank_str);
        }
        else{
            if(rank_str == "A")
                rank = 1;
            else if (rank_str == "J")
                rank = 11;
            else if (rank_str == "Q")
                rank = 12;
            else if (rank_str == "k")
                rank = 13;
        }
    }
    void _setSuit(char suit_str){
        switch(suit_str){
            case 'C':
                suit = Suit::CLUBS;
                break;
            case 'D':
                suit = Suit::DIAMONDS;
                break;
            case 'H':
                suit = Suit::HEARTS;
                break;
            case 'S':
                suit = Suit::SPADES;
        }
    }
    int getRank(){
        return rank;
    }
    Suit getSuit(){
        return suit;
    }
    friend ostream& operator<<(ostream& output, Card&& c);
    friend ostream& operator<<(ostream& output, Card& c);
private:
    int rank;
    Suit suit;
};
ostream& operator<<(ostream& output, Card&& c){
    output << c.toString();
    return output;
}

ostream& operator<<(ostream& output, Card& c){
    output << c.toString();
    return output;
}

int main(){
    for (Suit suit = Suit::CLUBS; suit <= Suit::SPADES; suit++) {
        for (int rank = static_cast<int>(Rank::ACE); rank <= static_cast<int>(Rank::KING); rank++) {
            cout << " " << Card(rank, suit);
        }
        cout << endl;
    }
 return 0;
}