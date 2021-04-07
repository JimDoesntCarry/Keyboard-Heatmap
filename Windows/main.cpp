#include <iostream>
#include <windows.h>
#define LENGTH 500

using namespace std;

int main()
 {
   HANDLE hstdin;
   DWORD  mode;
   int keys[LENGTH];
   int i = 0;

  hstdin = GetStdHandle( STD_INPUT_HANDLE );
  GetConsoleMode( hstdin, &mode );
  SetConsoleMode( hstdin, ENABLE_ECHO_INPUT | ENABLE_PROCESSED_INPUT );  // see note below 

  for(i= 0; i < LENGTH; i++){
    keys[i]=0;
  }


  cout << "Press any key..." << "\n" << flush;
  while(true){
      int ch = cin.get();
      keys[ch]++;

      if(ch == 13){
        break;
      }
  }

  for(i= 0; i < LENGTH; i++){
    if(keys[i] > 0){
      switch(i){
        case 13: cout << "Key " << "Enter" << " pressed " << keys[i] << " times!" << "\n";break;
        case 32: cout << "Key " << "Space" << " pressed " << keys[i] << " times!" << "\n";break;
        case 97: cout << "Key " << "A" << " pressed " << keys[i] << " times!" << "\n";break;
        case 115: cout << "Key " << "S" << " pressed " << keys[i] << " times!" << "\n";break;
        case 100: cout << "Key " << "W" << " pressed " << keys[i] << " times!" << "\n";break;
        case 119: cout << "Key " << "D" << " pressed " << keys[i] << " times!" << "\n";break;
        
        default: cout << "Key " << i << " pressed " << keys[i] << " times!" << "\n";break;
      }
       
     
    }
  }
  
   SetConsoleMode( hstdin, mode );
   return 0;
  }
