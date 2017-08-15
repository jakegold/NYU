/* this is us making the vector class!!! we would technically be able to us it but the library one 
is very clearly better
so the first question is what is a vector...we cant actually make it grow..that doesnt make any sense
so what is going to happen is that the vector will be point to something on the heap?
to what???? to an arry!!!!!
but this arry is going to be super super simple...all it does is holds things and just allows me to
see those things and change them...thats it
so how can we push things back?....the pointer that is vector will make a new array...put all the things 
from the first in the second arry...delete the first one and now we have a bigger vector
*/
#include <iostream>
using namespace std;

class Vector{
public:
	Vector(){

	}
}