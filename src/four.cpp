#include "../include/four.hpp"

Four::Four() : data_(nullptr), size_(0) {}

Four::Four(const size_t& n, unsigned char digit)
{
    validateFour(digit);
    size_ = n;
    data_ = new unsigned char[n];
    for (size_t i = 0; i < size_; i++)
    {
        data_[i] = digit;
    }
}

Four::Four(const std::initializer_list<unsigned char>& digits) {
    size_ = digits.size();
    data_ = new unsigned char[size_];
    size_t i = 0;
    for (auto it = digits.end(); it != digits.begin();)
    {
        --it;
        validateFour(*it);
        data_[i++] = *it;
    }
}

Four::Four(const std::string& digits) {
    size_ = digits.size();
    data_ = new unsigned char[size_];
    for (size_t i = 0; i < size_; ++i)
    {
        unsigned char value = digits[size_ - 1 - i] - '0';
        validateFour(value);
        data_[i] = value;
    }
}

Four::Four(const Four& other)
{
    size_ = other.size_;
    data_ = new unsigned char[size_];

    for (size_t i = 0; i < size_; i++)
    {
        data_[i] = other.data_[i];
    }
}

Four::Four(Four&& other) noexcept
{
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.size_ = 0;
}

Four::~Four() noexcept
{
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
}

Four& Four::operator=(const Four& other) {
    if (this == &other) {
        return *this;
    }
    
    unsigned char* new_data = new unsigned char[other.size_];

    for (size_t i = 0; i < other.size_; ++i) {
        new_data[i] = other.data_[i];
    }

    delete[] data_;
    size_ = other.size_;
    data_ = new_data;

    return *this;

}

Four& Four::operator=(Four&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] data_;

    size_ = other.size_;
    data_ = other.data_;

    other.size_ = 0;
    other.data_ = nullptr;

    return *this;   
}

Four& Four::operator+=(const Four& other)
{
    size_t transfer = 0;
    size_t maxsize_ = std::max(size_, other.size_);
    unsigned char *newNumber = new unsigned char[maxsize_ + 1];

    for (size_t i = 0; i < maxsize_; ++i)
    {
        int sum = transfer;
        if (i < size_)
        {
            sum += data_[i];
        }
        if (i < other.size_)
        {
            sum += other.data_[i];
        }
        newNumber[i] = sum % 4;
        transfer = sum / 4;
    }
    if (transfer > 0)
    {
        newNumber[maxsize_] = transfer;
        maxsize_++;
    }

    delete[] data_;
    data_ = newNumber;
    size_ = maxsize_;

    return *this;
}

Four Four::operator+(const Four& other)
{
    size_t transfer = 0;
    size_t maxsize_ = std::max(size_, other.size_);
    unsigned char *newNumber = new unsigned char[maxsize_ + 1];

    for (size_t i = 0; i < maxsize_; i++)
    {
        int sum = transfer;
        if (i < size_)
        {
            sum += data_[i];
        }
        if (i < other.size_)
        {
            sum += other.data_[i];
        }
        newNumber[i] = sum % 4;
        transfer = sum / 4;
    }

    if (transfer > 0)
    {
        newNumber[maxsize_] = transfer;
        maxsize_++;
    }

    Four result;
    result.size_ = maxsize_;
    result.data_ = new unsigned char[maxsize_];

    for (size_t i = 0; i < maxsize_; i++)
    {
        result.data_[i] = newNumber[i];
    }

    delete[] newNumber;

    return result;
}

Four& Four::operator-=(const Four& other)
{
    if (size_ < other.size_)
    {
        throw std::invalid_argument("Сheck size_ of the numbers");
    }
    int transfer = 0;
    for (size_t i = 0; i < size_; i++)
    {
        int currentDigit = data_[i];
        int otherDigit = (i < other.size_) ? (other.data_[i]) : 0;

        int different = currentDigit - otherDigit - transfer;

        if (different < 0)
        {
            different += 4;
            transfer = 1;
        }
        else
        {
            transfer = 0;
        }

        data_[i] = different;
    }
    if (transfer != 0)
    {
        throw std::invalid_argument("Otricial result");
    }

    return *this;
}

Four Four::operator-(const Four& other)
{
    if (size_ < other.size_)
    {
        throw std::invalid_argument("Check size_ of the number");
    }

    Four result = *this;
    int transfer = 0;

    for (size_t i = 0; i < result.size_; ++i)
    {
        int currentDigit = result.data_[i];
        int otherDigit = (i < other.size_) ? other.data_[i] : 0;

        int different = currentDigit - otherDigit - transfer;

        if (different < 0)
        {
            different += 4;
            transfer = 1;
        }
        else
        {
            transfer = 0;
        }

        result.data_[i] = different;
    }

    if (transfer != 0)
    {
        throw std::invalid_argument("Otricial result");
    }

    return result;
}

bool Four::operator==(const Four& other) const
{
    if (size_ != other.size_)
    {
        return false;
    }

    for (size_t i = 0; i < size_; ++i)
    {
        if (data_[i] != other.data_[i])
        {
            return false;
        }
    }
    return true;
}

bool Four::operator!=(const Four& other) const {
    if (size_ == other.size_)
    {
        return false;
    }

    for (size_t i = 0; i < size_; ++i)
    {
        if (data_[i] == other.data_[i])
        {
            return false;
        }
    }
    return true;
}

bool Four::operator<(const Four& other) const
{
    if (size_ < other.size_)
    {
        return true;
    }

    if (size_ > other.size_)
    {
        return false;
    }

    for (size_t i = size_; i > 0; --i)
    {
        int currentDig = data_[i - 1];
        int otherDig = other.data_[i - 1];

        if (currentDig < otherDig)
        {
            return true;
        }
        if (currentDig > otherDig)
        {
            return false;
        }
    }
    return false;
}

bool Four::operator>(const Four& other) const {
    return !(*this < other) && *this != other;
}

bool Four::operator<=(const Four& other) const {
    return *this < other || *this == other;
}

bool Four::operator>=(const Four& other) const {
    return *this > other || *this == other;
}

std::ostream& operator<<(std::ostream &os, const Four& obj)
{
    for (size_t i = obj.size_; i > 0; --i)
    {
        os << static_cast<int>(obj.data_[i - 1]);
    }
    return os;
}

size_t Four::getSize() const {
    return size_;
}

unsigned char* Four::getData() const {
    return data_;
}

void Four::validateFour(unsigned char digit)
{
    if (digit < 0 || digit > 3)
    {
        throw std::invalid_argument("Invalid digit. Digit must be from 0 to 3");
    }
}