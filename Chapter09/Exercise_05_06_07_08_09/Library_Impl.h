// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Library_Impl
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 9 Exercises 5 - 9
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Driver that runs the program.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef LIBRARY_IMPL_H
#define LIBRARY_IMPL_H
#pragma once

#include "Book.h"
#include "Patron.h"
#include "Library.h"

#include <iostream>
#include <string>
#include <exception>

namespace Local_Library
{
	void print_lib(const Library& lib);
	void driver(const std::string& inv_b, const std::string& inv_p, const std::string& inv_l);
	char cont_loop(const std::string& prompt);
}

#endif // LIBRARY_IMPL_H
