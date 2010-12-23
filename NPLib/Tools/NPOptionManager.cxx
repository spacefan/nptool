/*****************************************************************************
 * Copyright (C) 2009-2010   this file is part of the NPTool Project         *
 *                                                                           *
 * For the licensing terms see $NPTOOL/Licence/NPTool_Licence                *
 * For the list of contributors see $NPTOOL/Licence/Contributors             *
 *****************************************************************************/

/*****************************************************************************
 * Original Author: A. MATTA  contact address: matta@ipno.in2p3.fr *
 *                                                                           *
 * Creation Date  : 21/07/09                                                 *
 * Last update    :                                                          *
 *---------------------------------------------------------------------------*
 * Decription: This class is a singleton class which deals with input        *
 * arguments of the different NPTool programm (NPS and NPA)                  *
 *---------------------------------------------------------------------------*
 * Comment: The singleton form allow users to call the object from anywhere  *
 * in the code                                                               *
 *                                                                           *
 *                                                                           *
 *****************************************************************************/
 
#include "NPOptionManager.h"
 
#include <cstdlib>


NPOptionManager* NPOptionManager::instance = 0 ;

NPOptionManager* NPOptionManager::getInstance(int argc,char** argv)
  {
    if( instance == 0 ) instance = new NPOptionManager(argc,argv);
    
    return instance ;
  }
  
  
//////////////////////////////////////////////////////
NPOptionManager::NPOptionManager(int argc,char** argv)
  {
    // Default Setting
    fReactionFileName    = "myReaction.reaction"  ;
    fDetectorFileName    = "myDetector.detector"  ;
    fOutputFileName      = "myResult"             ;
    fRunToReadFileName   = "RunToRead.txt"        ;
    fCalibrationFileName = "Calibration.txt"      ; 
  
    for (int i = 0 ; i < argc ; i++)
      {
        string argument = argv[i];
        
        if(argument == "-H" || argument == "-h" || argument == "--help") 
          DisplayHelp(); 
              
        else if(argument == "--event-generator" && argc>=i+1 )    fReactionFileName    = argv[i+1] ; 
              
        else if(argument == "-E" && argc>=i+1 )                  fReactionFileName    = argv[i+1] ;
        
        else if(argument == "--detector" && argc>=i+1 )    fDetectorFileName    = argv[i+1] ;
        
        else if(argument == "-D" && argc>=i+1 )    fDetectorFileName    = argv[i+1] ;
        
        else if(argument == "--output" && argc>=i+1 )    fOutputFileName      = argv[i+1] ;
        
        else if(argument == "-O" && argc>=i+1 )    fOutputFileName      = argv[i+1] ;
        
        else if(argument == "--run" && argc>=i+1 )  fRunToReadFileName   = argv[i+1] ;
        
        else if(argument == "-R" && argc>=i+1 )     fRunToReadFileName   = argv[i+1] ;
        
        else if(argument == "--cal" && argc>=i+1 )  fCalibrationFileName = argv[i+1] ;
        
        else if(argument == "-C" && argc>=i+1 )     fCalibrationFileName = argv[i+1] ;
        
        else ;
      }
  
  }

///////////////////////////////////////////////////  
void NPOptionManager::DisplayHelp()
  {
    cout << "----NPOptionManager Help----" << endl ;
    cout << "List of Option " << endl ;
    cout << "\t --detector　-D <arg>\t \t \t \t \t \t　Set arg as the detector configuration file" << endl ;
    cout << "\t --event-generator　-E <arg>\t \t \t \t \t　Set arg as the event generator file" << endl ;
    cout << "\t --cal -C <arg>\t \t \t \t \t \t \t　Set arg as the calibration file list" << endl ;
    cout << "\t --help　-H -h\t \t \t \t \t \t \t　Display this help message" << endl ;
    cout << "\t --output　-O <arg>\t \t \t \t \t \t　Set arg as the Output File Name (output tree)" << endl ;
    cout << "\t --run -R <arg>\t \t \t \t \t \t \t　Set arg as the run to read file list" << endl  ;
    cout << endl << endl ;  

    // exit current program
    exit(1);
  }



void NPOptionManager::Destroy()
{
   if (instance != 0) {
      delete instance;
      instance = 0;
   }
}


