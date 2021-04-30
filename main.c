/*
자료 참조 출처 : https://studyfield.tistory.com/136
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int trapCount(int x, int y);	// 지뢰카운팅
void printMap(int x, int y, int count);	// 주변 지뢰 개수 포함한 맵을 띄움
void printAll(void);	// 지거나 이겼을 시 지뢰까지 표현해서 맵을 띄움
int arr[10][10];		// 지뢰를 포함할 맵을 만들 배열
int countarr[10][10];	// 주변의 지뢰개수 표시할 배열
int mine = 0;		// 지뢰개수
int Y = 1;			// main문의 while문 값 확인용
int main(void)
{
	srand((unsigned)time(NULL));
	int x, y;
	int count = 0;	// printMap에 쓸 지뢰개수 카운팅용 변수
	// 초기 맵 생성
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			countarr[i][j] = -1;	// countarr배열 -1로 초기화
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if ((rand() % 100) < 30) {	// 맵의 지뢰개수 확률
				arr[i][j] = 99;			// 지뢰가 있다면 arr배열에 지뢰확인용으로 99대입
				mine++;					// 지뢰개수++
			}
			else arr[i][j] = 0;			// 지뢰없으면 0
		}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf(". ");
		}
		printf("\n");
	}
	while (Y) {	// 승리나 패배시 Y를 0으로 바꿈
		printf("좌표를 입력하세요(x, y) : ");
		scanf("%d %d", &x, &y);
		if (arr[x][y] == 99) {	// 패배조건
			printAll();
			printf("\n지뢰를 밟았습니다!\n");
			Y = 0;
		}
		else {
			count = trapCount(x, y);	// 주변에 지뢰 개수 파악용 함수
		}
		printMap(x, y, count);	// 입력한 좌표를 ". " 대신 주변 지뢰개수를 나타낸 정수로 바꿔서 맵을 띄움
	}
	return 0;
}

int trapCount(int x, int y)	// 코드 참조 : https://studyfield.tistory.com/136
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (x + i < 0 || x + i > 9 || y + j < 0 || y + j > 9) // 한 좌표의 8방면 중 지뢰가 없다면 continue
				continue;
			// 지뢰가 있다면
			if (arr[x + i][y + j] == 99)
				count++;
		}
	return count;
}
void printMap(int x, int y, int count)
{
	int checkmine = 0;	// 승리조건을 확인하기위해 mine변수와 비교할 변수
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (x == i && y == j) {	// 지정한 좌표에 주변지뢰개수를 띄움
				countarr[x][y] = count;
				printf("%d ", countarr[x][y]);
			}
			else {	// 이후 printMap함수를 재실행 했을 때 이전에 입력한 좌표의 지뢰개수 값을 유지시킴
				if (countarr[i][j] != -1) {
					printf("%d ", countarr[i][j]);
				}
				else {	// 나머진 ". "
					printf(". ");
					checkmine++;	// "."의 개수
				}
			}
		}
		printf("\n");
	}
	if (checkmine == mine) {	// "."의 개수가 지뢰의 개수랑 같다면(지뢰를 다 찾았다면) 승리
		printf("\n승리!\n");
		printAll();
		Y = 0;
	}
}
void printAll(void)	// 승리나 패패시 지뢰를 포함해서 맵을 띄움
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 0)	// 지뢰가 아니면 "." 출력
				printf(". ");
			else if (arr[i][j] == 99) {	// 지뢰면 "#" 출력
				printf("# ");
			}
		}
		printf("\n");
	}
}