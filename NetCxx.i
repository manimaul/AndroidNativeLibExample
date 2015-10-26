/* NetCxx.i */
 %module NetCxxModule
 %include "std_string.i"
 %{
/* Includes the header in the wrapper code */
 #include "NetCxx.h"
 %}

/* Parse the header file to generate wrappers */
 %include "NetCxx.h"