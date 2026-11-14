//2026.11.12: 기초 뼈대 잡기
//2026.11.14: [1]배열 크기 초과 오류 수정 (double enter[9]; => double enter[100];), [2]반복문 break; 추가, [3]기존의 마지막 숫자만 계산되던 오류를 누적 계산이 result 변수를 통해 누적 계산이 되도록 수정, [4]사칙연산 적용

#define _CRT_SECURE_NO_WARNINGS  //scanf등으로 인한 경고가 뜨는 것을 무시하기 위한 코드, https://shek.tistory.com/49
#include <stdio.h>

int main() {
    double enter[100];    // 숫자들을 저장할 배열
    char operator[100];   // 연산자들을 저장할 배열
    double result;
    int count;

    while (1) {
        printf("\n계산 수식을 입력하세요 (예: 1 + 2 * 3 = ): \n");

        // 1. = 이 나올 때까지 입력받기
        for (count = 0; count < 100; count++) {
            scanf("%lf", &enter[count]);
            scanf(" %c", &operator[count]);

            if (operator[count] == '=') {
                break; 
            }
        }

        // 2. 계산 (수정기록 2-3, 2-4)
        for (int i = 0; i < count; i++) {
            if (operator[i] == '*' || operator[i] == '/') {
                if (operator[i] == '*') {
                    enter[i] = enter[i] * enter[i + 1];
                }
                else if (operator[i] == '/') {
                    if (enter[i + 1] == 0) {
                        printf("오류: 0으로 나눌 수 없습니다.\n");
                        break;
                    }
                    enter[i] = enter[i] / enter[i + 1];
                }

                
                for (int j = i; j < count - 1; j++) {
                    enter[j + 1] = enter[j + 2];
                    operator[j] = operator[j + 1];
                }
                count--; 
                i--;     
            }
        }

        
        result = enter[0];

        for (int i = 0; i < count; i++) {
            if (operator[i] == '+') {
                result = result + enter[i + 1];
            }
            else if (operator[i] == '-') {
                result = result - enter[i + 1];
            }
        }

        // 3. 결과 출력
		printf("결과: %.15g\n", result); // 만약 소수점 아래 숫자가 있다면 소수점 이하 15자리까지 출력, 없으면 정수만 출력(%.15g)
    }

    return 0;
}
