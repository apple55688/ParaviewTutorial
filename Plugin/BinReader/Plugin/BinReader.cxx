#include "BinReader.h"

#include "vtkImageData.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkObjectFactory.h"
#include "vtkStreamingDemandDrivenPipeline.h"

vtkStandardNewMacro(BinReader);

BinReader::BinReader()
{
  this->FileName = nullptr;
}

BinReader::~BinReader()
{
  if (this->FileName)
  {
    delete[] this->FileName;
    this->FileName = nullptr;
  }
}

void BinReader::PrintSelf(ostream& os, vtkIndent indent)
{
  Superclass::PrintSelf(os, indent);
}

int BinReader::RequestData(vtkInformation* request, vtkInformationVector** inputVector, vtkInformationVector* outputVector)
{
  // Get the output image data object.
  vtkInformation* outputInfo = outputVector->GetInformationObject(0);
  vtkImageData* outputData = vtkImageData::SafeDownCast(outputInfo->Get(vtkDataObject::DATA_OBJECT()));

  // Get the file name.
  const char* fileName = this->GetFileName();

  // Open the file.
  FILE* file = fopen(fileName, "rb");

  return 1;
} 
