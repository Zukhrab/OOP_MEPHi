//
//  lottoCard2.cpp
//  Lab3.2
//
//  Created by Зухраб Асаханов on 12.10.2022.
//

#include "lotto.hpp"

using namespace std;

namespace lab32
{
    //constructors
    Card::Card()
    {
        linesNumber = 3;

        cages = new Cage*[linesNumber];
        try
        {
            for(size_t i = 0; i < linesNumber; i++)
                cages[i] = new Cage[CAGE_NUMBER];
        }
        catch(bad_alloc& ba)
        {
            cout << "Allocation in  failed: " << ba.what() << endl;
            for(size_t i = 0; i < linesNumber; i++)
                delete cages[i];
            delete cages;

            throw ba;
        }

        for(size_t i = 0; i < linesNumber; i++)
        {
            size_t j;
            for(j = 0; j < CAGE_NUMBER - 7; j++)
            {
                if(1 == rand() % 2 + 1)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = size_t(rand() % 90 + 1);
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;

                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = size_t(rand() % 90 + 1);
                }
                j++;
            }

            for(; j < CAGE_NUMBER - 5; j++)
            {
                if(3 == rand() % 2 + 3)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = size_t(rand() % 90 + 1);
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;

                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = size_t(rand() % 90 + 1);
                }
                j++;
            }

