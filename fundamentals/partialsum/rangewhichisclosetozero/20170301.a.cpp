-*- mode: compilation; default-directory: "~/prj/github/dsalgorithm/partialsum/rangewhichisclosetozero/" -*-
Compilation started at Sun Mar  5 12:12:03

make -k a.out
g++  -c -std=c++11  -o a.o a.cpp -MMD
a.cpp:25:21: error: call to 'abs' is ambiguous
    r = std::min(r, std::abs(psum[i] - psum[i-1]));
                    ^~~~~~~~
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/cmath:664:1: note: 
      candidate function
abs(float __lcpp_x) _NOEXCEPT {return fabsf(__lcpp_x);}
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/cmath:668:1: note: 
      candidate function
abs(double __lcpp_x) _NOEXCEPT {return fabs(__lcpp_x);}
^
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/cmath:672:1: note: 
      candidate function
abs(long double __lcpp_x) _NOEXCEPT {return fabsl(__lcpp_x);}
^
1 error generated.
make: *** [a.o] Error 1
make: Target `a.out' not remade because of errors.

Compilation exited abnormally with code 2 at Sun Mar  5 12:12:03
