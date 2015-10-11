#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib> //rand, srand
#include <time.h> //time (for random seed)
#include <stdlib.h> //maloc, realloc (for resizing an array)

#include "map_vec_iterators.h" //print_map and print_linear

using namespace std;




int main(int argc, char* argv[])
{
    //Declaring and populating different containers
    //maps: 3 hard-coded values each
    map<string, int> name_map;
    map<int, int> number_map;

    name_map["Bob Saget"] = 1234;
    name_map["Bob Dylan"] = 3456;
    name_map["Bob Singer"] = 4567;

    number_map[1234] = 4321;
    number_map[2345] = 5432;
    number_map[4567] = 7654;

    //vector: 10 random numbers
    vector<int> test_vector(10);
    srand(time(NULL));
    for(int i = 0; i < test_vector.size(); i++) test_vector.at(i) = rand() % 10000;

    //array: 10 random numbers.
    /*
    We could use the simpler `int test_array[]` syntax, but as discussed in class, 
     an array declared like this is equivalent to `const int *`.

     By using a pointer to an integer (`int *`), we can reassign it to a different
     block of memory (to copy + resize the array).

     This is essentially what vectors do... without all this work.
    */ 
    int test_array_size = 10;
    int *test_array = (int*)malloc(test_array_size * sizeof(int)); //Bare pointer to a block of memory!
    if (test_array == NULL) // malloc failed
    {
        cout << "Error allocating memory for array." << endl;
        return 1;
    }
    for(int i = 0; i < test_array_size; i++) test_array[i] = rand() % 10000;

    //Displaying all of the containers' contents
    cout << "Initial values of data structures:" << endl;
    cout << "name_map contains:" << endl;
    print_map(name_map);
    
    cout << endl;
    cout << "number_map contains:" << endl;
    print_map(number_map);
    
    cout << endl;
    cout << "test_vector contains: " << endl;
    print_linear(test_vector, 0, test_vector.size()-1);

    cout << endl;
    cout << "test_array contains: " << endl;
    print_linear(test_array, 0, test_array_size - 1);

    //Adding members to each container
    cout << endl << "Adding some new values." << endl;
    //maps: Just use brackets to add a key.
    name_map["Bob Charles"] = 5678;
    number_map[5678] = 8765;
    
    //vector: we can use push_back. The vector will automatically resize
    test_vector.push_back(rand() % 10000);
    
    //array: Oops! It's full. We have to resize it.
    //look at how miserably complicated this is. Use a freakin' vector!
    
    //get a pointer to a new block of memory (realloc will copy old contents)
    int *tmp_array = (int*)realloc(test_array, (test_array_size + 1) * sizeof(int));
    if (tmp_array == NULL) //Make sure realloc succeeded
    {
        cout << "Error reallocating memory for array resizing." << endl;
        return 2;
    }
    
    test_array = tmp_array;         //array now points to the new block of memory
    test_array[10] = rand() % 10000; //adding the new element
    test_array_size += 1;           //increase our array length variable
    
    //Displaying the containers again after extending them
    cout << "New values: " << endl;
    cout << "name_map contains:" << endl;
    print_map(name_map);
    
    cout << endl;
    cout << "number_map contains:" << endl;
    print_map(number_map);
    
    cout << endl;
    cout << "test_vector contains: " << endl;
    print_linear(test_vector, 0, test_vector.size()-1);

    cout << endl;
    cout << "test_array contains: " << endl;
    print_linear(test_array, 0, test_array_size - 1);

    return 0;
}
