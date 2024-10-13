#include <array>
#include <math.h>
#include <iostream>
#include "interp.cpp"

int main(){
	//eq3
	std::array<float, 3> args3;
	std::array<float, 3> val3;
	for(int pw = 1; pw > -5; pw--){
		for(int i = 0; i < 3; i++){
			args3[i] = i / (2.f);
			// std::cout << args3[i] << " ";
		}
		for(int i = 0; i < 3; i++){
			args3[i] *= pow(2, pw);
			val3[i] = exp(args3[i]);
			// std::cout << args3[i] << " ";
		}
		// std::cout << "\n";

		newtonInterp<float, float, 3> in3(args3, val3);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(in3.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(in3.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//cheb3
	std::array<float, 3> cheb3;
	for(int pw = 1; pw > -5; pw--){
		for(size_t i = 0; i < 3; i++){
			cheb3[2-i] = cos((2.f * i + 1) / 2 / 3 * M_PI);
			// std::cout << cheb3[i] << " ";
		}
		for(size_t i = 0; i < 3; i++){
			// cheb3[i] *= pow(2, pw);
			cheb3[i] = (cheb3[i] + 1) / 2 * pow(2, pw);
			val3[i] = exp(cheb3[i]);
			// std::cout << cheb3[i] << " ";
		}
		// std::cout << "\n";

		newtonInterp<float, float, 3> ch3(cheb3, val3);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(ch3.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(ch3.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//eq4
	std::array<float, 4> args4;
	std::array<float, 4> val4;
	for(int pw = 1; pw > -5; pw--){
		for(int i = 0; i < 4; i++){
			args4[i] = i / (3.f);
		}
		for(int i = 0; i < 4; i++){
			args4[i] *= pow(2, pw);
			val4[i] = exp(args4[i]);
		}

		newtonInterp<float, float, 4> in4(args4, val4);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(in4.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(in4.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//cheb4
	std::array<float, 4> cheb4;
	for(int pw = 1; pw > -5; pw--){
		for(size_t i = 0; i < 4; i++){
			cheb4[3-i] = cos((2.f * i + 1) / 2 / 4 * M_PI);
		}
		for(size_t i = 0; i < 4; i++){
			cheb4[i] = (cheb4[i] + 1) / 2 * pow(2, pw);
			val4[i] = exp(cheb4[i]);
		}

		newtonInterp<float, float, 4> ch4(cheb4, val4);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(ch4.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(ch4.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//eq5
	std::array<float, 5> args5;
	std::array<float, 5> val5;
	for(int pw = 1; pw > -5; pw--){
		for(int i = 0; i < 5; i++){
			args5[i] = i / (4.f);
		}
		for(int i = 0; i < 5; i++){
			args5[i] *= pow(2, pw);
			val5[i] = exp(args5[i]);
		}

		newtonInterp<float, float, 5> in5(args5, val5);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(in5.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(in5.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//cheb5
	std::array<float, 5> cheb5;
	for(int pw = 1; pw > -5; pw--){
		for(size_t i = 0; i < 5; i++){
			cheb5[4-i] = cos((2.f * i + 1) / 2 / 5 * M_PI);
		}
		for(size_t i = 0; i < 5; i++){
			cheb5[i] = (cheb5[i] + 1) / 2 * pow(2, pw);
			val5[i] = exp(cheb5[i]);
		}

		newtonInterp<float, float, 5> ch5(cheb5, val5);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(ch5.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(ch5.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//ermit
	//eq3
	for(int pw = 1; pw > -5; pw--){
		for(int i = 0; i < 3; i++){
			args3[i] = i / (2.f);
		}
		for(int i = 0; i < 3; i++){
			args3[i] *= pow(2, pw);
			val3[i] = exp(args3[i]);
		}

		ermitInterp<float, float, 3> ein3(args3, val3, val3);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(ein3.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(ein3.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//eq4
	for(int pw = 1; pw > -5; pw--){
		for(int i = 0; i < 4; i++){
			args4[i] = i / (3.f);
		}
		for(int i = 0; i < 4; i++){
			args4[i] *= pow(2, pw);
			val4[i] = exp(args4[i]);
		}

		ermitInterp<float, float, 4> ein4(args4, val4, val4);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(ein4.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(ein4.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";

	//eq5
	for(int pw = 1; pw > -5; pw--){
		for(int i = 0; i < 5; i++){
			args5[i] = i / (4.f);
		}
		for(int i = 0; i < 5; i++){
			args5[i] *= pow(2, pw);
			val5[i] = exp(args5[i]);
		}

		ermitInterp<float, float, 5> ein5(args5, val5, val5);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(ein5.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw))) > err)
				err = abs(ein5.interp(i / 1000.f * pow(2, pw)) - exp(i / 1000.f * pow(2, pw)));
		}	
		std::cout << pow(2, pw) << " " << err << "\n";
	}
	std::cout << "\n";
}