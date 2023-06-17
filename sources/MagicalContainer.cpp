#include "MagicalContainer.hpp"
#include <algorithm>

namespace ariel {

    // AscendingIterator methods

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magicalContainer) 
        : container(magicalContainer), position(0)
    {
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magicalContainer, int position) 
        : container(magicalContainer), position(position)
    {
    }

    MagicalContainer::AscendingIterator::~AscendingIterator() {
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (this != &other) {
            container = other.container;
            position = other.position;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &this->container == &other.container && this->position == other.position;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return this->position > other.position;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return this->position < other.position;
    }

    int MagicalContainer::AscendingIterator::operator*() const {
        // Explicitly cast position to size_type to avoid the warning.
        return container.elements[static_cast<std::vector<int>::size_type>(position)];
    }


    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        
        position += 1;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(container, 0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(container, container.size());
    }


























    // Implementations for SideCrossIterator

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer)
        : container(magicalContainer), position(0){}

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
        : container(other.container), position(other.position), flag(other.flag) {}

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer, int p)
        : container(magicalContainer), position(p) {}

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {
        // No cleanup necessary
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return &this->container == &other.container && this->position == other.position && this->flag == other.flag;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return this->position > other.position;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return this->position < other.position;
    }

    // Dereference operator
    int MagicalContainer::SideCrossIterator::operator*() const {
        if ( !(SideCrossIterator::position % 2)) {
            return container.elements.at(static_cast<std::vector<int>::size_type>(position / 2));
        } else {
            return container.elements.at(static_cast<std::vector<int>::size_type>(container.size() - 1 - (position - 1) / 2));
        }
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if (this != &other) {
            container = other.container;
            position = other.position;
            flag = other.flag;
        }
        return *this;
    }

        // Pre-increment operator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (position >= static_cast<int>(container.size())) {
            throw std::runtime_error("Cannot increment iterator past end of container.");
        }

        if (flag) {
            position = (position + 1) / 2;
        } else {
            position = container.size() - 1 - position;
        }

        flag = !flag;
    
        return *this;
    }

    // Begin method
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(container, 0);
    }

    // End method
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(container, container.size()/2);
    }
























    // Implementations for PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer) : container(magicalContainer), position(0) {}

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer, int position) : container(magicalContainer), position(position) {}

    MagicalContainer::PrimeIterator::~PrimeIterator() {
        // No cleanup necessary
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if (&other != this) {
            this->position = other.position;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &this->container == &other.container && this->position == other.position;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return this->position > other.position;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return this->position < other.position;
    }

    int MagicalContainer::PrimeIterator::operator*() const {
        return container.elements.at(static_cast<std::vector<int>::size_type>(position));
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        do {
            position++;
        } while (position < static_cast<int>(container.elements.size()) && !isPrime(container.elements.at(static_cast<std::vector<int>::size_type>(position))));
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        int startPosition = 0;
        while (startPosition < static_cast<int>(container.elements.size()) && !isPrime(container.elements.at(static_cast<std::vector<int>::size_type>(startPosition)))) {
            startPosition++;
        }
        return PrimeIterator(container, startPosition);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        return PrimeIterator(container, container.elements.size());
    }

    // Function to check if number is prime
    bool MagicalContainer::PrimeIterator::isPrime(int num) const {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i*i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }


}
