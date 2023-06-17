#ifndef ARIEL_MAGICALCONTAINER_HPP
#define ARIEL_MAGICALCONTAINER_HPP

#include <vector>
#include <algorithm>
#include <cmath>

namespace ariel {

    class MagicalContainer {

    private:
        std::vector<int> elements;
        std::vector<int*> pElements;

    public:

        bool contains(int el){
            return true;
        }
        
        void addElement(int element) {
            pElements.clear();
            elements.push_back(element);
            std::sort(elements.begin(), elements.end());

            for(int e : elements){
                if(isPrime(e)){
                    pElements.push_back(&e);
                }
            }
        }

        void removeElement(int element) {
            auto itr = std::find(elements.begin(), elements.end(), element);
            if (itr != elements.end()) {
                elements.erase(itr);
            }
            else{
                throw std::runtime_error("Error");
            }
        }

        int size() const {
            return elements.size();
        }

        // Function to check if number is prime
        bool isPrime(int num) const {
            if (num <= 1) return false;
            if (num == 2) return true;
            if (num % 2 == 0) return false;
            for (int i = 3; i*i <= num; i += 2) {
                if (num % i == 0) return false;
            }
            return true;
        }

        std::vector<int*> getPrimeE(){
            return this->pElements;
        }

        class AscendingIterator {

            private:
                MagicalContainer& container; // Pointer to the MagicalContainer
                int position; // Current position within the container

            public:
                AscendingIterator() = delete; 
                AscendingIterator(AscendingIterator&&) = delete;
                AscendingIterator& operator=(AscendingIterator&&) = delete;

                AscendingIterator( MagicalContainer &, int);
                AscendingIterator( MagicalContainer& magicalContainer);
                AscendingIterator(const AscendingIterator& other);// Copy constructor      
                ~AscendingIterator() ;// Destructor    
                AscendingIterator& operator=(const AscendingIterator& other);// Assignment operator   
                bool operator==(const AscendingIterator& other) const;// Equality comparison  
                bool operator!=(const AscendingIterator& other) const;// Inequality comparison   
                bool operator>(const AscendingIterator& other) const;// Greater than comparison  
                bool operator<(const AscendingIterator& other) const;// Less than comparison  
                int operator*() const ;// Dereference operator   
                AscendingIterator& operator++();
                AscendingIterator begin()const;
                AscendingIterator end()const;
        };

        class SideCrossIterator {

            private:
                MagicalContainer& container; // Pointer to the MagicalContainer
                int position; // Current position at the start side
                // int position_end; // Current position at the end side
                bool flag; // Indicator whether the iterator is moving forward or backward

            public:
                SideCrossIterator() = delete; 
                SideCrossIterator(SideCrossIterator&&) = delete;
                SideCrossIterator& operator=(SideCrossIterator&&) = delete;

                SideCrossIterator( MagicalContainer &, int);
                SideCrossIterator( MagicalContainer& magicalContainer) ;                
                SideCrossIterator(const SideCrossIterator& other) ;// Copy constructor       
                //~SideCrossIterator() ;// Destructor              
                SideCrossIterator& operator=(const SideCrossIterator& other);// Assignment operator       
                bool operator==(const SideCrossIterator& other) const ;// Equality comparison               
                bool operator!=(const SideCrossIterator& other) const ;// Inequality comparison               
                bool operator>(const SideCrossIterator& other) const ;// Greater than comparison               
                bool operator<(const SideCrossIterator& other)const;// Less than comparison               
                int operator*() const ; // Dereference operator                
                SideCrossIterator& operator++() ; 

                //void addElement(int element);

                SideCrossIterator begin()const;
                SideCrossIterator end()const;

                ~SideCrossIterator();
        };

        class PrimeIterator {

            private:
                MagicalContainer& container; // Pointer to the MagicalContainer
                int position; // Current position in the container
                
            public:
                PrimeIterator() = delete; 
                PrimeIterator(PrimeIterator&&) = delete;
                PrimeIterator& operator=(PrimeIterator&&) = delete;

                PrimeIterator(MagicalContainer &, int);
                PrimeIterator(MagicalContainer& magicalContainer);
                PrimeIterator(const PrimeIterator& other);// Copy constructor
                ~PrimeIterator();// Destructor 
                PrimeIterator& operator=(const PrimeIterator& other);// Assignment operator
                bool operator==(const PrimeIterator& other) const ;// Equality comparison 
                bool operator!=(const PrimeIterator& other) const ;// Inequality comparison
                bool operator>(const PrimeIterator& other) const ;// Greater than comparison   
                bool operator<(const PrimeIterator& other) const ;// Less than comparison  
                int operator*() const ;// Dereference operator
                PrimeIterator& operator++() ;
                void addElement(int element);
                bool isPrime(int num) const;


                PrimeIterator begin()const;
                PrimeIterator end()const;
        };
    };

}

#endif //ARIEL_MAGICALCONTAINER_HPP
