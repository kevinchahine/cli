// cli.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "cli.h"


// This is an example of an exported variable
CLI_API int ncli=0;

// This is an example of an exported function.
CLI_API int fncli(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
Ccli::Ccli()
{
    return;
}
