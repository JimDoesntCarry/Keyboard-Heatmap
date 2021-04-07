#include <iostream>
#include <Windows.h>
#define LENGTH 500

using namespace std;

int main()
 {  
    int keys[LENGTH];
    int i = 0;

    for(i= 0; i < LENGTH; i++){
        keys[i]=0;
    }

    while(true){
        if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            keys['A']++;
        }
    
        if(GetKeyState(VK_SHIFT) & 0x8000)
        {
            keys[VK_SHIFT]++;
        }
        if(GetKeyState(VK_RETURN) & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            break;
        }
        printf("Hello\n");
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
                case VK_SHIFT: cout << "Key " << "SHIFT" << " pressed " << keys[i] << " times!" << "\n";break;
                default: cout << "Key " << i << " pressed " << keys[i] << " times!" << "\n";break;
            }
        }
    }

    return 0;
 }