            for(; j < CAGE_NUMBER - 3; j++)
            {
                if(5 == rand() % 2 + 5)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = size_t(rand() % 90 + 1);
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;

                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = size_t(rand() % 90 + 1);
                }
                j++;
            }

            if (j == 8)
            {
                cages[i][j].status = Status::FREE;
                cages[i][j].number = size_t(rand() % 90 + 1);
            }
        }
    }

    Card::Card(size_t numLines)
    {
        linesNumber = numLines;

        cages = new Cage*[linesNumber];
        try
        {
            for(size_t i = 0; i < linesNumber; i++)
                cages[i] = new Cage[CAGE_NUMBER];
        }
        catch(bad_alloc& ba)
        {
            cout << "Allocation in  failed";
            for(size_t i = 0; i < linesNumber; i++)
                delete cages[i];
            delete cages;

            throw ba;
        }

        for(size_t i = 0; i < linesNumber; i++)
        {
            size_t j;
            for(j = 0; j < CAGE_NUMBER - 7; j++)
            {
                if(1 == rand() % 2 + 1)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = size_t(rand() % 90 + 1);
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;

                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = size_t(rand() % 90 + 1);
                }
                j++;
            }

            for(; j < CAGE_NUMBER - 5; j++)
            {
                if(3 == rand() % 2 + 3)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = size_t(rand() % 90 + 1);
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;

                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = size_t(rand() % 90 + 1);
                }
                j++;
            }

            for(; j < CAGE_NUMBER - 3; j++)
            {
                if(5 == rand() % 2 + 5)
                {
                    cages[i][j].status = Status::FREE;
                    cages[i][j].number = size_t(rand() % 90 + 1);
                    cages[i][j + 1].status = Status::EMPTY;
                    cages[i][j + 1].number = 0;

                }
                else
                {
                    cages[i][j].status = Status::EMPTY;
                    cages[i][j].number = 0;
                    cages[i][j + 1].status = Status::FREE;
                    cages[i][j + 1].number = size_t(rand() % 90 + 1);
                }
                j++;
            }

            if (j == 8)
            {
                cages[i][j].status = Status::FREE;
                cages[i][j].number = size_t(rand() % 90 + 1);
            }
        }
    }

    Card::Card(const Card& obj)
    {
        linesNumber = obj.linesNumber;
        cages = new Cage*[linesNumber];
        try
        {
            for(size_t i = 0; i < linesNumber; i++)
                cages[i] = new Cage[CAGE_NUMBER];
        }
        catch(bad_alloc& ba)
        {
            for(size_t i = 0; i < linesNumber; i++) {
                delete cages[i];
            }
            delete cages;

            cout << "Allocation in  failed";

            throw ba;
        }

        for(int i = 0; i < linesNumber;i++)
            for(int j = 0; j < CAGE_NUMBER;j++)
                cages[i][j] = obj.cages[i][j];
    }

    Card::Card(Card&& obj)
    {
        this->linesNumber = obj.linesNumber; // Перекидываем указатели с obj в this
        this->cages = obj.cages;

        obj.linesNumber = 0;                // Обнуляем все указатели у obj, чтобы два обьекта не смотрели на один
        obj.cages = nullptr;                // участок памяти

                                            // Нельзя удалять объект obj, потому что this будем смотреть в пустоту
    }


    //setters
    void Card::setStatus(Status status, size_t lineNumber, size_t cageNumber)
    {
        if(lineNumber < 0)
            throw invalid_argument("setter error1 ...");

        if(cageNumber < 0)
            throw invalid_argument("setter error2 ...");

        if(cages[cageNumber][lineNumber].status == EMPTY)
            throw invalid_argument("setter error3 ...");

        cages[cageNumber][lineNumber].status = status;
    }

    void Card::setNumber(size_t lineNumber, size_t cageNumber, size_t number)
    {
        if(lineNumber < 0)
            throw invalid_argument("setter error1 ...");

        if(cageNumber < 0)
            throw invalid_argument("setter error2 ...");

        if(cages[cageNumber][lineNumber].status == EMPTY)
            throw invalid_argument("setter error3 ...");

        if((number < 1) || (number > 90))
            throw invalid_argument("setter error4 ...");

        cages[cageNumber][lineNumber].number = number;
    }

    void Card::setLineNumber(size_t lnNumber)
    {
        linesNumber = lnNumber;
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

        size_t countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if (kegNumber == cages[countLine][countCage].number)
                    matches++;

        return matches;
    }

    void Card::takeCardCage(size_t kegNumber)
    {
        size_t countLine, countCage;
        for(countLine = 0; countLine < linesNumber; countLine++)
            for(countCage = 0; countCage < CAGE_NUMBER; countCage++)
                if (kegNumber == cages[countLine][countCage].number)
                    cages[countLine][countCage].status = Status::BUSY;
    }

    Status Card::statusOfCard() const
    {
        int busyCages = 0;

        size_t countLine, countCage;
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

        size_t countLine, countCage;
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
        size_t countLine, countCage;
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
        size_t countLine, countCage;
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
        size_t countLine, countCage;
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
        size_t numCard, x, y, number;
        s >> numCard;

        size_t i;
        for (i = 0; i < numCard; i++)
        {
            s >> x >> y >> number;
            cd.setNumber(x, y, number);
        }

        return s;
    };

    Card& Card::operator !()
    {
        size_t countLine, countCage;
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
        size_t i;
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

    Card& Card::operator =(const Card& obj)
     {
        if (linesNumber != obj.linesNumber)             //Если А != А, то присваиваем this->linesNumber = obj.linesNumber;
        {
            linesNumber = obj.linesNumber;

            Cage** tmp
            cages = new Cage *[linesNumber];
            try
            {
                for (size_t i = 0; i < linesNumber; i++)
                    cages[i] = new Cage[CAGE_NUMBER];
            }
            catch (bad_alloc &ba) {
                cout << "Allocation in  failed: " << ba.what() << endl;
                for (size_t i = 0; i < linesNumber; i++)
                    delete cages[i];
                delete cages;

                throw ba;
            }
        }

        for (int i = 0; i < linesNumber; i++)                   //Если А = А, то приссваиваем каждому значению из obj
            for (int j = 0; j < CAGE_NUMBER; j++)               //значение this
                cages[i][j] = obj.cages[i][j];

         for(size_t i = 0; i < linesNumber; i++)                // Потом удаляем объект obj
             delete obj.cages[i];
         delete obj.cages;

        return *this;
    }

    Card& Card::operator =(Card&& obj)
    {
        if ((this->linesNumber == obj.linesNumber) && (this->cages == obj.cages))   //Проверяем случай А = А;
        {
            obj.linesNumber = 0;                                                    //Если А = А, то обнуляем все
            obj.cages = nullptr;                                                    //указатели у obj,
                                                                                    //и просто возвращаем this т.к. А = А
            return *this;
        }
        else                                                                        // Иначе перекидываем указатели,
        {                                                                           // и обнуляем указатели у obj;
            this->linesNumber = obj.linesNumber;
            this->cages = obj.cages;

            obj.linesNumber = 0;
            obj.cages = nullptr;
        }
        return *this;
    }

    //destructor
    Card::~Card()
    {
        for(size_t i = 0; i < linesNumber; i++)
            delete cages[i];
        delete cages;
    }
}