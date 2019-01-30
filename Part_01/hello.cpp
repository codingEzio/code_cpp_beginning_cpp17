#include <iostream>
#include <iomanip>
#include <cmath>

namespace Boilerplate
{
/*
    Code within must be called with a prefix.
    
    =>  endl	    // using namespace NAMESPACE_NAME;
    =>  std::endl	// default 
*/
}

namespace InitAndAuto
{

/*
        All stmts here are valid.
            int p_init(3.14);
            int c_init = 3.14;
            int s_init {3.14};

        The last one is much safer.
    */

/*
        unsigned    like 'count students' (pos-num only)
        signed      by default 
    */

/*
        Bi-endian  VS  Little-endian 

        Umm, most of time it doesn't matter (said by author)
        It does matters when (how u interprete)
            processing binary data that is from another PC.
    */

/*
         `auto` and `{}`

         The `auto` is used to "let compiler deduct its type".
         Such as 
             auto m (10)     =>  int 
             auto n = 20UL	=>  unsigned long 

         Brief example
             // Yep
             auto VAR = VAL;
             auto VAR (VAL);

             // Nope
             auto VAR {VAL};
             auto VAR = {VAL};
    */
auto w = 10;
auto h(10);
auto a{10};    // avoid using this
auto t = {10}; // it's a list not an int :P
} // namespace InitAndAuto

namespace IntroCharacter
{

/*
        Unicode in C++
        ->  wchar_t 
        ->  char16_t
        ->  char32_t
    */

// Normal `char` type
char c1;
char c2{65};
char c3{'Y'};

// It's still `char`, but a much much wider range :D
wchar_t w1{L'Я'};      // prefix with a 'L'
wchar_t w2{L'\x0438'}; // the 'w' means 'wide'

/*  Ah, I dunno why it doesn't print correctly (None)
        For the "wider" characters,
        y'all need to use `wcout` (& `wcin`)
*/
// std::wcout << w1 << std::endl;
// std::wcout << w2 << std::endl;

// => UTF-16, UTF-32
char16_t cw1{u'Я'};
char32_t cw2{u'\x044f'};
} // namespace IntroCharacter

