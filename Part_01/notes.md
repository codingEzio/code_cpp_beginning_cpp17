
### About ```import```
- Okay, okay, I know, it's not dynamic langs like *Python*,
    - that is the ```import XX; XX.method()```
    - For *C++*, I assume y'all need to check the respective docs?

### Compiling commands
- Here you are 

    ```bash
    # c++1z => C++ 17
    clang++ -Wall -std=c++11 CODE_FILE BIN_NAME
    clang++ -Wall -std=c++14 CODE_FILE BIN_NAME
    clang++ -Wall -std=c++1z CODE_FILE BIN_NAME
    ```

### The *extensions*
- ```.cpp```
- ```.h```  ```.hpp```

### *Statement*
- I havn't *figure it out*, here's an example on the book

    ```c++
    int one { 1 };
    int one {1};
    int one{1};
    int one{
        1
    };
    ```

### ```return``` statements
- ```main()``` is the only func that not writing ```return``` is equivalent to ```return 0;```
    - Any other func with return type ```int``` must **explicitly** ```return``` a value. 

### *Namespace*
- Things that are not defined in a namespace exist in the *global* namespace.

### Variable names 
- Names start with a ```_``` or ```__``` should **NOT** be used.
- Cuz you *might* override the code gen_ed by *compiler* or ur *STL implementation*.

### C++ *Templates* 
- From my point of view, it is 
    - a technique for (auto)generating the repeated code. 
- Some info
    1. There're *function templates*, and *class templates*.
    2. The *Standard Library* uses templates **extensively**.
- A glimpse 

    ```c++
    #include <iostream>
    using namespace std;

    template <class T>
    T max(T a, T b)
    {
    	return a > b ? a : b ;
    }
    int main()
    {
        // This file cannot run correctly right now,
        //  I'll fix it when I've got more knowledge of it.
    	cout << max(1, 2)       << endl ;
    	cout << max('k', 's')   << endl ;
    	cout << max(10.1, 15.2) << endl ;
    }
    ``` 

### Code Style 
- Just an example 

    ```c++
    bool has_it_or_not(int x)
    {
        /*
        No matter which one do you prefer, 
            it's recommended to pick one style 
            and then use it CONSISTENTLY throughout ur code.

        In the real world, 
            you either follow the company policies,
            or on ur personal pref (based on nice linters!).
        */
    }
    ```

### Creating an *Executable*
- It basically a 3-step process
    1. Copy the entire contents of all ```#include``` to ur ```.cpp``` files 
    2. Then ur compiler translates the code into *machine code*
    3. The *linker* combines *all* the *object files* into *ONE* file containing the *complete executable program*.
        - [all] your project typically contains more than one files 
        - [object files] the file contains the machine code 
        - [ONE] the executable binary file 