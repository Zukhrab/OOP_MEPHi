//
//  lottoCard2.cpp
//  Lab3.2
//
//  Created by Зухраб Асаханов on 12.10.2022.
//

#include "lottoCard2.hpp"

using namespace std;

namespace lab32
{
    //constructors
    Card::Card()
    {
        cout << "Enter number of Lotto Card lines" << endl;
        get_num(linesNumber);
        
        if(linesNumber < 1)
            throw invalid_argument("invalid argument");
        
        try
        {
            cages = new Cage*[linesNumber];
        }
        catch(bad_alloc& ba)
        {
            cout << "Allocation in  failed";
            delete cages;
        }
        
        try
        {
            for(int i = 0; i < linesNumber; i++)
                cages[i] = new Cage[CAGE_NUMBER];
        }
        catch(bad_alloc& ba)
        {
            cout << "Allocation in  failed";
            for(int i = 0; i < linesNumber; i++)
                delete cages[i];
            delete cages;
        }
        
        for(int i = 0; i < linesNumber; i++)
        {
            int j;
            for(j = 0; j < CAGE_NUMBER - 7; j++)
            {
                if(1 == rand() % 2 + 1)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = rand() % 90 + 1;
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;
                    
                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = rand() % 90 + 1;
                }
                j++;
            }
            
            for(; j < CAGE_NUMBER - 5; j++)
            {
                if(3 == rand() % 2 + 3)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = rand() % 90 + 1;
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;
                    
                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = rand() % 90 + 1;
                }
                j++;
            }
            
