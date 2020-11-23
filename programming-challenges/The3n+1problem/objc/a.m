/*
 * To compile objective-c on the command line:
 *
 * gcc -framework Foundation objc-gcc.m
 *
 * You may have to link with -lobjc or other libs,
 * as required.
 *
 * How to link it
 * > clang -fobjc-arc a.m -o a.out
 */



#import <Foundation/Foundation.h>

int main(int argc, char** argv)
{
  NSLog(@"Testing");
}
