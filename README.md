# algorithm

[문제] 대나무가 많이 나는 어느 마을에는 윷놀이 대신 대나무 막대를 던져서 대나무들이 겹쳐서 뭉쳐있는
그룹의 크기가 큰 팀이 이기는 게임을 즐겼다. 대나무가 겹쳐서 뭉쳐있는 그룹이란 대나무가
하나라도 겹쳐서 연결되어 있는 대나무의 뭉치를 말한다. 그룹의 크기란 연결된 대나무의 개수를
말한다. 주어진 N개의 대나무를 던져서 그룹의 수와 가장 큰 그룹의 크기를 출력하는 프로그램을
작성해 보자. 대나무는 선분으로 나타낸다. 선분은 양끝점 p(x,y) 으로 나타낸다.


[입출력] 입력은 첫줄에 대나무 개수 N (1 <= N <= 500) 이 주어진다. 둘째 줄부터 (N + 1)번째 줄에는
양끝점의 좌표 x1,y1,x2,y2 의 순서로 주어진다. 각 좌표의 절대값은 10000을 넘지 않으며,
입력되는 좌표 사이에는 빈칸이 하나 있다.
출력에는 첫째 줄에는 그룹의 수를, 둘째 줄에는 가장 크기가 큰 그룹에 속한 선분의 개수를
출력한다.

예시)

입력						출력

6							2
2 -4 10 1					4
1 5 5 1
6 6 -3 3
-3 7 2 11
9 3 7 -3
-2 8 7 4


3							2
-1 -1 1 1					2
-2 -2 2 2
0 1 -1 0

