# minishell
minishell

1. subject 번역
2. 기본적인 fuctions 공부
3. 프로그램 작성
4. memory leak 확인
- ps를 사용하여 process_id를 찾는다.

while;
do leaks (process_id);
sleep 5;
clean;
done
5. crtl + c 로 종료하지 못한 경우
- ps를 사용하여 process_id를 찾는다.
- kill (process_id)
- 입력하여 강제 종료한다.

## git
브랜치 생성
브랜치 로컬 삭제
- git branch -d [브랜치명]
브랜치 원격 삭제
- git push origin :[브랜치명]