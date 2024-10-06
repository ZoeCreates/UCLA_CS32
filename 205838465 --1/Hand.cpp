//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//
#include <iostream>

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{   //if the two cards in hand is a pair
    if(isPair()){
        // both cards in the player's hand are aces, and dealer's card are from 2-10 and ACE
        if (mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::ACE) {
            if ((dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::TEN) || dealerCard.getFace() == Face::ACE) {
                return Choice::SPLIT;
            }
        }
        
        
        
        //10,10
        else if (mCard1.getFace() == Face::TEN && mCard2.getFace() == Face::TEN){
            if((dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::TEN) || dealerCard.getFace() == Face::ACE){
                return Choice::STAND;
            }
        }
        //9,9
        else if(mCard1.getFace() == Face::NINE && mCard2.getFace() == Face::NINE){
            if((dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::SIX) ||(dealerCard.getFace() >= Face::EIGHT && dealerCard.getFace() <= Face::NINE)){
                return Choice::SPLIT;
            }
            else{
                return Choice::STAND;
            }
        }
        //8,8
        else if(mCard1.getFace() == Face::EIGHT && mCard2.getFace() == Face::EIGHT){
            if ((dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::TEN) || dealerCard.getFace() == Face::ACE) {
                return Choice::SPLIT;
            }
        }
        //7,7
        else if(mCard1.getFace() == Face::SEVEN && mCard2.getFace() == Face::SEVEN){
            if (dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::SEVEN) {
                return Choice::SPLIT;
            }
            else if ((dealerCard.getFace() >= Face::EIGHT && dealerCard.getFace() <= Face::TEN) || dealerCard.getFace() == Face::ACE){
                return Choice::HIT;
            }
        }
        //66
        else if(mCard1.getFace() == Face::SIX && mCard2.getFace() == Face::SIX){
            if(dealerCard.getFace() == Face::DEUCE){
                return Choice::SPLITHIT;
            }
            else if (dealerCard.getFace() >= Face::THREE && dealerCard.getFace() <= Face::SIX){
                return Choice::SPLIT;
            }
            else{
                return Choice::HIT;
            }
        }
        //55
        else if(mCard1.getFace() == Face::FIVE && mCard2.getFace() == Face::FIVE){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::NINE){
                return Choice::DOUBLEHIT;
            }
            else{
                return Choice::HIT;
            }
        }
        //44
        else if(mCard1.getFace() == Face::FOUR && mCard2.getFace() == Face::FOUR){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::FOUR){
                return Choice::HIT;
            }
            else if(dealerCard.getFace() >= Face::FIVE && dealerCard.getFace() <= Face::SIX){
                return Choice::SPLITHIT;
            }
            else{
                return Choice::HIT;
            }
        }
        //33, 22 这里有一个疑问是3，2或者2，3的case需不需要考虑到
        else if((mCard1.getFace() == Face::THREE || mCard1.getFace() == Face::DEUCE)&&((mCard2.getFace() == Face::THREE || mCard2.getFace() == Face::DEUCE))){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::THREE){
                return Choice::SPLITHIT;
            }
            else if(dealerCard.getFace() >= Face::FOUR && dealerCard.getFace() <= Face::SEVEN){
                return Choice::SPLIT;
            }
            else{
                return Choice::HIT;
            }
        }
    }
    //if the two cards in hand is soft(one of them is ace)
    else if(isSoft()){
            //A,8
            if((mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::ACE)){
                return Choice::SPLIT;
        }
            else if((mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::EIGHT)){
                 if ((dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::TEN) || dealerCard.getFace() == Face::ACE) {
                    return Choice::STAND;
                }
            }
            //A,7
            else if(mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::SEVEN){
                if (dealerCard.getFace() == Face::DEUCE || dealerCard.getFace() == Face:: SEVEN || dealerCard.getFace() == Face:: EIGHT ) {
                    return Choice::STAND;
                }
                else if (dealerCard.getFace() >= Face::THREE && dealerCard.getFace() <= Face::SIX ){
                    return Choice::DOUBLESTAND;
                }
                else if(dealerCard.getFace() == Face::NINE || dealerCard.getFace() == Face:: TEN || dealerCard.getFace() == Face::ACE ){
                    return Choice::HIT;
                }
            }
            //A, 6
            else if(mCard1.getFace() == Face::ACE && mCard2.getFace() == Face::SIX){
                if (dealerCard.getFace() == Face::DEUCE || (dealerCard.getFace() >= Face:: SEVEN && dealerCard.getFace() <= Face:: TEN) || dealerCard.getFace() == Face::ACE) {
                    return Choice::HIT;
                }
                else if (dealerCard.getFace() >= Face::THREE && dealerCard.getFace() <= Face::SIX ){
                    return Choice::DOUBLEHIT;
                }
            }
            //A5,A4
            else if((mCard1.getFace() == Face::ACE ) && ((mCard2.getFace() == Face::FOUR || mCard2.getFace() == Face::FIVE))){
                if ((dealerCard.getFace() >= Face:: DEUCE && dealerCard.getFace() <= Face:: THREE) || (dealerCard.getFace() >= Face:: SEVEN && dealerCard.getFace() <= Face:: NINE) || dealerCard.getFace() == Face:: ACE )  {
                    return Choice::HIT;
                }
                else if (dealerCard.getFace() >= Face::FOUR && dealerCard.getFace() <= Face::SIX){
                    return Choice::DOUBLEHIT;
                }
            }
            //A3, A2
            else if((mCard1.getFace() == Face::ACE ) && ((mCard2.getFace() == Face::THREE || mCard2.getFace() == Face::DEUCE))){
                if ((dealerCard.getFace() >= Face:: DEUCE && dealerCard.getFace() <= Face:: FOUR) || (dealerCard.getFace() >= Face:: SEVEN && dealerCard.getFace() <= Face:: NINE) || dealerCard.getFace() == Face:: ACE )  {
                    return Choice::HIT;
                }
                else if (dealerCard.getFace() >= Face::FIVE && dealerCard.getFace() <= Face::SIX){
                    return Choice::DOUBLEHIT;
                }
            }
        }
    //the case when we have only one sum number our hand according to strategy card
    else{
//these four lines of code are for testing
//        int card1Value = mCard1.getValue();
//        int card2Value= mCard2.getValue();
//        std::cout << "card1 value: " << card1Value << std::endl;
//        std::cout << "card2 value: " << card2Value << std::endl;

        if(mCard1.getValue()+ mCard2.getValue()== 17){
            return Choice::STAND;
        }
        else if(mCard1.getValue()+ mCard2.getValue()== 16){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::SIX){
                return Choice::STAND;
            }
            else if(dealerCard.getFace() >= Face::SEVEN && dealerCard.getFace() <= Face::EIGHT){
                return Choice::HIT;
            }
            else{
                return Choice::SURRENDERHIT;
            }
            
        }
        else if(mCard1.getValue() + mCard2.getValue()== 15){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::SIX){
                return Choice::STAND;
            }
            else if(dealerCard.getFace()== Face::TEN){
                return Choice::SURRENDERHIT;
            }
            else{
                return Choice::HIT;
            }
        }
        else if (mCard1.getValue()+ mCard2.getValue()== 14 || mCard1.getValue()+ mCard2.getValue()== 13){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::SIX){
                return Choice::STAND;
            }
            else if((dealerCard.getFace() >= Face::SEVEN && dealerCard.getFace() <= Face::TEN) || dealerCard.getFace() == Face::ACE ){
                return Choice::HIT;
            }
        }
        else if(mCard1.getValue()+ mCard2.getValue()== 12){
            if(dealerCard.getFace() >= Face::FOUR && dealerCard.getFace() <= Face::SIX){
                return Choice::STAND;
            }
            else{
                return Choice::HIT;
            }
        }
       
        else if(mCard1.getValue()+ mCard2.getValue()== 11){
            return Choice::DOUBLEHIT;
        }
        else if(mCard1.getValue()+ mCard2.getValue()== 10){
            if(dealerCard.getFace() >= Face::DEUCE && dealerCard.getFace() <= Face::NINE){
                return Choice::DOUBLEHIT;
            }
            else{
                return Choice::HIT;
            }
                
        }
        else if(mCard1.getValue()+ mCard2.getValue()== 9){
            
            if(dealerCard.getFace() >= Face::THREE&& dealerCard.getFace() <= Face::SIX){
                return Choice::DOUBLEHIT;
            }
            else{
                return Choice::HIT;
            }
        }
        else if(mCard1.getValue()+ mCard2.getValue()== 8){
            return Choice::HIT;
        }
    }
    
    
    // by default STAND
    Choice c = Choice::STAND;
    return( c );
}

// TODO CS 32 students need to complete this operation
bool Hand::isPair() const
{
    return( mCard1.getFace() == mCard2.getFace() );
}

// TODO CS 32 students need to complete this operation
bool Hand::isSoft() const
{
    return (mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE);
}


}
