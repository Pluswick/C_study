#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkScore(int mScore, int cScore)
{
	printf("\n-------------------------");
	printf("\n현재 각 플레이어의 점수입니다.");
	printf("\n플레이어의 점수 : %d", mScore);
	printf("\n컴퓨터의 점수 : %d", cScore);
	printf("\n-------------------------");
}

void showEnding(int mScore, int cScore)
{
	printf("\n-------------------------");
	printf("\n최종 점수입니다.");
	printf("\n플레이어의 점수 : %d", mScore);
	printf("\n컴퓨터의 점수 : %d", cScore);
	if (mScore > cScore) {
		printf("\n따라서 플레이어의 승리입니다.");
	}
	else if (mScore == cScore) {
		printf("\n무승부입니다.");
	}
	else {
		printf("\n따라서 컴퓨터의 승리입니다.");
	}
	printf("\n-------------------------");
}

int main()
{
	int diceCount = 0;
	int diceEnd = 3;
	int mScore = 0;
	int cScore = 0;
	int selection;
	srand((unsigned)time(NULL));

	printf("게임 설명 : 주사위를 총 3 번 굴려 합친 주사위 눈의 합이 더 높은 사람이 이기게 됩니다.");
	printf("\n주사위 게임을 시작하겠습니다.");
	printf("\n------------------------");

	while (diceCount < diceEnd)
	{
		printf("\n주사위를 굴려주세요. 1번 주사위 굴리기 2번 현재 눈의 합 확인하기 : ");
		scanf_s("%d", &selection);

		if (selection == 1)
		{
			int mResult = (rand() % 6) + 1;
			int cResult = (rand() % 6) + 1;

			mScore += mResult;
			cScore += cResult;

			printf("\n플레이어의 차례입니다. 주사위를 굴립니다.");
			printf("\n주사위의 눈은 %d 입니다.", mResult);
			printf("\n현재 총 점수는 %d 입니다.", mScore);

			printf("\n컴퓨터의 차례입니다. 주사위를 굴립니다.");
			printf("\n주사위의 눈은 %d 입니다.", cResult);
			printf("\n현재 총 점수는 %d 입니다.", cScore);

			diceCount++;
		}
		else if (selection == 2)
		{
			checkScore(mScore, cScore);
		}
		else
		{
			printf("\n잘못 입력하셨습니다.");
		}
	}

	showEnding(mScore, cScore);

	return 0;
}