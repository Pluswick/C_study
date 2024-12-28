#include <stdio.h>

typedef struct _student { // �л� ����ü ����

    int stunum; // �л���ȣ
    double hei; // Ű
    double wei; // ������

}st;

int main() {
    int N, i;
    double heiavg = 0.0, weiavg = 0.0; // ��� �ʱ�ȭ
    st member[10] = { '\0', 0, 0.0 }; // ����ü �ʱ�ȭ

    scanf("%d", &N); // �л��� �Է¹޽��ϴ�.

    for (i = 0; i < N; i++) {
        scanf("%d %lf %lf", &member[i].stunum, &member[i].hei, &member[i].wei);
    } // �Է¹����� �Է¹޽��ϴ�.

    for (i = 0; i < N; i++) {
        heiavg += member[i].hei;
        weiavg += member[i].wei; // ������ ���� �ϴ� ������ ������ڿ� ���մϴ�.
    }

    heiavg /= (double)N;
    weiavg /= (double)N; // ����ȯ�� �л����� �����ݴϴ�.

    printf("%.1lf %.1lf\n", heiavg, weiavg); // ���

    for (i = 0; i < N; i++) {
        if (member[i].hei < heiavg) { // Ű�� ���Ű���� �۰�
            if (member[i].wei < weiavg) // �����԰� ��պ��� ���� ������
                printf("%d below\n", member[i].stunum); // below
            else // �����Դ� ���� ������
                printf("%d average\n", member[i].stunum); // average
        }
        else { // Ű�� ���Ű���� ũ��
            if (member[i].wei >= weiavg) // �����԰� ��պ��� ���� ������
                printf("%d super\n", member[i].stunum); // super
            else // �����Դ� ���� ������
                printf("%d average\n", member[i].stunum); // average �Դϴ�.
        }
    }
    return 0;
}