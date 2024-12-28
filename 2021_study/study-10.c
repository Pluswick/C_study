#include <stdio.h>

typedef struct _student { // 학생 구조체 선언

    int stunum; // 학생번호
    double hei; // 키
    double wei; // 몸무게

}st;

int main() {
    int N, i;
    double heiavg = 0.0, weiavg = 0.0; // 평균 초기화
    st member[10] = { '\0', 0, 0.0 }; // 구조체 초기화

    scanf("%d", &N); // 학생수 입력받습니다.

    for (i = 0; i < N; i++) {
        scanf("%d %lf %lf", &member[i].stunum, &member[i].hei, &member[i].wei);
    } // 입력받을거 입력받습니다.

    for (i = 0; i < N; i++) {
        heiavg += member[i].hei;
        weiavg += member[i].wei; // 값들의 합을 일단 선언한 평균인자에 더합니다.
    }

    heiavg /= (double)N;
    weiavg /= (double)N; // 형변환한 학생수로 나눠줍니다.

    printf("%.1lf %.1lf\n", heiavg, weiavg); // 출력

    for (i = 0; i < N; i++) {
        if (member[i].hei < heiavg) { // 키가 평균키보다 작고
            if (member[i].wei < weiavg) // 몸무게가 평균보다 적게 나가면
                printf("%d below\n", member[i].stunum); // below
            else // 몸무게는 많이 나가면
                printf("%d average\n", member[i].stunum); // average
        }
        else { // 키가 평균키보다 크고
            if (member[i].wei >= weiavg) // 몸무게가 평균보다 많이 나가면
                printf("%d super\n", member[i].stunum); // super
            else // 몸무게는 적게 나가면
                printf("%d average\n", member[i].stunum); // average 입니다.
        }
    }
    return 0;
}