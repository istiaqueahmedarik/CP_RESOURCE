// C++ implementation of Dynamic Array
#include <iostream>
#include <stdio.h>
using namespace std;

// template <class T> // this is a template class. It's helpful since we don't know what's the data of of the DAL that the user wants (int, float or some user-def Data type
class DynamicArray
{
private:
    int *d_array; // a pointer that we'll use to store whatever data we need
    int max_size; // to store the current array's max possible size (it doubles, remember?)
    int length;   // to store array's current length
public:
    DynamicArray() // a constructor function, it's called whenever a object of this class is created

    {
        // initially allocate a single memory block
        max_size = 2;
        d_array = new int[max_size]; // like int * a = new int [10], this is static
        length = 0;
    }

    // insert a new item to the end of the d_array
    void add(int item)
    {
        if (isFull())
        {
            // create temporary array with double the size of the previous array
            max_size = 2 * max_size;
            int *temp_d_array = new int[max_size];
            cout << "\nDAL Limit reached, new array created, values copied\n"
                 << endl;
            // move all the elements to the temporary d_array
            for (int i = 0; i < length; i++)
            {
                temp_d_array[i] = d_array[i];
            }

            // delete the old d_array
            delete[] d_array;

            // assign temp d_array's ptr to d_array
            d_array = temp_d_array;

            // delete [] temp_d_array;
        }

        // add the new item at the end of the d_array
        // the following portion is out of the if condition, since this will happen for both the cases
        // the if portion contains only the new array declaration and copying portion
        d_array[length] = item;

        length++;
    }

    void printd_array()
    {
        for (int i = 0; i < length; i++)
        {
            cout << d_array[i] << ' ';
        }
        cout << endl;
    }

    // check if the d_array is full
    bool isFull()
    {
        return length == max_size;
    }

    void delete_element(int pos)
    {
        if (pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        int past = d_array[pos];
        for (int i = pos - 1; i < length - 1; i++)
        {
            d_array[i] = d_array[i + 1];
        }
        cout << "Deleted the value in position " << pos << " which was " << past << endl;
        cout << "The current Array is: " << endl;
        length--;
        printd_array();
    }
    void insert_element(int pos, int val)
    {
        if (pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        for (int i = length - 1; i >= pos; i--)
        {
            d_array[i + 1] = d_array[i];
        }
        d_array[pos] = val;
        cout << "Inserted " << val << " in position " << pos << endl;
        cout << "The current Array is: " << endl;
        length++;
        printd_array();
    }
    void delete_matching_values(int val)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (d_array[i] == val)
            {
                count++;
            }
        }
        int *temp_d_array = new int[length - count];
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (d_array[i] != val)
            {
                temp_d_array[j] = d_array[i];
                j++;
            }
        }
        delete[] d_array;
        d_array = temp_d_array;
        length = length - count;
        cout << "Deleted all occurrences of " << val << endl;
        cout << "Total " << count << " items were deleted.\nArray Resized.";
        cout << "The current Array is: " << endl;
        printd_array();
    }
    void Replace_all_matching_values(int val, int new_val)
    {
        int count = 0;
        for (int i = 0; i < length; i++)
        {
            if (d_array[i] == val)
            {
                count++;
                d_array[i] = new_val;
            }
        }
        if (count == 0)
        {
            cout << "No occurrence of " << val << "was found. No Items were replaced." << endl;
            return;
        }
        cout << val << " replaced with " << new_val << ". Total " << count << " replacement." << endl;
        cout << "The current Array is: " << endl;
        printd_array();
    }
    void concate(DynamicArray &dal)
    {
        int *temp_d_array = new int[length + dal.length];
        for (int i = 0; i < length; i++)
        {
            temp_d_array[i] = d_array[i];
        }
        for (int i = length; i < length + dal.length; i++)
        {
            temp_d_array[i] = dal.d_array[i - length];
        }
        delete[] d_array;
        d_array = temp_d_array;
        length = length + dal.length;
        cout << "The current Array is: " << endl;
        printd_array();
    }
    ~DynamicArray() // a destructor function, deallocates memory when the program closes/object is no longer needed
    {
        delete[] d_array;
    }
};

int main()
{

    DynamicArray dal;

    int a, choice;

    while (1)
    {

        cout << "1. Add an element to the array\n 2. Print the array\n 3. Delete an element from a particular position\n 4. Insert an element at a particular position\n 5. Delete all occurrences of a particular value\n 6. Replace all occurrences of a particular value with another value\n 7. Concatenate two arrays\n 8. Exit\n";
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter a num to add: ");
            scanf("%d", &a);
            dal.add(a);

            cout << "The current dynamic array is: ";
            dal.printd_array();
        }

        else if (choice == 2)
        {
            cout << "The current dynamic array is: ";
            dal.printd_array();
        }

        else if (choice == 3)
        {
            // do by yourself
            // Let the user delete the value from a particular position in the DAL.
            cout << "Enter Position to Delete from : ";
            int pos;
            cin >> pos;
            dal.delete_element(pos);
        }

        else if (choice == 4)
        {
            // do by yourself
            // Let the user insert a value into a particular position in the DAL.
            cout << "Enter Position to Insert Into: ";
            int pos;
            cin >> pos;
            cout << "Enter Value to Insert: ";
            int val;
            cin >> val;
            dal.insert_element(pos, val);
        }
        else if (choice == 5)
        {
            // do by yourself
            // Delete ALL matching values. Resize the Dynamic array as per the algorithm shown in class
            // think when it�ll be resized carefully
            cout << "Enter Value to Delete: ";
            int val;
            cin >> val;
            dal.delete_matching_values(val);
        }
        else if (choice == 6)
        {
            cout << "Enter the value to replace: ";
            int val;
            cin >> val;
            cout << "Enter the value to be replaced by: ";
            int new_val;
            cin >> new_val;
            dal.Replace_all_matching_values(val, new_val);
        }
        else if (choice == 7)
        {
            // do by yourself
            /*A unique function that you think can be beneficial for DALs.
             Write appropriate comments on top of your function. */

            DynamicArray dal2;
            int new_array_size;
            cout << "Enter the size of the new array: ";
            cin >> new_array_size;
            for (int i = 0; i < new_array_size; i++)
            {
                int val;
                cout << "Enter value " << i + 1 << ": ";
                cin >> val;
                dal2.add(val);
            }
            dal.concate(dal2);
        }

        else
        {
            printf("\n\t\tProgram Terminated\n\n");
            break;
        }
    }

    return 0;
}
