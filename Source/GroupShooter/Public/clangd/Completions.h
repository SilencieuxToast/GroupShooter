#pragma once

// These headers are only for clangd editor completions. They should not be compiled by UBT.
// The .clangd file defines CLANGD=1 and -include's this header.
// Paste the contents provided by "Unreal Clangd: Open 'Add Completions' Files (regular)" below.
#ifdef CLANGD

// --- Begin Regular Completions (paste from extension) ---
/*
* addCompletions.h - Adds any 'non-macro' completion. Does NOT cause code completion file loading slowness.
*
* *** NOTE: This file will have Intellisense errors/warnings when opened directly. *****
*
* *** NOTE: Edits/Editions won't work until you reload the file or press the bottom left 'UC' button twice (Do it twice to get back to same setting it was on).
*/

// This is only an example. The file below isn't included by default for code completion and is commented out here.
// Usually you'll use 'FMath::' for your math library. This example is here to show that you can add custom completions if needed.
// #include "Kismet/KismetMathLibrary.h"
// --- End Regular Completions ---

#endif // CLANGD