int main()
{
    // Compile & run this file by
    //  clang++ -Wall -std=c++11 YOUR_FILE -o BIN_NAME

    {
        // But, there ARE taboos
        //  you should NOT use them if its names like these
        int i = _CLOCK_UPTIME_RAW;
        int j = __SIG_ATOMIC_MAX__;

        // #TODO To know why there's `{}`
        int lucky_number{42};

        // Similarly, there's also a `>>`
        //  that is used to "reads data from a stream".
        std::cout << "The '_CLOCK_UPDATE_RAW' equals "
                  << i
                  << std::endl;

        // Division
        std::cout << "Here's the result: "
                  << 7 / 3 % 2
                  << " (-> should be '0')"
                  << ", "
                  << 10.0 / 4
                  << std::endl;

        // 0b, 0, 0x, 00'00'01
        std::cout << "Mixed: "
                  << 0b11111110 + 0b0000'0001 + 010 + 0x10
                  << ", "
                  << 1 + 2U + 3L + 4UL + 5'5'5
                  << ", "
                  << 010
                  << std::endl;

        // Zero init
        int t1{};
        float t2{};
        std::cout << "[initial values]: "
                  << t1 << ", "
                  << t2 << ", "
                  << std::endl;

        // Constant
        const char aha[]{"aha!"};
        std::cout << "[const]: "
                  << aha
                  << std::endl;

        // initial val & expression
        int apple_pie{10};
        int apple_pie_plus{apple_pie + 5};

        // These are the bad examples
        //  For 'beyond_limit',
        //      if u use `int`, the compiler will raise errors
        //  For 'not_the_right_type',
        //      it'll try to convert the required type.
        long int beyond_limit{400'0000'0000};
        int not_the_right_type{'200'};
        std::cout << "[bad examples]: "
                  << beyond_limit << ", "
                  << not_the_right_type << ", "
                  << std::endl;
    }

    {
        // Properties of the fundamental types
        std::cout << std::numeric_limits<float>::min() << ", "
                  << std::numeric_limits<char16_t>::max() << ", "
                  << std::numeric_limits<double>::infinity() << ", "
                  << std::numeric_limits<double>::quiet_NaN() << ", "
                  << std::endl;

        // Do note the differences between 'int' & 'float'
        // For type 'double'
        //  min()       ->  2.22507e-308	(still positive btw)
        //  lowest()    ->  -1.79769e+308	(hugely neg number!)
        std::cout << std::numeric_limits<int>::min() << ", "
                  << std::numeric_limits<int>::lowest() << ", "
                  << std::numeric_limits<double>::min() << ", "
                  << std::numeric_limits<double>::lowest() << ", "
                  << std::endl;
    }

    {
        // Explicit type conversion

        double d1{10.0};
        double d2{5.5};
        int d_resultOne{
            static_cast<int>(d1) +
            static_cast<int>(d2)}; // => 2 (10 / 5)

        int d_resultTwo{
            static_cast<int>(d1 + d2) // => 15 (15.5)
        };

        // Inexplicit type conversion

        /*
            The one having the wider range 
                will assimilate all the other operands :D 

            The ranks 
                long double, double, float,
                unsigned long long, long long,      
                unsigned long,      long          
                unsigned int,       int
        */
        int x{20u};     // -> unsigned internally
        unsigned y{30}; // -10 => max(unsigned) - 10

        std::cout << x - y << " Surprise!!\n"
                  << std::endl;
    }

    {
        // Formatting stream output

        /*
            Some of methods here were 
                imported by `#include <iomanip>`

            Most 'manipulator' remains in effect until you change it.
                The only exception is the `std::setw()` (only the next). 
        */
        std::cout << std::setprecision(10)
                  << std::setw(15)
                  << std::fixed << 30.75 << ", "
                  << std::scientific << 30.75 << ", "
                  << std::defaultfloat << 30.75 << ", "
                  << std::hex << 30 << ", "
                  << std::showbase
                  << std::hex << 30 << "\n"
                  << std::endl;
    }

    {
        long rand_num{};
        int ra{}, rb{}, rc{5}, rd{4};

        ra = rc;
        rb = rd;
        rand_num = ra * rb;

        // Simple calculation :D
        std::cout << std::dec << rand_num << std::endl;
    }

    {
        // Just use 'double' !
        float pi_f{3.1415926F};
        double pi_d{3.14159265358979};
        long double pi_ld{3.14159265358979323L};

        // Other types of valid literals
        double sci_int{5E3};
        double sci_flt{5.5E3};
        double sci_int_ng{10E-2};
        double sci_flt_ndot{.001E3};

        std::cout << sci_int << ", "
                  << sci_flt << ", "
                  << sci_int_ng << ", "
                  << sci_flt_ndot << ",\n"
                  << std::endl;

        // Those invalid floating-point results
        double mem1{10}, mem2{}, mem3{0};

        // => inf
        double res_inf_divnone{mem1 / mem2};
        double res_inf_divzero{mem1 / mem3};

        // => nan
        double res_nan_optinf{res_inf_divnone - res_inf_divzero};
        double res_nan_dbzero{mem3 / mem3};

        std::cout << res_inf_divnone << ", "
                  << res_inf_divzero << ", "
                  << std::endl;

        std::cout << res_nan_optinf << ", "
                  << res_nan_dbzero << ", "
                  << std::endl;

        // Check whether it's valid or not (<cmath>)
        std::cout << std::isinf(res_inf_divnone) << ", "  // => 1
                  << std::isnan(res_nan_dbzero) << ", \n" // => 1
                  << std::endl;
    }

    {
        // Math functions

        std::cout << abs(20) << ", " << abs(-3.5) << ", "
                  << ceil(3.9) << ", " << ceil(-3.9) << ", "
                  << floor(3.9) << ", " << floor(-3.9) << ", "
                  << "\n"
                  << exp(1) << ", " << log(exp(1)) << ", " << log10(10)
                  << "\n"
                  << pow(10, 4) << ", " << sqrt(25)
                  << "\n"
                  << round(13) << ", " << round(13.6) << ", " << round(13.67) << ", "
                  << std::endl;
    }

    return 0;
}