#include "heap.h"
#include <iomanip>
#include <iostream>

/**************************************************************
void get_list(vector<T> &v, const char *path);

Use: This opens an input file for reading, then reads the items 
from the file and inserts them in a vector. Finally, it closes 
the input file. 

Parameters:
    1.) vector<T> &v
	2.) const char *path
Returns: nothing
***************************************************************/
template <typename T>
void get_list(vector<T> &v, const char *path) {
  // Your implementation goes here!!!

	while(!v.empty())
	 v.pop_back();

	ifstream file;
	file.open(path, ios::in);

	T x;

	while(file >> x)
	{
		v.push_back(x);
	}
	file.close();
}
/**************************************************************
void construct_heap(vector<T> &v, P pred);

Use: It calls the function make_heap() to construct the heap and 
the function sort_heap() to sort the items in the heap using the 
predicate pred

Parameters:
        1.) vector<T> &v
        2.) P pred
Returns: nothing
***************************************************************/
template <typename T, typename P>
void construct_heap(vector<T> &v, P pred) {
  // Your implementation goes here!!!
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

int main() {
  vector<int>    v1;  // heap of integers
  vector<float>  v2;  // heap of floating-pt nums
  vector<string> v3;  // heap of strings

  // print header message
  cout << "\t\t\t*** Heaps and Heapsort - Output ***\n\n";

  // first heap

  cout << "first heap - ascending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, less<int>());
  print_list<int> print1(v1.size(), INT_SZ, INT_LN);
  for_each(v1.begin(), v1.end(), print1);

  cout << "first heap - descending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, greater<int>());
  for_each(v1.begin(), v1.end(), print1);

  // second heap

  cout << "second heap - ascending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, less<float>());
  print_list<float> print2(v2.size(), FLT_SZ, FLT_LN);
  for_each(v2.begin(), v2.end(), print2);

  cout << "second heap - descending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, greater<float>());
  for_each(v2.begin(), v2.end(), print2);

  // third heap

  cout << "third heap - ascending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, less<string>());
  print_list<string> print3(v3.size(), STR_SZ, STR_LN);
  for_each(v3.begin(), v3.end(), print3);

  cout << "third heap - descending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, greater<string>());
  for_each(v3.begin(), v3.end(), print3);

  // print termination message
  cout << "\t\t\t*** end of program execution ***\n\n";
  return 0;
}
/************************************************************** 
print_list(const unsigned &s, const unsigned &w, const unsigned &l, 
  const unsigned &c)

Use: This initializes member values

Parameters:
        1.) const unsigned &s
        2.) const unsigned &w
	3.) const unsigned &l
	4.) const unsigned &c

Returns: nothing
***************************************************************/
template<typename T> print_list<T>::print_list(const unsigned &s, 
                                                const unsigned &w, 
                                                const unsigned &l, 
                                                const unsigned &c)
{
	sz = s; //heap size
	wid = w; // w is the minimum number of chars written in printout
	len = l; //l is the maximum number of items printed in a single line
	cnt = c; // and c is used as a counter with the 
}

/**************************************************************
void print_list<T>::operator()(const T &x)

Use: Prints the values in the formatted asked for in the problem

Parameters:
        1.) const T &x
Returns: nothing
***************************************************************/
template<typename T> void print_list<T>::operator()(const T &x)
{
		cout.width(wid); 
		cout.precision(2);
		cout << fixed << showpoint;

		cout  << setw(wid) << x << " ";
		cnt++;

		if(cnt == sz)
			cout << endl << endl;

		if(cnt %  len == 0)
			cout << endl;
}


