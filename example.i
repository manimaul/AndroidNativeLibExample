/* Example.i */
 %module ExampleModule
 %include "std_string.i"
 %{
/* Includes the header in the wrapper code */
 #include "Example.h"
 %}

/* Parse the header file to generate wrappers */
 %include "Example.h"