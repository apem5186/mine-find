/*
�ڷ� ���� ��ó : https://studyfield.tistory.com/136
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int trapCount(int x, int y);	// ����ī����
void printMap(int x, int y, int count);	// �ֺ� ���� ���� ������ ���� ���
void printAll(void);	// ���ų� �̰��� �� ���ڱ��� ǥ���ؼ� ���� ���
int arr[10][10];		// ���ڸ� ������ ���� ���� �迭
int countarr[10][10];	// �ֺ��� ���ڰ��� ǥ���� �迭
int mine = 0;		// ���ڰ���
int Y = 1;			// main���� while�� �� Ȯ�ο�
int main(void)
{
	srand((unsigned)time(NULL));
	int x, y;
	int count = 0;	// printMap�� �� ���ڰ��� ī���ÿ� ����
	// �ʱ� �� ����
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			countarr[i][j] = -1;	// countarr�迭 -1�� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if ((rand() % 100) < 30) {	// ���� ���ڰ��� Ȯ��
				arr[i][j] = 99;			// ���ڰ� �ִٸ� arr�迭�� ����Ȯ�ο����� 99����
				mine++;					// ���ڰ���++
			}
			else arr[i][j] = 0;			// ���ھ����� 0
		}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf(". ");
		}
		printf("\n");
	}
	while (Y) {	// �¸��� �й�� Y�� 0���� �ٲ�
		printf("��ǥ�� �Է��ϼ���(x, y) : ");
		scanf("%d %d", &x, &y);
		if (arr[x][y] == 99) {	// �й�����
			printAll();
			printf("\n���ڸ� ��ҽ��ϴ�!\n");
			Y = 0;
		}
		else {
			count = trapCount(x, y);	// �ֺ��� ���� ���� �ľǿ� �Լ�
		}
		printMap(x, y, count);	// �Է��� ��ǥ�� ". " ��� �ֺ� ���ڰ����� ��Ÿ�� ������ �ٲ㼭 ���� ���
	}
	return 0;
}

int trapCount(int x, int y)	// �ڵ� ���� : https://studyfield.tistory.com/136
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (x + i < 0 || x + i > 9 || y + j < 0 || y + j > 9) // �� ��ǥ�� 8��� �� ���ڰ� ���ٸ� continue
				continue;
			// ���ڰ� �ִٸ�
			if (arr[x + i][y + j] == 99)
				count++;
		}
	return count;
}
void printMap(int x, int y, int count)
{
	int checkmine = 0;	// �¸������� Ȯ���ϱ����� mine������ ���� ����
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (x == i && y == j) {	// ������ ��ǥ�� �ֺ����ڰ����� ���
				countarr[x][y] = count;
				printf("%d ", countarr[x][y]);
			}
			else {	// ���� printMap�Լ��� ����� ���� �� ������ �Է��� ��ǥ�� ���ڰ��� ���� ������Ŵ
				if (countarr[i][j] != -1) {
					printf("%d ", countarr[i][j]);
				}
				else {	// ������ ". "
					printf(". ");
					checkmine++;	// "."�� ����
				}
			}
		}
		printf("\n");
	}
	if (checkmine == mine) {	// "."�� ������ ������ ������ ���ٸ�(���ڸ� �� ã�Ҵٸ�) �¸�
		printf("\n�¸�!\n");
		printAll();
		Y = 0;
	}
}
void printAll(void)	// �¸��� ���н� ���ڸ� �����ؼ� ���� ���
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 0)	// ���ڰ� �ƴϸ� "." ���
				printf(". ");
			else if (arr[i][j] == 99) {	// ���ڸ� "#" ���
				printf("# ");
			}
		}
		printf("\n");
	}
}