#include <stdio.h>

int main() {
	double enter[9]; //사용자에게 숫자를 입력받습니다.
	char operator[9]; //사용자에게 연산자를 입력받습니다.
	char equal='='; //사용자에게 결과를 출력 하기 위해 등호를 입력받습니다.
	double result; //사용자에게 결과를 출력하기 위해 result를 선언합니다.
	int count;

	while (1) {
		for (count = 0; count < 10; count++) { //사용자에게 숫자를 입력받습니다. max 10개까지.
			scanf_s("%lf", &enter[count]);
			scanf_s(" %c", &operator[count]);
		}

		int count3 = 0; //스택에 저장된 숫자와 연산자를 불러오기 위해 count를 초기화하여 재사용합니다.
		for (int count2 = 0; count2 < count; count2++) //사용자가 입력한 숫자의 개수인 count보다 같아질때 까지 연산합니다.
		{
			if (operator[count3] == '+') { 
				result = enter[count2] + enter[count2 + 1];
				count3++; //계산할 다음 숫자와 연산자를 가져오기 위해 ++
			}
			else if (operator[count3] == '-') {
				result = enter[count2] - enter[count2 + 1];
				count3++;
			}
			else if (operator[count3] == '*') {
				result = enter[count2] * enter[count2 + 1];
				count3++;
			}
			else if (operator[count3] == '/') {
				result = enter[count2] / enter[count2 + 1];
				count3++;
			}
			else if (operator[count3] == '=') {
				printf("%lf\n", result);
				break;
			}
		}
	}
	return 0;

}