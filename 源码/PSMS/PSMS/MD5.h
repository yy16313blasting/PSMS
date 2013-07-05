#pragma once
#ifndef _CMD5_H
 #define _CMD5_H
 
 //#pragma warning(disable:4786)
 #include "stdafx.h"
 #include <string>

 
 using namespace std;
 
 /*!
  * Manage CMD5.
  */
 class CMD5
 {
 private:
     #define uint8  unsigned char
     #define uint32 unsigned long int
 
     struct CMD5_context
     {
         uint32 total[2];
         uint32 state[4];
         uint8 buffer[64];
     };
 
     void CMD5_starts( struct CMD5_context *ctx );
     void CMD5_process( struct CMD5_context *ctx, uint8 data[64] );
     void CMD5_update( struct CMD5_context *ctx, uint8 *input, uint32 length );
     void CMD5_finish( struct CMD5_context *ctx, uint8 digest[16] );
 
 public:

     //! construct a CMD5 from any buffer
     void GenerateCMD5(unsigned char* buffer,int bufferlen);
 
     //! construct a CMD5
     CMD5();
 
     //! construct a CMD5src from char *
     CMD5(const char * CMD5src);
 
     //! construct a CMD5 from a 16 bytes CMD5
     CMD5(unsigned long* CMD5src);
 
     //! add a other CMD5
     CMD5 operator +(CMD5 adder);
 
     //! just if equal
     bool operator ==(CMD5 cmper);
 
     //! give the value from equer
     // void operator =(CMD5 equer);
 
     //! to a string
     CString ToString();
 
     unsigned long m_data[4];
 };
 #endif /* CMD5.h */