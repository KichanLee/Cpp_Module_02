/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kichlee <kichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:51:36 by kichlee           #+#    #+#             */
/*   Updated: 2023/12/17 17:42:33 by kichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointVaule(0){
}

Fixed::~Fixed(){
}

Fixed::Fixed(const int num){             
    this->fixedPointVaule = num << bit;   
}

Fixed::Fixed(float num){  
    (this->fixedPointVaule) = roundf((float)(num * 256));   
}

Fixed::Fixed(const Fixed &rhs):fixedPointVaule(rhs.fixedPointVaule){
}

Fixed& Fixed::operator=(const Fixed &rhs){
    if(this != &rhs)
        this->fixedPointVaule = rhs.fixedPointVaule;
    return (*this);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return Fixed(fixedPointVaule + rhs.fixedPointVaule);
}
Fixed Fixed::operator-(const Fixed &rhs) const
{
    return Fixed(fixedPointVaule - rhs.fixedPointVaule);
}
Fixed Fixed::operator*(const Fixed &rhs) const
{   
       return Fixed(float( float(((fixedPointVaule) * (rhs.fixedPointVaule)) / 256 ) / 256));
}  
  // return Fixed(float(((fixedPointVaule) * (rhs.fixedPointVaule))/256)/256));
Fixed Fixed::operator/(const Fixed &rhs) const
{   
    return Fixed(fixedPointVaule / rhs.fixedPointVaule);
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (fixedPointVaule > rhs.fixedPointVaule);   
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (fixedPointVaule < rhs.fixedPointVaule);   
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (fixedPointVaule >= rhs.fixedPointVaule);   
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (fixedPointVaule <= rhs.fixedPointVaule);   
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (fixedPointVaule == rhs.fixedPointVaule);   
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (fixedPointVaule != rhs.fixedPointVaule);   
}

Fixed& Fixed::operator++(void)
{
    this->fixedPointVaule++;

    return (*this);
}

const   Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixedPointVaule++;
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    this->fixedPointVaule--;
    return (*this);
}

const   Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixedPointVaule++;
    return (temp);
}




int Fixed::getRawBits(void) const{
       return this->fixedPointVaule;
}
void   Fixed::setRawBits(int const raw){
   
    this->fixedPointVaule = raw;
}

int     Fixed::toInt(void)     const{
    return (this->fixedPointVaule >> bit);
}

float Fixed::toFloat(void) const {
    return (float)this->fixedPointVaule / (1 << bit);
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
    
    os << rhs.toFloat();
    return os;
}

           