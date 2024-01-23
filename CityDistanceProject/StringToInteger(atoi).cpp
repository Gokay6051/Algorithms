#include<iostream>
#include <cctype> 
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string numstr;
        //numstr = "  ";
        int i;
        int num;
        int signFlag;
        signFlag = 0;
        num = 0;
        char strcopy;
     
		
		// sayidan onceki bosluklari atliyor
		for(i=0; i<s.length(); ++i){
			if(s[i] != ' '){
				break;
			}
		}

        // negatif pzitif kontrolu
		if(s[i] == '-' && isdigit(s[i+1])){
			signFlag = -1;	
            ++i;
		}
        if(s[i] == '+' && isdigit(s[i+1])){
			signFlag = 0;	
            ++i;
		}

        

        //sayinin onundeki 0lari atliyor
		for(; i<s.length(); ++i){
			if(s[i] != '0')
				break;
		}
	
        while(i < s.length() && s[i] != '\"' && isdigit(s[i])){
			numstr = numstr + s[i];
			++i;
            
		}




        if(numstr.length() >= 10){
			if(numstr.length() == 10){
				if(signFlag == 0){
                    if(numstr[0] == '3' || numstr[0] == '4' || numstr[0] == '5' || numstr[0] == '6' || numstr[0] == '7' || numstr[0] == '8' || numstr[0] == '9') {
                        numstr = "";
                        num = 2147483647;
                    }
                    else if(numstr[1] == '2' || numstr[1] == '3' || numstr[1] == '4' || numstr[1] == '5' || numstr[1] == '6' || numstr[1] == '7' || numstr[1] == '8' || numstr[1] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[2] == '5' || numstr[2] == '6' || numstr[2] == '7' || numstr[2] == '8' || numstr[2] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[3] == '8' || numstr[3] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[4] == '5' || numstr[4] == '6' || numstr[4] == '7' || numstr[4] == '8' || numstr[4] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[5] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[6] == '4' || numstr[6] == '5' || numstr[6] == '6' || numstr[6] == '7' || numstr[6] == '8' || numstr[6] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[7] == '7' || numstr[7] == '8' || numstr[7] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'&&  numstr[6] != '0' && numstr[6] != '1' && numstr[6] != '2'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[8] == '5' || numstr[8] == '6' || numstr[8] == '7' || numstr[8] == '8' || numstr[8] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'&&  numstr[6] != '0' && numstr[6] != '1' && numstr[6] != '2' && numstr[7] != '0' && numstr[7] != '1' && numstr[7] != '2'&& numstr[7] != '3' && numstr[7] != '4'&& numstr[7] != '5'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                    else if(numstr[9] == '8' || numstr[9] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'&&  numstr[6] != '0' && numstr[6] != '1' && numstr[6] != '2' && numstr[7] != '0' && numstr[7] != '1' && numstr[7] != '2'&& numstr[7] != '3' && numstr[7] != '4'&& numstr[7] != '5'  && numstr[8] != '0' && numstr[8] != '1' && numstr[8] != '2' && numstr[8] != '3'){
                            numstr = "";
                            num = 2147483647;
                        }
                    }
                }




                else{
                    if(numstr[0] == '3' || numstr[0] == '4' || numstr[0] == '5' || numstr[0] == '6' || numstr[0] == '7' || numstr[0] == '8' || numstr[0] == '9') {
                        numstr = "";
                        num = -2147483648;
                    }
                    else if(numstr[1] == '2' || numstr[1] == '3' || numstr[1] == '4' || numstr[1] == '5' || numstr[1] == '6' || numstr[1] == '7' || numstr[1] == '8' || numstr[1] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[2] == '5' || numstr[2] == '6' || numstr[2] == '7' || numstr[2] == '8' || numstr[2] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[3] == '8' || numstr[3] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[4] == '5' || numstr[4] == '6' || numstr[4] == '7' || numstr[4] == '8' || numstr[4] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[5] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[6] == '4' || numstr[6] == '5' || numstr[6] == '6' || numstr[6] == '7' || numstr[6] == '8' || numstr[6] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[7] == '7' || numstr[7] == '8' || numstr[7] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'&&  numstr[6] != '0' && numstr[6] != '1' && numstr[6] != '2'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[8] == '5' || numstr[8] == '6' || numstr[8] == '7' || numstr[8] == '8' || numstr[8] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'&&  numstr[6] != '0' && numstr[6] != '1' && numstr[6] != '2' && numstr[7] != '0' && numstr[7] != '1' && numstr[7] != '2'&& numstr[7] != '3' && numstr[7] != '4'&& numstr[7] != '5'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                    else if(numstr[9] == '8' || numstr[9] == '9') {
                        if(numstr[0] != '0' && numstr[0] != '1' && numstr[1] != '0' && numstr[2] != '0' && numstr[2] != '1' && numstr[2] != '2' && numstr[2] != '3' && numstr[3] != '0' && numstr[3] != '1' && numstr[3] != '2' && numstr[3] != '3' && numstr[3] != '4' && numstr[3] != '5'&& numstr[3] != '6' && numstr[4] != '0' && numstr[4] != '1' && numstr[4] != '2' && numstr[4]!= '3' && numstr[5] != '0' && numstr[5] != '1' && numstr[5] != '2' && numstr[5] != '3' && numstr[5] != '4' && numstr[5] != '5'&& numstr[5] != '6' && numstr[5] != '7'&&  numstr[6] != '0' && numstr[6] != '1' && numstr[6] != '2' && numstr[7] != '0' && numstr[7] != '1' && numstr[7] != '2'&& numstr[7] != '3' && numstr[7] != '4'&& numstr[7] != '5'  && numstr[8] != '0' && numstr[8] != '1' && numstr[8] != '2' && numstr[8] != '3'){
                            numstr = "";
                            num = -2147483648;
                        }
                    }
                }
			}




			else{
				if(signFlag == -1){
            		num = -2147483648;
                    numstr = "";
        		}
        		else{
        			num = 2147483647;
                    numstr = "";
				}
			}	
		}

		if(numstr != ""){
            
			for(int j=0; j<numstr.length(); ++j){
				switch(numstr[j]) {
				case '0':
					break;
				case '1':
					num += 1;
					break;
				case '2':
					num += 2;
					break;
				case '3':
					num += 3;
					break;
				case '4':
					num += 4;
					break;
				case '5':
					num += 5;
					break;
				case '6':
					num += 6;
					break;
				case '7':
					num += 7;
					break;
				case '8':
					num += 8;
					break;
				case '9':
					num += 9;
					break;
				}
                if(isdigit(numstr[j+1]))
                    num *= 10;
				
			}
			
            
		}
        if(signFlag == -1 && num != -2147483648){
            num *= -1;
        }
        
        return num;
    }
};
















