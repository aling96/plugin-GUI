#ifndef __CEREBUSTHREAD_H_D9135C03__
#define __CEREBUSTHREAD_H_D9135C03__

#include "../../../JuceLibraryCode/JuceHeader.h"
#include <ftdi.h>
#include <stdio.h>
#include "DataThread.h"

class SourceNode;

/**
    Interface to the Cerebus Demo Board.
     
    @see SourceNode, DataThread
*/
class CerebusThread : public DataThread
{
public:
    CerebusThread (SourceNode* sn);
    ~CerebusThread();
    
    bool foundInputSource() override;
    
    float getSampleRate()   const override;
    float getBitVolts()     const override;
    
    int getNumEventChannels()   const override;
    
    int getNumChannels()   const;
   
private:
    bool updateBuffer() override;
    
    bool startAcquisition() override;
    bool stopAcquisition()  override;
    
    bool initializeUSB (bool);
    bool closeUSB();
    
    struct ftdi_context ftdic;
    
    int vendorID, productID;
    int baudrate;
    
    bool isTransmitting;
    bool deviceFound;
    
    unsigned char startCode, stopCode;
    unsigned char buffer[240]; //5 samples per channel
    
    float thisSample[17]; //1 continuous channel, one event channel
    
    int ch;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CerebusThread);

};


#enddif // __CEREBUSTHREAD_H_D9135C03
