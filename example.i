/* Example.i */
 %module ExampleModule
 %{
/* Includes the header in the wrapper code */
 #include "Example.h"
 %}

/* Parse the header file to generate wrappers */
 %include "Example.h"