// $Header$
//----------------------------------------------------------------------------------------------------------------------------------
//                                               Main
//----------------------------------------------------------------------------------------------------------------------------------
// Chapter 21 Exercises 9 & 10
//
// Author: Hernan Teran
// Created: 2021/02/09
//
/*
* Define an Order class with (customer) name, address, data, and vector<Purchase> members.
* Purchase is a class with a (product) name, unit_price, and count members.
* Define a mechanism for reading and writing Orders to and from a file.
* Define a mechanism for printing Orders.
* Create a file out of at least ten Orders, read it into a vecotr<Order>, sort it by name
* (of customer), and write it back out to a file.
* Create another file of at least ten Orders of which about a third are the same as in the first file,
* read it into a list<Order>, sort it by address (of customer), and write it back out to a file.
* Merge the two files into a third using std::merge().
* Compute the total value of the orders in the two files.
* The value of an individual Purchase is its unit_price * count.
*/
//----------------------------------------------------------------------------------------------------------------------------------
#ifndef MAIN_H
#define MAIN_H
#pragma once

#include "Order_Data.h"

#endif // MAIN_H
