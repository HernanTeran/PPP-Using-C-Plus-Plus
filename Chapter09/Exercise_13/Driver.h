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
	void driver();
	char calc_again(const std::string& message);
}

#endif // DRIVER_H
