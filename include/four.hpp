#ifndef FOUR_HPP
#define FOUR_HPP

#include <initializer_list>
#include <string>
#include <stdexcept>
#include <iostream>

class Four {
public:
    Four();
    Four(const size_t& n, unsigned char digit);
    Four(const std::initializer_list<unsigned char>& digits);
    Four(const std::string& digits);
    Four(const Four& other);
    Four(Four&& other) noexcept;

    virtual ~Four() noexcept;

    Four& operator=(const Four& other);
    Four& operator=(Four&& other) noexcept;

    Four& operator+=(const Four& other);
    Four& operator-=(const Four& other);
    Four operator+(const Four& other);
    Four operator-(const Four& other);
    
    bool operator==(const Four& other) const;
    bool operator!=(const Four& other) const;
    bool operator<(const Four& other) const;
    bool operator>(const Four& other) const;
    bool operator<=(const Four& other) const;
    bool operator>=(const Four& other) const;

    size_t getSize() const;
    unsigned char *getData() const;

    friend std::ostream &operator<<(std::ostream& os, const Four& obj);

private:
    unsigned char *data_;
    size_t size_;

    void validateFour(unsigned char digit);
};

#endif // FOUR_HPP
