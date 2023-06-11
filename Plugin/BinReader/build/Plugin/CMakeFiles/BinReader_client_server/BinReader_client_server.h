#ifndef BinReader_client_server_h
#define BinReader_client_server_h

#include "vtkClientServerInterpreter.h"

extern "C" void vtkBinReaderCS_Initialize(vtkClientServerInterpreter*);

inline void BinReader_client_server_initialize(vtkClientServerInterpreter* csi)
{
  (void)csi;
  vtkBinReaderCS_Initialize(csi);
}

#endif
