#include <iostream>
#include <string>
using namespace std;

struct Link
{
	string value;
	Link* prev;
	Link* succ;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		: value{v}, prev{p}, succ{s} {}
};

Link* insert(Link* p, Link* n)
// insert n before p
{
	if (!n) return p;  // can't insert into a nullptr
	if (!p) return n;  // can't insert into a nullptr
	n->succ = p;       // p comes after n
	if (p->prev)       // readjust p's pointer so its actually pointing to something (n)
		p->prev->succ = n;
	n->prev = p->prev; // p's predecessor becomes n's predecessor (p->prev is a pointer that needed to be updated)
	p->prev = n;       // n becomes p's predecessor
	return n;

}

int main()
{
	/*
	* (1) Link* norse_gods = new Link{"Thor", nullptr, nullptr};
	* 
	* (1) Here "Thor" is just a string value. Nothing points to it. The Link*
	* points to it in that the pointer is pointing to the object as a whole.
	* That's why the -> operator is used because its one of the member access operators.
	* the prev and succ pointer point to nothing (nullptr)
	* 
	* (2) norse_gods = new Link{"Odin", nullptr, norse_gods};
	* 
	* (2) Here the pointer to the class object is moved to point to a new version of it.
	* The current string value is "Odin". prev is still pointing to nothing (nullptr).
	* succ is now pointing to the old class object where: prev=nullptr, value="Thor", succ=nullptr
	* 
	* (3) norse_gods->succ->prev = norse_gods;
	* 
	* (3) Up until now the memory looks like: prev=nullptr, value="Odin", succ=old Link* where prev=nullptr,val="Thor",succ=nullptr
	* Here the the current class object first accesses the pointer succ which is pointing to the old Link* object.
	* Then the object's prev pointer is accessed which points to nullptr.
	* The prev pointer is then assigned to point to the new norse_gods Link* object
	* 
	* (4) norse_gods = new Link{"Freia", nullptr, norse_gods};
	* 
	* (4) Here a new Link object is created once again with its own set of 2 new pointers.
	* Its prev points to nothing (nullptr) and its succ points to the old norse_gods class object
	* And that norse_gods object hold the other set of pointers where prev points to nothing and succ points to Thor
	* 
	* (5) norse_gods->succ->prev = norse_gods;
	* 
	* (5) Once again the old norse_gods object is accessed and then its prev pointer is accessed and
	* is made to point to the new norse_gods object because Odin comes before Thor now instead of nullptr Thor
	*/

	Link* norse_gods = new Link{ "Thor" };
	norse_gods = insert(norse_gods, new Link{ "Odin" });
	norse_gods = insert(norse_gods, new Link{ "Freia" });

	delete norse_gods;
	
	return 0;
}
