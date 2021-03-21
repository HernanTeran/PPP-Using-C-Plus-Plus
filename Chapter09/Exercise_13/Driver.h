// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Driver
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Excercise 13
//
// Author: Hernan Teran
// Created: 2021/03/21
//
/*
* Design and implement a rational number class, Rational.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef DRIVER_H
#define DRIVER_H
#pragma once

#include "Rational.h"
#include "Expression.h"

#include <iostream>
#include <string>

namespace Algebra
{
	void driver(const std::string& menu, const std::string& message, const std::string& error);
	Expression get_expression();
	void print_calc(const Expression& expression);
	char calc_again(const std::string& message);
}

#endif // DRIVER_H