            for(; j < CAGE_NUMBER - 3; j++)
            {
                if(5 == rand() % 2 + 5)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = rand() % 90 + 1;
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;
                    
                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = rand() % 90 + 1;
                }
                j++;
            }
            
            if (j == 8)
            {
                cages[i][j].status = Status::FREE;
                cages[i][j].number = rand() % 90 + 1;
            }
        }
    }

    Card::Card(size_t numLines)
    {
        linesNumber = numLines;
        
        try
        {
            cages = new Cage*[linesNumber];
        }
        catch(bad_alloc& ba)
        {
            cout << "Allocation in  failed";
            delete cages;
        }
        
        try
        {
            for(int i = 0; i < linesNumber; i++)
                cages[i] = new Cage[CAGE_NUMBER];
        }
        catch(bad_alloc& ba)
        {
            cout << "Allocation in  failed";
            for(int i = 0; i < linesNumber; i++)
                delete cages[i];
            delete cages;
        }
        
        for(int i = 0; i < linesNumber; i++)
        {
            int j;
            for(j = 0; j < CAGE_NUMBER - 7; j++)
            {
                if(1 == rand() % 2 + 1)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = rand() % 90 + 1;
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;
                    
                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = rand() % 90 + 1;
                }
                j++;
            }
            
            for(; j < CAGE_NUMBER - 5; j++)
            {
                if(3 == rand() % 2 + 3)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = rand() % 90 + 1;
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;
                    
                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = rand() % 90 + 1;
                }
                j++;
            }
            
            for(; j < CAGE_NUMBER - 3; j++)
            {
                if(5 == rand() % 2 + 5)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = rand() % 90 + 1;
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;
                    
                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = rand() % 90 + 1;
                }
                j++;
            }
            
            if (j == 8)
            {
                cages[i][j].status = Status::FREE;
                cages[i][j].number = rand() % 90 + 1;
            }
        }
    }

    Card::Card(const Card& obj)
    {
        *this = obj;
    }

    Card::Card(const Card&& obj)
    {
        *this = move(obj);
    }
    

    //setters
    void Card::setStatus(Status status, size_t lineNumber, size_t cageNumber)
    {
        if(lineNumber < 0)
            throw invalid_argument("setter error ...");
        
        if(cageNumber < 0)
            throw invalid_argument("setter error ...");
        
        if(cages[cageNumber][lineNumber].status == EMPTY)
            throw invalid_argument("setter error ...");
                
        cages[cageNumber][lineNumber].status = status;
    }

    void Card::setNumber(size_t lineNumber, size_t cageNumber, size_t number)
    {
        if(lineNumber < 0)
            throw invalid_argument("setter error ...");
        
        if(cageNumber < 0)
            throw invalid_argument("setter error ...");
        
        if(cages[cageNumber][lineNumber].status == EMPTY)
            throw invalid_argument("setter error ...");

        if((number < 1) || (number > 90))
            throw invalid_argument("setter error ...");
        
        cages[cageNumber][lineNumber].number = number;
    }


    //getters
    Status Card::getStatus(size_t lineNumber, size_t cageNumber) const
    {
        if(lineNumber < 0)
            throw invalid_argument("getter error ...");
        
        if(cageNumber < 0)
            throw invalid_argument("getter error ...");

        return cages[cageNumber][lineNumber].status;
    }

    size_t Card::getNumber(size_t lineNumber, size_t cageNumber) const
    {
        if(lineNumber < 0)
            throw invalid_argument("getter error ...");
        
        if(cageNumber < 0)
            throw invalid_argument("getter error ...");

        return cages[cageNumber][lineNumber].number;
    }

    const size_t Card::getLineNumber() const { return linesNumber; }
    const size_t Card::getCageNumber() const { return CAGE_NUMBER; }


    //methods
    size_t Card::checkMatch(size_t kegNumber) const
    {
        size_t matches = 0;
        
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if (kegNumber == cages[countLine][countCage].number)
                    matches++;
        
        return matches;
    }

    void Card::takeCardCage(size_t kegNumber)
    {
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if (kegNumber == cages[countLine][countCage].number)
                    cages[countLine][countCage].status = Status::BUSY;
    }

    Status Card::statusOfCard() const
    {
        int busyCages = 0;
        
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
        {
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if (cages[countLine][countCage].status == Status::BUSY)
                    busyCages++;
            
            if (busyCages == 5)
                return Status::BUSY;
        }
        
        return Status::FREE;
    }

    void Card::deleteBusyLines()
    {
        int busyLines = 0;
        
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
        {
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if (cages[countLine][countCage].status == Status::BUSY)
                    busyLines++;
            
            if (busyLines == 5)
                for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                    if (cages[countLine][countCage].status == Status::BUSY)
                    {
                        cages[countLine][countCage].number = 0;
                        cages[countLine][countCage].status = Status::EMPTY;
                    }
        }
    }

    void Card::showCard() const
    {
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
            {
                cout << cages[countLine][countCage].number << ' ';
                cout << cages[countLine][countCage].status << endl;
            }
    }

    size_t* Card::fallOutCages(size_t kegNumber) const
    {
        int matches = 0;
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if ((kegNumber != cages[countLine][countCage].number) && (cages[countLine][countCage].status != Status::EMPTY))
                    matches++;
        
        size_t* capacity = new size_t[matches];
        
        
        int i = 0;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if ((kegNumber != cages[countLine][countCage].number) && (cages[countLine][countCage].status != Status::EMPTY))
                {
                    capacity[i] = kegNumber;
                    i++;
                }
        
        return capacity;
    }
    

    //overloaders
    ostream& operator <<(ostream &s, const Card &cd)
    {
        int countLine, countCage;
        for(countLine = 0; countLine < cd.linesNumber; countLine++)
            for(countCage = 0; countCage < cd.CAGE_NUMBER; countCage++)
            {
                s << cd.cages[countCage][countLine].number << ' ';
                s << cd.cages[countCage][countLine].status << std::endl;
            }
        
        return s;
    };

    istream& operator >>(istream &s, Card &cd)
    {
        int numCard, x, y, number;
        s >> numCard;
        
        int i;
        for (i = 0; i < numCard; i++)
        {
            s >> x >> y >> number;
            cd.setNumber(x, y, number);
        }
        
        return s;
    };

    Card& Card::operator !()
    {
        int countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
            {
                if(cages[countCage][countLine].status == Status::FREE)
                    cages[countCage][countLine].status = Status::BUSY;
                
                if(cages[countCage][countLine].status == Status::BUSY)
                    cages[countCage][countLine].status = Status::FREE;
            }
        
        return *this;
    }

    Cage* Card::operator [](size_t lv)
    {
        return cages[lv];
    }

    Status Card::operator ()(size_t lineNumber, size_t cageNumber) const
    {
        return cages[cageNumber][lineNumber].status;
    }

    Card& Card::operator +=(Cage *line)
    {
        int i;
        for (i = 0; i < CAGE_NUMBER; i++)
        {
            cages[i][linesNumber].status = line[i].status;
            cages[i][linesNumber].number = line[i].number;
        }
        linesNumber++;
        
        return *this;
    }

    Card& Card::operator +=(const Card &cd)
    {
        size_t countLine, countCage, cdCountLine;
        for(countLine = linesNumber; countLine < linesNumber + cd.getLineNumber(); countLine++)
        {
            cdCountLine = countLine - linesNumber;
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
            {
                cages[countCage][countLine].status = cd.cages[countCage][cdCountLine].status;
                cages[countCage][countLine].number = cd.cages[countCage][cdCountLine].number;
            }
        }
        linesNumber += cd.getLineNumber();
        
        return *this;
    }

    Card Card::operator +(const Card &cd) const
    {
        Card newCard;
        size_t countLine, countCage, cdCountLine;
        
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
            {
                newCard.cages[countCage][countLine].status = cages[countCage][countLine].status;
                newCard.cages[countCage][countLine].number = cages[countCage][countLine].number;
            }
        newCard.linesNumber = linesNumber;
        
        for(countLine = newCard.linesNumber; countLine < newCard.linesNumber + cd.getLineNumber(); countLine++)
        {
            cdCountLine = countLine - newCard.linesNumber;
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
            {
                newCard.cages[countCage][countLine].status = cd.cages[countCage][cdCountLine].status;
                newCard.cages[countCage][countLine].number = cd.cages[countCage][cdCountLine].number;
            }
        }
        newCard.linesNumber += cd.getLineNumber();
        
        return newCard;
    }

    Card& Card::operator =(const Card& obj) noexcept
    {
        if (&obj == this)
            return *this;

        for(int i = 0; i < linesNumber; i++)
            delete cages[i];
        
        delete cages;

        *this = obj;

        return *this;
    }

    Card& Card::operator =(const Card&& obj) noexcept
    {
        if (&obj == this)
            return *this;

        for(int i = 0; i < linesNumber; i++)
            delete cages[i];
        delete cages;

        *this = move(obj);

        return *this;
    }
    
    //destructor
    Card::~Card()
    {
        for(int i = 0; i < linesNumber; i++)
            delete cages[i];
        delete cages;
    }
}
