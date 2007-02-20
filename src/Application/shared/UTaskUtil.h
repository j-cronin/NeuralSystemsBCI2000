/* (C) 2000-2007, BCI2000 Project
/* http://www.bci2000.org
/*/
//---------------------------------------------------------------------------

#ifndef UTaskUtilH
#define UTaskUtilH
//---------------------------------------------------------------------------

// these functions are to get block-randomized numbers
// they contain static variables, so be careful when using
// them at more than one place
int     GetBlockRandomizedNumber( int blocksize );
void    ShuffleBlocks( int blocksize );
float   ran1( long *idum );
void    InitializeBlockRandomizedNumber();
// VK adding
void	ResetBlockCounter();
#endif


