//
//  lottoCard2.hpp
//  Lab3.2
//
//  Created by Зухраб Асаханов on 12.10.2022.
//

#ifndef lottoCard2_hpp
#define lottoCard2_hpp

#include <iostream>

    
namespace lab32
{
    enum Status
    {
        EMPTY,
        FREE,
        BUSY
    };

    struct Cage
    {
        Status status;
        size_t number;
    };

    class Card
    {
        private:
            static const size_t CAGE_NUMBER = 9;
            size_t linesNumber;
            Cage** cages;
            
        public:
            
            //constructors
            Card();
            Card(size_t linesNumber);
            Card(const Card& obj);
            Card(const Card&& obj);
        
            //setters
            void setStatus(Status status, size_t lineNumber, size_t cageNumber);
            void setNumber(size_t lineNumber, size_t cageNumber, size_t number);
        
            //getters
            Status getStatus(size_t lineNumber, size_t cageNumber) const;
            size_t getNumber(size_t lineNumber, size_t cageNumber) const;
            const size_t getLineNumber() const;
            const size_t getCageNumber() const;
            
            //methods
            static size_t kegSelection() { return rand() % 90 + 1; };
            size_t checkMatch(size_t kegNumber) const;
            void showCard() const;
            void takeCardCage(size_t kegNumber);
            void deleteBusyLines();
            Status statusOfCard() const;
            size_t* fallOutCages(size_t kegNumber) const;
            
            //overloaders
            Cage* operator [](size_t lv);
            friend std::ostream& operator <<(std::ostream &s, const Card &cd);
            friend std::istream & operator >>(std::istream &s, Card &cd);
            Card& operator !();
            Status operator ()(size_t lineNumber, size_t cageNumber) const;
            Card& operator +=(Cage *line);
            Card& operator +=(const Card &cd);
            Card operator +(const Card &cd) const;
        
            Card& operator =(const Card& obj) noexcept;
            Card& operator =(const Card&& obj) noexcept;
        
            
            //destructor
            ~Card();
    };

    template <class T>
    int get_num(T& a)
    {
        std::cin >> a;

        while (!std::cin.good())
        {
            if (std::cin.bad())
                throw std::runtime_error("Fatal error");
            
            if (std::cin.eof())
                return 1;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input. Please, try again." << std::endl;
            std::cin >> a;
        }
        return 0;
    }
}


#endif /* lottoCard2_hpp */
