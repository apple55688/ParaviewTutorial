#ifndef __BinReader_h
#define __BinReader_h

#include "vtkImageAlgorithm.h" 

class BinReader : public vtkImageAlgorithm
{
public:
  static BinReader* New();
  vtkTypeMacro(BinReader, vtkImageAlgorithm);
  
  void PrintSelf(ostream& os, vtkIndent indent) override;

  vtkSetStringMacro(FileName);
  vtkGetStringMacro(FileName);

protected:
  BinReader();
  ~BinReader() override;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

private:
  char* FileName;

  BinReader(const BinReader&) = delete;
  void operator=(const BinReader&) = delete;
};

#endif
