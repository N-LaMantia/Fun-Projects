// blackjack game in c++
//one of two major projects this summer

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> //swap fn

//defining suits and ranks by putting them in a class
enum class Suit { Hearts, Clubs, Diamonds, Spades};
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, 
Ten, Jack, Queen, King, Ace};

struct Card {
    Suit suit;
    Rank rank; //properties of a card
}; //a card

std::vector<Card> buildDeck() {

    std::vector<Card> deck; 
    for (int s = static_cast<int>(Suit::Hearts); s <= static_cast<int>(Suit::Spades); 
    ++s) {//from hearts to spades...
        for (int r = static_cast<int>(Rank::Two); r <= static_cast<int>(Rank::Ace); ++r) {

            deck.push_back({static_cast<Suit>(s), static_cast<Rank>(r)});

        }

    }
    return deck; 

}//initialized a 52 card deck

void shuffle(std::vector<Card>& deck) {

    srand(static_cast<unsigned int>(time(0))); //randomizer

    for (int i = deck.size() - 1; i > 0; --i) {
        int p = rand() % (i+1); 
        std::swap(deck[i], deck[p]); 
    }

}//shuffling the deck using rand

int valueOfCards (const Card& card) {
    switch (card.rank) {

        case Rank::Two: return 2; 
        case Rank::Three: return 3;
        case Rank::Four: return 4;
        case Rank::Five: return 5;
        case Rank::Six: return 6;
        case Rank::Seven: return 7;
        case Rank::Eight: return 8;
        case Rank::Nine: return 9;
        case Rank::Ten: //return 10
        case Rank::Jack: //return 10
        case Rank::Queen: //return 10
        case Rank::King: return 10; 
        case Rank::Ace: return 11; 
        default: return 0; 
    }


    
} //initializing the value of cards

int handValue(const std::vector<Card>& hand) {

    int value = 0; //current value of hand
    int aces = 0; //number of aces
    for (const Card& card : hand) {
        value += valueOfCards(card);
        if (card.rank == Rank::Ace) {
            aces++; 
        }
    }
    while (value > 21 && aces > 0) {
        value -= 10; //aces can either be 10 or 1
        aces--; 
    }
    return value; 

}

void outputCard(const Card& card) {

    const char* suits[] = { "Hearts", "Diamonds", "clubs", "Spades"}; 
    const char* ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    std::cout << ranks[static_cast<int>(card.rank) - 2] << " of " << suits[static_cast<int>(card.suit)] << std::endl; 

}//outputting a card 

void outputHand(const std::vector<Card>& hand) {
    for (const Card card : hand) {
        outputCard(card); 

    }
    std::cout << "Total value: " << handValue(hand) << std::endl; 
}

int main() {

    std::vector<Card> deck = buildDeck(); //new deck of 52
    shuffle(deck); //shuffle the new deck

    std::vector<Card> player; 
    std::vector<Card> dealer; 
    std::string hitOrStand = " ";

    player.push_back(deck.back()); //picked a card from the deck
    deck.pop_back(); //deck has 51 cards now

    dealer.push_back(deck.back()); //dealer picked card from deck
    deck.pop_back(); //deck has 50 cards now

    player.push_back(deck.back()); //picked a card from the deck
    deck.pop_back(); //deck has 49 cards now

    dealer.push_back(deck.back()); //dealer picked card from deck
    deck.pop_back(); //deck has 48 cards left

    std::cout << "Your hand: " << std::endl; 
    outputHand(player); 
    std::cout << "Dealer's hand: " << std::endl; 
    outputCard(dealer[0]); 
    std::cout << "Hidden card" << std::endl; 


    while (handValue(player) < 21) {
        std::cout << "Do you want to hit or stand? "; 
        std::cin >> hitOrStand; 

        if (hitOrStand == "hit" || hitOrStand == "Hit") {
            player.push_back(deck.back()); 
            deck.pop_back(); 
            std::cout << "You drew "; 
            outputCard(player.back()); 
            outputHand(player); 

        } //if they draw another card
        else if (hitOrStand == "Stand" || hitOrStand == "stand") {

            break;

        }
    } //end while loop 



    if (handValue(player) > 21) { //lose condition
        std::cout << "You lose! Dealer wins." << std::endl; 
        return 0; 
    }

    std::cout << "Dealer's hand: " << std::endl; 
    outputHand(dealer); 
    while (handValue(dealer) < 17) {
        dealer.push_back(deck.back());
        deck.pop_back(); 
        std::cout << "Dealer picked up: ";
        outputCard(dealer.back());
        outputHand(dealer); 

    }

    int playerTOT = handValue(player);
    int dealerTOT = handValue(dealer); 

    if (dealerTOT > 21 || playerTOT > dealerTOT) {
        std::cout << "You win!"; 

    }
    else if (playerTOT < dealerTOT) {
        std::cout << "Dealer wins." << std::endl; 

    }
    else {
        std::cout << "It's a tie." << std::endl; 
    }
    return 0; 
}

